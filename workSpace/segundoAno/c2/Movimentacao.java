package model;

public class Movimentacao {
	
	public enum Tipo {CREDITO,DEBITO};
	
	protected Integer idmovimentacao;
	protected Integer idconta;
	protected String  descricao;
	protected Tipo    tipo;
	protected Double  valor;
	
	public Movimentacao () {
		this.idmovimentacao = null;
	}

	public Integer getIdmovimentacao() {
		return idmovimentacao;
	}

	public void setIdmovimentacao(Integer idmovimentacao) {
		this.idmovimentacao = idmovimentacao;
	}

	public Integer getIdconta() {
		return idconta;
	}

	public void setIdconta(Integer idconta) {
		this.idconta = idconta;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public Tipo getTipo() {
		return tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}
	
	public Double getValor() {
		return valor;
	}

	public void setValor(Double valor) {
		this.valor = valor;
	}
	
	@Override
	public String toString() {
		return this.descricao +
				"\t" +
				this.tipo +
				"\t" +
				this.valor;
	}	

}
