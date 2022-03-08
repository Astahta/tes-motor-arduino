#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial module_bluetooth(0, 1);

AF_DCMotor motor(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
char data = 0;

int trig = 3;           // membuat varibel trig yang di set ke-pin 3
int echo = 2;           // membuat variabel echo yang di set ke-pin 2
long durasi, jarak;     // membuat variabel durasi dan jarak

void setup ()
{
  motor.setSpeed(150);
  motor.run(RELEASE);

  motor2.setSpeed(150);
  motor2.run(RELEASE);

  motor3.setSpeed(150);
  motor3.run(RELEASE);

  motor4.setSpeed(150);
  motor4.run(RELEASE);

  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  Serial.begin(9600);
  
}

void loop ()
{
//  motor.run(BACKWARD);
//  motor2.run(BACKWARD);
//  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);
//  motor.run(FORWARD);
//  motor2.run(FORWARD);
//  motor3.run(FORWARD);
//  motor4.run(FORWARD);
  if(Serial.available() > 0)  
  {
    data = Serial.read();Serial.print(data);    //Pembacaan dan ditampilkan data yang masuk   
    Serial.print("\n"); 
    //Data yang masuk      
    if(data == '1'){
      moveLeft();
//    digitalWrite(13, HIGH);//diberikan waktu tunda 1 detik
    } else if(data == '2'){
      moveRight();
    }
//    else if(data == '0')      
//    digitalWrite(13, LOW);  
  } 

  // program dibawah ini agar trigger memancarakan suara ultrasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);

  durasi = pulseIn(echo, HIGH); // menerima suara ultrasonic
  jarak = (durasi / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
  Serial.println(jarak);        // menampilkan jarak pada Serial Monitor
    
//  motor.run(FORWARD);
//  motor2.run(FORWARD);
//  motor3.run(FORWARD);
//  motor4.run(FORWARD);
}

void moveLeft()
{
  motor.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
//  delay(5000);
//
//  motor.run(RELEASE);
//  motor2.run(RELEASE);
//  motor3.run(RELEASE);
//  motor4.run(RELEASE);
}

void moveRight()
{
  motor.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
//  delay(5000);
//
//  motor.run(RELEASE);
//  motor2.run(RELEASE);
//  motor3.run(RELEASE);
//  motor4.run(RELEASE);
}
