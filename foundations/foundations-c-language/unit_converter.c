#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define INPUT_SIZE 128
#define EPSILON 1e-12

typedef enum {
    CAT_TEMPERATURE,
    CAT_LENGTH,
    CAT_MASS,
    CAT_INVALID
} Category;

typedef struct {
    const char *name;
    Category category;
    double (*to_base)(double);
    double (*from_base)(double);
} Unit;

/* ============================
   Funções de conversão base
   ============================ */

/* Temperatura (base: Celsius) */
double f_to_c(double v) { return (v - 32.0) * 5.0 / 9.0; }
double c_to_f(double v) { return v * 9.0 / 5.0 + 32.0; }
double k_to_c(double v) { return v - 273.15; }
double c_to_k(double v) { return v + 273.15; }

/* Comprimento (base: metro) */
double identity(double v) { return v; }
double cm_to_m(double v) { return v / 100.0; }
double m_to_cm(double v) { return v * 100.0; }
double mm_to_m(double v) { return v / 1000.0; }
double m_to_mm(double v) { return v * 1000.0; }

/* Massa (base: kg) */
double g_to_kg(double v) { return v / 1000.0; }
double kg_to_g(double v) { return v * 1000.0; }
double mg_to_kg(double v) { return v / 1000000.0; }
double kg_to_mg(double v) { return v * 1000000.0; }

/* ============================
   Tabela de unidades
   ============================ */

Unit units[] = {
    /* Temperatura */
    {"C",  CAT_TEMPERATURE, identity, identity},
    {"F",  CAT_TEMPERATURE, f_to_c,  c_to_f},
    {"K",  CAT_TEMPERATURE, k_to_c,  c_to_k},

    /* Comprimento */
    {"m",  CAT_LENGTH, identity, identity},
    {"cm", CAT_LENGTH, cm_to_m, m_to_cm},
    {"mm", CAT_LENGTH, mm_to_m, m_to_mm},

    /* Massa */
    {"kg", CAT_MASS, identity, identity},
    {"g",  CAT_MASS, g_to_kg, kg_to_g},
    {"mg", CAT_MASS, mg_to_kg, kg_to_mg},
};

#define UNIT_COUNT (sizeof(units) / sizeof(units[0]))

/* ============================
   Utilitários
   ============================ */

int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int parse_double(const char *input, double *out) {
    char *end;
    errno = 0;

    double value = strtod(input, &end);

    if (errno != 0 || end == input || *end != '\0')
        return 0;

    *out = value;
    return 1;
}

const Unit* find_unit(const char *name) {
    for (size_t i = 0; i < UNIT_COUNT; ++i) {
        if (strcmp(name, units[i].name) == 0)
            return &units[i];
    }
    return NULL;
}

/* ============================
   Conversão
   ============================ */

int convert(double value,
            const Unit *from,
            const Unit *to,
            double *result)
{
    if (!from || !to || !result)
        return 0;

    if (from->category != to->category) {
        fprintf(stderr, "Erro: unidades incompatíveis.\n");
        return 0;
    }

    double base_value = from->to_base(value);
    *result = to->from_base(base_value);

    return 1;
}

/* ============================
   MAIN
   ============================ */

int main(void) {
    char buffer[INPUT_SIZE];
    char from_unit[INPUT_SIZE];
    char to_unit[INPUT_SIZE];

    double value, result;

    printf("Digite o valor: ");
    if (!read_line(buffer, sizeof(buffer)) ||
        !parse_double(buffer, &value)) {
        fprintf(stderr, "Valor inválido.\n");
        return EXIT_FAILURE;
    }

    printf("Unidade de origem: ");
    if (!read_line(from_unit, sizeof(from_unit))) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    printf("Unidade de destino: ");
    if (!read_line(to_unit, sizeof(to_unit))) {
        fprintf(stderr, "Entrada inválida.\n");
        return EXIT_FAILURE;
    }

    const Unit *from = find_unit(from_unit);
    const Unit *to   = find_unit(to_unit);

    if (!from || !to) {
        fprintf(stderr, "Unidade desconhecida.\n");
        return EXIT_FAILURE;
    }

    if (!convert(value, from, to, &result))
        return EXIT_FAILURE;

    printf("Resultado: %.10g %s\n", result, to->name);

    return EXIT_SUCCESS;
}