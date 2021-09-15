#include <SoftwareSerial.h>

#define trigPin 11
#define echoPin 12

long duration;
int distance;
//Create software serial object to communicate with A6
SoftwareSerial mySerial(9,8); //A6 Tx & Rx is connected to Arduino #7 & #5
// int led_red = 7;
// int led_green = 8;
// int buzzer = 5;
void setup()
{
  // pinMode(led_red,OUTPUT);
  // pinMode(led_green,OUTPUT);
  // pinMode(buzzer,OUTPUT);

  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);
  // digitalWrite(led_red,LOW);
  // digitalWrite(led_green,LOW);
  // digitalWrite(buzzer,LOW);


  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and A6
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(2000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop()
{

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();


  // digitalWrite(trigPin, LOW);
  // delayMicroseconds(5);
  // // Trigger the sensor by setting the trigPin high for 10 microseconds:
  // digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(trigPin, LOW);
  // // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  // duration = pulseIn(echoPin, HIGH);
  // // Calculate the distance:
  // distance = duration * 0.034 / 2;
  // // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  // Serial.print("Distance = ");
  // Serial.print(distance);
  // Serial.println(" cm");
  // delay(50);

  // if(distance<=20){
  //   digitalWrite(led_red,HIGH);
  //   digitalWrite(led_green,LOW);
  //   digitalWrite(buzzer,HIGH);
  //   mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  // updateSerial();
  // mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  // updateSerial();
  // mySerial.println("AT+CMGS=\"XXXXXXXX\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  // updateSerial();
  // mySerial.print("One person detected"); //text content
  // updateSerial();
  // mySerial.write(26);
  // }
  // delay(5000);
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
