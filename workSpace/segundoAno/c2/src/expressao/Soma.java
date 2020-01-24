package expressao;

public class Soma extends Node {

	public Soma ( Node esq, Node dir ) {
		super ( "+", esq, dir );
	}
	
	@Override
	public Double processa() {
		return esq.processa() + dir.processa();
	}

}
