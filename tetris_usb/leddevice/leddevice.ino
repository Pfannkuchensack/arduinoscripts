// For WMOS Devices ?
//#define FASTLED_ALLOW_INTERRUPTS 0
//#define FASTLED_INTERRUPT_RETRY_COUNT 1
#include <FastLED.h>
// Change if needed
#define PIN      6
#define N_LEDS 384
#define BRIGHTNESS  80
// https://gist.github.com/hsiboy/11545fd0241ab60b567d
#define MAX_BRIGHTNESS 255      // Thats full on, watch the power!
#define MIN_BRIGHTNESS 16       // set to a minimum of 25%
const int brightnessInPin = A2;  // The Analog input pin that the brightness control potentiometer is attached to.
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[N_LEDS];
#define UPDATES_PER_SECOND 24



void setup()
{
  delay(2000);
  FastLED.addLeds<WS2812, PIN, COLOR_ORDER>(leds, N_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  // Change if needed
  Serial.begin(1000000);
}


void loop()
{
  // Read all N_LEDS * 3 Bytes 
  while (!Serial.available() ) {
    Serial.readBytes( (char*)leds, N_LEDS * 3);
    // Show Matrix
    FastLED.show();
  // Needed?
     delay(10);
  // Send OK for Info
     int mappedValue = map(analogRead(brightnessInPin), 0, 1023, 0, 255);
    //Serial.println(mappedValue);
    // now we set the brightness of the strip
    //FastLED.setBrightness(constrain(mappedValue, MIN_BRIGHTNESS, MAX_BRIGHTNESS));
    Serial.println(mappedValue);
  }
  delay(100);
  Serial.println("NOK");
}
