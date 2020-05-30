//Rays going through the led cube space (should be generalizable to cubes made of stacked symmetrical layers each arranged in a serpentine layout)
//Right now limited to simple lines with slope of -1,0 or 1 but would like to extend to any line or even curves or sine waves? Not sure if it's worth trying on a display of 9x9x9 resolution though
#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

uint8_t brightness = 255;
uint8_t hue = 110;
uint8_t fade = 30;
const int width = 9;
const int height = 9;
const int depth = 9;

//FUNCTIONS

//xy to led number translation from FastLED extended to z dimension and protected from out of range
uint16_t XYZ( uint8_t x, uint8_t y, uint8_t z){
  
  
    uint16_t i;

    if(x<width && y<height && z<depth){
    
    if( y & 1) {
      // Odd rows run backwards
      uint8_t reverseX = (width - 1) - x;
      i = (y * width) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * width) + x;
    }
  

  i = i + (z * width * height);
  
  return i;
    }else{
      return 0;
    }
}

  //position and movement variables
  int x;
  int y;
  int z;

  int xchange;
  int ychange;
  int zchange;


void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    
    randomSeed(analogRead(0));
}

  
  
void loop() {
  //choose random face to "enter" from and starting position on that face, and how the line is going to move
  
  int die6D = random(0,6);
    
  switch(die6D){
    
    //e.g. in this first case we start on the x=0 face and a random y and z position. we limit the movement in the x direction to positive but allow movement in y and z direction to be positive, negative or stationary
    case 0:
    x = 0;
    y = random(height);
    z = random(depth);
    xchange = 1;
    ychange = random(-1,2);
    zchange = random(-1,2);
    break;

    case 1:
    x = width-1;
    y = random(height);
    z = random(depth);
    xchange = -1; 
    ychange = random(-1,2);
    zchange = random(-1,2);
    break;
    
    case 2:
    x = random(width);
    y = 0;
    z = random(depth);
    xchange = random(-1,2); 
    ychange = 1;
    zchange = random(-1,2);
    break;
    
    case 3:
    x = random(width);
    y = height-1;
    z = random(depth);
    xchange = random(-1,2); 
    ychange = -1;
    zchange = random(-1,2);
    break;
    
    case 4:
    x = random(width);
    y = random(height);
    z = 0;
    xchange = random(-1,2); 
    ychange = random(-1,2);
    zchange = 1;
    break;
    
    case 5:
    x = random(width);
    y = random(height);
    z = depth-1;
    xchange = random(-1,2); 
    ychange = random(-1,2);
    zchange = -1;
    break;
  }

    //once starting position and movement direction decided, add the change value to each coord, convert to led number and display, until one hits a face (x,y or z = 0 or width/height/depth-1)

    while(x>=0 && x<width && y>=0 && y<height && z>=0 && z<depth){
      int ledToLight = XYZ(x,y,z);
      leds[ledToLight] = (CHSV(hue,255,brightness));
      FastLED.show(); 
      
      fadeToBlackBy(leds, NUM_LEDS, fade);
      
      x = x + xchange;
      y = y + ychange;
      z = z + zchange;

      delay(20);
      
  }
  
    //continue fading out and random time until next line appears
    int timelim = random(100);
    for(int i=0; i<timelim; i++){
      fadeToBlackBy(leds, NUM_LEDS, fade);
      delay(20);
      FastLED.show();
    }
    

 
}
