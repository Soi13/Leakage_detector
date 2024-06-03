/*Leakage detector for dishwasher
https://newbiely.com/tutorials/esp8266/esp8266-water-sensor
*/

#define LED_PIN     D2
#define POWER_PIN   D7
#define SIGNAL_PIN  A0
#define THRESHOLD   300

int sensor_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);
  delay(10);
  value = analogRead(SIGNAL_PIN);
  digitalWrite(POWER_PIN, LOW);

  if (value > THRESHOLD) {
    Serial.print("The water is detected");
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

}
