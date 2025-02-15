#include "led.h"
#include <Arduino.h>  

#define PIN_RED    13 // GPIO23
#define PIN_GREEN  12 // GPIO22
#define PIN_BLUE   14 // GPIO21

void setUpLed(){
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);

}

void setColor(int R, int G, int B){
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);

}

void ledColorPlay() {
    int brightness = 255;  // Max brightness
    int speed = 20;        // Delay between color changes

    // 🌈 Rainbow transition loop
    for (int i = 0; i < 256; i++) {
        int r, g, b;

        // Color cycling through the rainbow spectrum
        if (i < 85) {
            r = i * 3;
            g = 255 - i * 3;
            b = 0;
        } else if (i < 170) {
            r = 255 - (i - 85) * 3;
            g = 0;
            b = (i - 85) * 3;
        } else {
            r = 0;
            g = (i - 170) * 3;
            b = 255 - (i - 170) * 3;
        }

        setColor(r * brightness / 255, g * brightness / 255, b * brightness / 255);
        delay(speed);
    }
}


void fireEffect() {
    int minBrightness = 50;
    int maxBrightness = 255;
    int speed = 50; // Flickering speed

    for (int i = 0; i < 50; i++) {
        int flicker = random(minBrightness, maxBrightness);
        setColor(flicker, flicker / 2, 0);  // Warm yellow-orange glow
        delay(random(30, speed));
    }
}



void breathingEffect() {
    int speed = 5;  // Speed of breathing

    // Fade in
    for (int i = 0; i <= 50; i += speed) {
        setColor(0, 0, i);  // Blue breathing effect
        delay(20);
    }

    // Fade out
    for (int i = 50; i >= 0; i -= speed) {
        setColor(0, 0, i);
        delay(20);
    }
}