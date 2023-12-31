const int analogInPin = A0;  // Analog Pin ADC0 = A0
const float x = 0.4172099087353325; // tutorial how to adjust this value in README.md
float min_voltage = 3.1; // I want my esp to repport 0% when avarage voltage on a cell drops to 3.1V, ajust it to yours liking
float max_voltage = 4.2; // Voltage of max charged batteries
int number_of_cells = 4; // If you use 4s battery put here 4, if 3s - 3 etc
float v = 0;
float percent = 0;
int sensorValue = 0;  // value read from the pot

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  v = sensorValue * x / 100; // v represents now voltage of your battery pack
  percent = ((v / number_of_cells) - min_voltage) / (max_voltage - min_voltage);
  Serial.println(percent);
  // this delay has to be the same as in your python script, note that delay here is in ms but in python it is in s, so if here is 30000 in python it should be 30
  delay(30000);
}
