# 📊 Dashboard de Análise Salarial na Área de Dados

> Aplicação analítica interativa para exploração de salários na área de dados, desenvolvida com Streamlit e Plotly.

Este projeto apresenta um dashboard interativo que permite analisar tendências salariais no mercado de dados.  

A aplicação transforma um dataset estático em um ambiente dinâmico de exploração, permitindo filtragem, cálculo de métricas e visualizações interativas.

Este projeto representa o domínio de **Data Science & Analytics** dentro do engineering-portfolio.

---

## 🎯 Objetivo

Fornecer uma aplicação analítica que permita:

- Explorar a distribuição de salários
- Comparar níveis de senioridade
- Analisar impacto do tipo de contrato
- Avaliar diferenças por tamanho de empresa
- Identificar padrões geográficos
- Entender proporção de trabalho remoto, híbrido e presencial

O foco é transformar dados brutos em informações estratégicas acessíveis por meio de uma interface interativa.

---

## 🧠 Arquitetura Analítica

A aplicação segue o fluxo abaixo:
Dataset CSV
↓
Tratamento de Dados (Pandas)
↓
Filtros Interativos (Streamlit)
↓
Cálculo de Métricas
↓
Visualizações Interativas (Plotly)
↓
Exploração pelo Usuário

### Componentes

- Ingestão de dados via CSV
- Transformação e agregação com Pandas
- Gerenciamento de estado via Streamlit
- Visualizações interativas com Plotly

---

## 📊 Funcionalidades Principais

### 🔎 Filtros Interativos

- Ano
- Nível de senioridade
- Tipo de contrato
- Tamanho da empresa

---

### 📈 Métricas Calculadas

- Salário médio (USD)
- Salário máximo (USD)
- Total de registros filtrados
- Cargo mais frequente

---

### 📊 Visualizações

- Distribuição salarial (histograma)
- Top 10 cargos por salário médio
- Proporção de tipo de trabalho (remoto, híbrido, presencial)
- Salário médio de Data Scientists por país (mapa)

---

### 📋 Tabela Detalhada

Exibição dinâmica do dataset filtrado para análise granular.

---

## 🌐 Aplicação Online

O dashboard está disponível publicamente:

👉 https://dashboard-salarios-dados.streamlit.app/

---

## ⚙️ Como Executar Localmente

### 1️⃣ Clonar o repositório

	```
	bash
	git clone https://github.com/seu-usuario/data-salary-dashboard.git
	cd data-salary-dashboard
	```
### 2️⃣ Criar ambiente virtual
Windows
	```
	python -m venv .venv
	.venv\Scripts\activate
	macOS / Linux
	```
### python3 -m venv .venv
```
	source .venv/bin/activate
	3️⃣ Instalar dependências
	pip install -r requirements.txt
```
### 4️⃣ Executar a aplicação
streamlit run salary_analytics_app.py

A aplicação estará disponível em:
http://localhost:8501

## 📂 Estrutura do Projeto
data-engineering-data-processing-lab/
├── salary_analytics_app.py
├── requirements.txt
├── data_salary_analytics_dataset.csv
└── README.md

- salary_analytics_app.py → Aplicação principal do Streamlit
- requirements.txt → Dependências do projeto
- data_salary_analytics_dataset.csv → Dataset utilizado
- README.md → Documentação

## 🛠 Tecnologias Utilizadas
- Python
- Pandas
- Streamlit
- Plotly

## 📈 Abordagem Analítica

O projeto contempla:
- Limpeza e filtragem de dados
- Agregações dinâmicas
- Cálculo de KPIs
- Atualização reativa das métricas
- Visualizações interativas orientadas à exploração

Demonstra aplicação prática de análise de dados com foco em experiência do usuário.

## 🚀 Possíveis Evoluções
- Otimização com cache de dados
- Integração com banco de dados relacional
- Camada de autenticação
- Análise temporal de tendências salariais
- Inclusão de modelo preditivo
- Containerização com Docker
- Pipeline CI/CD para deploy automatizado

## 📊 Papel no Engineering Portfolio

Este projeto demonstra:
- Pipeline analítico completo
- Transformação e modelagem de dados
- Construção de aplicação interativa
- Deploy público de solução analítica
- Mentalidade de data product

Conecta análise de dados, visualização e experiência interativa em uma única solução.

## 📜 Licença

MIT License

---

Dados geram valor quando se tornam exploráveis.