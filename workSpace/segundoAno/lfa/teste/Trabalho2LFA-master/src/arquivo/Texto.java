package arquivo;

public class Texto{
    private String texto;

    //Construtor da classe Texto
    public Texto(){
        this.texto = null;
    }

    //Construtor da classe Texto
    public Texto(String texto){
        this.texto = texto;
    }

    //Getter da variável texto
    public String getTexto() {
        return texto;
    }

    //Setter da variável texto
    public void setTexto(String texto) {
        this.texto = texto;
    }

    /**
     * Método que muda uma string para maiúscula
     * Entrada:      Nenhuma
     * Retorno:      String em maiúscula
     * Pré-condição: A string que vai ser passada para maiúscula deve estar carregada na classe
     * Pós-condição: A string é passada para maiúscula
     */
    public String toUpper(){
        return this.texto.toUpperCase();
    }

    /**
     * Método que muda uma string para minúscula
     * Entrada:      Nenhuma
     * Retorno:      String em minúscula
     * Pré-condição: A string que vai ser passada para minúscula deve estar carregada na classe
     * Pós-condição: A string é passada para minúscula
     */
    public String toLower(){
        return this.texto.toLowerCase();
    }

    /**
     * Método que remove espaços em branco excedentes na string
     * Entrada:      Nenhuma
     * Retorno:      String sem espaços excedentes
     * Pré-condição: A string que vai ser processada deve estar carregada na classe
     * Pós-condição: Os espaços excedentes são removidos
     */
    public String removerEspacosExtras(){
        int i;
        String aux[];
        aux = this.texto.split(" ");
        this.texto = "";
        for(i=0;i<aux.length;i++){
            if(aux[i].length() > 0 && aux[i].toCharArray()[0] != ' '){
                this.texto += aux[i];
                if(i != aux.length-1) this.texto += " ";
            }
        }
        return this.texto;
    }
}