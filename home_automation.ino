const int tempPin = A0;      // TMP36 analog pin
const int ir1Pin = 2;         // IR sensor pin
const int fanPin = 9;        // Fan (LED)
const int lightPin = 8;      // Light (LED)

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  pinMode(ir1Pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature from TMP36
  int rawValue = analogRead(tempPin);
  float voltage = rawValue * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;

  // Read IR sensor
  int irState1 = digitalRead(ir1Pin);  // 0 when detects object, 1 when no object

  // Fan logic
  if (tempC > 30) {
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
  }

  // Light logic
  if (irState1 == HIGH) {
    digitalWrite(lightPin, HIGH);  // Object detected
  } else {
    digitalWrite(lightPin, LOW);   // No object
  }

  // Debug output
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C | IR: ");
  Serial.println(irState1);

  delay(500);
}
