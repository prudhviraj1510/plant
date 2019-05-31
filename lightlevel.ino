int photoResistor = A5;
int photoResistorPower = A0;
int LeD = D6; 

int ledToggle(String command);

// The next variable defines how often to check the photoresistor's light level
int photoResistorCheckTime = 10000;  // 10000 milliseconds is 10 seconds
// and we also record the time we report the photoresistor status with this
int lastPhotoResistorReport;
char lightValue[4];   // this is a string where we will actual light value read from the photoresistor

void setup() {
  // Tell Photon if our pins are inputs or outputs
  pinMode(photoResistor, INPUT);
  pinMode(photoResistorPower, OUTPUT);

  // Turn on power to the photoresistor
  digitalWrite(photoResistorPower, HIGH);
  lastPhotoResistorReport = millis();
  Serial.begin();
  pinMode(LeD, OUTPUT);
  // register the cloud function
  Particle.function("led", ledToggle);
  
  digitalWrite(LeD, LOW);
}

void loop() {
  if ((millis() - lastPhotoResistorReport) >= photoResistorCheckTime) {
      lastPhotoResistorReport = millis();   
      int lightLevel = analogRead(photoResistor);  
      if (lightLevel < 500) Particle.publish("lightLevel", "dark", PRIVATE);
      if (lightLevel >= 500 && lightLevel < 900) Particle.publish("lightLevel", "medium", PRIVATE);
      if (lightLevel >= 900) Particle.publish("lightLevel", "bright", PRIVATE);
      
      sprintf(lightValue,"%d", lightLevel);   
      Particle.publish("sensorValue", lightValue, PRIVATE);
  }
}  
int ledToggle(String command)
{
 if (command == "onred")
    {
        digitalWrite(LeD, HIGH);
        return 1;
    }
    else if (command == "offred")
    {
        digitalWrite(LeD, LOW);
        return 0;
    }
    
    else
    {
        return -1;
    }
}