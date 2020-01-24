#include "HobbyRadioReceiver.h"
#include <Wire.h>
#include <math.h>


//Controle Remoto
HobbyRadioReceiver rec( 3, A0, A1, A2);


#define sendSpeed 9
#define sendSteer 10
#define sendLimit 11

#define LEDCONTROLE 3

//Velocidade e direção padrão
#define X_PADRAO 130
#define Y_PADRAO 123


//Variaveis globais
int x,y,calibragemX,calibragemY;
long distancia,distancia2;
int Velocidade,Direcao,Limite;
String informacao="";
bool stringComplete;
int Speed,Steer,Limit;

//Vetor enviado pelo i2c
uint8_t vetor[6] = {218, 130, 0, 1, 0, 1};

void setup(){
  Serial.begin(9600);
  //Serial.print( "Num Channels: " );
  //Serial.println(rec.getNumChannels());

  //led interno arduino
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDCONTROLE,OUTPUT);

//  pinMode(sendLimit, OUTPUT);
//  pinMode(sendSpeed, OUTPUT);
//  pinMode(sendSteer, OUTPUT);

  //analogWrite(sendLimit, 0);
  
  //i2c
  Wire.begin(0x52);                
  Wire.onRequest(requestEvent); 

  //calibragem do controle remoto
  calibragemX = rec.check(1) * -1;  
  calibragemY = rec.check(2) * -1;
}

//Função que calcula a velocidade, direção e o limite máximo de velocidade do carrinho e coloca nas respectivas variáveis os valores
void controle(float vel, float dir, float limite){
  float fatorVel,fatorDir;
  int envia;
  if( vel < -10 || vel > 10) {
      fatorVel = (vel/100) * abs(limite);
      fatorDir = (dir/100) * abs(limite);
      y = Y_PADRAO + fatorVel;
      if(y < 35) y = 35; if(y > 230) y = 230; 
      x = X_PADRAO + fatorDir;
      if(x < 35) x = 35; if(x > 230) x = 230;
  }else{      
      x = X_PADRAO;
      y = Y_PADRAO;
  }
  Serial.write(x);
  Serial.write(y);
  
  
}

//Função que converte o sinal do controle remoto e executa a função controle com esses dados
void converteSinalRadio(){
  int sinalx, sinaly;
  int direcao,velocidade;
  int enviaSpeed, enviaSteer;

//  Serial.print("Speed: ");
//  Serial.print(enviaSpeed);
//  Serial.print(" Steer: ");
//  Serial.println(enviaSteer);
  
  sinalx = rec.check(1) + calibragemX;  
  sinaly = rec.check(2) + calibragemY;

  sinalx += 255; sinalx /= 2; sinalx -= 128;
  direcao = (sinalx * 100) / 256;
  
  sinaly += 255; sinaly /= 2; sinaly -= 128;
  velocidade = (sinaly * 100) / 256;
  
  velocidade *= 2;
  direcao *= 2;
 
  controle(-velocidade,direcao,25);
}

//Função que diz como será controlado o robô
void iniciarMovimento(String modoControle, String subModoControle){
  if(modoControle.equals("manual")){
    if(subModoControle.equals("radio")){
      converteSinalRadio();
    }else{
      Serial.println("Modo de controle não definido");
    }
  }else if(modoControle.equals("automatico")){
    if(subModoControle.equals("gps")){
      //Colocar aqui a função de gps
      ConverteUart();
    }else{
      Serial.println("Modo de controle não definido");
    }
  }else{
    Serial.println("Modo de controle não definido");
  }
}

void DefineModoControle(){
  int radioaux = rec.check(3);
  if(radioaux < -60){
    digitalWrite(LEDCONTROLE,HIGH);
    iniciarMovimento("automatico","gps");
  }
  else if(radioaux > 60){
    digitalWrite(LEDCONTROLE,LOW);
    iniciarMovimento("manual","radio");
  }
}
void loop(){
  //DefineModoControle();
  ConverteUart();
}

//Função que responde à requisião de evento da placa do hoverboard
void requestEvent() {
  int i;
  vetor[0] = x;
  vetor[1] = y;
  for(i = 0; i < 6; i++){
    Wire.write(vetor,6);
  }
}

void readinfo(){
      informacao = "";
      stringComplete = false;  
}

void ConverteUart() {
  String temp;
  char sinal;
  EventSerial();
  if(stringComplete){
    Serial.print("Info = {");
    Serial.print(informacao);
    Serial.println("}");
    temp="";
    sinal = informacao[0] - 48;
    temp += informacao[1];
    temp += informacao[2];
    temp += informacao[3];
    Velocidade = temp.toInt();
    if(!sinal) Velocidade *= -1;
    
    temp="";
    sinal = informacao[5] - 48;
    temp += informacao[6];
    temp += informacao[7];
    temp += informacao[8];
    Direcao = temp.toInt();
    if(!sinal) Direcao *= -1;
    
    temp="";
    sinal = informacao[10] - 48;
    temp += informacao[11];
    temp += informacao[12];
    temp += informacao[13];
    Limite = temp.toInt();
    if(!sinal) Limite *= -1;
//    Serial.print("Velocidade= ");
//    Serial.println(Velocidade);
//    Serial.print("Direcao= ");
//    Serial.println(Direcao);
//    Serial.print("Limite= ");
//    Serial.println(Limite);
    
    controle(Velocidade,Direcao,Limite);
    readinfo();
  }
}


void EventSerial() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    informacao += inChar;
    if (inChar == ';') {
      stringComplete = true;
    }
  }
}
