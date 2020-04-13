int soilSensor = 0;
int redLed = D2;
int greenLed = D3;
int led = D7;
void setup() {
    Serial.begin(9600);
    Particle.variable("soilSensor", &soilSensor, INT);
    pinMode(A4, INPUT);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
}
void loop() {
    soilSensor = analogRead(A4);
    if(soilSensor > 2000) {
        digitalWrite(redLed, HIGH);
        delay(1000);
        digitalWrite(redLed, LOW);
    } else {
        digitalWrite(greenLed, HIGH);
        delay(1000);
        digitalWrite(greenLed, LOW);
    }
        delay(30000);
    
    String soilSensor = String(random(0, 2000));
    Particle.publish("soilSensor", soilSensor, PRIVATE);
    

}
