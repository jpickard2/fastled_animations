//Lights a random led on top layer and then the ones below. Specific to this 9x9x9 display

#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB


CRGB leds[NUM_LEDS];

uint8_t hue = 130;
uint8_t brightness = 255;
uint16_t delaytime = 50;
uint8_t fade = 80;

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

    randomSeed(analogRead(0));
}

  
  
void loop() {

 //light a random led on top layer 
 int ledToLight = random(648,729);
 leds[ledToLight] = CHSV(hue,255,brightness);

 FastLED.show();
 
 delay(delaytime); 
 
 //then light leds below it
while(ledToLight>=81){
  ledToLight = ledToLight-81;
  leds[ledToLight] = CHSV(hue,255,brightness);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);
  delay(delaytime);
}

    
}
