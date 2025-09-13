Super Trunfo - Países - Comparação das Cartas
Este projeto implementa um sistema de comparação de cartas no estilo "Super Trunfo" com o tema de países, permitindo aos usuários cadastrar cartas de cidades e comparar seus atributos de diferentes maneiras.

Descrição
O sistema permite cadastrar cartas representando cidades com diversos atributos (população, área, PIB, pontos turísticos) e implementa três níveis de complexidade para comparação entre as cartas:

Nível Novato: Comparação básica de atributos individuais

Nível Aventureiro: Cálculo de atributos derivados (densidade populacional, PIB per capita)

Nível Mestre: Comparação avançada com múltiplos atributos e cálculo do "Super Poder"

Funcionalidades
Nível Novato
Cadastro de cartas com atributos básicos

Comparação individual de atributos (população, área, PIB, pontos turísticos)

Interface simples com entrada via terminal

Nível Aventureiro
Cálculo automático de densidade populacional

Cálculo automático de PIB per capita

Exibição dos atributos calculados

Nível Mestre
Cálculo do "Super Poder" (soma ponderada de todos os atributos)

Comparação avançada entre múltiplos atributos

Sistema de pontuação para determinar a carta vencedora

Tecnologias Utilizadas
Linguagem C

Estruturas de dados (struct)

Entrada/saída padrão (stdio.h)

Manipulação de strings (string.h)

Funções de caractere (ctype.h)

Como Compilar e Executar
Compilação
text
gcc super_trunfo.c -o super_trunfo
Execução
text
./super_trunfo
Como Usar
Execute o programa

Selecione o nível de desafio (1-Novato, 2-Aventureiro, 3-Mestre)

Cadastre as duas cartas, fornecendo os dados solicitados:

Estado (sigla de 2 letras)

Código (1-4)

Nome da cidade

População

Área

PIB

Pontos turísticos

Visualize as cartas cadastradas

No nível Mestre, visualize a comparação detalhada entre as cartas

Estrutura dos Dados
Cada carta é representada pela seguinte estrutura:

c
struct Carta {
    char estado[3];
    int codigo;
    char cidade[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
    double super_poder;
};
Regras de Comparação
População, Área, PIB, Pontos Turísticos: Maior valor vence

Densidade Populacional: Menor valor vence

Super Poder: Maior valor vence (soma de todos os atributos com densidade invertida)

Desenvolvimento
Este projeto foi desenvolvido como parte de um desafio de programação, com foco no aprendizado de:

Estruturas de dados em C

Manipulação de entrada/saída

Implementação de lógica de comparação

Organização de código em funções

Validação de entrada de dados

Licença
Este projeto é para fins educacionais e pode ser utilizado livremente para aprendizado.
