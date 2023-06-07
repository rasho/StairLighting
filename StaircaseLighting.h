#include <Adafruit_NeoPixel.h>

#define PIN_LED 6       // Pin na kojem su spojene LED sijalice
#define NUM_LEDS 10     // Broj LED sijalica koje koristimo

// Definiraj različite efekte za osvjetljavanje
enum LightingEffect {
  EFFECT_OFF,      // Isključeno
  EFFECT_STATIC,   // Statičan efekt (sve LED-ice su jednobojne)
  EFFECT_FADE,     // Efekt postupnog blijedenja
  EFFECT_BLINK,    // Efekt treptanja
  EFFECT_RANDOM    // Slučajan efekt
};

class StaircaseLighting {
  private:
    Adafruit_NeoPixel pixels;   // Objekt za upravljanje LED-icama
    LightingEffect currentEffect;   // Trenutni efekt
    uint32_t currentColor;   // Trenutna boja
    unsigned long previousMillis;   // Vrijeme zadnjeg ažuriranja efekta
    unsigned long interval;   // Interval između ažuriranja efekta

  public:
    StaircaseLighting() : pixels(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800), currentEffect(EFFECT_OFF), currentColor(0), previousMillis(0), interval(1000) {
      pixels.begin();   // Inicijalizacija LED-ica
    }

    void setEffect(LightingEffect effect) {
      currentEffect = effect;
    }

    void setColor(uint8_t r, uint8_t g, uint8_t b) {
      currentColor = pixels.Color(r, g, b);
    }

    void update() {
      switch (currentEffect) {
        case EFFECT_OFF:
          turnOff();
          break;

        case EFFECT_STATIC:
          staticEffect();
          break;

        case EFFECT_FADE:
          fadeEffect();
          break;

        case EFFECT_BLINK:
          blinkEffect();
          break;

        case EFFECT_RANDOM:
          randomEffect();
          break;

        default:
          turnOff();
          break;
      }
    }

  private:
    void turnOff() {
      pixels.clear();   // Isključi sve LED-ice
      pixels.show();    // Prikazi promjene na LED-icama
    }

    void staticEffect() {
      for (int i = 0; i < NUM_LEDS; i++) {
        pixels.setPixelColor(i, currentColor);   // Postavi boju svake LED-ice
      }
      pixels.show();    // Prikazi promjene na LED-icama
    }

    void fadeEffect() {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        for (int i = 0; i < NUM_LEDS; i++) {
          uint32_t color = pixels.getPixelColor(i);
          uint8_t r = (color >> 16) & 0xFF;
          uint8_t g = (color >> 8) & 0xFF;
          uint8_t b = color & 0xFF;

          if (r > 0) r--;   // Smanji vrijednost crvene komponente
          if (g > 0) g--;   // Smanji vrijednost zelene komponente
          if (b > 0) b--;   // Smanji vrijednost plave komponente

          pixels.setPixelColor(i, pixels.Color(r, g, b));   // Postavi novu boju LED-ice
        }

        pixels.show();    // Prikazi promjene na LED-icama
      }
    }

    void blinkEffect() {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        if (pixels.getPixelColor(0) == currentColor) {
          pixels.clear();   // Isključi sve LED-ice
        } else {
          for (int i = 0; i < NUM_LEDS; i++) {
            pixels.setPixelColor(i, currentColor);   // Postavi boju svake LED-ice
          }
        }

        pixels.show();    // Prikazi promjene na LED-icama
      }
    }

    void randomEffect() {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        for (int i = 0; i < NUM_LEDS; i++) {
          // Generiraj slučajnu boju
          uint8_t r = random(256);
          uint8_t g = random(256);
          uint8_t b = random(256);

          pixels.setPixelColor(i, pixels.Color(r, g, b));   // Postavi slučajnu boju LED-ice
        }

        pixels.show();    // Prikazi promjene na LED-icama
      }
    }
};
