// Classe Casa
public class Casa extends Imovel {
    private int numeroQuartos;
    private boolean temGaragem;
    
    public Casa(String endereco, double valorAluguel, String descricao, int numeroQuartos, boolean temGaragem) {
        super(endereco, valorAluguel, descricao);
        this.numeroQuartos = numeroQuartos;
        this.temGaragem = temGaragem;
    }
    
    @Override
    public double calcularAluguel() {
        // Para casa, o aluguel é apenas o valor definido no imóvel
        return this.valorAluguel;
    }
    
    // Getters e Setters
    public int getNumeroQuartos() {
        return numeroQuartos;
    }
    
    public void setNumeroQuartos(int numeroQuartos) {
        this.numeroQuartos = numeroQuartos;
    }
    
    public boolean isTemGaragem() {
        return temGaragem;
    }
    
    public void setTemGaragem(boolean temGaragem) {
        this.temGaragem = temGaragem;
    }
}