
const int smokePin = A0; //Gas sensor output pin to Arduino analog A0 pin
const int alcoholPin = A1; //
const int methanePin = A2; 
const int gasPin = A3; 
const int isobutanepropanePin = A8; 
const int carbonmonoxidePin = A7;
const int hydrogenPin = A6; 
const int carbonmonoxidegasPin = A5; 
const int airqualityPin = A4; 

void setup() {

  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop() {

  int smoke = analogRead(smokePin); 
  int alcohol = analogRead(alcoholPin); 
  int methane = analogRead(methanePin); 
  int gas = analogRead(gasPin); 
  int isobutanepropane = analogRead(isobutanepropanePin); 
  int carbonmonoxide = analogRead(carbonmonoxidePin);
  int hydrogen = analogRead(hydrogenPin); 
  int carbonmonoxidegas = analogRead(carbonmonoxidegasPin); 
  int airquality = analogRead(airqualityPin); 

  /*Serial.print("Variable_1 gas:");
  Serial.print(gas);
  Serial.print(",");
  Serial.print("Variable_2 air:");
  Serial.println(airquality);*/

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

  delay(1000); //Print values every 1 sec. 
}
