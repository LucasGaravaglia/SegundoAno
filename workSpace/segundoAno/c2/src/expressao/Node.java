package expressao;

public abstract class Node {
	
	protected String nome;
	protected Node esq;
	protected Node dir;
	
	public Node ( String nome, Node esq, Node dir ) {
		this.nome = nome;
		this.esq  = esq;
		this.dir  = dir;
	}

	public abstract Double processa ();
	
	@Override
	public String toString() {		
		return this.nome;
	}		
}
