package expressao;

public class Multiplicacao extends Node {

	public Multiplicacao ( Node esq, Node dir ) {
		super ( "*", esq, dir );
	}
	
	
	@Override
	public Double processa() {
		return esq.processa() * dir.processa();
	}

}
