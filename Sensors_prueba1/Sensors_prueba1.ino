

const int gasPin = A0; //Gas sensor output pin to Arduino analog A0 pin
const int airPin = A1; //

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialize serial port - 9600 bps

}

void loop() {
  int gas = analogRead(gasPin); 
  int air = analogRead(airPin); 
  // put your main code here, to run repeatedly:
  Serial.print("Variable_1 gas:");
  Serial.print(gas);
  Serial.print(",");
  Serial.print("Variable_2 air:");
  Serial.println(air);  
  delay(1000); //Print values every 1 sec. 
}

