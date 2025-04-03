#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio no tabuleiro
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if ((orientacao == 'H' && coluna + tamanho > TAMANHO) || (orientacao == 'V' && linha + tamanho > TAMANHO)) {
        return 0; // Falha no posicionamento
    }

    // Verifica se as posições estão livres
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H' && tabuleiro[linha][coluna + i] != 0) {
            return 0; // Espaço ocupado
        } else if (orientacao == 'V' && tabuleiro[linha + i][coluna] != 0) {
            return 0; // Espaço ocupado
        }
    }

    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    
    return 1; // Sucesso
}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("  ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição das coordenadas dos navios (fixo no código)
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical
    
    // Posicionando os navios
    if (!posicionarNavio(tabuleiro, linhaH, colunaH, NAVIO, 'H')) {
        printf("Falha ao posicionar o navio horizontal!\n");
    }
    if (!posicionarNavio(tabuleiro, linhaV, colunaV, NAVIO, 'V')) {
        printf("Falha ao posicionar o navio vertical!\n");
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}