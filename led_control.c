//pins
const int LED_PIN = 13;      
const int BUTTON_PIN = 2;    

void setup() {
  // led for O/P
  pinMode(LED_PIN, OUTPUT);
  
  // button for I/P
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
}

void loop() {
  // Reading btn state
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);  // LED ON when button is pressed
  } else {
    digitalWrite(LED_PIN, LOW);   // LED OFF when button is not pressed
  }
}
