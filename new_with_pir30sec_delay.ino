const int motionPin = PB0;  // Motion sensor input pin
const int ledPin = PB1;     // LED output pin
const unsigned long activeTime = 20000;  // Active time in milliseconds (20 seconds)
const unsigned long cooldownTime = 900000; // Cooldown time in milliseconds (15 minutes)
const unsigned long stabilityDelay = 100;  // Stability delay in milliseconds (0.1 seconds)

void setup() {
  pinMode(motionPin, INPUT_PULLUP); // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  delay(30000);  // Wait for 30 seconds to allow the PIR sensor to stabilize
}

void loop() {
  int motionValue = digitalRead(motionPin);

  if (motionValue == LOW) {  // Adjusted logic for INPUT_PULLUP
    digitalWrite(ledPin, HIGH);  // Turn on the LED (or activate the atomizer)
    delay(activeTime);           // Keep the LED/atomizer on for the active time
    digitalWrite(ledPin, LOW);   // Turn off the LED/atomizer
    delay(cooldownTime);         // Wait for the cooldown time before rechecking motion
  } 

  delay(stabilityDelay);  // Short delay for stability
}

