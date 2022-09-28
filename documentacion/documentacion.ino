// Documentación de componentes individuales. Registro de cómo se usan

/*

Lista de componentes programables del robot, con tipo de pin necesario:

Puente H L298N (1): 6 pines de output(4 digitales y 2 pwm). Los pwm controlan la velocidad de la llanta. los 4 de output la dirección de las llantas (2 para cada llanta)

Sensor ultrasónico HC-SR04 (3):

Sensor de color TCS230 (1):

Sensor infrarrojo IC-20271 (1):

Servomotor SG90 (2):

Motores DC Amarillos (4):

acelerometro (1):

pines

*/


/* 
Cómo usar los componentes:

Puente H: 

Se conecta la fuente al espacio de +12V y tierra con tierra. Si hay jumper puesto, no se necesita conectar nada en el de 5v.
Si no hay jumper, se necesita conectar 5v al espacio de 5v para dar energía a la parte lógica del controlador.
Si hay jumper y se conecta el puente h a +12v y +5v hay corto.

Los motores se conectan en los apartados de las esquinas. 

in1 controla al out1, in2 al out2 y asi hasta in4 y out4


Para que avanze: velocidad != 0 && (in1 y in2 tiene que ser diferentes; uno HIGH y otro LOW)

Para que frene: todas las in# se ponen en low, y la velocidad de los enA y enB en 0.



 */

void setup() {
  // Puente H y movimiento
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // Puente H y movimiento 
  avanzar();
  retroceder();
  girarIzquierda();
  girarDerecha();
  cambiarVelocidad(velocidad);

}

// Puente H y movimiento

void avanzar(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(tiempo);
    pararLlantas();
}

void retrocederLlantas(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(tiempo);
    pararLlantas();
}

// Pueden variar dependiendo del conectado.
void girarIzquierda(){
    velocidadLlantas();
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(tiempoAvanzar);
    pararLlantas();
}

void girarDerecha(){
    velocidadLlantas();
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(tiempoAvanzar);
    pararLlantas();
}

void pararLlantas(){
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void cambiarVelocidad(int velocidad){
  analogWrite(enA, velocidad);
  analogWrite(enB, velocidad);
}
