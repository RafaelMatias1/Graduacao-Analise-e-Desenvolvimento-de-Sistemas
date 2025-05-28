public class Matricula {
    private String nomeAluno;
    private String nomeDisciplina;
    private double primeiraNota;
    private double segundaNota;
    private double terceiraNota;

    public Matricula(String nomeAluno, String nomeDisciplina) {
        this.nomeAluno = nomeAluno;
        this.nomeDisciplina = nomeDisciplina;
        this.primeiraNota = 0.0;
        this.segundaNota = 0.0;
        this.terceiraNota = 0.0;
    }

    public String getNomeAluno() {
        return nomeAluno;
    }

    public String getNomeDisciplina() {
        return nomeDisciplina;
    }

    public double getPrimeiraNota() {
        return primeiraNota;
    }

    public double getSegundaNota() {
        return segundaNota;
    }

    public double getTerceiraNota() {
        return terceiraNota;
    }

    public void setNomeAluno(String nomeAluno) {
        this.nomeAluno = nomeAluno;
    }

    public void setNomeDisciplina(String nomeDisciplina) {
        this.nomeDisciplina = nomeDisciplina;
    }

    public void setPrimeiraNota(double primeiraNota) {
        if (primeiraNota < 0) {
            this.primeiraNota = 0.0;
        } else if (primeiraNota > 10) {
            this.primeiraNota = 10.0;
        } else {
            this.primeiraNota = primeiraNota;
        }
    }

    public void setSegundaNota(double segundaNota) {
        if (segundaNota < 0) {
            this.segundaNota = 0.0;
        } else if (segundaNota > 10) {
            this.segundaNota = 10.0;
        } else {
            this.segundaNota = segundaNota;
        }
    }

    public void setTerceiraNota(double terceiraNota) {
        if (terceiraNota < 0) {
            this.terceiraNota = 0.0;
        } else if (terceiraNota > 10) {
            this.terceiraNota = 10.0;
        } else {
            this.terceiraNota = terceiraNota;
        }
    }

    public double calcularMediaSimples() {
        return (primeiraNota + segundaNota + terceiraNota) / 3.0;
    }

    public double calcularMediaPonderada(double peso1, double peso2, double peso3) {
        double somaNotas = (primeiraNota * peso1) + (segundaNota * peso2) + (terceiraNota * peso3);
        double somaPesos = peso1 + peso2 + peso3;
        return somaNotas / somaPesos;
    }

    public void imprimirInformacoes() {
        System.out.println("Nome do Aluno: " + nomeAluno);
        System.out.println("Nome da Disciplina: " + nomeDisciplina);
        System.out.println("Média Final (Simples): " + String.format("%.2f", calcularMediaSimples()));
    }

    public void imprimirInformacoesPonderada(double peso1, double peso2, double peso3) {
        System.out.println("Nome do Aluno: " + nomeAluno);
        System.out.println("Nome da Disciplina: " + nomeDisciplina);
        System.out.println("Média Final (Ponderada): " + String.format("%.2f", calcularMediaPonderada(peso1, peso2, peso3)));
    }
}
