#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contaCaminhos(int i, int j, int somaAtual, int n, int matriz[10][10]){
    if(i >= 10 || j >= 10) return 0;

    somaAtual += matriz[i][j];

    if(i == 9 && j == 9){
        return (somaAtual == n) ? 1 : 0;
    }

    return contaCaminhos(i+1, j, somaAtual, n, matriz) + contaCaminhos(i, j+1, somaAtual, n, matriz);
}

int main(){
    int i, j, matriz[10][10], n;
    srand(time(NULL));
    
    // Preenchendo a matriz com valores aleatórios de 0 a 10
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++)
            matriz[i][j] = rand() % 11;
    }

    // Imprimindo a matriz com a formatação desejada
    printf("Matriz gerada:\n");
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("%02d ", matriz[i][j]);  // Exibe números com 2 dígitos (0 à esquerda se necessário)
        }
        printf("\n");
    }

    // Solicitando ao usuário um valor para n
    printf("Informe um valor menor que 150: ");
    scanf("%d", &n);

    // Chamando a função que conta os caminhos
    int total = contaCaminhos(0, 0, 0, n, matriz);

    // Exibindo o total de caminhos
    printf("Total de caminhos com soma %d: %d\n", n, total);

    return 0;
}
