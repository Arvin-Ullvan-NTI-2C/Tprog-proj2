#include <IRremote.h> // >v3.0.0 // inkluderar version 3.0.0 av IRremote biblioteket

#define PIN_SEND 3 //definerar att IR transmittern är på pin 3

const int buttonPin = 7;  // Här definieras en konstant för knappens pin 
int buttonState = 0;  // Variabel för att hålla knappens tillstånd
const int LaserPin = 10;  // Här definieras en konstant för laserens pin 

void setup()  
{  
  IrSender.begin(PIN_SEND); // Initialiserar IR-sändaren med det angivna pinnumret
  pinMode(buttonPin, INPUT);  // Sätter knappens pin som en input
  pinMode(LaserPin, OUTPUT);  // Sätter laserens pin som en output
}  
                               
void loop()  
{  
  buttonState = digitalRead(buttonPin);  // Läser av knappens tillstånd HIGH eller LOW

  if (buttonState == HIGH) {
    IrSender.sendNEC(0x0102, 0x34, true, 0); // Skickar en NEC IR-signal med adressen 0x0102 och kommandot 0x34
    digitalWrite(LaserPin, HIGH);  // Slår på laser genom att sätta dess pin till HIGH
  } else {
    digitalWrite(LaserPin, LOW);  // Slår av laser genom att sätta dess pin till LOW
  }  
}
