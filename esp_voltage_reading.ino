const int analogInPin = A0;  // Analog Pin ADC0 = A0
const float x = 0.4172099087353325; // adjust this number to match your microcontrollers ADC using formula = ADC-battery-reading/battery-voltage-in-milivolts
float v = 0;
float percent = 0;

int sensorValue = 0;  // value read from the pot

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  v = sensorValue * x / 100;
  percent = ((v / 4) - 3) / 1.2;
  Serial.println(percent);
  // this delay has to be the same as in your python script
  delay(1000);
}