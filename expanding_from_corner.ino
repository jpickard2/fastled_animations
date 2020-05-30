//Cube outlines expanding from the zero corner of this 9x9x9 display (not generalizable)

#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    729
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
uint8_t brightness = 255;
uint16_t delaytime;
uint8_t fade = 255;

//numbers for each layer for expanding from corner

int level2 [7] = {1,16,17,81,82,97,98};
int level3 [19] = {2,15,18,19,20,83,96,99,100,101,162,163,164,177,178,179,180,181,182};
int level4 [37] = {3,14,21,32,33,34,35,84,95,102,113,114,115,116,165,176,183,194,195,196,197,243,244,245,246,257,258,259,260,261,262,263,264,275,276,277,278};
int level5 [61] = {4,13,22,31,36,37,38,39,40,85,94,103,112,117,118,119,120,121,166,175,184,193,198,199,200,201,202,247,256,265,274,279,280,281,282,283,
324,325,326,327,328,337,338,339,340,341,342,343,344,345,346,355,356,357,358,359,360,361,362,363,364};
int level6 [91] = {5,12,23,30,41,48,49,50,51,52,53,86,93,104,111,122,129,130,131,132,133,134,167,174,185,192,203,210,211,212,213,214,215,248,255,266,273,284,291,292,293,294,295,296,329,336,347,354,365,372,373,374,375,376,377,
405,406,407,408,409,410,417,418,419,420,421,422,423,424,425,426,427,428,435,436,437,438,439,440,441,442,443,444,445,446,453,454,455,456,457,458};
int level7 [127] = {6,11,24,29,42,47,54,55,56,57,58,59,60,87,92,105,110,123,128,135,136,137,138,139,140,141,168,173,186,191,204,209,216,217,218,219,220,221,222,249,254,267,272,285,290,297,298,299,300,301,302,303,330,335,348,353,366,371,378,379,380,381,382,383,384,411,416,429,434,447,452,459,460,461,462,463,464,465,486,487,488,489,490,491,492,497,498,499,500,501,502,503,504,505,506,507,508,509,510,515,516,517,518,519,520,521,522,523,524,525,526,527,528,533,534,535,536,537,538,539,540,541,542,543,544,545,546};
int level8 [169] = {7,10,25,28,43,46,61,64,65,66,67,68,69,70,71,88,91,106,109,124,127,142,145,146,147,148,149,150,151,152,
169,172,187,190,205,208,223,226,227,228,229,230,231,232,233,250,253,268,271,286,289,304,307,308,309,310,311,312,313,314,331,334,349,352,367,370,385,388,389,390,391,392,393,394,395,
412,415,430,433,448,451,466,469,470,471,472,473,474,475,476,493,496,511,514,529,532,547,550,551,552,553,554,555,556,557,567,568,569,570,571,572,573,574,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,595,596,597,598,599,600,601,602,
603,604,605,606,607,608,609,610,613,614,615,616,617,618,619,620,621,622,623,624,625,626,627,628,631,632,633,634,635,636,637,638};
int level9 [217] = {8,9,26,27,44,45,62,63,72,73,74,75,76,77,78,79,80,89,90,107,108,125,126,143,144,153,154,155,156,157,158,159,160,161,170,171,188,189,206,207,224,225,234,235,236,237,238,239,240,241,242,
251,252,269,270,287,288,305,306,315,316,317,318,319,320,321,322,323,332,333,350,351,368,369,386,387,396,397,398,399,400,401,402,403,404,413,414,431,432,449,450,467,468,477,478,480,481,482,483,484,485,
494,495,512,513,530,531,548,549,558,559,560,561,562,563,564,565,566,575,576,593,594,611,612,629,630,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,678,679,680,
681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,717,718,719,720,721,722,723,724,725,726,727,728};

void setup() {
    FastLED.setMaxPowerInMilliWatts(90000); //max 100W for this power supply
    delay(1000);
    LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);


    
}

  
  
void loop() {

  delaytime = analogRead(10); //use pot to control speed
  
  //expanding cubes. manually entered led numbers in arrays above

  //level1
  leds[0] = CHSV(hue,255,brightness);
  
  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);
  
  //level2
  for(int i=0; i<7; i++){
    int ledtolight = level2[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

  //level3
  for(int i=0; i<19; i++){
    int ledtolight = level3[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

//level4
  for(int i=0; i<37; i++){
    int ledtolight = level4[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

  
//level5
  for(int i=0; i<61; i++){
    int ledtolight = level5[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);


//level6
  for(int i=0; i<91; i++){
    int ledtolight = level6[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

//level7
  for(int i=0; i<127; i++){
    int ledtolight = level7[i];
    leds[ledtolight] = CHSV(hue,255,brightness);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade); 

//level8
  for(int i=0; i<169; i++){
    int ledtolight = level8[i];
    leds[ledtolight] = CHSV(hue,255,200);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);    
    

//level9
  for(int i=0; i<217; i++){
    int ledtolight = level9[i];
    leds[ledtolight] = CHSV(hue,255,150);
  }

  delay(delaytime);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, fade);

  hue = hue+10; //move through rainbow every cycle
}
