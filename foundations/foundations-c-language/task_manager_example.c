#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define INITIAL_CAPACITY 8
#define MAX_DESC 256
#define DB_FILE "tasks.db"

/* ================================
   Modelo
================================ */

typedef struct {
    char description[MAX_DESC];
    int completed;
} Task;

typedef struct {
    Task *items;
    size_t size;
    size_t capacity;
} TaskList;

/* ================================
   Utilitários
================================ */

int read_line(char *buffer, size_t size) {
    if (!fgets(buffer, size, stdin))
        return 0;

    buffer[strcspn(buffer, "\n")] = '\0';
    return 1;
}

int read_int(int *out) {
    char buffer[64];
    char *end;

    if (!read_line(buffer, sizeof(buffer)))
        return 0;

    errno = 0;
    long value = strtol(buffer, &end, 10);

    if (errno != 0 || end == buffer || *end != '\0')
        return 0;

    *out = (int)value;
    return 1;
}

/* ================================
   Core - TaskList
================================ */

int tasklist_init(TaskList *list) {
    list->items = malloc(INITIAL_CAPACITY * sizeof(Task));
    if (!list->items)
        return 0;

    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return 1;
}

void tasklist_free(TaskList *list) {
    free(list->items);
}

int tasklist_expand(TaskList *list) {
    size_t new_capacity = list->capacity * 2;

    Task *new_items = realloc(list->items, new_capacity * sizeof(Task));
    if (!new_items)
        return 0;

    list->items = new_items;
    list->capacity = new_capacity;
    return 1;
}

int tasklist_add(TaskList *list, const char *desc) {
    if (list->size == list->capacity) {
        if (!tasklist_expand(list))
            return 0;
    }

    strncpy(list->items[list->size].description, desc, MAX_DESC - 1);
    list->items[list->size].description[MAX_DESC - 1] = '\0';
    list->items[list->size].completed = 0;

    list->size++;
    return 1;
}

int tasklist_mark_done(TaskList *list, size_t index) {
    if (index >= list->size)
        return 0;

    list->items[index].completed = 1;
    return 1;
}

int tasklist_remove(TaskList *list, size_t index) {
    if (index >= list->size)
        return 0;

    memmove(&list->items[index],
            &list->items[index + 1],
            (list->size - index - 1) * sizeof(Task));

    list->size--;
    return 1;
}

void tasklist_print(const TaskList *list) {
    printf("\n===== Lista de Tarefas =====\n");
    for (size_t i = 0; i < list->size; i++) {
        printf("%zu. [%c] %s\n",
               i + 1,
               list->items[i].completed ? 'X' : ' ',
               list->items[i].description);
    }
    printf("\n");
}

/* ================================
   Persistência
================================ */

int tasklist_save(const TaskList *list) {
    FILE *f = fopen(DB_FILE, "wb");
    if (!f)
        return 0;

    fwrite(&list->size, sizeof(size_t), 1, f);
    fwrite(list->items, sizeof(Task), list->size, f);

    fclose(f);
    return 1;
}

int tasklist_load(TaskList *list) {
    FILE *f = fopen(DB_FILE, "rb");
    if (!f)
        return 1;  // não é erro se não existir

    size_t size;
    if (fread(&size, sizeof(size_t), 1, f) != 1) {
        fclose(f);
        return 0;
    }

    while (list->capacity < size) {
        if (!tasklist_expand(list)) {
            fclose(f);
            return 0;
        }
    }

    if (fread(list->items, sizeof(Task), size, f) != size) {
        fclose(f);
        return 0;
    }

    list->size = size;
    fclose(f);
    return 1;
}

/* ================================
   UI
================================ */

void print_menu(void) {
    printf("===== Gerenciador de Tarefas =====\n");
    printf("1. Adicionar tarefa\n");
    printf("2. Listar tarefas\n");
    printf("3. Marcar como concluída\n");
    printf("4. Remover tarefa\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

/* ================================
   MAIN
================================ */

int main(void) {
    TaskList list;

    if (!tasklist_init(&list)) {
        fprintf(stderr, "Erro ao inicializar lista.\n");
        return EXIT_FAILURE;
    }

    if (!tasklist_load(&list)) {
        fprintf(stderr, "Erro ao carregar tarefas.\n");
        tasklist_free(&list);
        return EXIT_FAILURE;
    }

    int option;

    do {
        print_menu();

        if (!read_int(&option)) {
            printf("Entrada inválida.\n");
            continue;
        }

        switch (option) {
            case 1: {
                char desc[MAX_DESC];
                printf("Descrição: ");
                if (read_line(desc, sizeof(desc))) {
                    if (!tasklist_add(&list, desc))
                        printf("Erro ao adicionar tarefa.\n");
                }
                break;
            }

            case 2:
                tasklist_print(&list);
                break;

            case 3: {
                printf("Número da tarefa: ");
                int idx;
                if (read_int(&idx) &&
                    tasklist_mark_done(&list, idx - 1))
                    printf("Tarefa marcada como concluída.\n");
                else
                    printf("Tarefa inválida.\n");
                break;
            }

            case 4: {
                printf("Número da tarefa: ");
                int idx;
                if (read_int(&idx) &&
                    tasklist_remove(&list, idx - 1))
                    printf("Tarefa removida.\n");
                else
                    printf("Tarefa inválida.\n");
                break;
            }

            case 0:
                tasklist_save(&list);
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (option != 0);

    tasklist_free(&list);
    return EXIT_SUCCESS;
}