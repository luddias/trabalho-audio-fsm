#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarArquivo(FILE *arquivo, int tamanho, unsigned char (*modo)(void)) {
    for (int i = 0; i < tamanho; i++) {
        unsigned char num = modo();
        fwrite(&num, sizeof(unsigned char), 1, arquivo);
    }
}

unsigned char aleatorioCompleto(void) {
    return rand() % 256;
}

unsigned char aleatorioRestrito(void) {
    return rand() % 26;
}

unsigned char naoAleatorio(void) {
    static int contador = 0;
    return contador++ % 26;
}

int main() {
    int tamanho = 10 * 1024 * 1024; // 10 MB
    srand(time(NULL));

    FILE *arquivo1 = fopen("aleatorio.bin", "wb");
    gerarArquivo(arquivo1, tamanho, aleatorioCompleto);
    fclose(arquivo1);

    FILE *arquivo2 = fopen("aleatorio_restrito.bin", "wb");
    gerarArquivo(arquivo2, tamanho, aleatorioRestrito);
    fclose(arquivo2);

    FILE *arquivo3 = fopen("nao_aleatorio.bin", "wb");
    gerarArquivo(arquivo3, tamanho, naoAleatorio);
    fclose(arquivo3);

    return 0;
}
