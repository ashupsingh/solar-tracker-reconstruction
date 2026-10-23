// Reconstructed 2026-10-23. New pin map; not the lost original firmware.
#include <Arduino.h>
#if defined(ESP32)
const int SENSOR=34, INPUT_A=27, INPUT_B=14, OUT=26, AUX=25;
const int ADC_MAXIMUM=4095;
#else
const int SENSOR=A0, INPUT_A=2, INPUT_B=3, OUT=8, AUX=9;
const int ADC_MAXIMUM=1023;
#endif
// OUT/AUX drive a transistor/module input, never an inductive load directly.
// Default OFF = LOW. Use a compatible active-HIGH driver for this reconstruction.

#if defined(ESP32)
#include <ESP32Servo.h>
#else
#include <Servo.h>
#endif

#if defined(ESP32)
const int TL=32,TR=33,BL=34,BOTTOM_RIGHT_PIN=35;
#else
const int TL=A0,TR=A1,BL=A2,BOTTOM_RIGHT_PIN=A3;
#endif
Servo panServo,tiltServo;int pan=90,tilt=90;unsigned long last=0;
int delta(int e){return abs(e)<ADC_MAXIMUM/20?0:(e>0?1:-1);}
void setup(){panServo.attach(OUT);tiltServo.attach(AUX);panServo.write(pan);tiltServo.write(tilt);}
void loop(){unsigned long now=millis();if(now-last<100)return;last=now;
 int tl=analogRead(TL),tr=analogRead(TR),bl=analogRead(BL),br=analogRead(BOTTOM_RIGHT_PIN);
 if(tl+tr+bl+br<ADC_MAXIMUM/4)return;
 pan=constrain(pan+delta((tr+br)-(tl+bl)),15,165);tilt=constrain(tilt+delta((tl+tr)-(bl+br)),15,165);
 panServo.write(pan);tiltServo.write(tilt);
}
