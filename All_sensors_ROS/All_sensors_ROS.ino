#include <ros.h>
#include <std_msgs/String.h>
#include <stdio.h>
#include <vector_sensors/vector_id.h> //mi mensaje personalizado
#include <vector_sensors/vector_id_complete.h> //mensaje personalizado como vector
#include <vector_sensors/vector_id_value.h>


const int smokePin = A0; //Gas sensor output pin to Arduino analog A0 pin
const int alcoholPin = A1; //
const int methanePin = A2; 
const int gasPin = A3; 
const int isobutanepropanePin = A8; 
const int carbonmonoxidePin = A7;
const int hydrogenPin = A6; 
const int carbonmonoxidegasPin = A5; 
const int airqualityPin = A4; 

uint8_t num_portss[5] = {1, 2, 3, 4, 5};

ros::NodeHandle nh; 

std_msgs::String str_msg; 
ros::Publisher chatter("chatter", &str_msg); 

vector_sensors::vector_id_value msg; 
ros::Publisher pub("vector_id_topic", &msg); 

char hello[13] = "hello world"; 

void setup() {
  Serial.begin(57600); //Initialize serial port - 9600 bps
  nh.initNode(); 
  nh.advertise(chatter); 
  nh.advertise(pub); 
}

void loop() {

  //-------SENSORS----------

  int smoke = analogRead(smokePin); 
  int alcohol = analogRead(alcoholPin); 
  int methane = analogRead(methanePin); 
  int gas = analogRead(gasPin); 
  int isobutanepropane = analogRead(isobutanepropanePin); 
  int carbonmonoxide = analogRead(carbonmonoxidePin);
  int hydrogen = analogRead(hydrogenPin); 
  int carbonmonoxidegas = analogRead(carbonmonoxidegasPin); 
  int airquality = analogRead(airqualityPin); 

  Serial.print("Smoke:");
  Serial.print(smoke);
  Serial.print(",");

  Serial.print("Alcohol:");
  Serial.print(alcohol);
  Serial.print(",");

  Serial.print("Methane:");
  Serial.print(methane);
  Serial.print(",");

  Serial.print("Gas:");
  Serial.print(gas);
  Serial.print(",");

  Serial.print("Isobutanepropane:");
  Serial.print(isobutanepropane);
  Serial.print(",");

  Serial.print("Carbonmonoxide:");
  Serial.print(carbonmonoxide);
  Serial.print(",");

  Serial.print("Hydrogen:");
  Serial.print(hydrogen);
  Serial.print(",");

  Serial.print("Carbonmonoxidegas:");
  Serial.print(carbonmonoxidegas);
  Serial.print(",");

  Serial.print("Airquality:");
  Serial.println(airquality);

  /*char** names [9] = {"Smoke", "Alcohol", "Methane", "Gas", "Isobutanepropane", "Carbonmonoxide", "Hydrogen", "Carbonmonoxidegas", "Air quality"};
  char** names;  // Declare the char** variable
  names = new char*[9];
  names[0] = new char[10];  
  strcpy(names[0], "Smoke"); 

  names[1] = new char[10]; 
  strcpy(names[1], "Alcohol"); 

  names[2] = new char[10];  
  strcpy(names[2], "Methane"); 

  names[3] = new char[10];
  strcpy(names[2], "Gas"); 

  names[4] = new char[20]; 
  strcpy(names[2], "Isobutanepropane"); 

  names[5] = new char[20]; 
  strcpy(names[2], "Carbonmonoxide");

  names[6] = new char[20];
  strcpy(names[2], "Hydrogen"); 

  names[7] = new char[20]; 
  strcpy(names[2], "Carbonmonoxide gas");  

  names[8] = new char[20];  
  strcpy(names[2], "Air quality");*/

  uint8_t values[9] = {smoke, alcohol, methane, gas, isobutanepropane, carbonmonoxide, hydrogen, carbonmonoxidegas, airquality};
  uint8_t pins[9] = {0, 1, 2, 3, 8, 7, 6, 5, 4}; 

  //---------ROS-----------
  str_msg.data = hello; 
  chatter.publish(&str_msg); 


  //msg.num_ports[0] = num_portss[0];
  //msg.num_ports[1] = num_portss[1]; 
  //msg.sensor_name = sensors;
  //msg.sensor_name_length = 9; 
  //msg.sensors_names = names; 
  //msg.sensors_names_length = 9; 
  msg.sensors_values = values; 
  msg.sensors_values_length = 9;  
  msg.sensors_pins = pins; 
  msg.sensors_pins_length = 9; 


  //msg.sensor_id = "SENSOR 1 - MQ2: "; 
  //msg.port_number = 1; 
  

  pub.publish(&msg); 

  nh.spinOnce(); 

  delay(1000); //Print values every 1 sec. 
}
