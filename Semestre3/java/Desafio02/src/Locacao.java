// Classe Locação
public class Locacao {
    private Locatario locatario;
    private Proprietario proprietario;
    private Corretor corretor;
    private Imovel imovel;
    private String dataInicio;
    private String dataFim;
    
    public Locacao(Locatario locatario, Proprietario proprietario, Corretor corretor, 
                   Imovel imovel, String dataInicio, String dataFim) {
        this.locatario = locatario;
        this.proprietario = proprietario;
        this.corretor = corretor;
        this.imovel = imovel;
        this.dataInicio = dataInicio;
        this.dataFim = dataFim;
    }
    
    public void enviarCobranca() {
        double valorAluguel = imovel.calcularAluguel();
        System.out.println("E-mail: " + locatario.getEmail());
        System.out.println("O valor referente ao seu aluguel neste mês foi de R$" + String.format("%.2f", valorAluguel) + ".");
    }
    
    public void pagarProprietario() {
        double valorAluguel = imovel.calcularAluguel();
        double comissao = valorAluguel * (corretor.getPercentualComissao() / 100);
        double valorLiquidoProprietario = valorAluguel - comissao;
        
        // Chama o método receber() do proprietário
        proprietario.receber(valorLiquidoProprietario);
        
        // Chama o método receber() do corretor
        corretor.receber(comissao);
    }
    
    // Getters e Setters
    public Locatario getLocatario() {
        return locatario;
    }
    
    public void setLocatario(Locatario locatario) {
        this.locatario = locatario;
    }
    
    public Proprietario getProprietario() {
        return proprietario;
    }
    
    public void setProprietario(Proprietario proprietario) {
        this.proprietario = proprietario;
    }
    
    public Corretor getCorretor() {
        return corretor;
    }
    
    public void setCorretor(Corretor corretor) {
        this.corretor = corretor;
    }
    
    public Imovel getImovel() {
        return imovel;
    }
    
    public void setImovel(Imovel imovel) {
        this.imovel = imovel;
    }
    
    public String getDataInicio() {
        return dataInicio;
    }
    
    public void setDataInicio(String dataInicio) {
        this.dataInicio = dataInicio;
    }
    
    public String getDataFim() {
        return dataFim;
    }
    
    public void setDataFim(String dataFim) {
        this.dataFim = dataFim;
    }
}