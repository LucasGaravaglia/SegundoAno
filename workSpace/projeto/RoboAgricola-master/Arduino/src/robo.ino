#include "HobbyRadioReceiver.h"
#include "Ultrasonic.h"
#include <Wire.h>
#include <math.h>

//Pinos utilizados para o ultrassom
Ultrasonic ultrassom(8,7);
Ultrasonic ultrassom2(9,10);

//Controle Remoto
HobbyRadioReceiver rec( 2, A0, A1);

/*   *****OBS: Não utilizar os pinos: 7,8,9,10,A0,A1,A4 e A5 pois já estão reservados*****    */

/*Filtros
 * FILTRO_CONTROLE: Filtra o sinal recebido do controle para evitar ruidos
 * FILTRO_DISTANCIA: Distancia mínima para os sensores de distância acusarem objetos na frente
 */
#define FILTRO_CONTROLE 65
#define FILTRO_DISTANCIA 50

/*Pinos de controle manuais
 * PINO_CONTROLE_VEL_MAX: Pino utilizado para definir qual será a velocidade máxima
 * IGNORAR_SENSORES: Pino utilizado para decidir se os sensores serão considerados ou não
 */
#define PINO_CONTROLE_VEL_MAX 2
#define IGNORAR_SENSORES 5

//Velocidade e direção padrão
#define X_PADRAO 130
#define Y_PADRAO 123

/*Controlar velocidade máxima pelo pino
 * VEL_MAX_1 -> Pino no positivo
 * VEL_MAX_2 -> Pino no negativo
 */
#define VEL_MAX_1 70
#define VEL_MAX_2 25

//Variaveis globais
int x,y,calibragemX,calibragemY,velMax,ignorarSensores;
long distancia,distancia2;

//Vetor enviado pelo i2c
uint8_t vetor[6] = {218, 130, 0, 1, 0, 1};

void setup(){
  Serial.begin(9600);
  Serial.print( "Num Channels: " );
  Serial.println(rec.getNumChannels());

  //led interno arduino
  pinMode(LED_BUILTIN, OUTPUT);
  
  //Pino manual de controle de velocidade maxima
  pinMode(PINO_CONTROLE_VEL_MAX, INPUT);

  //Pino manual para controlar se os sensores devem ou não serem obedecidos
  pinMode(IGNORAR_SENSORES, INPUT);

  //i2c
  Wire.begin(0x52);                
  Wire.onRequest(requestEvent); 

  //calibragem do controle remoto
  calibragemX = rec.check(1) * -1;  
  calibragemY = rec.check(2) * -1;
}

//Função que define a velocidade maxima com base no pino de controle de modo analogico
void calculaVelMax(){
  if(digitalRead(PINO_CONTROLE_VEL_MAX)) velMax = 70;
  else velMax = 25;
}

//Função que pisca o led do arduino caso algum objeto esteja em rota de colisão com o robô
void pisca(){
  if(distancia < FILTRO_DISTANCIA
        || distancia2 < FILTRO_DISTANCIA)
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));    
}

//Função que calcula a velocidade, direção e o limite máximo de velocidade do carrinho e coloca nas respectivas variáveis os valores
void controle(float vel, float dir, float limite){
  float fatorVel,fatorDir;
  
  if( (distancia >= FILTRO_DISTANCIA && distancia2 >= FILTRO_DISTANCIA || vel < 0 || ignorarSensores == 1) && (vel < -10 && vel > 10) ) {
      fatorVel = (vel/100) * abs(limite);
      fatorDir = (dir/100) * abs(limite);
      y = Y_PADRAO + fatorVel;
      if(y < 35) y = 35; if(y > 230) y = 230; 
      x = X_PADRAO + fatorDir;
      if(x < 35) x = 35; if(x > 230) x = 230;
  }else{
      pisca();
      x = X_PADRAO;
      y = Y_PADRAO;
  }
  
}

//Função que converte o sinal do controle remoto e executa a função controle com esses dados
void converteSinalRadio(){
  int sinalx, sinaly;
  int direcao,velocidade;
  
  sinalx = rec.check(1) + calibragemX;  
  sinaly = rec.check(2) + calibragemY;

  if(sinalx >= -FILTRO_CONTROLE && sinalx <= FILTRO_CONTROLE) sinalx = 0;
  if(sinaly >= -FILTRO_CONTROLE && sinaly <= FILTRO_CONTROLE) sinaly = 0;

  sinalx += 255; sinalx /= 2; sinalx -= 128;
  direcao = (sinalx * 100) / 256;
  
  sinaly += 255; sinaly /= 2; sinaly -= 128;
  velocidade = (sinaly * 100) / 256;

  velocidade *= 2;
  direcao *= 2;

  if(velocidade < 0) direcao *= -1;
  
  controle(-velocidade,direcao,velMax); 
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
    }else{
      Serial.println("Modo de controle não definido");
    }
  }else{
    Serial.println("Modo de controle não definido");
  }
}

//Função que executa todas as configurações básicas do programa
void funcoesBasicas(){
  distancia = ultrassom.Ranging(CM);
  distancia2 = ultrassom2.Ranging(CM);
  ignorarSensores = digitalRead(IGNORAR_SENSORES);
  calculaVelMax();
}

void loop(){
  funcoesBasicas();
  iniciarMovimento("manual","radio");
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
