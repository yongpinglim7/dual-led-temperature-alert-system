#include <DHT.h>

#define DHTPIN 2        
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

// Define pins for the two LEDs
#define LED_WARNING 7  // Warning LED (Turns ON at 32°C)
#define LED_ALERT 8    // Alert LED (Turns ON at 34°C)

// Define temperature thresholds
const float ALERT_TEMP = 34.0;
const float WARNING_TEMP = 32.0;

void setup() {
  Serial.begin(9600);
  Serial.println("Dual-LED Temperature System Starting...");
  dht.begin();
  
  pinMode(LED_WARNING, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);
  
  // Ensure both LEDs are OFF on startup
  digitalWrite(LED_WARNING, LOW);
  digitalWrite(LED_ALERT, LOW);
}

void loop() {
  // Wait 2 seconds between measurements (DHT11 requirement)
  delay(2000); 

  float tempC = dht.readTemperature(); 

  // Error handling if the sensor fails to read
  if (isnan(tempC)) {
    Serial.println("Error: Sensor disconnected or reading failed!");
    return;
  }

  // Output current temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC, 1); 
  Serial.println(" *C");

  // --- Dual-LED Trigger Logic ---
  if (tempC >= ALERT_TEMP) {
    // High Temperature Alert (>= 34°C): Both LEDs ON
    digitalWrite(LED_WARNING, HIGH);
    digitalWrite(LED_ALERT, HIGH);
    Serial.println("Status: ALERT! (Both LEDs ON)");
  } 
  else if (tempC >= WARNING_TEMP) {
    // Medium Temperature Warning (>= 32°C): Only Warning LED ON
    digitalWrite(LED_WARNING, HIGH);
    digitalWrite(LED_ALERT, LOW);
    Serial.println("Status: WARNING! (Warning LED ON, Alert LED OFF)");
  } 
  else {
    // Normal Temperature (< 32°C): Both LEDs OFF
    digitalWrite(LED_WARNING, LOW);
    digitalWrite(LED_ALERT, LOW);
    Serial.println("Status: Normal (All OFF)");
  }
  
  Serial.println("-------------------------");
}
