#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>
#include <limits.h>

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
   RNG Seguro
===================================== */

/*
   Gera inteiro uniforme no intervalo [min, max]
*/
int random_in_range(int min, int max) {
    if (min > max)
        return 0;

    uint32_t range = (uint32_t)max - (uint32_t)min + 1;

    uint32_t limit = UINT32_MAX - (UINT32_MAX % range);

    uint32_t r;
    do {
        r = ((uint32_t)rand() << 16) ^ (uint32_t)rand();
    } while (r >= limit);

    return min + (r % range);
}

/* =====================================
   MAIN
===================================== */

int main(void) {
    char buffer[64];
    int min, max;

    printf("Digite o valor mínimo: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_int(buffer, &min)) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    printf("Digite o valor máximo: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_int(buffer, &max)) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    if (min > max) {
        fprintf(stderr, "Erro: mínimo maior que máximo.\n");
        return EXIT_FAILURE;
    }

    /* único por execução */
    srand((unsigned)time(NULL));

    int result = random_in_range(min, max);

    printf("Número gerado: %d\n", result);

    return EXIT_SUCCESS;
}