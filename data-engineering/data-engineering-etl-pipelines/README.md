# 🔄 Pipeline de Dados em Python (ETL com SQLite)

> Implementação incremental de uma pipeline de Extração, Transformação e Carga (ETL) utilizando Python puro e SQLite.

Este projeto demonstra a construção progressiva de uma pipeline de dados aplicada a um cenário de produção de alimentos.  

A solução evolui em versões, adicionando regras de negócio, limpeza, transformação e enriquecimento de dados até consolidar uma estrutura consistente de processamento.

Este projeto representa o domínio de **Data Engineering** dentro do engineering-portfolio.

---

## 🎯 Objetivo

Construir uma pipeline didática que seja capaz de:

- Extrair dados de arquivos CSV
- Aplicar regras de negócio
- Realizar limpeza e transformação de dados
- Enriquecer registros com métricas adicionais
- Persistir dados tratados em banco SQLite

O foco é demonstrar o ciclo completo de processamento de dados estruturados.

---

## 🧠 Arquitetura da Pipeline

A pipeline segue o fluxo clássico de ETL:
Arquivo CSV
↓
Extração
↓
Limpeza
↓
Transformação
↓
Regras de Negócio
↓
Enriquecimento
↓
Carga no SQLite


A evolução entre versões demonstra maturidade progressiva no tratamento de dados.

---

## 📂 Evolução das Versões

### 🔹 Versão 1 — `etl_pipeline_v1.py`

- Criação do banco SQLite
- Criação da tabela `produtos`
- Leitura do arquivo `food_production_dataset.csv`
- Inserção direta de todos os registros
- Sem regras de filtragem ou transformação

Objetivo: Estrutura básica de ingestão e persistência.

---

### 🔹 Versão 2 — `etl_pipeline_v2.py`

- Implementação de regra de negócio:
  - Inserir apenas registros com `quantidade > 10`
- Recriação da tabela a cada execução

Objetivo: Introduzir filtragem baseada em regra operacional.

---

### 🔹 Versão 3 — `etl_pipeline_v3.py`

- Limpeza da coluna `receita_total`
- Remoção do caractere ponto (`.`)
- Ajuste do tipo da coluna para `INTEGER`
- Manutenção da regra `quantidade > 10`

Objetivo: Corrigir inconsistências numéricas e evitar truncamento.

---

### 🔹 Versão 4 — `etl_pipeline_v4.py`

- Inclusão da coluna `margem_lucro`
- Cálculo da margem bruta por produto
- Manutenção das regras anteriores

Objetivo: Enriquecer os dados com métrica derivada.

---

### 🔹 Versão 5 — `etl_pipeline_v5.py`

- Conversão correta de valores numéricos com arredondamento
- Margem de lucro arredondada para duas casas decimais
- Leitura ajustada do dataset
- Consolidação das regras e transformações anteriores

Objetivo: Refinamento e robustez do pipeline.

---

## 🗃 Estrutura da Tabela `produtos`

| Coluna        | Tipo     | Descrição |
|---------------|----------|-----------|
| produto       | TEXT     | Nome do produto |
| quantidade    | INTEGER  | Quantidade produzida |
| preco_medio   | REAL     | Preço médio unitário |
| receita_total | INTEGER  | Receita total limpa e convertida |
| margem_lucro  | REAL     | Margem de lucro calculada |

---

## ⚙️ Como Executar

### 1️⃣ Pré-requisitos

- Python 3.x instalado

O projeto utiliza apenas bibliotecas padrão:

- `csv`
- `sqlite3`

---

### 2️⃣ Estrutura Esperada

Certifique-se de que o arquivo `food_production_dataset.csv` esteja na mesma pasta dos scripts.
data-engineering-etl-pipelines/
├── etl_pipeline_v1.py
├── etl_pipeline_v2.py
├── etl_pipeline_v3.py
├── etl_pipeline_v4.py
├── etl_pipeline_v5.py
├── food_production_dataset.csv
└── README.md


---

### 3️⃣ Executar o script desejado

Exemplo:
	```
	bash
	python etl_pipeline_v5.py
	```
Após a execução:

Será criado (ou recriado) o banco dsadb.db

A tabela produtos será populada com os dados processados

## 🛠 Tecnologias Utilizadas
- Python 3
- SQLite
- CSV (biblioteca padrão)

## 📈 Conceitos Demonstrados

- ETL tradicional
- Aplicação de regras de negócio
- Limpeza de dados numéricos
- Transformação de tipos
- Enriquecimento com métricas derivadas
- Persistência relacional
- Evolução incremental de pipeline

## 🚀 Possíveis Evoluções

- Modularização em funções reutilizáveis
- Separação por camadas (extract / transform / load)
- Uso de Pandas para maior performance
- Integração com banco PostgreSQL
- Logging estruturado
- Tratamento de exceções robusto
- Testes automatizados
- Containerização com Docker
- Orquestração com Airflow ou Prefect

## 📊 Papel no Engineering Portfolio

Este projeto demonstra:

- Fundamentos sólidos de Data Engineering
- Implementação manual de ETL
- Evolução arquitetural progressiva
- Aplicação prática de regras de negócio
- Estruturação de dados para persistência

Representa a base de pipelines estruturadas antes da adoção de ferramentas mais avançadas de orquestração e processamento distribuído.

## 📜 Licença

MIT License

---

Dados confiáveis são construídos com processos confiáveis.