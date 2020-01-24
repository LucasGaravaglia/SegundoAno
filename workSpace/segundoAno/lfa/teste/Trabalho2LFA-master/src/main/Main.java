package main;

import estrutura.Pilha;
import arquivo.Texto;

public class Main {
	public static void main(String[] args) {
		Texto t = new Texto(" a ");
		System.out.println(t.getTexto());
		System.out.println(t.removerEspacosExtras());
	}
}
