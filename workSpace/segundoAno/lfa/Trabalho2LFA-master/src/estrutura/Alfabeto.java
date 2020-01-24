package estrutura;

import java.util.ArrayList;

//Classe que representa um alfabeto
public class Alfabeto {
	private ArrayList<String> alfabeto;//Variavel que contem os caracteres do alfabeeto
	private Integer tamanho;//Variavel que contem o tamanho do alfabeto
	
	//Construtor da classe
	public Alfabeto(String alfabeto) {
		this.alfabeto = new ArrayList<String>();
		String[] aux = alfabeto.split(",");
		
		for(String a : aux)
			this.alfabeto.add(a);
		
		this.tamanho = this.alfabeto.size();
	}
	
	//Getter da variável alfabeto
	public ArrayList<String> getAlfabeto() {
		return this.alfabeto;
	}
	
	//Setter da variável alfabeto
	public void setAlfabeto(String alfabeto) {
		String[] aux = alfabeto.split(",");
		this.alfabeto.clear();
		for(String a : aux)
			this.alfabeto.add(a);
	}
	
	//Getter da variável tamanho
	public Integer getTamanho() {
		return tamanho;
	}
	
	//Setter da variável tamanho
	public void setTamanho(Integer tamanho) {
		this.tamanho = tamanho;
	}
	
	/**
	 * Método transforma conteudo da classe em string
	 * Entrada: 	  Nenhuma
	 * Retorno: 	  string contendo conteudo da classe
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String toString() {
		return this.alfabeto +  "  Qtd simbolos: " + this.tamanho;
	}
}