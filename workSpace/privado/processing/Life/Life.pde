matriz game = new matriz(600);
int tam=10;
void setup(){
  game.inicializa();
  size(600,600);
}
void draw(){
  game.imprime();
  game.atualiza();  
  delay(1000);
}

public class matriz{
  private int matriz[][];
  private int size;
  
  public matriz(int size){
    this.matriz = new int[size][size]; 
    this.size = size;
  }
  
  private void inicializa(){
    randomSeed(10);
    int i,j;
    for(i=0;i<this.size;i++){
      for(j=0;j<this.size;j++){
        this.matriz[i][j] = (int) (random(1) * 1.4);
      }
    }    
  }
  
  public int vizinho(int i, int j){
    int NumVizinho=0;
      if(i > 0 && j > 0) 
        NumVizinho+=this.matriz[i-1][j-1];
      if(i < this.size-1 && j < this.size-1) 
        NumVizinho+=this.matriz[i+1][j+1];
      if(i > 0 && j < this.size-1) 
        NumVizinho+=this.matriz[i-1][j+1];
      if(i < this.size-1 && j > 0) 
        NumVizinho+=this.matriz[i+1][j-1];
      if(i > 0) 
        NumVizinho+=this.matriz[i-1][j];
      if(j > 0) 
        NumVizinho+=this.matriz[i][j-1];
      if(i < this.size-1) 
        NumVizinho+=this.matriz[i+1][j];
      if(j < this.size-1) 
        NumVizinho+=this.matriz[i][j+1];
    return NumVizinho;       
  }
  
  public void atualiza(){
  int tabuleiro[][] = this.matriz;
    int i,j;
    int numVizinhos;
    for(i=0;i<this.size;i++) {
      for(j=0;j<this.size;j++) {
        numVizinhos = this.vizinho(i, j);
                if(tabuleiro[i][j] == 1) {
          if(numVizinhos < 2) tabuleiro[i][j] = 0;
          if(numVizinhos > 3) tabuleiro[i][j] = 0;
        }else {
          if(numVizinhos == 3) tabuleiro[i][j] = 1;
        }
      }
    }
    this.matriz = tabuleiro; 
  }
  
  public void imprime(){
    int i,j;
    for(i=0;i<this.size;i++){
      for(j=0;j<this.size;j++){
        if(this.matriz[i][j] == 1){
          stroke(0);
          fill(0);
          rect(i*tam,j*tam,tam,tam);
        }else{
          stroke(255);
          fill(255);
          rect(i*tam,j*tam,tam,tam);
        }
      }
      
    }
    
    
  }
}
