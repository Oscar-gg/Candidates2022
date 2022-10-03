// Esqueleto de lógica del robot.

char zone = 'u';
char color = 'u';

// Ultrasonic variables.
double distancia;
double tiempo;

int echo1 = 12;
int trigger1 = 11;

int echo2 = 9;
int trigger2 = 8;

// H bridge pins
#define enA 8
#define in1 7
#define in2 6

#define enB 3
#define in3 5
#define in4 4

double movementTime = 1000;

/*

Ultrasónico 1:
  echo: 12
  trigger: 11
  
Ultrasónico 2:
  echo: 9
  trigger: 8

Ultrasónico 3:


Infrarrojo: 13

Servomotor: 2
  
*/

void setup() {
  Serial.begin(9600);
  setPins();
  attachObjects();
  sensorData();
  // setZone();
}

void loop() {
  int d = getDistance1();
  Serial.println("Distancia ultrasónico 1: " + d);

  d = getDistance2();
  Serial.println("Distancia ultrasónico 2: " + d);
  
  moveForward();
  delay(250);

  
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

  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
  
  // Puente H y movimiento
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

// set/attach objects such as motors.
void attachObjects(){
  
}

// Updates data recieved by all sensors.
void sensorData(){
  
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
int getDistance2(){
  digitalWrite(trigger2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(echo2, HIGH); 
  distancia = int(0.017 * tiempo); // Distancia en centimetros
  Serial.println(distancia);
  return distancia;
}

void moveForward(){
    wheelSpeed();
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(movementTime);
    stopWheels();
}

void moveBackwards(){
    wheelSpeed();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
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
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
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

// Brute-force approach functions (in case sensors not working as intended):


// Discarded code:
