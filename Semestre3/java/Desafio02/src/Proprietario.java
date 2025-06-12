// Classe Proprietário
public class Proprietario extends Pessoa implements RecebeValor {
    
    public Proprietario(String nome, String cpf, String telefone, String email) {
        super(nome, cpf, telefone, email);
    }
    
    @Override
    public void receber(double valor) {
        System.out.println("O proprietário " + nome + " está recebendo o valor de R$" + String.format("%.2f", valor));
    }
}