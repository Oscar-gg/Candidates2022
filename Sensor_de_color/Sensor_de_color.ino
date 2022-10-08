const int s0 = 43;  
const int s1 = 42;  
const int s2 =46;  
const int s3 = 44;  
const int out = 45;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Primera linea de codigo");
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  // Checar si conviene bajar el frequency scaling a 20% -> Esto haría el código más rápido pero menos preciso. 20%: s0 = high, s1 = low;
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop() 
{
  int R = getRojo();
  delay(200);
  int G = getVerde();
  delay(200);
  int B = getAzul();
  delay(200);

  Serial.print("Red: ");
  Serial.println(R);
  Serial.print("Green: ");
  Serial.println(G);
  Serial.print("Blue: ");
  Serial.println(B);
  Serial.println(" ");

  


  delay(500);

/*
  Serial.print("Int R" + String(R));
  Serial.print(" -- Int V" + String(V));
  Serial.println(" -- Int A" + String(A));

  if (R > V && V > A && R > 10 && R < 16) {
    Serial.print("El color es azul claro");
  }
  else if(R > V && V > A && R >= 16 && V < 16) {
    Serial.print("El color es azul fusia");
  }
  else if( R < V && V > A && R >= 8 && V >= 16){
    Serial.print("El color es rojo");
  }
  else if(R < V && V > A && R > 10 && V <= 16){
    Serial.print("El color es morado"); 
  }
  else if(R > V && R > A && R > 10 && R <= 16){
    Serial.print("El color es verde");
  }
  else {
    Serial.print("El color no ha sido registrado");
  }
  Serial.println(" ");
  */
}

int getRojo()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  int ROJO = pulseIn(out, LOW);
  Serial.println("Valor de rojo: " + ROJO);
    
  // Modifica el color detectado a la escala RGB. Los valores 25 y 72 puede modificarse en función de qué detecta el sensor.
  // 25 lo combierte a 255 y 72 a 0.
  
  ROJO = map(ROJO, 25, 72, 255, 0);  
  return ROJO;
}

int getAzul()
{
  digitalWrite(s2, LOW);  
  digitalWrite(s3, HIGH);
  int AZUL = pulseIn(out, LOW);
  //Serial.println("Valor de azul: " + AZUL);
  AZUL = map(AZUL, 25, 70, 255, 0);  
  return AZUL;
}

int getVerde()
{
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  int VERDE = pulseIn(out, LOW);
  //Serial.println("Valor de verde: " + VERDE);
  VERDE = map(VERDE, 30, 90, 255, 0); 
  return VERDE;
}
