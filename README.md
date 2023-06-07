Ovaj primjer klase StaircaseLighting koristi biblioteku Adafruit_NeoPixel za upravljanje LED svjetlima. Klasa ima različite metode za postavljanje efekta, boje i ažuriranje stanja LED svjetala. Efekti uključuju isključivanje svjetala, statički prikaz jednobojne svjetlosti, postupno blijedenje, treptanje i slučajnu promjenu boja.


U ovom primjeru, prvo se uključuju potrebne biblioteke i definira broj LED svjetala na stepenicama. Zatim se inicijalizira objekt klase StaircaseLighting pod nazivom staircaseLights. U funkciji setup() postavljaju se pinovi za LED svjetla kao izlazni, određuje se početni efekt (u ovom slučaju EFFECT_FADE - postupno blijedenje) i boja (crvena). Ovo su samo primjeri postavki, a možete ih prilagoditi prema vlastitim potrebama.

U glavnoj petlji loop(), poziva se metoda update() objekta staircaseLights kako bi se ažuriralo stanje LED svjetala prema odabranom efektu. Ovdje možete dodati dodatni kod ili logiku programa.

Sada, kad pokrenete Arduino s ovim kodom, LED svjetla će se kontrolirati putem klase StaircaseLighting i odabrani efekt će se primijeniti na stepenice. Možete eksperimentirati s različitim efektima i bojama kako biste postigli željeni vizualni dojam.

