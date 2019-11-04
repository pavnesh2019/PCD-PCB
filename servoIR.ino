#include <IRremote.h>
const int irPin = 3;
int angle = 90;
int incomingByte = 0;
int servo0 = 600;
int servo180 = 2100;
int inc = 20;
int pos = servo0;
int servoPin = 9;
int pulseInterval=2000;
unsigned long lastCode; 
IRrecv irrecv(irPin);
decode_results results;
void setup()
{
irrecv.enableIRIn();
pinMode(servoPin, OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results))
{
    if(results.value == 0xFFFFFFFF)   
    {
       results.value = lastCode;        
    }

    if(results.value == 0xFD08F7)    
    {
        lastCode = results.value;
        angle += 5;
        if(angle > 180){angle = 180;} 
        pos = (angle*11) + 470;
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(pos);
        digitalWrite(servoPin, LOW);
        delay(20);      
    }
      
    if(results.value == 0xFD8877)     
    {
      lastCode = results.value;
       angle -= 5; 
       if(angle < 0){angle = 0;}                   
       pos = (angle*11) + 470;
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(pos);
        digitalWrite(servoPin, LOW);
        delay(20);       
    }
    delay(1); 
    irrecv.resume(); 
}
    
 }
