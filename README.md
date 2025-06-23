# trabalho_ED2

# Trabalho de Programação: Pilhas, Recursão e Visualização de Algoritmos

**Aluno:** Matheus Mangia, João Allemand, Pedro Paulo e Gabriel Maia
**Disciplina:** Estrutura de Dados
**Professor:** Milton

---

## 📌 Descrição Geral

Este trabalho tem como objetivo a implementação de dois algoritmos clássicos utilizando conceitos de **Estruturas de Dados (Pilhas)** e **Recursão**, com foco em:

- Controle de execução por passos
- Manipulação de vetores e estruturas dinâmicas
- Visualização intermediária do estado dos algoritmos

Os algoritmos desenvolvidos foram:

1. **Flood Fill com Pilha**
2. **Torres de Hanoi com Visualização**

---

## 🧱 Parte 1: Flood Fill com Pilha

### 📋 Descrição:

Implementação de um algoritmo de **Flood Fill** (preenchimento de regiões) utilizando uma **pilha genérica implementada manualmente**.

### 📌 Funcionamento:

- O programa **lê uma matriz de caracteres a partir de um arquivo texto** (`matriz_de_caracteres.txt`).
- O **ponto de partida** é identificado pelo caractere `'X'`.
- O algoritmo faz a propagação do preenchimento substituindo os espaços vizinhos.
- O usuário escolhe um valor **P** que define o número de passos entre cada visualização do estado da matriz.
- A cada **P passos**, o programa **exibe o estado atual da matriz** e aguarda o ENTER do usuário para continuar.

### 📌 Principais conceitos usados:

- Estrutura de Dados: **Pilha (Stack)** implementada manualmente
- Algoritmo: **Flood Fill (Busca em Profundidade)**
- Manipulação de Arquivos: **Leitura de matriz de caracteres**
- Controle de Fluxo: **Pausas por ENTER**

---

## 🏯 Parte 2: Torres de Hanoi com Visualização

### 📋 Descrição:

Implementação do problema das **Torres de Hanoi**, utilizando **recursão** e **vetores como estrutura de armazenamento das torres**.

### 📌 Funcionamento:

- O usuário informa:
  - O número de discos (**N**)
  - A quantidade de movimentos entre cada visualização (**M**)
- O algoritmo resolve o problema recursivamente, **movendo os discos de forma ordenada entre os três pinos (vetores)**.
- A cada **M movimentos**, o estado das torres é exibido.
- O programa aguarda ENTER para continuar nas visualizações intermediárias.

### 📌 Principais conceitos usados:

- **Recursão**
- Estrutura de Dados: **Vetores representando pilhas**
- Controle de Fluxo: **Contagem de movimentos e pausas**
- Cálculo matemático: **Número total de movimentos (`2^N - 1`)**

---

## ✅ Conclusão

Este trabalho proporcionou a aplicação prática de:

- **Estruturas de Dados Personalizadas**
- **Recursão**
- **Manipulação de Arquivos**
- **Controle de execução e visualização passo a passo**

Ambos os programas foram testados com diferentes entradas e apresentam funcionamento correto, respeitando as regras dos algoritmos propostos.

---

## 📎 Arquivos no Projeto:

- `flood_fill_stack.cpp` → Implementação do Flood Fill com Pilha
- `hanoi.cpp` → Implementação das Torres de Hanoi com Visualização
- `matriz_de_caracteres.txt` → Exemplo de matriz de entrada para o Flood Fill

---

*Fim do README.*
