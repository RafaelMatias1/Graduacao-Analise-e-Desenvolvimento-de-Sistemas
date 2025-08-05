#include "pessoa.h"
#include "estrutura.h"
#include <stdio.h>
#include <string.h>


int main() {
    char nomes[50][50] = {"Amarilis", "Amelia", "Alberto", "Andre", "Berenice", "Carlos", "Cesar", "Claudia", "Cristina", "Carmem", "Cleonice", "Davi", "Dirce", "Edesio", "Emerson", "Elvira", "Eliane", "Erico", "Fabio", "Flavio", "Fernando", "Fabiana", "Giovana", "Glades", "Gregorio", "Gerson", "Hamilton", "Helio", "Humberto", "Inacio", "Iolanda", "Iracema", "Jose", "Julio", "Kleber", "Luciana", "Laura", "Livia", "Lorena", "Marcelo", "Miriam", "Matilde", "Nadir", "Osvaldo", "Pedro", "Paulo", "Patricia", "Roberto Carlos Braga de OLiveira Silva Santos", "Sergio Abreu de Souza Alegrete Consergente da Luz", "Vitoria lima do Almeida Franco e Albuquerque"};
    char bairros[50][40] = {"Centro", "Trindade", "Caiera da Barra do Sul", "Pantano do Sul", "Itacorubi", "Saco Grande", "Vargem Pequena", "Ingleses", "Canasvieiras", "Jurere", "Campeche", "Canto", "Balneario", "Estreito", "Saco dos Limoes", "Serrinha", "Lagoa da Conceicao", "Rio Tavares", "Costeira", "Santinho", "Rio Vermelho", "Lagoinha da Ponta das Canas", "Cachoeira do Bom Jesus", "Cacupe", "Ribeirao da Ilha", "Centro", "Trindade", "Caiera da Barra do Sul", "Pantano do Sul", "Itacorubi", "Saco Grande", "Vargem Pequena", "Ingleses", "Canasvieiras", "Jurere", "Campeche", "Canto", "Balneario", "Estreito", "Saco dos Limoes", "Serrinha", "Lagoa da Conceicao", "Rio Tavares", "Costeira", "Santinho", "Rio Vermelho", "Lagoinha da Ponta das Canas", "Cachoeira do Bom Jesus", "Cacupe", "Ribeirao da Ilha"}; 
    double valores[50] = {300.0, 520.0, 498.0, 1545.5, 1247.2, 5450.9, 1450.3, 2120.0, 3120.9, 800.0, 240.0, 1140.7, 1000.75, 430.0, 760.0, 9500.0, 506.8, 624.9, 120.0, 500.0, 316.0, 283.9, 890.0, 721.9, 220.0, 184.5, 1780.8, 2900.0, 1890.0, 220.8, 3000.0, 2376.9, 4560.0, 7680.0, 3150.0, 2376.0, 678.0, 730.0, 454.0, 975.0, 295.0, 450.0, 676.7, 800.0, 560.0, 498.0, 1698.0, 3978.0, 987.0, 4890.0};

    int i;
    Estrutura* estrutura_nome = cria_estrutura(50);
    Estrutura* estrutura_valor = cria_estrutura(3); 
    for(i = 0; i < 50; i++) {
        Pessoa *p = create_pessoa(i + 1, nomes[i], bairros[i], valores[i]);
        inserir(estrutura_nome, p);
        inserir(estrutura_valor, p);
    }
    int quantidade;
    Pessoa** pessoa = consultar_por_nome(estrutura_nome, "Dirce", &quantidade);
    if(quantidade > 1) {
        perror("Falha na recuperacao do filtro de nome");
    } else {
        if(obtem_identificador(pessoa[0]) != 13) perror("Item inserido incorretamente");
        if(strcmp(obtem_nome(pessoa[0]), "Dirce")) perror("Item inserido incorretamente");
        if(strcmp(obtem_bairro(pessoa[0]), "Balneario")) perror("Item inserido incorretamente");
        if(obtem_media(pessoa[0]) != 1000.75) perror("Item inserido incorretamente");        
    }
    free(pessoa);
    
    Pessoa** pessoas_faixa1 = consultar_por_faixa(estrutura_valor, 1, &quantidade);
    if(quantidade != 15) perror("Erro na consulta pela faixa 1");
    free(pessoas_faixa1);
    
    Pessoa** pessoas_faixa2 = consultar_por_faixa(estrutura_valor, 2, &quantidade);
    if(quantidade != 14) perror("Erro na consulta pela faixa 2");
    free(pessoas_faixa2);
    
    Pessoa** pessoas_faixa3 = consultar_por_faixa(estrutura_valor, 3, &quantidade);
    if(quantidade != 21) perror("Erro na consulta pela faixa 3");
    free(pessoas_faixa3);
    libera_estrutura(estrutura_nome);
    libera_estrutura(estrutura_valor);
}