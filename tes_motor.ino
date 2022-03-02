#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor motor(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup ()
{
  motor.setSpeed(200);
  motor.run(RELEASE);

  motor2.setSpeed(200);
  motor2.run(RELEASE);

  motor3.setSpeed(200);
  motor3.run(RELEASE);

  motor4.setSpeed(200);
  motor4.run(RELEASE);
}

void loop ()
{
  motor.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
