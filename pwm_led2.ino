int sensePin=0;
int ledPin=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(sensePin);
  if(val<500) digitalWrite(ledPin,HIGH);
  else digitalWrite(ledPin,LOW);
  
}
