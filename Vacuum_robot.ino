// Connect TR and TX pins to 0 and 1
// Connect ENA and ENB pins to pwm
// Ntoice youe relay is PNP or NPN

#include "SRF05.h"

#define relay 2
#define ENA 3
#define ENB 4
#define IN1 5
#define IN2 6
#define IN3 7
#define IN4 8
#define trigger 9
#define echo 10

//----------VARIABELS
unsigned int distance = 0;
char blth;
SRF05 SRF(trigger, echo);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SRF.setCorrectionFactor(1.035);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(relay, OUTPUT);

  if (Serial.available() > 0)
    Serial.print("\tBluetooth Connected Seccessfully.\a");
}


void loop() {
  // put your main code here, to run repeatedly:
  blth = Serial.read();
  
  distance = SRF.getCentimeter();
  if(distance <= 5) stop();

  switch (blth) {

    case 'f': forward();
    case 'b': backward();
    case 'r': right();
    case 'l': left();
    case 'o': vacuume();
  }
}

//----------FUNCTIONS

void forward() {

  Serial.println("Going forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}


void backward() {

  Serial.println("Going backward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}


void right() {

  Serial.println("Turning right");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}


void left() {

  Serial.println("Turning left");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void stop() {

  Serial.println("Turning left");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void vacuume() {
  Serial.println("Motor is on");
  digitalWrite(relay, HIGH);
}
