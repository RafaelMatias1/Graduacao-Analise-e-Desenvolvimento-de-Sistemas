// Classe principal para testar o sistema
public class SistemaImobiliaria {
    public static void main(String[] args) {
        // Criando objetos para teste
        Proprietario proprietario = new Proprietario("João Silva", "123.456.789-00", "(11) 99999-9999", "joao@email.com");
        Corretor corretor = new Corretor("Maria Santos", "987.654.321-00", "(11) 88888-8888", "maria@email.com", 5.0);
        Locatario locatario = new Locatario("Pedro Oliveira", "111.222.333-44", "(11) 77777-7777", "pedro@email.com");
        
        // Criando uma casa
        Casa casa = new Casa("Rua das Flores, 123", 2000.0, "Casa com 3 quartos", 3, true);
        
        // Criando um apartamento
        Apartamento apartamento = new Apartamento("Av. Principal, 456", 1800.0, "Apartamento 2 quartos", 5, 300.0, 50.0, 100.0);
        
        // Criando locações
        Locacao locacaoCasa = new Locacao(locatario, proprietario, corretor, casa, "01/01/2024", "31/12/2024");
        Locacao locacaoApartamento = new Locacao(locatario, proprietario, corretor, apartamento, "01/01/2024", "31/12/2024");
        
        // Testando o sistema
        System.out.println("=== TESTE CASA ===");
        System.out.println("Valor do aluguel da casa: R$" + String.format("%.2f", casa.calcularAluguel()));
        locacaoCasa.enviarCobranca();
        locacaoCasa.pagarProprietario();
        
        System.out.println("\n=== TESTE APARTAMENTO ===");
        System.out.println("Valor do aluguel do apartamento: R$" + String.format("%.2f", apartamento.calcularAluguel()));
        locacaoApartamento.enviarCobranca();
        locacaoApartamento.pagarProprietario();
        
        System.out.println("\n=== TESTE SAQUE COMISSÃO ===");
        System.out.println("Comissão acumulada antes do saque: R$" + String.format("%.2f", corretor.getTotalComissaoAcumulada()));
        corretor.sacarComissao(50.0);
        System.out.println("Comissão acumulada após saque de R$50,00: R$" + String.format("%.2f", corretor.getTotalComissaoAcumulada()));
    }
}