package expressao;

public class Number extends Node {
	
	private Double n;
	
	public Number ( String n )  {
		super (n, null, null);
		this.n = Double.parseDouble(n);
	}

	@Override
	public Double processa() {		
		return n;
	}

}
