//Cube outlines expanding from the center of this 9x9x9 display (not generalizable)

#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

uint8_t hue = 10;
uint8_t brightness = 200;
uint16_t delaytime;
uint8_t fade = 255;

CRGB leds[NUM_LEDS];

//numbers of each layer

  int level2 [20] = {273,274,275,282,284,291,292,293,354,356,372,374,435,436,437,444,446,453,454,455};
  int level3 [44] = {182,183,184,185,186,191,195,200,204,209,213,218,219,220,221,222,263,267,299,303,344,348,380,384,425,429,461,465,506,507,508,509,510,515,519,524,528,533,537,542,543,544,545,546};
  int level4 [68] = {91,92,93,94,95,96,97,100,106,109,115,118,124,127,133,136,142,145,146,147,148,149,150,151,172,178,226,232,253,259,307,313,334,340,388,394,415,421,469,475,
  496,502,550,556,577,578,579,580,581,582,583,586,592,595,601,601,610,613,619,622,628,631,632,633,634,635,636,637};
  int level5 [92] = {0,1,2,3,4,5,6,7,8,9,17,18,26,27,35,36,44,45,53,54,62,63,71,72,73,74,75,76,77,78,79,80,81,89,153,161,162,170,234,242,243,251,315,323,324,332,396,404,405,413,
  477,485,486,494,558,566,567,575,639,647,648,649,650,651,652,653,654,655,656,657,665,666,674,675,683,684,692,693,701,702,710,711,719,720,721,722,723,724,725,726,727,728};

  

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);         
}
  
void loop() {
  //get analog value from pin 10
  delaytime = analogRead(10); //use pot to control speed

  
  //expanding cubes. manually entered led numbers in arrays above. adjusted brightness down for outer layers

  //level1
    leds[364] = CHSV(hue,255,255);
  
  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);
  
  //level2
  for(int i=0; i<20; i++){
    int ledtolight = level2[i];
    leds[ledtolight] = CHSV(hue,255,255);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

  //level3
  for(int i=0; i<44; i++){
    int ledtolight = level3[i];
    leds[ledtolight] = CHSV(hue,255,200);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

//level4
  for(int i=0; i<68; i++){
    int ledtolight = level4[i];
    leds[ledtolight] = CHSV(hue,255,130);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

  

//level5
  for(int i=0; i<92; i++){
    int ledtolight = level5[i];
    leds[ledtolight] = CHSV(hue,255,100);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

 hue = hue+10; //move through rainbow every cycle
}


  
  

  
  
  
