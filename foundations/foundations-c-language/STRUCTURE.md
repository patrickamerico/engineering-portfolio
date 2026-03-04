# 🏗 STRUCTURE — Foundations in C

Este documento descreve a organização estrutural do repositório `foundations-c-language` e as decisões adotadas para manter simplicidade, clareza e foco educacional.

---

# 🎯 Filosofia de Organização

Este repositório foi estruturado com três princípios:

1. **Independência dos exercícios**
2. **Clareza sobre complexidade**
3. **Progressão gradual de dificuldade**

Cada arquivo `.c` representa um programa completo e executável de forma independente.

Isso permite:

- Estudo modular
- Testes isolados
- Facilidade de compreensão
- Evolução incremental

---

# 📂 Estrutura Atual
foundations-c-language/
│
├── basic_calculator.c
├── unit_converter.c
├── task_manager_example.c
├── tic_tac_toe.c
├── hangman_game.c
├── random_number_generator.c
├── dice_simulator.c
├── simple_registration_system.c
│
├── README.md
├── CONCEPTS.md
├── LEARNING_PATH.md
├── ROADMAP.md
├── CONTRIBUTING.md
├── STRUCTURE.md
└── LICENSE


---

# 🧱 Organização dos Arquivos `.c`

Cada arquivo:

- Possui sua própria função `main`
- Não depende de outros arquivos
- Compila individualmente
- Representa um conceito específico

Exemplo de compilação:

```bash
gcc basic_calculator.c -o calculator
```

# 🟢 Separação por Nível Conceitual

Embora fisicamente estejam no mesmo diretório, os arquivos estão organizados logicamente por níveis:

Level 1 — Fundamentos básicos
- basic_calculator.c
- random_number_generator.c

Level 2 — Estruturação de dados
- unit_converter.c
- task_manager_example.c
- simple_registration_system.c

Level 3 — Lógica aplicada
- tic_tac_toe.c
- hangman_game.c
- dice_simulator.c

A progressão foi projetada para aumentar gradualmente a complexidade.

---

# 🧠 Decisões Arquiteturais
❌ Por que não usar múltiplos arquivos .h e .c agora?

Porque o foco atual é:
- Dominar lógica
- Entender fluxo
- Consolidar fundamentos
- Modularização avançada faz parte da próxima fase do roadmap.

---

❌ Por que não usar alocação dinâmica neste estágio?

O objetivo é consolidar primeiro:
- Memória automática (stack)
- Estruturas estáticas
- Organização procedural

A complexidade de ponteiros será introduzida nas fases futuras.

---

# 🔵 Evolução Estrutural Planejada

Conforme o ROADMAP.md, a estrutura deverá evoluir para:
project/
│
├── src/
│   ├── main.c
│   ├── module.c
│   ├── module.h
│
├── include/
│
├── Makefile
└── README.md

# 🎯 Conclusão

A estrutura atual prioriza:

- Simplicidade
- Clareza
- Progressão lógica
- Independência dos módulos

Ela foi projetada não apenas para funcionar, mas para ensinar.

Evoluções estruturais virão com o avanço do domínio técnico.

---

Estrutura simples bem organizada é superior a complexidade desnecessária.