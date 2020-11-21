/*
* Autor: Armas Paul
* Materia: Sistemas Embebidos
* Deber 2: Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99
*/

const int A = 8; //decodificador
const int B = 9; //decodificador
const int C = 10; //decodificador
const int D = 11; //decodificador
const int btn = 7;
const int unidades = 12;
const int decenas = 13;
int cont;
int i;
bool primo;
int uni;
int dec;


void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT); 
  pinMode(C,OUTPUT); 
  pinMode(D,OUTPUT); 
  pinMode(btn,INPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
}

void loop() {
  if(digitalRead(btn)==HIGH){   //Cuando se pulse el boton
    // Desde la linea 34 a la 43, unicamente son las condiciones para evaluar los números primos y arrojar un VERDADERO cuando se halle un primo.
    for(cont=1; cont<=99; cont++){
      primo = true; 
      for (i=2; i<cont; i++){
        if (cont%i == 0){
          primo = false;
        }
      }
      if(cont==1){
        primo=false;
      }
      // Cuando se ha enconctrado un primo, se descompene dicho numero en decenas y unidades desde la linea 45 a la 53
      if (primo){
        if(cont<10){
          uni = cont;
          dec = 0;
        }
        else{
          dec = cont/10;
          uni = cont - dec*10;
        }
        // Multiplexación de los displays de decenas y unidades para mostrar los números primos encontrados hasta el 99.
        digitalWrite(unidades,LOW);
        digitalWrite(decenas,HIGH);
        contador(dec);
        delay(300);
        digitalWrite(unidades,HIGH);
        digitalWrite(decenas,LOW);
        contador(uni);
        delay(300); 
      }
    }
  digitalWrite(unidades,LOW);
  digitalWrite(decenas,LOW);
  }
}

void contador (int i){
  switch(i){
      case 0:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
      case 1:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
      case 2:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
      case 3:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
        break;
      case 4:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
      case 5:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
      case 6:
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
      case 7:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        break;
      case 8:
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        break;
      case 9:
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        break;
  } 
}
