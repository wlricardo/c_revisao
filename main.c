#include <stdio.h>
#include <stdlib.h>

#define SECRET_NUMBER 42

// FUNÇÕES AUXILIARES
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*
 *
 * FUNÇÕES PARA O JOGO
 * 
*/ 

// Função para exibir a mensagem de boas-vindas
void welcome() {
    printf("*********************************************\n");
    printf("*   Welcome to My Guessing Number Game !   *\n");
    printf("*********************************************\n");
}

// Função para comparar o palpite com o número secreto
void compare(int guess) {
    if (guess < SECRET_NUMBER) {
        printf("Your guess is too low!\n");
    } else if (guess > SECRET_NUMBER) {
        printf("Your guess is too high!\n");
    }
}

// Função para comparar o palpite com o número secreto
void result(int number) {
    if (number == SECRET_NUMBER) {
        printf("\nCongratulations! You've guessed the number!\n");
    } else {
        printf("\nSorry, that's not correct. Try again!\n");
        compare(number);
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    clear_screen();
    welcome();

    int guess;
    
    do {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
    } while (guess < 1 || guess > 100);      // Verifica se o palpite está fora do intervalo ou se está incorreto
    
    result(guess);
    return 0;
}
