#define trigPin 2
#define echoPin 3

const int numReadings = 100; // Number of distance measurements to take
long durations[numReadings]; // Array to store echo pulse durations
int distances[numReadings]; // Array to store calculated distances

void setup() {
  Serial.begin(9600); // Initialize serial communication
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
