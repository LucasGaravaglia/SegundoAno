package lexico;

public class Lex {

	private Integer dot;
	private Integer indexSeparador;
	private String  input;    
	private char    input_char;
	private Token   token;

	private void next_char () {
		input_char =  (++dot<input.length()? input.charAt(dot) : '\0');
	}

	private boolean is_end_of_input() {
		return (input_char=='\0');
	}

	private boolean is_layout() {
		return (!is_end_of_input() && (input_char <= ' '));
	}

	// Define começo de comentário
	private boolean is_comment_starter() {  
		return (input_char == '#');
	}

	// Define Fim de comentário
	private boolean is_comment_stopper() {
		return (input_char == '#' || input_char == '\n');
	}

	private String[] separator = {" ", "(", ")", "[","]", "+", "-", "*", "/",
			">=", "<=", ">",  "<", "!=", "==", "=", ":", ".", ",", ";" }; 

	private boolean is_separator() {
		String s;
		boolean sucesso=false;
		for (int i=0; !sucesso && i<separator.length; i++) {
			sucesso=true;
			s = separator[i];
			for (int j=0; sucesso && j<s.length(); j++)
				sucesso = (dot+j<input.length())&&(input.charAt(dot+j)==s.charAt(j));

			indexSeparador= ((sucesso)? i : -1);
		}
		return sucesso;
	}

	private void recognize_separator () {
		int n = separator[indexSeparador].length();
		while (n-->0) next_char();

		token.setClasse( Token.TK_SEPARATOR ) ;
		token.setToken ( separator[indexSeparador]);
	}
	
	private boolean is_number() {
		return (input_char>='0') && (input_char<='9');
	}

	private void recognize_number() {
		int start_dot = dot;

		while (is_number() )
			next_char();

		if (input_char=='.') {
			next_char();

			while (is_number() )
				next_char();

			token.setClasse ( Token.TK_FLOAT );
		} else {
			token.setClasse ( Token.TK_INTEGER );
		}
		token.setToken(  input.substring( start_dot, dot )); //.toUpper();
	}
	
	private void recognize_string() {
		int start_dot = dot;

		while (!is_end_of_input() && !is_layout() && (!is_separator()))
			next_char();

		token.setClasse (  Token.TK_STRING );
		token.setToken(  input.substring( start_dot, dot ));
	}

	private void skip_layout_and_comment() {
		while(is_layout()){ next_char () ; }
		if (is_comment_starter()) {
			next_char();
			while(!is_comment_stopper()){
				if(is_end_of_input()) return;
				next_char();
			}
			next_char();
			while(is_layout()){
				next_char();
			}
		}
	}

	private void note_token_position() {
		token.setDot( dot );
	}

	public Lex ( ) {
		input = "";
	}

	public void start_lex( String input ) {
		token = new Token();

		this.indexSeparador = -1;
		this.dot    = -1;
		this.input  = input;

		next_char();
		goto_next_token();
	}
	
	public Token goto_next_token() {
		skip_layout_and_comment();

	    note_token_position();

	    if(is_end_of_input()){
	        token.setClasse( Token.TK_EOF );
	        token.setToken(  "<EOF>" );
	    }
	    else
	        if (is_separator())
	            recognize_separator();
	        else
	            if (is_number())
	                recognize_number();
	            else
	                recognize_string();

	    return token;
	}
	
	public Token get_current_token() {
		return this.token;
	}
	
	public static void main(String[] args) {
		Lex lex = new Lex();
		lex.start_lex("#teste# (783 + 8)*9\n +7"); 
		Token tk = lex.get_current_token();
		while (tk.getClasse()!=Token.TK_EOF) {
			System.out.println(tk);
			tk = lex.goto_next_token();
		}
		System.out.println(tk);
	}

}
