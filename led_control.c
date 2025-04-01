// Define pin numbers
const int LED_PIN = 13;      // Pin connected to the LED
const int BUTTON_PIN = 2;    // Pin connected to the button

void setup() {
  // Set up the LED pin as an OUTPUT
  pinMode(LED_PIN, OUTPUT);
  
  // Set up the button pin as an INPUT
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Using internal pull-up resistor
}

void loop() {
  // Read the button state (LOW when pressed)
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) {
    digitalWrite(LED_PIN, HIGH);  // Turn LED ON when button is pressed
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn LED OFF when button is not pressed
  }
}
