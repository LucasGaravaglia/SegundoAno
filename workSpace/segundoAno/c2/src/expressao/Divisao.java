package expressao;

public class Divisao extends Node {

	public Divisao ( Node esq, Node dir ) {
		super ( "/", esq, dir );
	}
	
	@Override
	public Double processa() {
		return esq.processa() / dir.processa();
	}

}
