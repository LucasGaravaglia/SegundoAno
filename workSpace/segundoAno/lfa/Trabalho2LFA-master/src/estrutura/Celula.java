package estrutura;

//Estrutura que representa uma célula da pilha do autômato
public class Celula<T> {
	private T info; //Guarda a informação
	private Celula<T> prox; //Guarda o próximo elemento
	
	//Construtor padrão
	public Celula() {
		this.info = null;
		this.prox = null;
	}
	
	//Construtor sobrecarregado
	public Celula(T info) {
		this.info = info;
		this.prox = null;
	}
	
	//Construtor sobrecarregado
	public Celula(T info, Celula<T> prox) {
		this.info = info;
		this.prox = prox;
	}
	
	//Setter da variável info
	public void setInfo(T info) {
		this.info = info;
	}
	
	//Setter da variável prox
	public void setProx(Celula<T> prox) {
		this.prox = prox;
	}
	
	//Getter da variável info
	public T getInfo() {
		return this.info;
	}
	
	//Getter da variável prox
	public Celula<T> getProx() {
		return this.prox;
	}
	
}