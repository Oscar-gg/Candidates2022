// Esqueleto de lógica del robot.

char zone = 'u';
char color = 'u';

void setup() {
  Serial.begin(9600);
  setPins();
  attachObjects();
  sensorData();
  setZone();
}

void loop() {
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
  }
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

// Brute-force approach functions (in case sensors not working as intended):


// Discarded code:
