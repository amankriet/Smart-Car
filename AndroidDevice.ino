int izqA = 7;
int izqB = 6;
int derA = 5;
int derB = 4;
int vel = 200; // Velocidad de los motores (0-255)
int estado = 'g'; // inicia detenido

void setup() {
Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
pinMode(derA, OUTPUT); 
pinMode(derB, OUTPUT);
pinMode(izqA, OUTPUT);
pinMode(izqB, OUTPUT);
}

void loop() {

  
if(Serial.available()>0){ // lee el bluetooth y almacena en estado
estado = Serial.read();
}
if(estado=='a'){ //Forward
  Serial.println(estado);
digitalWrite(derB, 0);
digitalWrite(izqB, 0);
digitalWrite(derA, vel);
digitalWrite(izqA, vel);
}
if(estado=='d'){ // Right
  Serial.println(estado);
digitalWrite(derB, vel);
digitalWrite(izqB, 0);
digitalWrite(derA, 0);
digitalWrite(izqA, vel);
}
if(estado=='c'){ // Stop
  Serial.println(estado);
digitalWrite(derB, 0);
digitalWrite(izqB, 0);
digitalWrite(derA, 0);
digitalWrite(izqA, 0);
}
if(estado=='b'){ // left
  Serial.println(estado);
digitalWrite(derB, 0);
digitalWrite(izqB, vel);
digitalWrite(izqA, 0);
digitalWrite(derA, vel);
}
if(estado=='e'){ // Reverse
  Serial.println(estado);
digitalWrite(derA, 0);
digitalWrite(izqA, 0);
digitalWrite(derB, vel); 
digitalWrite(izqB, vel);
}
if(estado=='f'){ // Boton ON se mueve sensando distancia
digitalWrite(izqB, vel);
digitalWrite(izqA, vel);
digitalWrite(derA, vel);
digitalWrite(derB, vel);

}
if(estado=='g'){ // Boton OFF, deteine los motores no hace nada
digitalWrite(izqB, 0);
digitalWrite(izqB, 0);
digitalWrite(derB, 0);
digitalWrite(derB, 0);
}


}
























