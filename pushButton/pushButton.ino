//everytimime i push the button led inverts itself
int ledPin=13;
int switchPin=8;
bool lastButton=LOW;
bool ledOn=false;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(switchPin)==HIGH && lastButton==LOW)
  {
    
    ledOn=!ledOn;
    lastButton=HIGH;
  }
  else{
    lastButton=digitalRead(switchPin);
  }
  digitalWrite(ledPin,ledOn);
}
