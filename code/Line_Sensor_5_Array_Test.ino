// IR Sensor Pins
const int irPins[5] = {2, 3, 4, 5, 6};
int irValues[5];

void setup() {
  Serial.begin(9600);
  
  // Set IR pins as input
  for (int i = 0; i < 5; i++) {
    pinMode(irPins[i], INPUT);
  }
}

void loop() {
  // Read all 5 sensors
  for (int i = 0; i < 5; i++) {
    irValues[i] = digitalRead(irPins[i]);
  }

  // Print sensor values
  Serial.print("IR Values: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(irValues[i]);
    Serial.print(" ");
  }
  Serial.println();

  delay(200); // Adjust delay as needed
}
