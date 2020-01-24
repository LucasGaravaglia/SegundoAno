package arvore;

public class ArvoreBinaria implements 
Comparable<Integer> {

	private Integer i;
	private ArvoreBinaria esq=null;
	private ArvoreBinaria dir=null;

	public ArvoreBinaria( Integer i ) {
		this.i = i;
	}

	public ArvoreBinaria( Integer i, ArvoreBinaria esq, 
			ArvoreBinaria dir ) {
		this.i = i;
		this.esq = esq;
		this.dir = dir;
	}

	public static ArvoreBinaria add ( ArvoreBinaria 
			raiz, Integer i ) {
		if (raiz==null) {
			raiz = new ArvoreBinaria(i);
		} else {
			if (raiz.compareTo(i)>0) {
				raiz.esq = add ( raiz.esq, i);
			} else {
				raiz.dir = add ( raiz.dir, i);			
			}
		}
		return raiz;
	}
	
	public void add ( Integer i ) {
	   if (this.compareTo(i)>0) {
			if (this.esq==null)
				this.esq = new ArvoreBinaria(i);
			else
				this.esq.add(i);
	   } else {
			if (this.dir==null)
				this.dir = new ArvoreBinaria(i);
			else
				this.dir.add(i);
	   }	
	}

	@Override
	public int compareTo(Integer i) {
		if (this.i>i) return 1;
		if (this.i<i) return -1;
		return 0;
	}
	
	@Override
	public String toString() {
		String ret="";
		if (this.esq!=null) {
			ret = this.esq.toString();
		}
		ret += " " + i + " ";
		if (this.dir!=null) {
			ret += this.dir.toString();
		}
		return ret;			
	}
	
	public static void main(String[] args) {
		ArvoreBinaria ab=null;
		ab = ArvoreBinaria.add(ab, 7);
		ab.add(10);
		ab = ArvoreBinaria.add(ab, 8);
		ab = ArvoreBinaria.add(ab, 2);
		ab = ArvoreBinaria.add(ab, 3);
		ab = ArvoreBinaria.add(ab, 7);
		System.out.println(ab);
	}


}
