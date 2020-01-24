package estrutura;

public class Fita {
	private String[] fita;//Caonteudo da fita
	private int agulha;//Agura que aponta para o local que a fita esta sendo lida
	private String estado;//Estado atual que está lendo a fita
	
	
	//Construtor da classe
	public Fita() {
		this.fita = null;
		this.agulha = 0;
		this.estado = null;
	}
	
	
	/**
	 * Método que retorna o conteudo atual da fita
	 * Entrada: 	  nenhuma
	 * Retorno: 	  String contendo conteudo da pilha
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String toString() {
		String aux = "";
		for(String a : this.fita) {
			if(this.agulha != this.fita.length && a == this.fita[this.agulha] )
				aux += "[" + this.estado + "]";
			aux += a;
		}
		if(this.agulha == this.fita.length)
			aux += "[" + this.estado + "]";
		return aux;			
	}
	
	
	/**
	 * Método que anda (le um sibolo da fita) na fita
	 * Entrada: 	  nenhuma
	 * Retorno: 	  caso ainda haja, retorna o proximo simbolo
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String anda(){
		if(this.agulha < this.fita.length)
			return this.fita[this.agulha++];				
		return null;			
	}
	
	/**
	 * Método que rdiz se a fita acabou
	 * Entrada: 	  nenhuma
	 * Retorno: 	  true caso tenha acabado, false caso nao
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public boolean fim() {
		return this.agulha > this.fita.length;
	}
	
	//Getter da varialvel fita
	public String[] getFita() {
		return fita;
	}
	
	//Setter da variavel fita
	public void setFita(String[] fita, String estado) {
		this.fita = fita;
		this.agulha = 0;
		this.estado = estado;
	}
	
	//Getter da variavel agulha
	public int getAgulha() {
		return agulha;
	}
	
	//Setter da variavel agulha
	public void setAgulha(int agulha) {
		this.agulha = agulha;
	}
	
	//Getter da variavel estado
	public String getEstado() {
		return estado;
	}
	
	//Setter da variavel Estado
	public void setEstado(String estado) {
		this.estado = estado;
	}
        
     /**
	 * Método que consulta o proximo simbolo da fita
	 * Entrada: 	  nenhuma
	 * Retorno: 	  caso ainda haja, retorna o proximo simbolo, se não retorna @
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
        public String consultaProxSimbolo(){
        	if(this.fita.length == 1 && this.fita[0].compareTo("") == 0)
        		return "@";
            if(this.agulha < this.fita.length)
            	return this.fita[this.agulha];
            return "@";	
        }	
        public String consultaSimboloAtual() {
            if(this.fita[this.agulha] == "")
            	return "@";
            return this.fita[this.agulha];	
        }
}
