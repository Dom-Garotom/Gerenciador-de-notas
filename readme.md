# Sistema de Gestão Escolar

Este projeto é um sistema de gestão escolar que permite cadastrar alunos, disciplinas, lançar notas, calcular médias e gerar relatórios.

## Funcionalidades

- **Cadastrar Aluno**: Adiciona um novo aluno ao sistema.
- **Cadastrar Disciplina**: Adiciona uma nova disciplina ao sistema.
- **Lançar Notas**: Permite inserir notas para os alunos em diferentes disciplinas.
- **Consultar Notas de um Aluno**: Visualiza as notas de um aluno específico.
- **Consultar Notas de uma Disciplina**: Visualiza as notas de todos os alunos em uma disciplina específica.
- **Ver Médias dos Alunos**: Calcula e exibe as médias de notas de cada aluno em suas disciplinas.
- **Ver Médias Gerais dos Alunos**: Calcula e exibe a média geral de cada aluno em todas as disciplinas.
- **Gerar Relatório**: Cria um relatório individual para cada aluno, detalhando suas notas e média.


### Arquivos Principais

O projeto utiliza os seguintes arquivos `.txt` como um banco de dados:

- `notas.txt`: Arquivo que armazena as notas dos alunos.
- `alunos.txt`: Arquivo que armazena informações dos alunos.
- `relatorio.txt`: Arquivo que armazena os relatórios gerados.
- `disciplinas.txt`: Armazena informações das disciplinas, como nome e código da disciplina.

Estes arquivos são essenciais para o funcionamento do sistema e devem ser incluídos no repositório.


### Funções Principais

#### `retornarMediasGeraisDosAlunos()`
Calcula a média geral dos alunos a partir das notas armazenadas em `notas.txt`.

#### `gerarRelatorio()`
Gera um relatório individual com as informações do aluno, suas notas e média geral.

## Como Usar

1. Clone o repositório:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_DIRETORIO>

2. Compile o código:
  ```bash
    g++ -o sistema_gestao system.cpp

3. Rode o código :
  ```bash
    ./system