// Skeleton of robot's logic Candidates 2022

// Libraries
#include <Servo.h>


char zone = 'u';
char color = 'u';

// Color sensor variables.  
const int s0 = 43;  
const int s1 = 42;  
const int s2 =46;  
const int s3 = 44;  
const int out = 45;

// Servo variables.
Servo rightServo;
Servo leftServo;

const int rightServoPIN = 5;
int rightServoClosePosition = 0;
int rightServoOpenPosition = 100;
boolean isRightOpen = false;

const int leftServoPIN = 10;
int leftServoClosePosition = 0;
int leftServoOpenPosition = 100;
boolean isLeftOpen = false;


// Ultrasonic variables.
double distancia;
double tiempo;

#define trigger1 3
#define echo1 2

#define triggerLeft 4
#define echoLeft 5

#define triggerRight 13
#define echoRight 12

// H bridge pins
#define enA 6
#define in1 52
#define in2 53

#define enB 7
#define in3 50
#define in4 51

double movementTime = 1000;
double delayLeftTurn = 200;


void setup() {
  Serial.println("Nuevo codigo");
  Serial.begin(9600);
  setPins();
  attachObjects();
  sensorData();
  // setZone();
}

void loop() {
 //moveForward();
 turnLeft();
 delay(1000);

 int dist = getDistance1();
 Serial.print("Distancia de enfrente: ");
 Serial.print(dist);
 
 dist = getDistanceLeft();
 Serial.print("Distancia de Izquierda: ");
 Serial.print(dist);

 dist = getDistanceRight();
 Serial.print("Distancia de Derecha: ");
 Serial.print(dist);
 

 
 //turnLeft();

  //analogWrite(enA, 200);
  //analogWrite(enB, 200);
  //digitalWrite(in1, HIGH);
  //digitalWrite(in2, LOW);
  //digitalWrite(in3, HIGH);
  //digitalWrite(in4, LOW);
  
  
  /*
  sensorData();
  
  switch (zone){
    case 'A':
      zoneA();
      break;
    case 'B':
      zoneB();
      break;
    case 'C':
      zoneC();
      break;
    case 'E':
      zoneE();
      break;
    default:
      Serial.println("ERROR: no zone detected");
      
  }*/
}

// Determines the next zone that the robot must finish. Only called on setup. Handles Lack of Progress. Causes infinite loop if no meaningful color is detected.
// Color legend: each letter corresponds to the initial letter of the color, in English. Exception: case 'E'; 'P' (Pink) is already used (Purple).
void setZone(){
  switch(color){
    case 'Y':
      zone = 'A';
      break;
    case 'G':
    case 'B':
    case 'R':
      zone = 'B';
      break;
    case 'P':
      zone = 'C';
      break;
     case 'E': 
      zone = 'E';
      break;
     default:
      sensorData();
      setZone();
  }
    
}

// Bind i/o pins.
void setPins(){
  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(triggerLeft, OUTPUT);
  pinMode(echoLeft, INPUT);
  
  pinMode(triggerRight, OUTPUT);
  pinMode(echoRight, INPUT);
  
  // Puente H y movimiento
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  // Checar si conviene bajar el frequency scaling a 20% -> Esto haría el código más rápido pero menos preciso. 20%: s0 = high, s1 = low;
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  
}

// set/attach objects such as motors.
void attachObjects(){
  rightServo.attach(rightServoPIN);
  leftServo.attach(leftServoPIN);

  rightServo.write(rightServoClosePosition);
  leftServo.write(leftServoClosePosition);
  
  
}




// Updates data recieved by all sensors.
void sensorData(){
  setColor();
  
}

void setColor(){
  int R = getRojo();
  delay(200);
  int G = getVerde();
  delay(200);
  int B = getAzul();
  delay(200);

  // Conditional ifs to establish color.
  if (false){
    
  } else {
    color = 'u';
  }
    
}

// Function to make sure the robot advances in staight line. Pending: determine if magnetometer or ultrasonic sensor will be used.
void calibrate(){
  
}

void zoneA(){
  
}

void zoneB(){
  
}

void zoneC(){
  
}

void zoneE(){
  
}

// Ultrasónico 1
int getDistance1(){
  digitalWrite(trigger1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(echo1, HIGH); 
  distancia = int(0.017 * tiempo); // Distancia en centimetros
  Serial.println(distancia);
  return distancia;
}

// Ultrasónico 2
int getDistanceLeft(){
  digitalWrite(triggerLeft, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerLeft, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(echoLeft, HIGH); 
  distancia = int(0.017 * tiempo); // Distancia en centimetros
  Serial.println(distancia);
  return distancia;
}

int getDistanceRight(){
  digitalWrite(triggerRight, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerRight, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(echoRight, HIGH); 
  distancia = int(0.017 * tiempo); // Distancia en centimetros
  Serial.println(distancia);
  return distancia;
}

void moveForward(){
    wheelSpeed();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(movementTime);
    stopWheels();
}

void moveBackwards(){
    wheelSpeed();
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(movementTime);
    stopWheels();
}

// Pueden variar dependiendo del conectado.
void turnLeft(){
    wheelSpeed();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(movementTime);
    stopWheels();
}

void turnRight(){
    wheelSpeed();
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(movementTime);
    stopWheels();
}

void stopWheels(){
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void changeSpeed(int newSpeed){
  analogWrite(enA, newSpeed);
  analogWrite(enB, newSpeed);
}

void wheelSpeed(){
  changeSpeed(200);
}

int getRojo(){
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  int ROJO = pulseIn(out, LOW);
  //Serial.println("Valor de rojo: " + ROJO);
    
  // Modifica el color detectado a la escala RGB. Los valores 25 y 72 puede modificarse en función de qué detecta el sensor.
  // 25 lo combierte a 255 y 72 a 0.
  
  ROJO = map(ROJO, 25, 72, 255, 0);  
  return ROJO;
}

int getAzul(){
  digitalWrite(s2, LOW);  
  digitalWrite(s3, HIGH);
  int AZUL = pulseIn(out, LOW);
  //Serial.println("Valor de azul: " + AZUL);
  AZUL = map(AZUL, 25, 70, 255, 0);  
  return AZUL;
}

int getVerde(){
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  int VERDE = pulseIn(out, LOW);
  //Serial.println("Valor de verde: " + VERDE);
  VERDE = map(VERDE, 30, 90, 255, 0); 
  return VERDE;
}



// Brute-force approach functions (in case sensors not working as intended):


// Discarded code:
