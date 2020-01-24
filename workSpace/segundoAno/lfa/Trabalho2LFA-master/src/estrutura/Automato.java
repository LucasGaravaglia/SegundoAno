package estrutura;
import java.util.ArrayList;import java.util.Spliterator;


//Classe que representa um automato com pilha deterministico
public class Automato {
    private  Alfabeto alfabetoPilha;//Variavel que contem o alfabeto da pilha
    private Alfabeto alfabetoFita;//Variavel que contem o alfabeto da fita
    private ArrayList<Estado> estados;//Variavel que contem os estados do APD
    private Pilha<String> pilha;//Variavel que contem a pilha do APD
    private String estadoInicial;//Variavel que contem o estado inicial
    private Fita fita;//Variavel que contem a fita do APD
    private String textoFita;//Variavel que contem o texto do processamento da fita
    private String textoPilha;//Variavel que contem o texto do processamento da pilha
    
    //Construtor da Classe Automato
    public Automato(Alfabeto a_pilha, Alfabeto a_fita, ArrayList<Estado> estados, String estadoInicial) {
        this.alfabetoFita = a_fita;
        this.alfabetoPilha = a_pilha;
        this.estadoInicial = estadoInicial;
        this.pilha = new Pilha<String>();
        this.fita = new Fita();
	
        this.estados = new ArrayList<Estado>();
        for(Estado x : estados)
        	this.estados.add(x);
    }
	//Construtor da Classe automato sobrecarregado
	public Automato(Automato o) {
            this.alfabetoFita = o.getalfabetoFita();
            this.alfabetoPilha = o.getalfabetoPilha();
            this.estadoInicial = o.getestadoInicial();
            this.pilha = o.getPilha();
            this.fita = o.getFita();
            this.estados = o.getEstados();
	}
	
	//Getter da variável alfabetoPilha
	public Alfabeto getalfabetoPilha() {
            return alfabetoPilha;
	}
	
	//Setter da variável alfabetoPilha
	public void setalfabetoPilha(Alfabeto alfabetoPilha) {
            this.alfabetoPilha = alfabetoPilha;
	}   
	
	//Getter da variável alfabetoFita
	public Alfabeto getalfabetoFita() {
            return alfabetoFita;
	}
	
	//Setter da variável alfabetoFita
	public void setalfabetoFita(Alfabeto alfabetoFita) {
            this.alfabetoFita = alfabetoFita;
	}

	//Getter da variável estados
	public ArrayList<Estado> getEstados() {
            return estados;
	}
	
	//Setter da variável estados
	public void setEstados(ArrayList<Estado> estados) {
            this.estados = estados;
	}
	
	//Getter da variável pilha
	public Pilha<String> getPilha() {
            return pilha;
	}
	
	//Setter da variável pilha
	public void setPilha(Pilha<String> pilha) {
            this.pilha = pilha;
	}
	
	//Getter da variável estadoInicial
	public String getestadoInicial() {
            return estadoInicial;
	}
	
	//Setter da variável estadoInicial
	public void setestadoInicial(String estadoInicial) {
            this.estadoInicial = estadoInicial;
	}
	
	//Getter da variável fita
	public Fita getFita() {
            return this.fita;
	}
	
	//Getter da variável TextoFita
        public String getTextoFita() {
            return this.textoFita;
	}
		
	//Getter da variável TextoPilha
	public String getTextoPilha() {
            return this.textoPilha;
	}

	/**
     * Metodo que remove espacos em branco na string
     * Entrada:      Nenhuma
     * Retorno:      String sem espacos 
     * Pre-condicao: Nenhuma
     * Pos-condicao: Os espacos sao removidos
     */
    public String removeArroba(String str) {
    	int i;
    	String[] aux;
    	String nova = "";
    	aux = str.split("@");
    	for(i=0;i<aux.length;i++)
    		nova+=aux[i];    		
    	return nova;
    }

	/**
	 * Método transforma conteudo da classe em string
	 * Entrada: 	  Nenhuma
	 * Retorno: 	  string contendo conteudo da classe
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String toString() {
            String aux = "Automato com Piha Deterministico:\n->Qtd Estados: " + this.estados.size();
            aux += "\n->Estado Incial: " + this.estadoInicial;
            aux += "\n->Alfabeto Fita: " + this.alfabetoFita.toString();
            aux += "\n->Alfabeto Pilha: " + this.alfabetoPilha.toString();
            aux += "\n->Estados: \n";
		
            for(Estado x : this.estados)
                aux += x.toString();
		
            aux += "\n";
            aux += "\n->Pilha: \n" + this.pilha.toString();
            return aux;
	}
	
	/**
	 * Método procura e retonra um estado pelo seu nome
	 * Entrada: 	  nome do estado
	 * Retorno: 	  variavel do tipo estado ou null caso nao exista
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public Estado getEstado(String estado) {
            for(Estado x : this.estados)
            	if(x.getNome().compareTo(estado) == 0)
                    return x;
            return null;
	}	
	
	
	/**
	 * Método que retorna o conteudo atual da fita
	 * Entrada: 	  nenhuma
	 * Retorno: 	  String contendo conteudo da fita
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String processamentoFita() {
            String aux = "fita: ";
            aux += this.fita.toString();
            aux += "\n";
            return aux;
	}
	
	
	/**
	 * Método que retorna o conteudo atual da pilha
	 * Entrada: 	  nenhuma
	 * Retorno: 	  String contendo conteudo da pilha
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public String processamentoPilha() {
            String aux = "pilha: ";
            aux += this.pilha.toString();
            aux += "\n";
            return aux;
	}
	
	/**
	 * Método que faz as opercões necessarias na pilha
	 * Entrada: 	  transicao contendo o que deve ser empilhado e desempilhado
	 * Retorno: 	  se foi possivel desempilhar e empilhar
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public boolean operaNaPilha(Transicao transicao) {
        String topo;
        if(transicao == null) {
            return false;
        }				
        if(transicao.getDesempilha().compareTo("@") != 0) {			
            topo = this.pilha.pop();
			if(topo == null || topo.compareTo(transicao.getDesempilha()) != 0){
                return false;				
			}
        }
        if(transicao.getEmpilha().compareTo("@") != 0){			
            char[] aux = transicao.getEmpilha().toCharArray();
        	try {
                for(char w : aux)
                    	this.pilha.push(Character.toString(w));	
			}catch (Exception e) {
                return false;
			}						
        }
        return true;
	}
	
	/**
	 * Método que avalia se os 3 booleans sao true
	 * Entrada: 	  3 condições
	 * Retorno: 	  true se tudo for verdadeiro, ou false caso algum não seja
	 * Pré-condição: Nenhuma
	 * Pós-condição: Nenhuma
	 */
	public boolean Avaliar(boolean ehFinal, boolean fimFita,boolean pilhaVazia) {
		return (ehFinal && fimFita && pilhaVazia);
	}
	
