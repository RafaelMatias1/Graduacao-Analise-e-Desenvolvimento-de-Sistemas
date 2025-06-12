// Classe Corretor
public class Corretor extends Pessoa implements RecebeValor {
    private double percentualComissao;
    private double totalComissaoAcumulada;
    
    public Corretor(String nome, String cpf, String telefone, String email, double percentualComissao) {
        super(nome, cpf, telefone, email);
        this.percentualComissao = percentualComissao;
        this.totalComissaoAcumulada = 0.0;
    }
    
    @Override
    public void receber(double valor) {
        System.out.println("O corretor " + nome + " está recebendo o valor de R$" + String.format("%.2f", valor));
        this.totalComissaoAcumulada += valor;
    }
    
    public void sacarComissao(double valor) {
        if (valor <= totalComissaoAcumulada) {
            totalComissaoAcumulada -= valor;
        } else {
            System.out.println("Valor insuficiente para saque.");
        }
    }
    
    // Getters e Setters
    public double getPercentualComissao() {
        return percentualComissao;
    }
    
    public void setPercentualComissao(double percentualComissao) {
        this.percentualComissao = percentualComissao;
    }
    
    public double getTotalComissaoAcumulada() {
        return totalComissaoAcumulada;
    }
    
    public void setTotalComissaoAcumulada(double totalComissaoAcumulada) {
        this.totalComissaoAcumulada = totalComissaoAcumulada;
    }
}