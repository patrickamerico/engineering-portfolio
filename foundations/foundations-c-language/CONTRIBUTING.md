# 🤝 Contributing Guide — Foundations C Language

Obrigado por considerar contribuir com este repositório!

Este projeto tem como objetivo consolidar fundamentos da linguagem C por meio de exemplos práticos e didáticos. Contribuições são bem-vindas, desde que mantenham a proposta educacional e a organização do código.

---

## 🎯 Objetivo das Contribuições

As contribuições devem:

- Melhorar a clareza do código
- Corrigir possíveis erros
- Otimizar lógica sem comprometer a didática
- Adicionar novos exemplos alinhados aos fundamentos
- Melhorar documentação

---

## 📂 Estrutura do Projeto

Todos os arquivos `.c` são independentes e executáveis individualmente.

Evite:

- Criar dependências entre arquivos
- Misturar múltiplos exercícios em um único arquivo
- Introduzir complexidade desnecessária

---

## 🧱 Padrões de Código

### 🔹 Convenções de Nome

- Arquivos em `snake_case`
- Funções com nomes descritivos
- Variáveis claras e legíveis
- Evitar abreviações ambíguas

Exemplo:

```c
int calculate_sum(int a, int b);
```
## 🔹 Organização

- Incluir bibliotecas no topo do arquivo
- Declarar funções antes do main() ou usar protótipos
- Separar lógica em funções quando possível
- Manter main() simples e legível

---

## 🔹 Formatação

- Indentação com 4 espaços
- Chaves sempre abertas na mesma linha:
```
if (condition) {
    // code
}
```
---

## 🧪 Compilação

Todos os arquivos devem compilar usando:

gcc nome_do_arquivo.c -o programa

O código deve funcionar com compiladores padrão como GCC ou Clang.

Evite dependências externas.

---

## 🚀 Como Contribuir

1.Faça um fork do repositório
2.Crie uma branch descritiva:
```
git checkout -b feature/nome-da-melhoria
```
3.Faça suas alterações
4.Teste a compilação
5. Envie um Pull Request com descrição clara

---

## 🧠 Tipos de Contribuição Aceitos

- Refatoração simples
- Melhoria de organização
- Adição de comentários explicativos
- Novos exercícios alinhados aos fundamentos
- Correção de bugs

---

## ❌ O que evitar

- Bibliotecas externas complexas
- Programação orientada a objetos (não aplicável em C tradicional)
- Uso avançado de ponteiros que comprometa a didática
- Código excessivamente otimizado que reduza clareza

---

## 📚 Filosofia do Projeto

Este repositório prioriza:

- Clareza sobre complexidade
- Didática sobre performance
- Fundamentos sobre abstrações avançadas

A ideia é fortalecer a base da programação antes de avançar para arquiteturas mais sofisticadas.

---

## 📩 Dúvidas

Abra uma issue descrevendo:
- O problema
- A sugestão
- O comportamento esperado

---

Obrigado por contribuir e ajudar a fortalecer a base da engenharia de software! 🚀