// Classe abstrata Imóvel
public abstract class Imovel {
    protected String endereco;
    protected double valorAluguel;
    protected String descricao;
    
    public Imovel(String endereco, double valorAluguel, String descricao) {
        this.endereco = endereco;
        this.valorAluguel = valorAluguel;
        this.descricao = descricao;
    }
    
    // Método abstrato que deve ser implementado pelas subclasses
    public abstract double calcularAluguel();
    
    // Getters e Setters
    public String getEndereco() {
        return endereco;
    }
    
    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
    public double getValorAluguel() {
        return valorAluguel;
    }
    
    public void setValorAluguel(double valorAluguel) {
        this.valorAluguel = valorAluguel;
    }
    
    public String getDescricao() {
        return descricao;
    }
    
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
}