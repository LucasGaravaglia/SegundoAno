package estrutura;
import java.util.ArrayList;

//Classe que representa um autômato com pilha determinístico
public class Automato {
	private  Alfabeto alfabetoPilha;//Variavel que contem o alfabeto da pilha
	private Alfabeto alfabetoFita;//Variavel que contem o alfabeto da fita
	private ArrayList<Estado> estados;//Variavel que contem os estados do APD
	private Pilha<String> pilha;//Variavel que contem a pilha do APD
	private String estadoInicial;//Variavel que contem o estado inicial
	private String fita;//Variavel que contem a fita do APD
	
	//Construtor da Classe Automato
	public Automato(Alfabeto a_pilha, Alfabeto a_fita, ArrayList<Estado> estados, String estadoInicial) {
		this.alfabetoFita = a_fita;
		this.alfabetoPilha = a_pilha;
		this.pilha = new Pilha<String>();
		this.estadoInicial = estadoInicial;
		
		this.estados = new ArrayList<Estado>();
		for(Estado x : estados)
			this.estados.add(x);
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
	public String getFita() {
		return fita;
	}

	//Setter da variável estado_fita
	public void setFita(String fita) {
		this.fita = fita;
	}	
	
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
	
}
