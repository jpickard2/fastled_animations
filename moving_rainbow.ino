//Moves through the range of hues for a rainbow effect
#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB


CRGB leds[NUM_LEDS];

uint8_t hue = 0;
uint8_t startHue = 0;
uint8_t brightness = 150;
uint16_t delaytime = 10;

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 90W

    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}
  
void loop() {

   delaytime = analogRead(10); //adjust speed with pot
    
   hue = startHue;
   
   for(int i=0; i<NUM_LEDS; i++){
   leds[i] = CHSV(hue,255,brightness);
   hue = hue+256/75; //tweak this value but looks good around 256/81 so that it goes through the rainbow about once each level
   }
        
   FastLED.show();
   delay(delaytime);

   startHue = startHue+5;
     
}
