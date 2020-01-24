package expressao;

import lexico.Lex;
import lexico.Token;

public class MontarArvore {
	
	protected Lex lex = new Lex();
	
	public MontarArvore() {		
	}
	
	public Node parse ( String expressao ) {
		lex.start_lex(expressao);
		return parseSOMAouSUBTRACAO();		
	}
	
	private Node parseSOMAouSUBTRACAO() {
		Node exp = parseDIVouMULT();
		if (lex.get_current_token().getToken()=="+") {
			lex.goto_next_token();
			return new Soma (exp, parseSOMAouSUBTRACAO() );
		} 
		if (lex.get_current_token().getToken()=="-") {
			lex.goto_next_token();
			return new Subtracao(exp, parseSOMAouSUBTRACAO() );
		}
		return exp;
	}
	
	private Node parseDIVouMULT () {
		Node exp = parseUnary();
		if (lex.get_current_token().getToken()=="/") {
			lex.goto_next_token();
			return new Divisao(exp, parseDIVouMULT() );
		} 
		if (lex.get_current_token().getToken()=="*") {
			lex.goto_next_token();
			return new Multiplicacao (exp, parseDIVouMULT() );
		}
		return exp;
	}
	
	private Node parseUnary () {
		if (lex.get_current_token().getToken()=="-") {
			lex.goto_next_token();
			return new Subtracao(new Number("0"), parseAtom());
		} 
		return parseAtom();
	}
	
	private Node parseAtom () {
		if (lex.get_current_token().getToken()=="(") {
			lex.goto_next_token();
			Node node = parseSOMAouSUBTRACAO();
			if (lex.get_current_token().getToken()==")") {
				lex.goto_next_token();
				return node;
			}
		}
		if (lex.get_current_token().getClasse()==Token.TK_INTEGER) {
			Node node = new Number ( lex.get_current_token().getToken() );
			lex.goto_next_token();
			return node;
		}
		//throw new Exception("");
		return null;
	}
	
	public static void main(String[] args) {
		MontarArvore m = new MontarArvore();
		Node node = m.parse("(7 + 8 * - 9)");
		System.out.println(node.processa());
	}
	

}
