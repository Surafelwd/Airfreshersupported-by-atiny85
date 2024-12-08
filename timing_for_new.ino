int motionPin = PB0;  // Motion sensor input pin
int ledPin = PB1;      // LED output pin

void setup() {
  pinMode(motionPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  int motionValue = digitalRead(motionPin);

  

  if (motionValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    delay(5000);                  // Wait for 1 second
                                 // Wait for 1 second
    digitalWrite(ledPin, LOW);
    delay(10000);
    
    //delay (5000);//wait for 5 second before start sensing aother motion
  } 

  delay(100);  // Delay for stability
}