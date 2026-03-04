# 🧠 Core Concepts — Foundations in C

Este documento descreve os principais conceitos de Ciência da Computação e programação trabalhados neste repositório.

O objetivo não é apenas implementar pequenos programas, mas compreender os fundamentos que sustentam sistemas maiores e mais complexos.

---

# 📌 1. Programação Procedural

A linguagem C é baseada no paradigma procedural.

Isso significa que:

- O programa é organizado em funções
- A execução ocorre de forma sequencial
- O fluxo é controlado por estruturas condicionais e de repetição

Neste repositório, todos os projetos seguem essa abordagem.

---

# 📌 2. Estruturas de Controle

## 🔹 Condicionais

- `if`
- `else`
- `switch`

Permitem controlar o fluxo do programa com base em decisões lógicas.

Exemplo de aplicação:
- Validação de jogadas (tic_tac_toe)
- Verificação de tentativa (hangman_game)
- Escolha de operação (basic_calculator)

---

## 🔹 Estruturas de Repetição

- `for`
- `while`
- `do while`

Permitem executar blocos de código repetidamente.

Exemplo:
- Simulação de lançamentos de dados
- Menu interativo
- Loops de jogo

---

# 📌 3. Funções

Funções são blocos reutilizáveis de código.

Benefícios:

- Organização
- Reutilização
- Separação de responsabilidades
- Melhor legibilidade

Boas práticas aplicadas:

- Funções pequenas
- Nome descritivo
- Separação da lógica principal (`main`)

---

# 📌 4. Arrays e Matrizes

Arrays são estruturas de dados fundamentais em C.

Neste projeto são usados para:

- Armazenar tarefas
- Representar tabuleiro (tic_tac_toe)
- Manipular strings

Matrizes bidimensionais permitem representar estruturas como grades e tabelas.

---

# 📌 5. Strings em C

Strings são arrays de caracteres terminados por `\0`.

Conceitos importantes:

- Manipulação com `string.h`
- Comparação com `strcmp`
- Cópia com `strcpy`
- Cuidado com buffer overflow

Aplicado em:
- hangman_game
- simple_registration_system

---

# 📌 6. Estruturas (`struct`)

Estruturas permitem agrupar diferentes tipos de dados.

Exemplo conceitual:

```c
struct User {
    char name[50];
    int age;
};
```
Aplicado em:

- simple_registration_system
- Isso introduz modelagem básica de dados.

---

# 📌 7. Geração de Números Aleatórios

Utilização de:
- rand()
- srand()
- time(NULL)

Importante compreender:
- Pseudoaleatoriedade
- Inicialização de semente
- Intervalos numéricos

Aplicado em:

- random_number_generator
- dice_simulator
- hangman_game

---

# 📌 8. Entrada e Saída (I/O)

Funções fundamentais:
- printf
- scanf
- Manipulação básica de entrada

Conceitos importantes:
- Formatação
- Conversão de tipos
- Validação de entrada

---

# 📌 9. Memória: Stack vs Heap

Embora este projeto foque principalmente em alocação estática (stack), é importante entender:

## 🔹 Stack

- Memória automática
- Escopo local
- Liberação automática ao sair da função

## 🔹 Heap

- Alocação dinâmica (malloc, free)
- Controle manual da memória
- Risco de vazamentos
- Futuras evoluções do projeto podem incluir uso de alocação dinâmica.

---

# 📌 10. Organização e Legibilidade

Boas práticas adotadas:

- Código simples
- Funções bem definidas
- Separação de responsabilidades
- Evitar complexidade desnecessária
- Clareza é priorizada sobre otimização prematura.

---

# 📌 11. Limitações Atuais

Este repositório:

- Não utiliza alocação dinâmica avançada
- Não implementa persistência em arquivos
- Não usa modularização com .h e múltiplos .c
- Não explora ponteiros complexos
- Essas evoluções podem fazer parte do roadmap futuro.

---

# 📌 12. Fundamentos Construídos Aqui

Os conceitos trabalhados aqui são base para:

- Estruturas de dados avançadas
- Programação de sistemas
- Desenvolvimento embarcado
- Backend de alta performance
- Linguagens como C++, Rust e Go

---

# 🎯 Conclusão

Este repositório não é apenas uma coleção de exercícios.

Ele representa a consolidação de fundamentos essenciais de programação:

- Lógica
- Estrutura
- Organização
- Pensamento algorítmico
- Controle de fluxo
- Modelagem básica de dados

---

Fundamentos sólidos permitem evolução consistente para sistemas mais complexos.