#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define tamanho_tabuleiro 10
#define tamanho_navio 3
#define tamanho_skill 5 // adição mestre: define o tamanho da matriz de habilidade

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
        }
    } else {
        printf("Erro o navio vertical sai dos limites do tabuleiro!\n\n");
}

// começa o nivel aventureiro

printf("\n--- Nível Aventureiro ---\n");

// navio na diagonal

int navio_d1_linha = 5;
int navio_d1_coluna = 1;
printf("Posicionando navio diagonal 1 (baixo-direita)...\n");

// validar limites (Diagonal);
// Precisa checar se a LINHA + TAMANHO e a COLUNA + TAMANHO estão no tabuleiro
int d1_cabe = 1; // 1 = sim, 0 = não
if (navio_d1_linha + tamanho_navio > tamanho_tabuleiro || navio_d1_coluna + tamanho_navio > tamanho_tabuleiro){
    d1_cabe = 0;
    printf("Erro: Navio diagonal 1 sai dos limites!\n\n");  
}

// Se couber, prossiga para a sobreposição
if (d1_cabe == 1) {
    // validar sobreposição
    int sobreposicao_d1 = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        // lógica da diagonal: checa [linha+i][coluna+i]
        if (tabuleiro[navio_d1_linha + i][navio_d1_coluna + i] != 0) {
            sobreposicao_d1 = 1;
            break;
        }
    }

    // Posicionar (Diagonal):
    if (sobreposicao_d1 == 0) {
        for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[navio_d1_linha + i][navio_d1_coluna + i] = 3;
    }
    printf("Navio diagonal 1 posicionado com sucesso.\n\n");
} else {
    printf("Erro: Navio diagonal 1 se sobrepõe a outro!\n\n");
    }
}

// adicional o navio diagonal 2 (Baixo-Esquerda)
int navio_d2_linha = 6;
int navio_d2_coluna = 8;
printf("Posicionando navio diagonal 2 (baixo-esquerda)...\n");

// Validar limites (Diagonal Oposta):
// checa LINHA + TAMANHO (para baixo) e COLUNA - TAMANHO (para esquerda)
int d2_cabe = 1;
if (navio_d2_linha + tamanho_navio > tamanho_tabuleiro || navio_d2_coluna - (tamanho_navio - 1) < 0) {
    d2_cabe = 0;
    printf("Erro: Navio diagonal 2 sai dos limites!\n\n");
}

// Se couber, prossiga para a sobreposição
if(d2_cabe == 1) {
    // validar sobreposição (Diagonal Oposta):
    int sobreposicao_d2 = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        // lógica da diagonal oposta: checa [Linha+i][coluna-i]
        if (tabuleiro[navio_d2_linha + i][navio_d2_coluna - i] != 0) {
            sobreposicao_d2 = 1;
            break;
        }
    }

// posicionar (Diagonal Oposta):
if (sobreposicao_d2 == 0) {
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[navio_d2_linha + i][navio_d2_coluna - i] =3;
    }
    printf("Navio diagonal 2 posicionado com sucesso.\n\n");
} else {
    printf("Erro: Navio diagonal 2 se sobrepõe a outro!\n\n");
    }
}

//nivel mestre
printf("\n--- Nível Mestre ---\n");
printf("Criando e aplicando habilidades especiais...\n\n");

// criar matrizes de habilidades (5x5)
int skill_cone[tamanho_skill][tamanho_skil] = {0};
int skill_cruz[tamanho_skill][tamanho_skill] = {0};
int skill_octaedro[tamanho_skill][tamanho_skill] = {0};

// centro da matriz 5x5 é o indice 2
int centro_skill = tamanho_skill / 2; // 5 / 2 = 2

/*
 criando habilidade cone (centrada, apontando para baixo)
i = 0 -> linha central (ponto do cone)
i = 1 -> linha abaixo, expande 1 para cada lado
i = 2 -> linha abaixo, expande 2 para cada lado
*/
for (int i = 0; i < 3; i++) {// i é o offset da linha a partir do centro
    for (int j = centro_skill - i; j <= centro_skill = i; j++) {
        // valida os limites da matriz de skill (5x5)
        if (centro_skill + i < tamanho_skill && j >= 0 && j < tamanho_skill) {
            skill_cone[centro_skill + i][j] = 1;
            
        }
    }

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
}
