//Lights random leds on one level at a time every 5 seconds. Specific to this 9x9x9 display
#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB


CRGB leds[NUM_LEDS];

uint8_t hue = 130;
uint8_t brightness = 255;
uint16_t delaytime = 5;
uint8_t fade = 60;

long startTime = 0;
long elapsedTime = 0;

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
   
    randomSeed(analogRead(0));
}

  
  
void loop() {

  startTime = millis();
  elapsedTime = millis() - startTime;
  
 //light random leds on top level and fade
while(elapsedTime < 5000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(648,729);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

//next level down

while(elapsedTime < 10000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(567,648);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

 while(elapsedTime < 15000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(486,567);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}     
while(elapsedTime < 20000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(405,486);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

while(elapsedTime < 25000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(324,405);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

while(elapsedTime < 30000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(243,324);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

while(elapsedTime < 35000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(162,243);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

while(elapsedTime < 40000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(81,162);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}

while(elapsedTime < 45000){
 EVERY_N_MILLISECONDS(delaytime){
 int ledToLight = random(0,81);
 leds[ledToLight] = CHSV(hue,255,brightness);
 FastLED.show();
 fadeToBlackBy(leds, NUM_LEDS, fade);
 elapsedTime = millis() - startTime;
 }
}
    }
    
