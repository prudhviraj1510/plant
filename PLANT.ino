
int sensorvalue = 0;
int soundSensor=2;
int LED=4;
int TAP=5;
boolean LEDStatus=false;

void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(TAP, OUTPUT);
 Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(A0);
  // print out the value you read:
  if (sensorValue <= 400)
  {
    Serial.print("-MOISTURE LEVEL = ");
    Serial.print(sensorValue);
    Serial.println(", I AM THIRSTY");
    digitalWrite(TAP,HIGH);
  }
  else
  {
    Serial.print("-MOISTURE LEVEL = ");
    Serial.print(sensorValue);
    Serial.println(", I AM HAPPY");
    digitalWrite(TAP,LOW);
    delay(5500);
  }
  //delay(5500); 
  int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,LOW);
    }
  }
 } 
