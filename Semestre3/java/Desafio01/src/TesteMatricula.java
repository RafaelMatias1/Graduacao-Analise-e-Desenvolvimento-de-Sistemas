import java.util.Scanner;

public class TesteMatricula {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Entrada dos dados
        System.out.print("Digite o nome do aluno: ");
        String nomeAluno = sc.nextLine();

        System.out.print("Digite o nome da disciplina: ");
        String nomeDisciplina = sc.nextLine();

        Matricula m = new Matricula(nomeAluno, nomeDisciplina);

        System.out.print("Digite a primeira nota: ");
        double nota1 = sc.nextDouble();
        m.setPrimeiraNota(nota1);

        System.out.print("Digite a segunda nota: ");
        double nota2 = sc.nextDouble();
        m.setSegundaNota(nota2);

        System.out.print("Digite a terceira nota: ");
        double nota3 = sc.nextDouble();
        m.setTerceiraNota(nota3);

        // Impressão dos resultados
        System.out.println();
        m.imprimirInformacoes();

        System.out.println();
        System.out.println("Agora, vamos calcular a média ponderada.");
        System.out.print("Digite o peso da primeira nota: ");
        double peso1 = sc.nextDouble();

        System.out.print("Digite o peso da segunda nota: ");
        double peso2 = sc.nextDouble();

        System.out.print("Digite o peso da terceira nota: ");
        double peso3 = sc.nextDouble();

        System.out.println();
        m.imprimirInformacoesPonderada(peso1, peso2, peso3);

        sc.close();
    }
}
