// Constantes para rangos de sensores
const int TEMP_MIN = 200;  // 20.0°C
const int TEMP_MAX = 450;  // 45.0°C
const int PRES_MIN = 75;   // 75 kPa
const int PRES_MAX = 90;   // 90 kPa
const int LED_PIN = 13;    // LED incorporado

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    while (!Serial) {
        ; // Esperar por conexión serial
    }
    digitalWrite(LED_PIN, HIGH);  // Indicar inicio
}

void loop() {
    digitalWrite(LED_PIN, HIGH);  // Indicar transmisión
    
    // Simular sensor de temperatura
    float temp = random(TEMP_MIN, TEMP_MAX) / 10.0;
    Serial.print("T:");
    Serial.println(temp, 1);  // Un decimal
    delay(500);

    // Simular sensor de presión
    int pres = random(PRES_MIN, PRES_MAX);
    Serial.print("P:");
    Serial.println(pres);
    delay(500);
    
    digitalWrite(LED_PIN, LOW);  // Indicar fin de transmisión
    delay(1000);  // Esperar antes del siguiente ciclo
}