	/**
	 * Método que verifica se o sibolo pertence ao alfabeto de fita
	 * Entrada: 	  Simbolo lido
	 * Retorno: 	  True caso pertença, false caso contrario
	 * Pré-condição:  Nenhuma
	 * Pós-condição:  Nenhuma
	 */
	public boolean verificaAlfabeto(String simbolo) {
		return this.alfabetoFita.getAlfabeto().indexOf(simbolo) != -1;
	}
	
	/**
	 * Método processa a fita de entrada
	 * Entrada: 	  A fita de entrada
	 * Retorno: 	  Nenhum
	 * Pré-condição:  Nenhuma
	 * Pós-condição:  Nenhuma
	 */
	public void processa(String fita) {
        String textoFita = "";
        String textoPilha = "";
        Estado estadoAtual;
        Transicao transAtual;
        boolean aceita = true;
        String simbolo = "@";
        fita = this.removeArroba(fita);           
        
        this.fita.setFita(fita.split(""), this.estadoInicial);
        estadoAtual = this.getEstado(this.estadoInicial);
      
        if(fita.isEmpty()) {
        	textoFita += "fita: " + this.fita.toString() + "\n";                
            textoPilha += "pilha: " + this.pilha.toString() + "\n";
            aceita = Avaliar(estadoAtual.ehFinal() , this.fita.consultaProxSimbolo().compareTo("@") == 0, this.pilha.ehVazia());
        }else{
        	while(aceita) {                
        		textoFita += "fita: " + this.fita.toString() + "\n";                
        		textoPilha += "pilha: " + this.pilha.toString() + "\n";
        		
        		if(estadoAtual.getTransicoes().size() == 1){                    
        			transAtual = estadoAtual.getTransicoes().get(0);
        			simbolo = transAtual.getSimbolo();
        			if(simbolo.compareTo("@") != 0){
        				simbolo = this.fita.consultaProxSimbolo();  
        				if(simbolo.compareTo("@") != 0 && this.verificaAlfabeto(simbolo)) { 
        					if(estadoAtual.getTransicao(simbolo, this.pilha.top()) == null) {
        						aceita = false;
        						break;
        					}
        						this.fita.anda();            						
        				}
        			}
        			if(simbolo.compareTo(transAtual.getSimbolo()) == 0){                        
        				if(this.operaNaPilha(transAtual) == false) {
        					aceita = false;
        					break;
        				}
        				estadoAtual = this.getEstado(transAtual.getEstado());
        				this.fita.setEstado(estadoAtual.getNome());
        			}else{
                        aceita = Avaliar(estadoAtual.ehFinal() , this.fita.consultaProxSimbolo().compareTo("@") == 0, this.pilha.ehVazia());
                        break;                        
        			}				
        		}else if (estadoAtual.getTransicoes().size() > 1) {                   
        			simbolo = this.fita.consultaProxSimbolo();
        			transAtual = estadoAtual.getTransicao(simbolo, this.pilha.top());
        			if(transAtual == null) {
                        aceita = Avaliar(estadoAtual.ehFinal() , this.fita.consultaProxSimbolo().compareTo("@") == 0, this.pilha.ehVazia());
        				break;
        			}
        			if(transAtual.getSimbolo().compareTo("@") != 0){
        				this.fita.anda();
        			}
        			if(this.operaNaPilha(transAtual) == false) {
        				aceita = false;
        				break;
        			}                    
        			estadoAtual = this.getEstado(transAtual.getEstado());
        			this.fita.setEstado(estadoAtual.getNome());
        		}else{
                    aceita = Avaliar(estadoAtual.ehFinal() , this.fita.consultaProxSimbolo().compareTo("@") == 0, this.pilha.ehVazia());
        			break;
        		}
        	}     
        }
        if(aceita) textoFita += "ACEITA";
        else textoFita += "REJEITADA";
        
        this.textoFita = textoFita;
        this.textoPilha = textoPilha;
	}
}
