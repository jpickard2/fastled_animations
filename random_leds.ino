#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB


CRGB leds[NUM_LEDS];

uint8_t hue = 70;
uint8_t brightness = 255;
uint16_t delaytime = 5;
uint8_t fade = 60;

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

    randomSeed(analogRead(0));
}

  
  
void loop() {

  leds[random(NUM_LEDS)] = CHSV(hue,255,brightness);
  FastLED.show();
  fadeToBlackBy(leds,NUM_LEDS,fade);
  delay(delaytime);
  //hue++; //cycle through hues
  hue = random(256); //random hues
    }
    
