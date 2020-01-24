package estrutura;

//Classe que representa uma transicao do autômato com pilha determinístico
public class Transicao {
	private String simbolo;//Variavel que contem o simbolo lido nessa transição
	private String empilha;//Variavel que contem o que será empilhado ao utilizar essa transição
	private String desempilha;//Variavel que contem o que será desempilhado ao utilizar essa transição
	private String estado;//Variavel que contem o nome do estado que essa transição leva
	
	//Cosntrutor padrao da classe Transicao
	public Transicao(String simbolo, String empilha, String desempilha, String estado) {
		this.simbolo = simbolo;
		this.empilha = empilha;
		this.desempilha = desempilha;
		this.estado = estado;
	}
	
	//Getter da variável simbolo
	public String getSimbolo() {
		return simbolo;
	}
	
	//Setter da variável simbolo
	public void setSimbolo(String simbolo) {
		this.simbolo = simbolo;
	}
	
	//Getter da variável empilha
	public String getEmpilha() {
		return empilha;
	}
	
	//Setter da variável empiha
	public void setEmpilha(String empilha) {
		this.empilha = empilha;
	}
	
	//Getter da variável desempilha
	public String getDesempilha() {
		return desempilha;
	}
	
	//Setter da variável desempilha
	public void setDesempilha(String desempilha) {
		this.desempilha = desempilha;
	}
	
	//Getter da variável estado
	public String getEstado() {
		return estado;
	}
	
	//Setter da variável estado
	public void setEstado(String estado) {
		this.estado = estado;
	}
	
	/**
	 * Método transforma conteudo da classe em string
	 * Entrada: 	  Nenhuma
	 * Retorno: 	  string contendo conteudo da classe
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String toString() {
		return (this.simbolo + "," + this.desempilha + "/" + this.empilha + "\t  Vai Para: " + this.estado);
	}
}