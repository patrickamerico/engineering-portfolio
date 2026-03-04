# 📝 Conventional Commits Guide

Este repositório segue o padrão **Conventional Commits** para manter histórico organizado, rastreável e profissional.

O objetivo é:

- Padronizar mensagens de commit
- Facilitar leitura do histórico
- Melhorar organização de mudanças
- Permitir versionamento semântico futuro
- Tornar o portfólio mais alinhado a boas práticas de engenharia

---

# 📌 Estrutura do Commit

Formato padrão:

<type>(optional-scope): short description

[optional body]

[optional footer]


---

# 🔎 Tipos Permitidos

## ✨ feat

Nova funcionalidade.

Exemplo:

feat(api): add student enrollment endpoint

---

## 🐛 fix

Correção de bug.

Exemplo:

fix(auth): correct password hash validation

---

## ♻️ refactor

Refatoração sem alterar comportamento externo.

Exemplo:

refactor(database): improve connection handling

---

## 📚 docs

Alterações na documentação.

Exemplo:

docs(readme): update project description

---

## 🎨 style

Mudanças que não afetam lógica (formatação, espaços, lint).

Exemplo:

style(frontend): format CSS structure

---

## 🧪 test

Adição ou alteração de testes.

Exemplo:

test(api): add unit tests for user creation

---

## 🔧 chore

Tarefas de manutenção.

Exemplo:

chore: update dependencies

---

## 🚀 perf

Melhoria de performance.

Exemplo:

perf(query): optimize student lookup query

---

## 🗑️ remove

Remoção de código ou arquivos.

Exemplo:

remove: delete deprecated endpoint

---

# 📦 Escopo (Opcional)

O escopo indica qual parte do projeto foi impactada.

Exemplos de escopo:

- api
- frontend
- backend
- database
- docker
- docs
- auth
- models
- ui
- pipeline
- dashboard

Exemplo completo:

feat(docker): add multi-stage build

---

# 🧾 Corpo do Commit (Opcional)

Utilize quando necessário para explicar:

- O motivo da mudança
- Contexto técnico
- Impacto arquitetural
- Decisão de design

Exemplo:

refactor(api): reorganize route structure

Improves separation of concerns by grouping routes
into dedicated modules.

---

# ⚠️ Breaking Changes

Para mudanças que quebram compatibilidade:

feat(api)!: change authentication flow

ou

feat(api): change authentication flow

BREAKING CHANGE: JWT structure updated.

---

# 📌 Boas Práticas

- Use verbo no imperativo (add, fix, update, remove)
- Seja objetivo
- Evite mensagens genéricas como "update code"
- Um commit deve representar uma mudança lógica
- Evite commits gigantes com múltiplas responsabilidades

---

# 🎯 Exemplos Reais para Este Portfólio

feat(frontend): create task management app  
feat(devops): add Dockerfile  
docs(portfolio): update project roadmap  
refactor(pipeline): improve data cleaning logic  
chore: initial commit  

---

# 🏗️ Versionamento Futuro

Este padrão permite uso de:

- Semantic Versioning (SemVer)
- Changelog automatizado
- CI/CD com version bump automático

---

# 📚 Referência Oficial

Padrão baseado em:

https://www.conventionalcommits.org/

---

> Histórico limpo é um sinal de maturidade em engenharia de software.