#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define INPUT_BUFFER 128

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_INVALID
} Operation;

/* ============================
   Parsing seguro de double
   ============================ */
int parse_double(const char *input, double *out) {
    char *endptr;
    errno = 0;

    double value = strtod(input, &endptr);

    if (errno != 0 || endptr == input || *endptr != '\n')
        return 0;

    *out = value;
    return 1;
}

/* ============================
   Leitura segura da entrada
   ============================ */
int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return 0;
    }

    return 1;
}

/* ============================
   Conversão operador
   ============================ */
Operation parse_operator(char op) {
    switch (op) {
        case '+': return OP_ADD;
        case '-': return OP_SUB;
        case '*': return OP_MUL;
        case '/': return OP_DIV;
        default:  return OP_INVALID;
    }
}

/* ============================
   Execução da operação
   ============================ */
int calculate(double a, double b, Operation op, double *result) {
    if (!result) return 0;

    switch (op) {
        case OP_ADD:
            *result = a + b;
            return 1;

        case OP_SUB:
            *result = a - b;
            return 1;

        case OP_MUL:
            *result = a * b;
            return 1;

        case OP_DIV:
            if (fabs(b) < 1e-12) {
                fprintf(stderr, "Erro: divisão por zero.\n");
                return 0;
            }
            *result = a / b;
            return 1;

        default:
            return 0;
    }
}

/* ============================
   MAIN
   ============================ */
int main(void) {
    char buffer[INPUT_BUFFER];
    double num1, num2, resultado;
    Operation op;

    printf("Digite o primeiro número: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_double(buffer, &num1)) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    printf("Digite o segundo número: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_double(buffer, &num2)) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    printf("Digite o operador (+, -, *, /): ");
    if (!read_line(buffer, sizeof(buffer))) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    op = parse_operator(buffer[0]);

    if (op == OP_INVALID) {
        fprintf(stderr, "Operador inválido.\n");
        return EXIT_FAILURE;
    }

    if (!calculate(num1, num2, op, &resultado))
        return EXIT_FAILURE;

    printf("Resultado: %.10g\n", resultado);

    return EXIT_SUCCESS;
}