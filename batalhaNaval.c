#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define tamanho_tabuleiro 10
#define tamanho_navio 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    // declaração da matriz 10 x 10 para o tabuleiro

    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];

    // Documentação: inicialização do tabuleiro

    printf("Inicializando o tabuleiro 10x10 com água (0)...\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    printf("Tabuleiro inicializado.\n\n");

    // posione os navios
    // horizontal
    int navio_h_linha = 1;
    int navio_h_coluna = 1;

    // coordenadas para o navio vertical
    int navio_v_linha = 3;
    int navio_v_coluna = 4;
    
    // posicionamento do navio horizontal
    if (navio_h_coluna + tamanho_navio <= tamanho_tabuleiro) {
        // o navio cabe. posiciona o navio no tabuleiro.
        for (int i = 0; i < tamanho_navio; i++) {
            // representa o vaio com o numero 3
            tabuleiro[navio_h_linha][navio_h_coluna + i] = 3;

        }
        printf("Navio horizontal posicionado com sucesso. \n\n");

    } else {
        printf("Erro: o navio horizontal sai dos limetes do tabuleiro!\n\n");
    }
    // posicionando o navio vertical
    if (navio_v_linha + tamanho_navio <= tamanho_tabuleiro) {
        // o navio está dentro dos limetes verticais.
        int sobreposicao = 0; // Flag para indicar se há sobreposição (0 = não, 1 = sim)
    
        // requesitos funcionais os navios não se sobreponham
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[navio_v_linha + i][navio_v_coluna] != 0) {
                sobreposicao = 1; // marca que há sobreposiçãi
                break; // sai do loop, pois encontramos um erro 
            }
        }
    // se não houver sobreposição, posiciona o navio
    if (sobreposicao == 0) {
        for (int i = 0; i < tamanho_navio; i++){
            //representa o navio com o numero 3
            tabuleiro[navio_v_linha + i][navio_v_coluna] = 3;

        }
        printf("Navio vertical posicionado com sucesso. \n\n");

    } else {
        printf("Erro: O navio vertical se sobrepõe a outro navio! \n\n");
   
    } else {
    printf("Erro o navio vertical sai dos limites do tabuleiro!\n\n");
}


// exiba o tabuleiro

printf("--- TABULEIRO FINAL DE BATALHA NAVAL ---\n\n");
for (int i = 0; i < tamanho_tabuleiro; i++) {
    for (int j = 0; j < tamanho_tabuleiro; j++) {
        printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
}

return 0;

   

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
