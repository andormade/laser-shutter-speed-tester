// You may override this if you connected  the photoresistor 
// to a different analog input pin.
const int SENSOR_PIN = A7;
// You may override this if you connected the laser 
// to a different digital output pin.
const int LASER_PIN = 2;

int sensorValue = 0;
int lowValue = 0;
bool isHigh = false;
unsigned long startTime = 0;
unsigned long endTime = 0;
unsigned long measurement = 0;

void setup() {
    lowValue = analogRead(SENSOR_PIN);
    pinMode(LASER_PIN, OUTPUT);
    digitalWrite(LASER_PIN, HIGH);
    Serial.begin(9600);
    Serial.println("Measurements are in milliseconds.");
}

void loop() {
    sensorValue = analogRead(SENSOR_PIN);

    if (!isHigh && sensorValue - 200 > lowValue) {
        startTime = millis();
        isHigh = true;
    }
    else if (isHigh && sensorValue - 200 < lowValue) {
        isHigh = false;
        endTime = millis();
        measurement = endTime - startTime;
        Serial.println(measurement);
    }
}