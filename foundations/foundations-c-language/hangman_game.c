#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD 128
#define MAX_ATTEMPTS 6
#define ALPHABET 26

typedef struct {
    char secret[MAX_WORD];
    char discovered[MAX_WORD];
    int attempts_left;
    int guessed_letters[ALPHABET];
    size_t length;
} Hangman;

/* ===========================
   Utilitários
=========================== */

int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* ===========================
   Engine
=========================== */

void hangman_init(Hangman *game, const char *word) {
    strncpy(game->secret, word, MAX_WORD - 1);
    game->secret[MAX_WORD - 1] = '\0';

    game->length = strlen(game->secret);
    game->attempts_left = MAX_ATTEMPTS;

    memset(game->guessed_letters, 0, sizeof(game->guessed_letters));

    for (size_t i = 0; i < game->length; i++) {
        if (isalpha(game->secret[i]))
            game->discovered[i] = '-';
        else
            game->discovered[i] = game->secret[i];
    }
    game->discovered[game->length] = '\0';
}

int hangman_guess(Hangman *game, char letter) {
    letter = tolower(letter);

    if (!isalpha(letter))
        return -1;

    int index = letter - 'a';

    if (game->guessed_letters[index])
        return -2;

    game->guessed_letters[index] = 1;

    int found = 0;

    for (size_t i = 0; i < game->length; i++) {
        if (tolower(game->secret[i]) == letter) {
            game->discovered[i] = game->secret[i];
            found = 1;
        }
    }

    if (!found)
        game->attempts_left--;

    return found;
}

int hangman_won(const Hangman *game) {
    return strcmp(game->secret, game->discovered) == 0;
}

int hangman_lost(const Hangman *game) {
    return game->attempts_left <= 0;
}

void hangman_print(const Hangman *game) {
    printf("\nPalavra: %s\n", game->discovered);
    printf("Tentativas restantes: %d\n", game->attempts_left);

    printf("Letras usadas: ");
    for (int i = 0; i < ALPHABET; i++) {
        if (game->guessed_letters[i])
            printf("%c ", 'a' + i);
    }
    printf("\n");
}

/* ===========================
   MAIN
=========================== */

int main(void) {
    Hangman game;
    char word[MAX_WORD];
    char input[32];

    printf("Digite a palavra secreta: ");
    if (!read_line(word, sizeof(word))) {
        fprintf(stderr, "Erro de entrada.\n");
        return EXIT_FAILURE;
    }

    clear_screen();

    hangman_init(&game, word);

    while (!hangman_won(&game) && !hangman_lost(&game)) {
        hangman_print(&game);

        printf("Digite uma letra: ");
        if (!read_line(input, sizeof(input)))
            continue;

        if (strlen(input) != 1) {
            printf("Digite apenas uma letra.\n");
            continue;
        }

        int result = hangman_guess(&game, input[0]);

        if (result == -1)
            printf("Entrada inválida.\n");
        else if (result == -2)
            printf("Letra já utilizada.\n");
        else if (!result)
            printf("Letra incorreta.\n");
        else
            printf("Boa!\n");
    }

    if (hangman_won(&game))
        printf("\nParabéns! Você venceu!\n");
    else
        printf("\nVocê perdeu! A palavra era: %s\n", game.secret);

    return EXIT_SUCCESS;
}