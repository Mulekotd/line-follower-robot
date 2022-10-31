//sensores
const int IN_A0 = A5; //direita
const int IN_A1 = A4; //esquerda

//configuração da pinagem da ponte para começar os motores
const int M1A = 10;
const int M1B = 9;
const int M2A = 6;
const int M2B = 5;

void Frente(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 150);
  analogWrite(M2A, 150);
  analogWrite(M2B, 0);
}

void Direita(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 100);
  analogWrite(M2A, 0);
  analogWrite(M2B, 100);
}

void Esquerda(){
  analogWrite(M1A, 100);
  analogWrite(M1B, 0);
  analogWrite(M2A, 100);
  analogWrite(M2B, 0);
}

//valores 
int value_A0 = 0;
int value_A1 = 0;

void setup() {
Serial.begin(9600);
pinMode (IN_A0, INPUT);
pinMode (IN_A1, INPUT);

pinMode (M1A, OUTPUT);
pinMode (M1B, OUTPUT);
pinMode (M2A, OUTPUT);
pinMode (M2B, OUTPUT);
}

void loop() {

if (value_A0 > 34) {
  Direita();
}
else if (value_A1 > 34) {
  Esquerda();
}
else {
  Frente();
}

value_A0 = analogRead(IN_A0);
value_A1 = analogRead(IN_A1);

Serial.print(value_A0);
Serial.print("\t");
Serial.print(value_A1);
Serial.print("\t\t");
Serial.print("\n");
}
