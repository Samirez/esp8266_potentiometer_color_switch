#include <Arduino.h>

#define potentiometer_pin A0
#define red_led 4

int analogValue = 0;
int angle = 0;
float voltage = 0.0;


float floatMap(float x, float in_min, float in_max, float out_min, float out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(red_led, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  analogValue = analogRead(A0);
  voltage = floatMap(analogValue, 0, 1023, 0, 5);
  angle = map(voltage, 0, 1023, 0, 270);
  Serial.println("analog value: "+String(analogValue));
  Serial.println("voltage: "+String(voltage));
  Serial.println("potentiometer angle: "+String(angle));

  if (analogValue >= 1024)
  {
    digitalWrite(red_led, HIGH);
  } else 
  {
    digitalWrite(red_led, LOW);
  }
  
}
