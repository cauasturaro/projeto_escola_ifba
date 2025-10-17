# Projeto Escola

Projeto Escola é um trabalho da disciplina INF029 (Laboratório de Programação) do Instituto Federal da Bahia (IFBA), do curso de Análise e Desenvolvimento de Sistemas — 2º semestre. Este projeto implementa um sistema simples de gerenciamento escolar em C para a prática de conceitos de modularidade, manipulação de arrays, entrada/saída em console e organização em camadas (model, view, controller, utils).

## Resumo

O sistema permite cadastrar e gerenciar Pessoas (Alunos e Professores) e Disciplinas. Fornece operações básicas de CRUD, listagens com adaptadores de exibição e ordenação, busca e algumas validações de entrada.

## Funcionalidades principais

- Gerenciamento de Pessoas:
  - Adicionar aluno/professor
  - Listar alunos/professores
  - Listar de maneira ordenada de acordo com algum "atributo"
  - Atualizar e remover registros
  - Listar aniversariantes de um mês em específico
  - Buscar pessoas por nome
- Gerenciamento de Disciplinas:
  - Adicionar disciplina
  - Listar disciplinas
  - Listar de maneira ordenada de acordo com algum "atributo"
  - Associar professor e alunos a uma disciplina
  - Atualizar e remover disciplinas
- Utilitários:
  - Validação de entradas (nomes, números, códigos...)
  - Ordenação genérica com adapters
  - Menu de desenvolvedor para facilitar testes

## Estrutura do projeto

Diretórios principais:

- `controller/` — lógica de controle (operações CRUD, fluxo de menus)
- `model/` — definições e estruturas de dados (Person, Subject, adapters)
- `view/` — funções de exibição e menus (entrada/saída com o usuário)
- `utils/` — funções auxiliares (validações, leitura formatada)
- `output/` — local onde os objetos compilados e o binário são gerados

## Como compilar e rodar

Requisitos básicos:

- GCC (ou outro compilador compatível com C)
- GNU Make (no Linux) ou MSYS2/MinGW/WSL no Windows

1. Linux / macOS:

   Entre na pasta `src` e execute:

   ```bash
   cd src
   make
   make start
   ```

2. Windows — opção recomendada: MSYS2 / MinGW (GCC)

- Instale MSYS2: https://www.msys2.org/
- No terminal MSYS2 (mingw64), instale ferramentas:

  ```bash
  pacman -Syu
  pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
  ```

- No prompt `MINGW64` (ou `MSYS2`), vá para a pasta `src` e rode:

  ```bash
  cd /c/caminho/para/projeto_escola_ifba/src
  make
  ../output/program
  ```

3. Windows — alternativa: WSL (Windows Subsystem for Linux)

- Instale o WSL e uma distribuição Linux (ex: Ubuntu) e siga as instruções de Linux acima dentro do WSL.

## Dicas e troubleshooting

- Se o `make` não for encontrado no Windows, instale MSYS2 ou use WSL.
- Se o `gcc` não for encontrado, instale MinGW-w64 (via MSYS2) ou configure outro compilador.
- Para limpar build artifacts:

  ```bash
  cd src
  make clean
  ```
