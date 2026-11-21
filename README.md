# Clocks

**Clocks** é um projeto realizado na disciplina de Estrutura de Dados 1 do curso ADS do IFSP Câmpus Hortolândia, que tem o objetivo de calcular a quantidade de clocks para cada uma das funções de inserir, imprimir e remover das estruturas de dados pilha, fila e lista, testando com 1000, 3000, 5000, 10000 e 50000 elementos, divididos em 3 baterias de teste para cada uma das funções e anotando esses valores em uma tabela, além de calcular a média de cada resultado das baterias de teste.

# Funcionalidades

- Calcular a quantidade de clocks para a função de inserir em pilha, fila e lista.
- Calcular a quantidade de clocks para a função de imprimir em pilha, fila e lista.
- Calcular a quantidade de clocks para a função de remover em pilha, fila e lista.
- Testar as funções com 1000, 3000, 5000, 10000 e 50000 elementos, divididos em 3 baterias de teste.
- Calcular a média dos resultados das baterias de teste.

Obs: as anotações de cada bateria de teste e das médias, estão no [Relatório](https://github.com/LucasBoaratti/Clocks/blob/main/Relatório.docx).

# Tecnologias utlizadas

<img src="https://cdn.jsdelivr.net/npm/@programming-languages-logos/c@0.0.3/c.png" alt="Linguagem C" title="Linguagem C" width="70px" height="70px" />

# Estrutura do projeto

```text
Clocks/
├── FilaComClock/ # Testes da fila
|   ├── .vscode 
|   ├── main.c 
|   ├── fila.c 
|   └── fila.h 
├── ListaComClock/ # Testes da lista
|   ├── .vscode 
|   ├── main.c 
|   ├── lista.c 
|   └── lista.h 
├── PilhaComClock/ # Testes da pilha
|   ├── .vscode 
|   ├── main.c 
|   ├── pilha.c 
|   └── pilha.h 
└── Relatório.docx # Explicação e tabelas com cada bateria de teste da pilha, fila e lista, e suas médias.
```

# Como rodar o projeto

1. Clique no botão Code e copie a URL do projeto:

```bash
https://github.com/LucasBoaratti/Clocks.git
```

2. Abra o Prompt de comando (ou PowerShell ou GitBash) em sua área de trabalho ou em documentos e realize o seguinte comando:

OBS: Certifique que o Git está instalado no seu computador. Caso não esteja, instale aqui: [Git](https://git-scm.com/downloads)

```bash 
git clone https://github.com/LucasBoaratti/Clocks.git
```

3. Acesse a pasta do projeto:

```bash
cd .\Clocks
```

4. Agora, entre no VSCode:

```bash
code .
```

5. Instale a extensão do C/C++ no VSCode, caso ainda não tenha;

6. Instale o compilador GCC no seu computador, caso ainda não tenha. Você pode baixá-lo aqui: [MinGW](https://sourceforge.net/projects/mingw/);

7. Acesse uma das pastas das estruturas de dados (FilaComClock, ListaComClock ou PilhaComClock) para compilar a respectiva estrutura de dados:

```bash
cd FilaComClock
```

ou

```bash
cd ListaComClock
```

ou

```bash
cd PilhaComClock
```

8. Abra o terminal no VSCode e compile o projeto utilizando o comando:

```bash
gcc -o nome_do_executavel caminho_para_o_arquivo_main.c
```

9. Execute o projeto com o comando:

```bash
./nome_do_executavel
```