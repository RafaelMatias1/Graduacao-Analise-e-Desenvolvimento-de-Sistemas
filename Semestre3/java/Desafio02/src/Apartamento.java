// Classe Apartamento
public class Apartamento extends Imovel {
    private int andar;
    private double valorCondominio;
    private double fundoReserva;
    private double investimentos;
    
    public Apartamento(String endereco, double valorAluguel, String descricao, int andar, 
                      double valorCondominio, double fundoReserva, double investimentos) {
        super(endereco, valorAluguel, descricao);
        this.andar = andar;
        this.valorCondominio = valorCondominio;
        this.fundoReserva = fundoReserva;
        this.investimentos = investimentos;
    }
    
    @Override
    public double calcularAluguel() {
        // Para apartamento: (valor do aluguel + valor do condomínio) - (fundo de reserva + investimentos)
        return (this.valorAluguel + this.valorCondominio) - (this.fundoReserva + this.investimentos);
    }
    
    // Getters e Setters
    public int getAndar() {
        return andar;
    }
    
    public void setAndar(int andar) {
        this.andar = andar;
    }
    
    public double getValorCondominio() {
        return valorCondominio;
    }
    
    public void setValorCondominio(double valorCondominio) {
        this.valorCondominio = valorCondominio;
    }
    
    public double getFundoReserva() {
        return fundoReserva;
    }
    
    public void setFundoReserva(double fundoReserva) {
        this.fundoReserva = fundoReserva;
    }
    
    public double getInvestimentos() {
        return investimentos;
    }
    
    public void setInvestimentos(double investimentos) {
        this.investimentos = investimentos;
    }
}