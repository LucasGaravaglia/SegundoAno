package expressao;

public class Subtracao extends Node {

	public Subtracao ( Node esq, Node dir ) {
		super ( "-", esq, dir );
	}
	
	@Override
	public Double processa() {
		return esq.processa() - dir.processa();
	}

}
