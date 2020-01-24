#define LED1  4
#define LED2  5
#define LED3  6
#define LED4  7
#define BUT1 8
#define BUT2 9
#define BUT3 10
#define BUT4 11
#define NEWGAME 12
#define MAX 40
#define MODE 10


int sequence[MAX];
int jogada[MAX];
int i=0;
int resposta;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(BUT1,INPUT);
  pinMode(BUT2,INPUT);
  pinMode(BUT3,INPUT);
  pinMode(BUT4,INPUT);
  randomSeed(analogRead(0));
  newSequence();
  showSequence();
}

void newSequence(){
  for(i = 0 ; i < MAX ; i++)
    sequence[i] = random(4,8);  
}

void perdeu(){
  for(i=0;i<10;i++){
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    delay(300);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
  }
}

void showSequence(){
  for(i=0;i<MODE;i++){
    digitalWrite(sequence[i],HIGH);
    delay(300);
    digitalWrite(sequence[i],LOW);
  }
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}

void loop() {
    //newSequence();
 
  for(i=0;i<MODE;i++){
    resposta = digitalRead(sequence[i]+4);
    if(resposta != sequence[i]){
      perdeu();
    }
  }  
}
