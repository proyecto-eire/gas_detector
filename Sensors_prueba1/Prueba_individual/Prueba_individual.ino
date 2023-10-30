const int SENSOR_PIN = A0; 

const int GREEN_LED = 49; 
const int YELLOW_LED = 51; 
const int RED_LED = 53; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(GREEN_LED, OUTPUT); 
  pinMode(YELLOW_LED, OUTPUT); 
  pinMode(RED_LED, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(SENSOR_PIN); 

  Serial.print("Sensor: "); 
  Serial.println(sensor);

  if(sensor < 50){
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(YELLOW_LED, LOW); 
    digitalWrite(RED_LED, LOW); 
  }
  else if ((sensor > 50) && (sensor < 150)){
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(YELLOW_LED, HIGH); 
    digitalWrite(RED_LED, LOW); 
  }
  else if ((sensor > 150) && (sensor < 250)){
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(YELLOW_LED, HIGH); 
    digitalWrite(RED_LED, LOW); 
  }
  else if ((sensor > 350) && (sensor < 450)){
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(YELLOW_LED, HIGH); 
    digitalWrite(RED_LED, HIGH); 
  }
  else if ((sensor > 450) && (sensor < 550)){
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(YELLOW_LED, LOW); 
    digitalWrite(RED_LED, HIGH); 
  }
  

}
