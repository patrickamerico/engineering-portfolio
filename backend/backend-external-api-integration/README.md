# 📮 CEP Lookup — Vue.js Frontend Integration

> Aplicação frontend para consulta de CEP utilizando Vue.js e integração com API pública.

Este projeto demonstra a construção de uma interface reativa para consulta de CEP, consumindo a API pública ViaCEP e aplicando boas práticas de organização, validação e experiência do usuário.

Mais do que uma página simples, o objetivo é evidenciar:

- Integração com API externa
- Tratamento assíncrono de requisições
- Validação de entrada
- Organização modular de frontend
- Estrutura pronta para evolução

---

## 🎯 Objective

Construir uma aplicação leve de consulta de CEP com:

- Validação básica de entrada
- Integração HTTP assíncrona
- Tratamento de erros
- Interface responsiva
- Separação clara entre estrutura, estilo e lógica

O projeto representa o domínio de **Frontend Integration** dentro do engineering-portfolio.

---

## 🧠 Architectural Overview

A aplicação segue uma separação simples e organizada:
User Input
↓
Vue Instance (State Management)
↓
Axios (HTTP Client)
↓
ViaCEP API
↓
Reactive UI Update


### Estrutura de responsabilidades

- **index.html** → Estrutura semântica
- **styles.css** → Camada visual e responsividade
- **app.js** → Lógica reativa e integração com API

Essa divisão facilita manutenção e evolução futura.

---

## 🛠 Tech Stack

- HTML5
- CSS3
- JavaScript
- Vue.js 2
- Axios
- API pública ViaCEP

---

## 🔍 Core Features

- Validação básica (8 dígitos numéricos)
- Requisição assíncrona via Axios
- Atualização reativa da interface
- Exibição estruturada dos dados retornados
- Tratamento de erro para:
  - CEP inválido
  - CEP não encontrado
  - Falha na requisição
- Layout responsivo

---

## ⚙️ How to Run

1. Clone o repositório:

	```bash
	git clone https://github.com/seu-usuario/consulta-cep-vue.git
	cd consulta-cep-vue
	```
2. Abra o arquivo index.html no navegador.
	Não é necessário servidor backend, pois a aplicação consome uma API pública diretamente.

## 📂 Project Structure
backend-external-api-integration/
├── index.html
├── styles.css
├── app.js
└── README.md

## 🔐 Input Validation Strategy

- Remoção automática de caracteres não numéricos
- Validação de tamanho (8 dígitos)
- Mensagens claras para o usuário
- Prevenção de requisições desnecessárias
Evolução futura pode incluir:
- Debounce para evitar múltiplas requisições
- Máscara dinâmica de input
- Feedback visual avançado

## 🚀 Evolution Roadmap

Possíveis melhorias arquiteturais:

- Migração para Vue 3
- Uso de Vite como bundler
- Componentização da interface
- Introdução de testes com Vitest
- Armazenamento local (LocalStorage)
- Tratamento global de erros
- Integração com backend próprio

## 📊 Purpose Within Engineering Portfolio

Este projeto demonstra:

- Capacidade de integração frontend com APIs externas
- Manipulação de estado reativo
- Organização básica de aplicação web
- Tratamento de cenários de erro
- Experiência de usuário orientada a clareza

Ele representa o domínio de Frontend dentro da estrutura de engenharia do portfólio.

📜 License

MIT License