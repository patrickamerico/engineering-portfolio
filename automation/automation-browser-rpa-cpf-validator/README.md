# 🧾 Validador de CPF com Automação (RPA) — Extensão Chrome

> Extensão para Google Chrome com validação local de CPF e automação (RPA) para consulta de situação cadastral junto à Receita Federal.

Este projeto demonstra a aplicação de **automação de processos (RPA)** integrada a uma **extensão de navegador**, com foco em validação de dados cadastrais em contextos sensíveis como sistemas de saúde.

A solução combina:

- Validação algorítmica de CPF
- Interface leve via extensão Chrome (Manifest V3)
- Integração com script externo de automação
- Retorno estruturado da situação cadastral

Este projeto representa o domínio de **Automation & RPA Engineering** dentro do engineering-portfolio.

---

## 🎯 Objetivo

Automatizar e tornar mais seguro o processo de validação de CPF durante cadastros, reduzindo:

- Erros de digitação
- Dados inconsistentes
- Retrabalho operacional
- Riscos de fraude

A proposta é integrar validação automática diretamente ao fluxo de cadastro.

---

## 🧠 Arquitetura da Solução

A extensão atua como interface e orquestradora da automação.
Usuário insere CPF
↓
Validação local (dígitos verificadores)
↓
Envio para serviço RPA
↓
Automação de consulta no site da Receita Federal
↓
Retorno estruturado
↓
Exibição no popup da extensão


### Componentes

- Extensão Chrome (Manifest V3)
- Validação JavaScript do CPF
- Script externo de RPA (Node.js + Puppeteer / Selenium)
- Comunicação entre extensão e serviço de automação

---

## ⚙️ Funcionalidades

- ✅ Validação local de formato e dígitos verificadores do CPF
- ✅ Prevenção de consultas desnecessárias
- ✅ Integração com automação para consulta oficial
- ✅ Feedback visual da situação cadastral
- ✅ Redução de inconsistências em sistemas de cadastro

---

## 🛠 Tecnologias Utilizadas

- HTML5
- CSS3
- JavaScript
- Chrome Extensions (Manifest V3)
- Node.js (para RPA externo)
- Puppeteer ou Selenium (automação)

---

## 📂 Estrutura do Projeto
automation-browser-rpa-cpf-validator/
│
├── src/
│ ├── manifest.json
│ ├── popup.html
│ ├── popup.js
│ └── styles.css
│
├── images/
│ ├── cpf_validator_extension_preview.png
│ └── cpf_validator_popup_preview.png
│
└── README.md


### Arquivos principais

- `manifest.json` → Configuração da extensão
- `popup.html` → Interface do usuário
- `popup.js` → Lógica de validação e integração
- `styles.css` → Estilização
- Script RPA externo → Automação da consulta

---

## 🚀 Como Testar a Extensão

### 1️⃣ Clonar o repositório

```bash
git clone https://github.com/seu-usuario/automation-browser-rpa-cpf-validator.git
 ```
 
###  2️⃣ Carregar no Chrome

Acesse chrome://extensions/
Ative o Modo do Desenvolvedor
Clique em Carregar sem compactação
Selecione a pasta do projeto
A extensão aparecerá na barra do navegador.

### 3️⃣ Configurar o serviço RPA

A extensão não executa RPA diretamente.
É necessário criar um serviço externo que:
- Automatize a navegação no site da Receita Federal
- Preencha os campos necessários
- Capture a resposta
- Retorne o status de forma estruturada
Esse serviço pode ser implementado com:
- Node.js + Puppeteer
- Selenium
- Outra ferramenta de automação

## 📌 Considerações Técnicas
## 🔐 Segurança e LGPD

- Deve respeitar a Lei Geral de Proteção de Dados (LGPD)
- Evitar armazenamento indevido de dados sensíveis
- Implementar controle de acesso quando usado em ambiente corporativo

## ⚠️ Limitações

- O site da Receita Federal pode utilizar CAPTCHA
- Pode haver bloqueios anti-bot
- Automação deve respeitar termos de uso

## 🔄 Alternativa

- Caso a automação direta não seja viável, pode-se:
- Integrar API autorizada de terceiros
- Utilizar serviços oficiais de consulta

## 📊 Impacto Operacional

A solução contribui para:
- Redução de erros humanos
- Maior confiabilidade de dados
- Aumento da produtividade administrativa
- Melhoria na qualidade cadastral
- Padronização de processos

## 🖼 Preview
Interface da Extensão
---
Popup de Validação

## 📈 Possíveis Evoluções

- Integração com API REST corporativa
- Log estruturado de consultas
- Controle de permissões por usuário
- Deploy como ferramenta interna corporativa
- Monitoramento de falhas na automação
- Versão enterprise com autenticação

## 📜 Licença

MIT License
---
Automação não substitui pessoas — ela elimina tarefas repetitivas para que decisões melhores sejam tomadas.