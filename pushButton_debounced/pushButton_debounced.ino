//everytimime i push the button led inverts itself
//debouncing switch using debounce function
int ledPin=13;
int switchPin=2;
bool lastButton=LOW;
bool currentButton=LOW;
bool ledOn=false;
bool debounce(bool last){
    bool current=digitalRead(switchPin);
    if(last!=current){
      delay(5);
      current=digitalRead(switchPin);
      
    }
    return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  currentButton=debounce(lastButton);
  if (lastButton==LOW && currentButton==HIGH)
  {
    
    ledOn=!ledOn;
    
  }
 
    lastButton=currentButton;
  
  digitalWrite(ledPin,ledOn);
}
