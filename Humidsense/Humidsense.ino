int moisture=A0, value;
void setup() {
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
void loop() {
value=analogRead(moisture);
if (value<1000)
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  delay(30);
}
else if (value>1000){
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  delay(30);
}
}
