#define trigPin 2
#define echoPin 3

const int numReadings = 100; 
long durations[numReadings]; 
int distances[numReadings]; 

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (int i = 0; i < numReadings; i++) {
    // Trigger ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure echo pulse duration
    long duration = pulseIn(echoPin, HIGH);

    // Calculate distance (cm)
    distances[i] = duration * 0.034 / 2;

    // Print distance to serial monitor
    Serial.print("Distance ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(distances[i]);

    // Delay between measurements
    delay(100);
  }
}
