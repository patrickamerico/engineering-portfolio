# 🏗 Backend REST API — User Registration Service

> API REST para cadastro de usuários com estrutura modular, foco em organização arquitetural, segurança e evolução sustentável.

Este projeto implementa uma API REST utilizando **Node.js**, **Express** e **Sequelize**, com separação clara de responsabilidades e armazenamento seguro de credenciais.

A aplicação serve como base para sistemas que necessitam de autenticação, gerenciamento de usuários e expansão futura para arquiteturas mais robustas.

---

## 🎯 Objetivo

Fornecer um serviço de cadastro de usuários que contemple:

- Persistência em banco de dados relacional
- Armazenamento seguro de senhas (hash)
- Organização modular em camadas
- Estrutura preparada para evolução arquitetural

---

## 🧠 Arquitetura

A aplicação segue uma estrutura em camadas:
HTTP Request
↓
Controller
↓
Service
↓
Model (Sequelize)
↓
Database


### 📌 Responsabilidades

**Controller**
- Recebe requisições HTTP
- Valida dados de entrada
- Retorna respostas padronizadas

**Service**
- Implementa regras de negócio
- Realiza hash de senha com bcrypt
- Verifica duplicidade de usuário

**Model**
- Define a entidade `Usuario`
- Realiza o mapeamento objeto-relacional (ORM)
- Interage com o banco de dados

---

## 🛠 Tecnologias Utilizadas

- Node.js
- Express
- Sequelize
- SQLite (padrão para desenvolvimento)
- bcrypt

---

## ⚙️ Requisitos

- Node.js 14+
- npm ou yarn

---

## 🚀 Como Executar

### 1️⃣ Clonar o repositório

```bash
git clone https://github.com/seu-usuario/backend-rest-api-architecture.git
cd backend-rest-api-architecture
```
### 2️⃣ Instalar dependências
```npm install```

### 3️⃣ Sincronizar o banco de dados
```node sync.js```

Esse comando criará as tabelas no banco SQLite.

### 4️⃣ Iniciar o servidor
```npm start```

Servidor disponível em:

```http://localhost:3000```

### 📌 Endpoint Disponível
POST /api/usuarios

Cria um novo usuário.

### 📥 Request Body (JSON)
{
  "nome": "João Silva",
  "email": "joao.silva@email.com",
  "senha": "senha123"
}

## 📤 Respostas
Status	Descrição
201	Usuário criado com sucesso (senha não é retornada)
400	Usuário já existente ou dados inválidos

## 🔐 Segurança

- Senhas armazenadas com hash utilizando bcrypt
- Senha nunca é retornada nas respostas
- Separação de regras de negócio da camada HTTP
- Estrutura preparada para futura implementação de autenticação JWT

## 🧪 Testando a API

Você pode utilizar:
- Postman
- Insomnia
- Thunder Client (VSCode)

Envie uma requisição POST para:
```
http://localhost:3000/api/usuarios
```
Com o JSON no corpo da requisição.

## 📂 Estrutura do Projeto
src/
 ├── controllers/
 │     └── usuarioController.js
 │
 ├── routes/
 │     └── usuarioRoutes.js
 │
 ├── models/
 │     └── usuario.js
 │
 ├── services/
 │     └── usuarioService.js
 ├── app.js
 ├── postman_collection.json
 ├── README.md


## 🚀 Evoluções Futuras

- Autenticação JWT
- Middleware de autorização
- Validação estruturada (Joi ou Zod)
- Tratamento centralizado de erros
- Testes automatizados (Jest)
- Integração com PostgreSQL
- Containerização com Docker
- Pipeline CI/CD

## 📊 Papel no Engineering Portfolio

- Este projeto demonstra:
- Organização em camadas
- Boas práticas de backend
- Separação de responsabilidades
- Segurança no armazenamento de senhas
- Base para arquiteturas mais avançadas (ex: Clean Architecture)

## 📜 Licença

MIT License

---

Código organizado hoje evita problemas arquiteturais amanhã.