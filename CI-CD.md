# Estratégia de CI/CD

## 1. Visão Geral

Integração Contínua e Entrega Contínua são tratadas como disciplinas estruturais da engenharia.

Mesmo sendo um portfólio, os princípios adotados refletem ambientes corporativos reais.

---

## 2. Integração Contínua (CI)

Princípios:

- Toda alteração deve ser rastreável
- Validações devem ser automatizadas
- Mudanças devem ser revisadas
- Feedback deve ser rápido

Objetivos:

- Manter consistência estrutural
- Evitar regressões
- Garantir qualidade incremental

---

## 3. Entrega Contínua (CD)

Princípios:

- Versionamento claro
- Estrutura reproduzível
- Histórico auditável
- Evolução controlada

---

## 4. Modelo de Branches

- main: estado estável
- branches de feature para mudanças isoladas
- Pull Requests para integração controlada

---

## 5. Governança de Releases

- Versionamento semântico
- Atualização obrigatória do CHANGELOG
- Registro de decisões relevantes