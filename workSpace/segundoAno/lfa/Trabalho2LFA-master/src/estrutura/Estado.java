package estrutura;
import java.util.ArrayList;

public class Estado {
	private  String nome;//Variavel que contem o nome do estado
	private  ArrayList<Transicao> transicoes;//Variavel que contem as transições possivel a partir deste estado
	private  boolean ehFinal;//Variavel que diz se o estado é final ou nao
	
	//Construtor da classe Estado
	public Estado(String nome, ArrayList<Transicao> transicoes, boolean ehFinal) {
		this.ehFinal = ehFinal;
		this.nome = nome;
		this.transicoes = new ArrayList<Transicao>();
		for(Transicao x : transicoes)
			this.transicoes.add(x);		
	}
	
	//Construtor sobrecarregado
	public Estado() {
		this.ehFinal = false;
		this.nome 	 = "";
		this.transicoes = new ArrayList<Transicao>();
	}
	
	//Getter da variável nome
	public String getNome() {
		return nome;
	}
	
	//Setter da variável nome
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	//Getter da variável transicoes
	public ArrayList<Transicao> getTransicoes() {
		return transicoes;
	}
	
	//Setter da variável transicoes
	public void setTransicoes(ArrayList<Transicao> transicoes) {
		this.transicoes.clear();
		for(Transicao x : transicoes)
			this.transicoes.add(x);
	}
	
	//Getter da variável ehFinal
	public boolean ehFinal() {
		return ehFinal;
	}
	
	//Setter da variável ehFinal
	public void setehFinal(boolean ehFinal) {
		this.ehFinal = ehFinal;
	}
	
	/**
	 * Método transforma conteudo da classe em string
	 * Entrada: 	  Nenhuma
	 * Retorno: 	  string contendo conteudo da classe
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String toString() {
		String aux = "~> " + this.nome + "\n" + "Final: " + this.ehFinal + "\n\t Transicoes:\n";
		for(Transicao X : this.transicoes)
			aux += "\t\t" + X.toString() + "\n";
		aux += "\n";
		return aux;
	}
	
	/**
	 * Método procura e retorna uma transicao pelo simbolo lido
	 * Entrada: 	  simbolo lido 
	 * Retorno: 	  Transicao
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public Transicao getTransicao(String simbolo, String topoPilha) {
        if(topoPilha == null)
            topoPilha = "@";
        for (Transicao x : this.transicoes){
            if(x.getSimbolo().compareTo(simbolo) == 0 || x.getSimbolo().compareTo("@") == 0) {
                if(x.getDesempilha().compareTo("@") == 0 || x.getDesempilha().compareTo(topoPilha) == 0)
                    return x;				
            }							
		}		
		return null;	
    }
}
