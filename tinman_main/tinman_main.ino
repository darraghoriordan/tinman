#include <Adafruit_FloraPixel.h>
#include <CapacitiveSensor.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 
  To upload to your Gemma or Trinket:
  1) Select the proper board from the Tools->Board Menu
  2) Select USBtinyISP from the Tools->Programmer
  3) Plug in the Gemma/Trinket, make sure you see the green LED lit
  4) For windows, install the USBtiny drivers
  5) Press the button on the Gemma/Trinket - verify you see
     the red LED pulse. This means it is ready to receive data
  6) Click the upload button above within 10 seconds
*/
 
//int led = 1; // blink 'digital' pin 1 - AKA the built in red LED
 CapacitiveSensor cs_0_2 = CapacitiveSensor(0,2);
 Adafruit_FloraPixel strip = Adafruit_FloraPixel(1);
// the setup routine runs once when you press reset:
void setup() {

    cs_0_2.set_CS_AutocaL_Millis(0xFFFFFFFF);   
       strip.begin();
    strip.show(); 
}
 
void loop()                    
{
    long start = millis();
    long total1 =  cs_0_2.capacitiveSensor(30);
 
    if (total1 > 4000){
      digitalWrite(1, HIGH);
       strip.setPixelColor(0, Color(0,0,255));  
      strip.show();
    }
    else{
      digitalWrite(1, LOW);
      strip.setPixelColor(0, Color(0,0,0)); 
      strip.show();
    }
      delay(10);
}

// Create a 24 bit color value from R,G,B
RGBPixel Color(byte r, byte g, byte b)
{
  RGBPixel p;
  
  p.red = r;
  p.green = g;
  p.blue = b;
  
  return p;
}
