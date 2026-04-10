// === Motor Driver Pins (L298N) ===
#define IN1 6
#define IN2 7
#define ENA 5   // PWM pin for left motor

#define IN3 8
#define IN4 9
#define ENB 10  // PWM pin for right motor

// === IR Sensor Pins ===
const int irPins[5] = {A0, A1, A2, A3, A4};

// === PID Constants ===
float Kp = 35;    // Proportional gain
float Ki = 0;     // Integral gain
float Kd = 22;    // Derivative gain

// === Parameters ===
int threshold = 600;     // Calibrate this based on sensor readings
int baseSpeed = 150;     // Moderate speed, adjust as needed
int minSpeed = 80;       // Prevent motors from stalling

// === Internal Variables ===
float lastError = 0;
float integral = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) pinMode(irPins[i], INPUT);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT); pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT); pinMode(ENB, OUTPUT);
}

void loop() {
  // === 1) Read Sensors ===
  int activeCount = 0;
  long weightedSum = 0;

  for (int i = 0; i < 5; i++) {
    int val = analogRead(irPins[i]);
    bool onLine = (val < threshold);
    if (onLine) {
      weightedSum += (i - 2);  // weights: -2 to +2
      activeCount++;
    }
  }

  // === 2) If all sensors are white, stop ===
  if (activeCount == 0) {
    stopMotors();
    return;
  }

  // === 3) PID Calculation ===
  float error = (float)weightedSum / activeCount;
  integral += error;
  float derivative = error - lastError;
  float correction = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;

  // === 4) Adjust motor speeds based on correction ===
  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  // Ensure minimum speed
  leftSpeed  = constrain(leftSpeed,  minSpeed, 255);
  rightSpeed = constrain(rightSpeed, minSpeed, 255);

  driveForward(leftSpeed, rightSpeed);

  // Optional: Debugging
  // Serial.print("Err: "); Serial.print(error);
  // Serial.print(" | L: "); Serial.print(leftSpeed);
  // Serial.print(" | R: "); Serial.println(rightSpeed);
}

// === Motor Control Functions ===
void driveForward(int leftSpd, int rightSpd) {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  analogWrite(ENA, leftSpd);

  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  analogWrite(ENB, rightSpd);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
