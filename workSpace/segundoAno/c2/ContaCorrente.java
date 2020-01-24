package model;


import java.util.ArrayList;

import model.Movimentacao.Tipo;

public class ContaCorrente {
	
	protected Integer idcontacorrente;
	protected Integer numero;
	protected Double  saldo;
	protected Boolean especial;
	protected Integer limite;
	protected ArrayList<Movimentacao> array;
	
	public ContaCorrente () {
		this.idcontacorrente=null;
		this.array = new ArrayList<Movimentacao>();
	}

	public Integer getIdcontacorrente() {
		return idcontacorrente;
	}

	public void setIdcontacorrente(Integer idcontacorrente) {
		this.idcontacorrente = idcontacorrente;
	}

	public Integer getNumero() {
		return numero;
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	public Double getSaldo() {
		return saldo;
	}

	public void setSaldo(Double saldo) {
		this.saldo = saldo;
	}

	public Boolean getEspecial() {
		return especial;
	}

	public void setEspecial(Boolean especial) {
		this.especial = especial;
	}

	public Integer getLimite() {
		return limite;
	}

	public void setLimite(Integer limite) {
		this.limite = limite;
	}

	
	public ArrayList<Movimentacao> getArray() {
		return array;
	}

	public void setArray(ArrayList<Movimentacao> array) {
		this.array = array;
	}
	
	public void saque (Double valor) throws Exception {
		Double tmp = this.saldo-valor;
		if (this.especial) {
			if (tmp+limite<0) {
				throw new Exception("Valor insuficiente para saque!");
			}
			
		} else {
			if (tmp<0) {
				throw new Exception("Valor insuficiente para saque!");
			}
		}
		this.saldo=tmp;
		Movimentacao m   = new Movimentacao();
		m.idconta        = this.idcontacorrente;
		m.idmovimentacao = array.size();
		m.descricao      = "SAQUE";
		m.tipo           = Tipo.DEBITO;
		m.valor          = valor;
		this.array.add(m);	
	}
	
	public void deposita (Double valor)  {
		this.saldo+=valor;
		
		Movimentacao m   = new Movimentacao();
		m.idconta        = this.idcontacorrente;
		m.idmovimentacao = array.size();
		m.descricao      = "DEPÓSITO";
		m.tipo           = Tipo.CREDITO;
		m.valor          = valor;
		this.array.add(m);	
	}
	
	@Override
	public String toString() {
		String s= "Saldo: " + saldo + "\n";
		for (Movimentacao movimentacao : array) {
			s += movimentacao.toString()+"\n";
		}
		return s;
	}
	
	
	public static void main(String[] args)  {
		ContaCorrente conta = new ContaCorrente();
		conta.setIdcontacorrente(1);
		conta.setNumero(1968);
		conta.setLimite(1000);
		conta.setEspecial(true);
		conta.setSaldo(1000.00);
		for (int i=1; i<6; i++) 
		try {
			if (i%2==0) {
			  conta.saque(i*1000.00);
			} else {
			  conta.deposita(500.00+i);
			}
			System.out.println(conta);
			
		} catch (Exception e) {
			System.err.println(e.getMessage());
			// TODO Auto-generated catch block
			e.printStackTrace();

		}
		
	}

}