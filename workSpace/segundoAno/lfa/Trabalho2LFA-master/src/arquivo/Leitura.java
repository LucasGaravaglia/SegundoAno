package arquivo;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;

import estrutura.Alfabeto;
import estrutura.Automato;
import estrutura.Estado;
import estrutura.Transicao;


public class Leitura{
    /**
     * Metodo que remove espacos em branco na string
     * Entrada:      Nenhuma
     * Retorno:      String sem espacos 
     * Pre-condicao: Nenhuma
     * Pos-condicao: Os espacos sao removidos
     */
    public String removeEspacoEmBranco(String str) {
    	int i;
    	String[] aux;
    	String nova = "";
    	aux = str.split(" ");
    	for(i=0;i<aux.length;i++)
    		nova+=aux[i];    		
    	return nova;
    }
	
	/**
     * Metodo cria uma transição a partir da linha lida
     * Entrada:      uma string que contem uma linha do arquivo, ArrayList de String, que guardara o nome do estado
     * Retorno:      Nova Transicao
     * Pre-condicao: Nenhuma
     * Pos-condicao: Nenhuma
     */
	public Transicao NovaTransicao(String linha,ArrayList<String>NomeEstados) {
		linha = this.removeEspacoEmBranco(linha);
		linha = linha.substring(1,linha.length()-1);
		String[] temp = linha.split("=");
		temp[0] = temp[0].substring(0,temp[0].length()-1);
		temp[1] = temp[1].substring(1,temp[1].length());
		linha = temp[0];
		linha += ",";
		linha += temp[1];
		temp = linha.split(",");
		if(NomeEstados.indexOf(temp[0]) == -1) {
			NomeEstados.add(temp[0]);
		}
		Transicao transicao = new Transicao(temp[1],temp[2],temp[4],temp[3],temp[0]);		
		return transicao;
	}

	/**
     * Metodo que Le o arquivo de entrada e Cria o automato para ser processado
     * Entrada:      string contendo o caminho do arquivo
     * Retorno:      Automato criado
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
     */
    public Automato LerArquivo(String caminho) throws Exception{
    	File arquivo = new File(caminho);
        FileReader ler = new FileReader(arquivo);//Intanciando o arquivo
        BufferedReader lerArq = new BufferedReader(ler);//Instanciando a classe para ler o arquivo
    	try {
    		int i,j;        
    		//Le e armazena em um integer o Numero de estados
    		String NumeroEstados = lerArq.readLine();
    		NumeroEstados = this.removeEspacoEmBranco(NumeroEstados);
    		Integer nEstados;
    		String[] Temp = NumeroEstados.split("=");
    		nEstados = Integer.parseInt(Temp[1]);       
    		
    		//Le e guarda em uma string os estados finais
    		String Finais = lerArq.readLine(); 
    		Finais = this.removeEspacoEmBranco(Finais);
    		
    		//Le e guarda em uma classe alfabeto o alfabeto da fita
    		String AlfabetoFita = lerArq.readLine();
    		AlfabetoFita = this.removeEspacoEmBranco(AlfabetoFita);
    		String[] AlfabetoTemp = AlfabetoFita.split("=");
    		AlfabetoFita = AlfabetoTemp[1];
    		AlfabetoFita = AlfabetoFita.substring(1,AlfabetoFita.length()-1);
    		Alfabeto AlfaFita = new Alfabeto(AlfabetoFita);
    		
    		//Le e guarda em uma classe alfabeto o alfabeto da pilha
    		String AlfabetoPilha = lerArq.readLine();
    		AlfabetoPilha = this.removeEspacoEmBranco(AlfabetoPilha);
    		AlfabetoTemp = AlfabetoPilha.split("=");
    		AlfabetoPilha = AlfabetoTemp[1];
    		AlfabetoPilha = AlfabetoPilha.substring(1,AlfabetoPilha.length()-1);
    		Alfabeto AlfaPilha = new Alfabeto(AlfabetoPilha);    
    		
    		Transicao transicaoTemp = new Transicao();//Uma instancia da classe transicao, para adicionar aos arrayLists
    		ArrayList<Transicao> Transicoes = new ArrayList<Transicao>();//ArrayList de Transiçães para a manipulação das mesmas
    		ArrayList<Transicao> TransicaoEstado = new ArrayList<Transicao>();//ArrayList que recebera todas as transições de um estado
    		
    		
    		ArrayList<String>ListaEstados = new ArrayList<String>();//ArrayList que tera o nome de todos os estados do automato
    		String linha = lerArq.readLine();
    		for(i=0;linha!=null;i++) {
    			Transicoes.add(this.NovaTransicao(linha,ListaEstados));//Armazena e linha lida em uma classe Transicao
    			linha = lerArq.readLine();
    		}	
    		
    		for(Transicao transicao:Transicoes) {
    			if(ListaEstados.indexOf(transicao.getEstado()) == -1 ) {
    				ListaEstados.add(transicao.getEstado());
    			}
    		}
    		lerArq.close();
    		
    		String EstadoInicial = ListaEstados.get(0);
    		ArrayList<Estado> EstadosAutomato= new ArrayList<Estado>();
    		Estado EstadoTemp = new Estado();
    		
    		for(i=0,j=0;i<nEstados;i++) {
    			for(;j<Transicoes.size();j++) {//Separa cada transição para seu estado.
    				transicaoTemp = Transicoes.get(j);
    				if(transicaoTemp.getEstadoAtual().compareTo(ListaEstados.get(i)) == 0) {
    					TransicaoEstado.add(transicaoTemp);
    				}else{
    					break;
    				}
    			}
    			//Cria um estado e adiciona no arrayList de estados
    			EstadoTemp = new Estado(ListaEstados.get(i),TransicaoEstado,Finais.indexOf(ListaEstados.get(i)) != -1);
    			EstadosAutomato.add(EstadoTemp);
    			TransicaoEstado.clear();
    		}
    		Automato automatoArquivo = new Automato(AlfaPilha,AlfaFita,EstadosAutomato,EstadoInicial);
    		return automatoArquivo;
    	}catch(Exception e) {
    		lerArq.close();
    		throw new Exception();
    	}
		
    }
}
