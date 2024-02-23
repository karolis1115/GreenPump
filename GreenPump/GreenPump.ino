int waterlvl = 1, var1; //vandens lygio matuoklis
int moisture = 0, var0; //vandens lygio matuoklis dirvoje
void setup() {
  pinMode(6, OUTPUT); //
  pinMode(7, OUTPUT); //
  pinMode(9, OUTPUT); //
  pinMode(5, OUTPUT);
  Serial.begin(9600); //
}
void loop() {
  var1 = analogRead(waterlvl); //nuskaito vandens lygi
  if (var1 < 400) //jei vandens lygis maziau uz 1000 tai
  {
    Serial.print(" vandens lygis ");
    Serial.println(var1);
    Serial.print(" dregme ");
    Serial.println(var0);
    delay(100);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(5,LOW);
    digitalWrite(9,HIGH);
    delay(100);
    digitalWrite(9,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    delay(1000);
  }
  else if (var1 > 400) //jei vandens lygis daugiau uz 1000 tai
  {
     digitalWrite(9,LOW);
     var0 = analogRead(moisture);
    Serial.print(" vandens lygis ");
    Serial.println(var1);
    Serial.print(" dregme ");
    Serial.println(var0);
     if (var0 < 900)
  {
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(5,HIGH);
  }
  else if (var0 > 900) {
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(5,LOW);
  }
    
  }
}
