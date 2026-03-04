#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

#define INPUT_SIZE 64

/* =====================================
   Utilitários
===================================== */

int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int parse_int(const char *input, int *out) {
    char *end;
    errno = 0;

    long value = strtol(input, &end, 10);

    if (errno != 0 || end == input || *end != '\0')
        return 0;

    if (value < INT_MIN || value > INT_MAX)
        return 0;

    *out = (int)value;
    return 1;
}

/* =====================================
   RNG sem viés
===================================== */

int random_uniform(int min, int max) {
    uint32_t range = (uint32_t)max - (uint32_t)min + 1;
    uint32_t limit = UINT32_MAX - (UINT32_MAX % range);

    uint32_t r;
    do {
        r = ((uint32_t)rand() << 16) ^ (uint32_t)rand();
    } while (r >= limit);

    return min + (r % range);
}

/* =====================================
   Engine
===================================== */

void simulate_dice(int sides, int rolls) {
    int *frequency = calloc(sides + 1, sizeof(int));
    if (!frequency) {
        fprintf(stderr, "Erro de memória.\n");
        return;
    }

    for (int i = 0; i < rolls; i++) {
        int result = random_uniform(1, sides);
        frequency[result]++;
        printf("Lançamento %d: %d\n", i + 1, result);
    }

    /* Estatísticas */
    printf("\nDistribuição:\n");
    for (int i = 1; i <= sides; i++) {
        printf("Face %d: %d vezes\n", i, frequency[i]);
    }

    free(frequency);
}

/* =====================================
   MAIN
===================================== */

int main(void) {
    char buffer[INPUT_SIZE];
    int sides, rolls;

    printf("Número de lados do dado: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_int(buffer, &sides) ||
        sides <= 0) {
        fprintf(stderr, "Valor inválido para lados.\n");
        return EXIT_FAILURE;
    }

    printf("Número de lançamentos: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_int(buffer, &rolls) ||
        rolls <= 0) {
        fprintf(stderr, "Valor inválido para lançamentos.\n");
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));

    simulate_dice(sides, rolls);

    return EXIT_SUCCESS;
}