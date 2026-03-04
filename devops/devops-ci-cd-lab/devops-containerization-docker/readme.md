```sh
     source venv/bin/activate
```

## Estrutura do Projeto

- `app.py`: Arquivo principal da aplicação.
- `models.py`: Modelos do banco de dados com SQLAlchemy.
- `schemas.py`: Schemas para validação com Pydantic.
- `database.py`: Configuração do banco SQLite.
- `routers/`: Diretório com rotas para alunos, cursos e matrículas.
- `requirements.txt`: Lista de dependências.

---
# 🧠 Arquitetura da Aplicação

- `app.py` → Inicialização da aplicação FastAPI
- `database.py` → Configuração do banco SQLite
- `models.py` → Modelos ORM com SQLAlchemy
- `schemas.py` → Validação de dados com Pydantic
- `routers/` → Separação modular das rotas
- `escola.db` → Banco criado automaticamente na primeira execução

A arquitetura segue separação clara entre:

- Camada de API
- Camada de validação
- Camada de persistência

---

# ▶️ Executando Localmente (Sem Docker)

1. Criar ambiente virtual
2. Ativar ambiente
3. Instalar dependências
4. Iniciar servidor com Uvicorn

Após iniciar, acessar:

http://127.0.0.1:8000/docs

A documentação interativa Swagger será exibida automaticamente.

---

# 🐳 Executando com Docker (Recomendado)

## Build da imagem

Criar a imagem Docker a partir do Dockerfile.

## Executar container

Rodar o container expondo a porta 8000.

Após execução, acessar:

http://localhost:8000/docs

---

# 📘 Endpoints Principais

A API permite:

- Criar alunos
- Listar alunos
- Criar cursos
- Listar cursos
- Realizar matrículas
- Listar matrículas

A documentação interativa pode ser acessada em `/docs`.

---

# 🗄️ Banco de Dados

- Banco utilizado: SQLite
- Arquivo: `escola.db`
- Criado automaticamente na primeira execução
- Para resetar o banco, basta apagar o arquivo `escola.db`

⚠️ Atenção: apagar o arquivo remove todos os dados.

---

# 🚀 Aplicação em DevOps

Este projeto pode ser expandido para:

- Docker Compose
- Integração com PostgreSQL
- Deploy em Google Cloud Run
- CI/CD com GitHub Actions
- Versionamento de imagens
- Monitoramento e logging

---

# ☁️ Contexto de Uso

Este código foi originalmente disponibilizado pela Alura como parte da Imersão DevOps.

Neste repositório, ele é utilizado para:

- Testes de containerização
- Simulações de deploy em cloud
- Estudos de arquitetura backend
- Experimentos com infraestrutura

---

# 🔮 Próximos Passos Evolutivos

- Substituir SQLite por PostgreSQL
- Implementar autenticação JWT
- Criar docker-compose com banco separado
- Adicionar healthcheck
- Criar pipeline CI/CD
- Deploy automatizado em cloud

---

# 📄 Licença

Este projeto está sob licença MIT.

---

> Containerização elimina o clássico problema: “na minha máquina funciona”.
