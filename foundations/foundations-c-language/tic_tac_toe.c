#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIM 3
#define NAME_SIZE 64
#define EMPTY_CELL ' '

typedef enum {
    PLAYER_X,
    PLAYER_O
} Player;

typedef struct {
    char board[DIM][DIM];
    Player current_player;
    int moves;
} Game;

/* =====================================
   Utilitários
===================================== */

int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int read_move(int *row, int *col) {
    char buffer[64];
    char *end;

    if (!read_line(buffer, sizeof(buffer)))
        return 0;

    errno = 0;
    long r = strtol(buffer, &end, 10);
    if (errno != 0 || end == buffer || *end != ' ')
        return 0;

    long c = strtol(end + 1, &end, 10);
    if (errno != 0 || *end != '\0')
        return 0;

    *row = (int)r;
    *col = (int)c;
    return 1;
}

char player_symbol(Player p) {
    return p == PLAYER_X ? 'X' : 'O';
}

Player switch_player(Player p) {
    return p == PLAYER_X ? PLAYER_O : PLAYER_X;
}

/* =====================================
   Game 
===================================== */

void game_init(Game *g) {
    memset(g->board, EMPTY_CELL, sizeof(g->board));
    g->current_player = PLAYER_X;
    g->moves = 0;
}

int game_make_move(Game *g, int row, int col) {
    if (row < 0 || row >= DIM || col < 0 || col >= DIM)
        return 0;

    if (g->board[row][col] != EMPTY_CELL)
        return 0;

    g->board[row][col] = player_symbol(g->current_player);
    g->moves++;
    return 1;
}

int game_check_victory(const Game *g) {
    char sym = player_symbol(g->current_player);

    /* Linhas e colunas */
    for (int i = 0; i < DIM; i++) {
        int row_win = 1;
        int col_win = 1;

        for (int j = 0; j < DIM; j++) {
            if (g->board[i][j] != sym)
                row_win = 0;

            if (g->board[j][i] != sym)
                col_win = 0;
        }

        if (row_win || col_win)
            return 1;
    }

    /* Diagonal principal */
    int diag1 = 1, diag2 = 1;
    for (int i = 0; i < DIM; i++) {
        if (g->board[i][i] != sym)
            diag1 = 0;

        if (g->board[i][DIM - i - 1] != sym)
            diag2 = 0;
    }

    return diag1 || diag2;
}

int game_is_draw(const Game *g) {
    return g->moves == DIM * DIM;
}

/* =====================================
   UI
===================================== */

void game_print(const Game *g,
                const char *p1,
                const char *p2) {
    printf("\n%s (X) vs %s (O)\n\n", p1, p2);

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf(" %c ", g->board[i][j]);
            if (j < DIM - 1)
                printf("|");
        }
        printf("\n");

        if (i < DIM - 1) {
            for (int k = 0; k < DIM; k++) {
                printf("---");
                if (k < DIM - 1)
                    printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

/* =====================================
   MAIN
===================================== */

int main(void) {
    Game game;
    char player1[NAME_SIZE];
    char player2[NAME_SIZE];

    printf("Jogador 1 (X): ");
    if (!read_line(player1, sizeof(player1)))
        return EXIT_FAILURE;

    printf("Jogador 2 (O): ");
    if (!read_line(player2, sizeof(player2)))
        return EXIT_FAILURE;

    game_init(&game);

    while (1) {
        game_print(&game, player1, player2);

        printf("%s (%c), digite linha e coluna (0-%d 0-%d): ",
               game.current_player == PLAYER_X ? player1 : player2,
               player_symbol(game.current_player),
               DIM - 1, DIM - 1);

        int row, col;

        if (!read_move(&row, &col)) {
            printf("Entrada inválida.\n");
            continue;
        }

        if (!game_make_move(&game, row, col)) {
            printf("Jogada inválida.\n");
            continue;
        }

        if (game_check_victory(&game)) {
            game_print(&game, player1, player2);
            printf("%s venceu!\n",
                   game.current_player == PLAYER_X ? player1 : player2);
            break;
        }

        if (game_is_draw(&game)) {
            game_print(&game, player1, player2);
            printf("Empate!\n");
            break;
        }

        game.current_player = switch_player(game.current_player);
    }

    return EXIT_SUCCESS;
}