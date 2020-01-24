package arvore;

public class No {
	private Integer info=null;
	private No direita=null;
	private No esquerda=null;
	
	public No(Integer info) {
		this.info = info;
	}
	public void add(Integer info,No raiz) {
		if(raiz == null) {
			raiz = new No(info);
		}
		if(compareTo(info) > 0) {
			raiz.direita.add(info,raiz.esquerda);
		}else if(compareTo(info) < 0) {
			raiz.esquerda.add(info,raiz.esquerda);
		}
	}
	
	private int compareTo(Integer info) {
		if(this.info>info) return -1;
		if(this.info<info) return 1;
		return 0;
	}
	public Integer maior(No raiz) {
		if(raiz.direita == null) return raiz.info;
		return maior(raiz.direita);
	}
	public Integer menor(No raiz) {
		if(raiz.esquerda == null) return raiz.info;
		return menor(raiz.esquerda);
	}
	public No remove(Integer info,No raiz) {
		if(raiz==null) {
			return raiz;
		}
		if(info > raiz.info) {
			return remove(info,raiz.direita);
		}else if(info < raiz.info) {
			return remove(info,raiz.esquerda);
		}else {
			if(raiz.esquerda == null && raiz.direita == null) {
				raiz.info = null;
			}else if(raiz.esquerda == null) {
				raiz.info = menor(raiz.direita);
				raiz.direita = remove(raiz.info,raiz.direita);
			}else {
				raiz.info = maior(raiz.esquerda);
				raiz.esquerda = remove(raiz.info,raiz.esquerda);
			}
			return raiz;
		}	
	}
	
	

}
