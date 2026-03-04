#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

#define INITIAL_CAPACITY 8
#define MAX_STR 128
#define DB_FILE "database.bin"

/* =====================================
   MODELOS
===================================== */

typedef struct {
    char nome[MAX_STR];
    char endereco[MAX_STR];
    char telefone[MAX_STR];
} Cliente;

typedef struct {
    char nome[MAX_STR];
    int64_t preco_centavos;  // dinheiro seguro
} Produto;

typedef struct {
    Cliente *clientes;
    Produto *produtos;
    size_t num_clientes;
    size_t num_produtos;
    size_t cap_clientes;
    size_t cap_produtos;
} Sistema;

/* =====================================
   UTILITÁRIOS
===================================== */

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

/* =====================================
   SISTEMA (CORE)
===================================== */

int sistema_init(Sistema *s) {
    s->clientes = malloc(INITIAL_CAPACITY * sizeof(Cliente));
    s->produtos = malloc(INITIAL_CAPACITY * sizeof(Produto));

    if (!s->clientes || !s->produtos)
        return 0;

    s->num_clientes = 0;
    s->num_produtos = 0;
    s->cap_clientes = INITIAL_CAPACITY;
    s->cap_produtos = INITIAL_CAPACITY;
    return 1;
}

void sistema_free(Sistema *s) {
    free(s->clientes);
    free(s->produtos);
}

int expand_clientes(Sistema *s) {
    size_t new_cap = s->cap_clientes * 2;
    Cliente *tmp = realloc(s->clientes, new_cap * sizeof(Cliente));
    if (!tmp) return 0;
    s->clientes = tmp;
    s->cap_clientes = new_cap;
    return 1;
}

int expand_produtos(Sistema *s) {
    size_t new_cap = s->cap_produtos * 2;
    Produto *tmp = realloc(s->produtos, new_cap * sizeof(Produto));
    if (!tmp) return 0;
    s->produtos = tmp;
    s->cap_produtos = new_cap;
    return 1;
}

int adicionar_cliente(Sistema *s, Cliente c) {
    if (s->num_clientes == s->cap_clientes)
        if (!expand_clientes(s)) return 0;

    s->clientes[s->num_clientes++] = c;
    return 1;
}

int adicionar_produto(Sistema *s, Produto p) {
    if (s->num_produtos == s->cap_produtos)
        if (!expand_produtos(s)) return 0;

    s->produtos[s->num_produtos++] = p;
    return 1;
}

/* =====================================
   PERSISTÊNCIA
===================================== */

int salvar(const Sistema *s) {
    FILE *f = fopen(DB_FILE, "wb");
    if (!f) return 0;

    fwrite(&s->num_clientes, sizeof(size_t), 1, f);
    fwrite(s->clientes, sizeof(Cliente), s->num_clientes, f);

    fwrite(&s->num_produtos, sizeof(size_t), 1, f);
    fwrite(s->produtos, sizeof(Produto), s->num_produtos, f);

    fclose(f);
    return 1;
}

int carregar(Sistema *s) {
    FILE *f = fopen(DB_FILE, "rb");
    if (!f) return 1; // primeira execução

    fread(&s->num_clientes, sizeof(size_t), 1, f);
    while (s->cap_clientes < s->num_clientes)
        expand_clientes(s);
    fread(s->clientes, sizeof(Cliente), s->num_clientes, f);

    fread(&s->num_produtos, sizeof(size_t), 1, f);
    while (s->cap_produtos < s->num_produtos)
        expand_produtos(s);
    fread(s->produtos, sizeof(Produto), s->num_produtos, f);

    fclose(f);
    return 1;
}

/* =====================================
   UI
===================================== */

void listar_clientes(const Sistema *s) {
    printf("\n--- Clientes ---\n");
    for (size_t i = 0; i < s->num_clientes; i++) {
        printf("%zu. %s\n", i + 1, s->clientes[i].nome);
        printf("   Endereço: %s\n", s->clientes[i].endereco);
        printf("   Telefone: %s\n", s->clientes[i].telefone);
    }
}

void listar_produtos(const Sistema *s) {
    printf("\n--- Produtos ---\n");
    for (size_t i = 0; i < s->num_produtos; i++) {
        printf("%zu. %s - R$ %.2f\n",
               i + 1,
               s->produtos[i].nome,
               s->produtos[i].preco_centavos / 100.0);
    }
}

/* =====================================
   MAIN
===================================== */

int main(void) {
    Sistema sistema;
    if (!sistema_init(&sistema)) {
        fprintf(stderr, "Erro de inicialização.\n");
        return EXIT_FAILURE;
    }

    carregar(&sistema);

    int opcao;
    char buffer[128];

    do {
        printf("\n1. Cadastrar cliente\n");
        printf("2. Cadastrar produto\n");
        printf("3. Listar clientes\n");
        printf("4. Listar produtos\n");
        printf("0. Sair\n");
        printf("Opção: ");

        if (!read_line(buffer, sizeof(buffer)))
            continue;

        opcao = atoi(buffer);

        if (opcao == 1) {
            Cliente c;
            printf("Nome: ");
            read_line(c.nome, sizeof(c.nome));
            printf("Endereço: ");
            read_line(c.endereco, sizeof(c.endereco));
            printf("Telefone: ");
            read_line(c.telefone, sizeof(c.telefone));
            adicionar_cliente(&sistema, c);
        }
        else if (opcao == 2) {
            Produto p;
            double preco;
            printf("Nome do produto: ");
            read_line(p.nome, sizeof(p.nome));

            printf("Preço (ex: 10.50): ");
            read_line(buffer, sizeof(buffer));

            if (parse_double(buffer, &preco)) {
                p.preco_centavos = (int64_t)(preco * 100.0);
                adicionar_produto(&sistema, p);
            } else {
                printf("Preço inválido.\n");
            }
        }
        else if (opcao == 3) {
            listar_clientes(&sistema);
        }
        else if (opcao == 4) {
            listar_produtos(&sistema);
        }

    } while (opcao != 0);

    salvar(&sistema);
    sistema_free(&sistema);
    return EXIT_SUCCESS;
}