/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  Serial.begin(57600); 
  nh.initNode();
  nh.advertise(chatter);
  pinMode(13, OUTPUT); 
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  digitalWrite(13, HIGH); 

  delay(1000);
  digitalWrite(13,LOW); 
  delay(100); 
}
