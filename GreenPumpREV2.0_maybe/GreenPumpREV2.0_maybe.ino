#include <dht.h>
#define DHT11_PIN 7
#define pumppin 13
dht DHT;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
char x, z;
char state = x;
int val;

void pumpaction() {
  if (val > 310) {
    digitalWrite(13, );
  } else if (val < 310) {
    digitalWrite(13, LOW);
  }
}

void sense() {
  val = analogRead(A0);  // read the input pin
  Serial.print("Moisture: ");
  Serial.println(val);
}

void dht() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
void ult() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
void setup() {
  pinMode(2, OUTPUT);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  pinMode(A0, INPUT);
  pinMode(pumppin, OUTPUT);
  digitalWrite(pumppin, LOW);
  Serial.begin(115200);  // communication with the host computer
                         //while (!Serial)   { ; }
}
void loop() {
  digitalWrite(2, LOW);
  dht();
  sense();
  pumpaction();
}
