#include <IRremote.h> // >v3.0.0 // här lägger jag till version 3.0.0 av IRremote biblioteket

// Här definieras en konstant för mottagarens pin 
#define PIN_RECV 11
const int buzzerPin = 7;  // Här definieras en konstant för buzzer-pin 
bool ShouldBuzzerBeOn = false;  // För att styra om buzzer ska vara på eller av
const int LEDPin = 13;  // Här definieras en konstant för LED-pin

void setup()  
{  
  Serial.begin(9600); // Initialiserar seriell kommunikation för att skriva till Seriell Monitorn
  IrReceiver.begin(PIN_RECV); // Initialiserar IR-mottagaren med den angivna pin-numret
  pinMode(buzzerPin, OUTPUT);  // Sätter buzzer-pin som en output
  pinMode(LEDPin, OUTPUT);  // Sätter LED-pin som en output
}  
                               
void loop()  {
  if (IrReceiver.decode()) { // testar för att se om mottagern lyckas dekoda en IR signal
    Serial.println("Received something..."); 
    tone(buzzerPin, 50);  // Ger en ton på buzzer-pin i 50 Hz
    digitalWrite(LEDPin, LOW);  // Slår av LED genom att sätta dess pin till LOW
    delay(500);  // Väntar i 500 millisekunder
    noTone(buzzerPin);  // Stänger av tonen på buzzer-pin
    IrReceiver.printIRResultShort(&Serial); // Skriver en sammanfattning av den mottagna IR-data till Seriell Monitor
    Serial.println();
    IrReceiver.resume(); // Aktiverar mottagningen av nästa IR-signal
  } else {
    digitalWrite(LEDPin, HIGH);  // Om ingen IR-signal detekteras ska den LEDPin stanna på HIGH
  }
}
