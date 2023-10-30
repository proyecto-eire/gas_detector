#include <math.h>
#define GREEN_LED 49
#define YELLOW_LED 51 
#define RED_LED 53

void setup() {
  Serial.begin(9600);
    pinMode(GREEN_LED, OUTPUT); 
  pinMode(YELLOW_LED, OUTPUT); 
  pinMode(RED_LED, OUTPUT); 
}
 
void loop() {
  
  float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  double ratio; // Get ratio RS_GAS/RS_air
  int sensorValue = analogRead(A5);
  sensor_volt=(float)sensorValue/1024*5.0;
  RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
  
  /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
  ratio = RS_gas/2.39;  // ratio = RS/R0 
  /*-----------------------------------------------------------------------*/
  
  Serial.print("sensor_volt = ");
  Serial.println(sensor_volt);
  Serial.print("RS_ratio = ");
  Serial.println(RS_gas);
  Serial.print("Rs/R0 = ");
  Serial.println(ratio);

  Serial.print("Variable_1 ppm: "); 
  float ppm = 1266.0*(pow(ratio,2.0))-4022.0*ratio+3380.0; 
  Serial.println(1266.0*(pow(ratio,2.0))-4022.0*ratio+3380.0); 

  Serial.println("\n\n");

  delay(1000);

  if(ppm < 200){
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(YELLOW_LED, LOW); 
    digitalWrite(RED_LED, LOW); 
  }
  else if(ppm > 200 && ppm < 300){
    digitalWrite(GREEN_LED, HIGH); 
    digitalWrite(YELLOW_LED, HIGH); 
    digitalWrite(RED_LED, LOW); 
  }
  else if(ppm > 300 && ppm < 400){
    digitalWrite(GREEN_LED, LOW); 
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);  
  }
  else if(ppm > 400 && ppm <500){
    digitalWrite(RED_LED, LOW); 
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
  }
  else if(ppm > 500){
    digitalWrite(RED_LED, LOW); 
    digitalWrite(YELLOW_LED, LOW); 
    digitalWrite(RED_LED, HIGH);
  }
  

}