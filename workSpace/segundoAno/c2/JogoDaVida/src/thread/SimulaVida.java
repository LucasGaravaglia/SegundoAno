package thread;

public class SimulaVida extends Thread {

	private Observador observador;
	private Integer size;
	private int matriz[][];
	private boolean fim;
	private boolean pausado;

	public SimulaVida ( Observador observador, int size ) {
		this.observador = observador;
		this.size       = size;
		this.matriz     = new int[size+2][size+2]; 
		this.fim        = false;
		this.pausado    = false;
	}

	public void finalize() {
		this.fim = true;
	}

	public void setPausado ( boolean valor ) {
		this.pausado = valor;
	}

	private void inicializa() {
		for (int i=1; i<=size; i++) {
			for (int j=1; j<=size; j++) {
				this.matriz[i][j] = (int) (Math.random()*1.5);
			}		
		}
	}

	private int[][] iteracao () {
		int nova[][] = new int[size+2][size+2];
		int n;
		for (int i=1; i<=size; i++) {
			for (int j=1; j<=size; j++) {
				n = contaVizinhos(i, j);
				if (matriz[i][j]==1) {
					nova[i][j]=1;
					if(n<2) nova[i][j]=0;
					if(n>3) nova[i][j]=0;
				} else {
					if (n==3) {
						nova[i][j]=1;
					}
				}				
			}
		}
		return nova;		
	}

	private Integer contaVizinhos ( Integer linha, Integer coluna ) {
		return this.matriz[linha-1][coluna-1] +
				this.matriz[linha-1][coluna] +
				this.matriz[linha-1][coluna+1] +
				this.matriz[linha][coluna-1] +
				this.matriz[linha][coluna+1] +
				this.matriz[linha+1][coluna-1] +
				this.matriz[linha+1][coluna] +
				this.matriz[linha+1][coluna+1]; 

		/*Integer n=0;
		for (int i=linha-1; i<=linha+1; i++) {
			for (int j=coluna-1; j<=coluna+1; j++) {
				if (i!=linha || j !=coluna) {
					n += this.matriz[i][j];
				}
			}
		}
		return n; */

	}

	private void imprimeTabuleiro(int iteracao) {
		System.out.println("Execução " + iteracao  );
		for (int i=0; i<size+2; i++) {
			for (int j=0; j<size+2; j++) {
				if (this.matriz[i][j] == 0)
					System.out.print(" .");
				else
					System.out.print(" X");
			}	
			System.out.println();
		}
	}

	public void run () {
		int i=0;
		inicializa();
		imprimeTabuleiro(i);
		observador.mostrarTabuleiro(matriz);
		while (!fim) {
			if (!pausado) {
				this.matriz = iteracao();
				imprimeTabuleiro(i++);	
				observador.mostrarTabuleiro(matriz);
			}
			try {
				sleep(500);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Fim da thread");
	}
}
