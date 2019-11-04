void setup(){
pinMode(3, OUTPUT);

  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS22);
  OCR2A = 180;
  OCR2B = 50; // changing this value affects the duty cycle.
              // here it is 50% duty cycle
}
void loop(){
  }
  
