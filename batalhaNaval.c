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
int skill_cone[tamanho_skill][tamanho_skill] = {0};
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
    for (int j = centro_skill - i; j <= centro_skill + i; j++) {
        // valida os limites da matriz de skill (5x5)
        if (centro_skill + i < tamanho_skill && j >= 0 && j < tamanho_skill) {
            skill_cone[centro_skill + i][j] = 1;
            
        }
    }

}

// cria a habilidade Cruz (centrada)
for (int i = 0; i < tamanho_skill; i++) {
    skill_cruz[centro_skill][i] = 1; //linha horizontal
    skill_cruz[i][centro_skill] = 1; // linha vertical

}

// cria a habilidade Octaedro (Losango)
// usa a distancia de manhattan 
int raio_octaedro = 2; // Raio 2 em uma matriz 5x5
for (int i = 0; i < tamanho_skill; i++) {
    for (int j = 0; j < tamanho_skill; j++) {
        // calcula o valor absoluto da distância de i,j até o centro,centro
        int dist_i = (i > centro_skill) ? (i - centro_skill) : (centro_skill - i);
        int dist_j = (j > centro_skill) ? (j - centro_skill) : (centro_skill - j);

        if (dist_i + dist_j <= raio_octaedro) {
            skill_octaedro[i][j] = 1;
        }
    }
}

// defini pontos de origem do tabuleiro 10x10
// onde o centro [2][2] da matriz de skill vai acertar
int cone_origem_linha = 2;
int cone_origem_coluna = 7;

int cruz_origem_linha = 7;
int cruz_origem_coluna = 2;

int octaedro_origem_linha = 7;
int octaedro_origem_coluna = 7;

// aplicar sobrepor as habilidades no tabuleiro
// valor 5 representa a área de efeito

// aplicando o cone
for (int i = 0; i < tamanho_skill; i++) {
    for (int j = 0; j < tamanho_skill; j++) {
    // se o ponto i,j na matriz de skill for 1 (afetado)
        if (skill_cone[i][j] == 1) {
            // calculamos a coordenada correspondente no tabuleiro
            // (i - centro_skill)
            int target_linha = cone_origem_linha + (i - centro_skill);
            int target_coluna = cone_origem_coluna + (j - centro_skill);

            // validamos se essa coordenada está dentro do tabuleiro 10x10
            if (target_linha >= 0 && target_linha < tamanho_tabuleiro &&
                target_coluna >= 0 && target_coluna < tamanho_tabuleiro) {

                        //marcamos o tabuleiro com 5
                    tabuleiro[target_linha][target_coluna] = 5;
                }
            }
        }
    }

for (int i = 0; i < tamanho_skill; i++) {
    for (int j = 0; j < tamanho_skill; j++) {
    // se o ponto i,j na matriz de skill for 1 (afetado)
        if (skill_cruz[i][j] == 1) {
            // calculamos a coordenada correspondente no tabuleiro
            // (i - centro_skill)
            int target_linha = cruz_origem_linha + (i - centro_skill);
            int target_coluna = cruz_origem_coluna + (j - centro_skill);

            // validamos se essa coordenada está dentro do tabuleiro 10x10
            if (target_linha >= 0 && target_linha < tamanho_tabuleiro &&
                target_coluna >= 0 && target_coluna < tamanho_tabuleiro) {

                    //marcamos o tabuleiro com 5
                    tabuleiro[target_linha][target_coluna] = 5;
                }
            }
        }
    }


            
// aplicando octaedro mesma lógica overlay
for (int i = 0; i < tamanho_skill; i++) {
    for (int j = 0; j < tamanho_skill; j++) {
    // se o ponto i,j na matriz de skill for 1 (afetado)
        if (skill_octaedro[i][j] == 1) {
            // calculamos a coordenada correspondente no tabuleiro
            // (i - centro_skill)
            int target_linha = octaedro_origem_linha + (i - centro_skill);
            int target_coluna = octaedro_origem_coluna + (j - centro_skill);

            // validamos se essa coordenada está dentro do tabuleiro 10x10
            if (target_linha >= 0 && target_linha < tamanho_tabuleiro &&
                target_coluna >= 0 && target_coluna < tamanho_tabuleiro) {

                    //marcamos o tabuleiro com 5
                    tabuleiro[target_linha][target_coluna] = 5;
               }
            }
        }
    }

    printf("Habilidades aplicadas!\n\n");
            
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
