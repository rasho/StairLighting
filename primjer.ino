// Uključi potrebne biblioteke
#include <Arduino.h>
#include "StaircaseLighting.h"

// Definiraj broj LED svjetala na stepenicama
#define NUM_STAIRS 10

// Inicijaliziraj objekt klase StaircaseLighting
StaircaseLighting staircaseLights;

void setup() {
  // Postavi pinove za LED svjetla kao izlazne
  for (int i = 2; i <= NUM_STAIRS + 1; i++) {
    pinMode(i, OUTPUT);
  }
  
  // Postavi početni efekt i boju
  staircaseLights.setEffect(EFFECT_FADE);
  staircaseLights.setColor(255, 0, 0);  // Crvena boja
  
  // Dodatne postavke prema potrebi
}

void loop() {
  // Ažuriraj stanje LED svjetala
  staircaseLights.update();
  
  // Dodatni kod ili logika programa
}
