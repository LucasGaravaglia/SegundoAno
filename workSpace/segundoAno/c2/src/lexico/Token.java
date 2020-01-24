package lexico;

public class Token {
	
	public final static int TK_EOF=255;
	public final static int TK_INTEGER=256;
	public final static int TK_FLOAT=257;
	public final static int TK_STRING = 258;
	public final static int TK_SEPARATOR=259;
		
	private String token;
	private Integer dot;
	private Integer classe;
	
	public Token ( ) {
		this.token  = "";
		this.dot    = -1;
		this.classe = -1;
	}

	public Token ( Token other ) {
		this.token  = other.token;
		this.dot    = other.dot;
		this.classe = other.classe; 
	}

	public void setToken (  String token ) {
		this.token  = token;
	}

	public void setDot (  Integer dot  ) {
		this.dot   = dot;
	}
	
	public void setClasse (  Integer classe  ) {
		this.classe   = classe;
	}
	
	public String getToken ( ) {
		return this.token;
	}
	
	public Integer getDotStart () {
		return this.dot;
	}		
	
	public Integer getDotEnd ()   { 
		return this.dot + token.length(); 
	}
		
	public Integer getClasse ()   { 
		return this.classe; 
	}
	
	public Token clone () {
		return new Token ( this );
	}
	
	@Override
	public String toString() {
		return this.token;
	}
}
