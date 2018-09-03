/*
 * HC-SR04 Proximity Sensor
 *
 * Author: Augusto Recordon
*/

const int TRIG_PIN = 10;
const int ECHO_PIN = 9;

void setup() {
  //Define the trig pin as an output.
  pinMode(TRIG_PIN, OUTPUT);
  // Define the echo pin as an input.
  pinMode(ECHO_PIN, INPUT);
  // Start Serial comm.
  Serial.begin(9600);
}
void loop() {
  // Clear the trig pin to have a clean high pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  
  // Send a HIGH pulse on the trig pin for 10 microseconds to trigger the sensor.
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  // Clear the trig pin.
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echoPin (travel time of the sound wave in microseconds).
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Transform the reading to cms or inches.
  int distance= (duration / 2) / 29.1 ; // Replace 29.1 with 74 for inches.
  
  // Write the distance to the Serial port.
  Serial.println(distance);

  // Wait for a second before the next loop.
  delay(1000);
}
