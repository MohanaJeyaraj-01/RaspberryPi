#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <DFRobotDFPlayerMini.h>

// Define Pins
#define SOIL_MOISTURE_PIN 34
#define LDR_PIN 35
#define DHTPIN 4
#define DHTTYPE DHT11
#define BUTTON_PIN 18

// Initialize DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize DFPlayer
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(115200);              // Start Serial Monitor
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Start Serial2 for DFPlayer Mini (RX=16, TX=17)

  dht.begin();                       // Start DHT sensor

  pinMode(SOIL_MOISTURE_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button with internal pull-up

  if (!myDFPlayer.begin(Serial2)) {   // Check if DFPlayer is connected
    Serial.println("DFPlayer Mini not detected!");
    while(true);
  }
  
  myDFPlayer.volume(20);  // Set volume (0-30)

  Serial.println("Talking Plant Started!");
}

void loop() {
  int soilMoisture = digitalRead(SOIL_MOISTURE_PIN);
  int ldrValue = analogRead(LDR_PIN);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  bool buttonPressed = (digitalRead(BUTTON_PIN) == LOW);

  Serial.print("Soil: "); Serial.println(soilMoisture);
  Serial.print("Light: "); Serial.println(ldrValue);
  Serial.print("Temp: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.println("----------------------");

  if (soilMoisture == HIGH) {
    myDFPlayer.play(1);  // "I need water!"
    delay(3000);
  }
  else {
    myDFPlayer.play(2);  // "I'm happy and watered!"
    delay(3000);
  }

  if (ldrValue < 500) {
    myDFPlayer.play(3);  // "It's too dark, I need sunlight!"
    delay(3000);
  }

  if (temperature > 35) {
    myDFPlayer.play(4);  // "It's too hot!"
    delay(3000);
  }

  if (humidity < 30) {
    myDFPlayer.play(5);  // "It's too dry!"
    delay(3000);
  }

  if (buttonPressed) {
    myDFPlayer.play(6);  // "Hello there! Thanks for checking me!"
    delay(3000);
  }

  delay(2000); // Small delay before next reading
}
