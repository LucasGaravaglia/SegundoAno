package expressao;

import lexico.Lex;
import lexico.Token;

public class MontarArvorex {

	private Lex lex = new Lex();
	
	public MontarArvorex() {		
	}
	
	private boolean verify_token ( String... params ) {
		String tk = lex.get_current_token().getToken();
		for (String string : params) {
			if (string.equals(tk)) {
				lex.goto_next_token();
				return true;
			}
		}
		return false;
	}
	
	private void assert_token ( String expected ) throws Exception {
		String tk = lex.get_current_token().getToken();
		if (tk.equals(expected)) {
			lex.goto_next_token();
			return;
		}
		throw new Exception("Erro");
	}

	private Node parseAtom() throws Exception {
		if (verify_token("(")) {
	        Node expression = parseExpression();
	        assert_token( ")" );
	        return expression;
	    }
		Token tk = lex.get_current_token().clone(); 
		if (tk.getClasse()==Token.TK_FLOAT) {
			lex.goto_next_token();
			return new Number(tk.getToken());
		}
		if (tk.getClasse()==Token.TK_INTEGER) {
			lex.goto_next_token();
			return new Number(tk.getToken());
		}
		
		throw new Exception("");
	}

	private Node parseUnary() throws Exception {
	    if (verify_token("-")) {
	    	return new Subtracao( new Number("0"), parseAtom() );
	    }
	    return parseAtom();
	}

	private Node parseMULTorDIV() throws Exception {
		 Node first = parseUnary();

		 if (verify_token("*")) {
			 return new Multiplicacao ( first, parseMULTorDIV() );
		 }
		 if (verify_token("/")) {
			 return new Divisao ( first, parseMULTorDIV() );
		 }
	    return first;	
	}
	
	private Node parseSUMorSUB() throws Exception {
		 Node first = parseMULTorDIV();

		 if (verify_token("+")) {
			 return new Soma ( first, parseSUMorSUB() );
		 }
		 if (verify_token("-")) {
			 return new Subtracao ( first, parseSUMorSUB() );
		 }
	    return first;
	}
	
	private Node parseExpression() throws Exception {
	    return parseSUMorSUB();
	}
	
	public Node parse ( String expressao ) throws Exception {
		lex.start_lex(expressao);
		return parseExpression();
	}

	
	public static void main(String[] args) {
		MontarArvorex montador = new MontarArvorex();
		
		Node node;
		try {
			node = montador.parse( "(7 + 8) * -9");
			System.out.println(node.processa());
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
