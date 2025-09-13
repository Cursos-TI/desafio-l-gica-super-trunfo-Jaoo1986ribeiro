#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Carta {
    char estado[3];
    int codigo;
    char cidade[50];
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n--- Cadastro da Carta %d ---\n", numero);
    
    printf("Estado (sigla 2 letras): ");
    scanf("%2s", carta->estado);
    limparBuffer();
    
    printf("Código (número): ");
    scanf("%d", &carta->codigo);
    limparBuffer();
    
    printf("Cidade: ");
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;
    
    printf("População: ");
    scanf("%lld", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%lf", &carta->area);
    
    printf("PIB: ");
    scanf("%lld", &carta->pib);
    
    printf("Pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    limparBuffer();
}

void exibirCarta(struct Carta carta) {
    printf("\n--- Carta %s ---\n", carta.cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("População: %lld\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %lld\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
}

int main() {
    struct Carta carta1, carta2;
    int opcao, opcao2;
    double densidade1, densidade2;
    
    printf("Bem-vindo ao Super Trunfo - Países!\n");
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibir cartas cadastradas
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Menu de comparação
    do {
        printf("\n--- Menu de Comparação ---\n");
        printf("1. Comparar por População\n");
        printf("2. Comparar por Área\n");
        printf("3. Comparar por PIB\n");
        printf("4. Comparar por Pontos Turísticos\n");
        printf("5. Comparar por Densidade Populacional\n");
        printf("6. Comparar por dois atributos (Mestre)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: // População
                if (carta1.populacao > carta2.populacao) {
                    printf("\nCarta %s vence por população!\n", carta1.cidade);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("\nCarta %s vence por população!\n", carta2.cidade);
                } else {
                    printf("\nEmpate em população!\n");
                }
                break;
                
            case 2: // Área
                if (carta1.area > carta2.area) {
                    printf("\nCarta %s vence por área!\n", carta1.cidade);
                } else if (carta2.area > carta1.area) {
                    printf("\nCarta %s vence por área!\n", carta2.cidade);
                } else {
                    printf("\nEmpate em área!\n");
                }
                break;
                
            case 3: // PIB
                if (carta1.pib > carta2.pib) {
                    printf("\nCarta %s vence por PIB!\n", carta1.cidade);
                } else if (carta2.pib > carta1.pib) {
                    printf("\nCarta %s vence por PIB!\n", carta2.cidade);
                } else {
                    printf("\nEmpate em PIB!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("\nCarta %s vence por pontos turísticos!\n", carta1.cidade);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("\nCarta %s vence por pontos turísticos!\n", carta2.cidade);
                } else {
                    printf("\nEmpate em pontos turísticos!\n");
                }
                break;
                
            case 5: // Densidade Populacional
                densidade1 = carta1.populacao / carta1.area;
                densidade2 = carta2.populacao / carta2.area;
                
                if (densidade1 < densidade2) {
                    printf("\nCarta %s vence por densidade populacional!\n", carta1.cidade);
                } else if (densidade2 < densidade1) {
                    printf("\nCarta %s vence por densidade populacional!\n", carta2.cidade);
                } else {
                    printf("\nEmpate em densidade populacional!\n");
                }
                break;
                
            case 6: // Nível Mestre - Dois atributos
                printf("\n--- Escolha o primeiro atributo ---\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turísticos\n");
                printf("5. Densidade Populacional\n");
                printf("Escolha: ");
                scanf("%d", &opcao);
                
                printf("--- Escolha o segundo atributo ---\n");
                printf("1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Pontos Turísticos\n");
                printf("5. Densidade Populacional\n");
                printf("Escolha: ");
                scanf("%d", &opcao2);
                
                // Lógica complexa de comparação com dois atributos
                int vence1 = 0, vence2 = 0;
                
                // Comparar primeiro atributo
                switch(opcao) {
                    case 1:
                        if (carta1.populacao > carta2.populacao) vence1++;
                        else if (carta2.populacao > carta1.populacao) vence2++;
                        break;
                    case 2:
                        if (carta1.area > carta2.area) vence1++;
                        else if (carta2.area > carta1.area) vence2++;
                        break;
                    case 3:
                        if (carta1.pib > carta2.pib) vence1++;
                        else if (carta2.pib > carta1.pib) vence2++;
                        break;
                    case 4:
                        if (carta1.pontos_turisticos > carta2.pontos_turisticos) vence1++;
                        else if (carta2.pontos_turisticos > carta1.pontos_turisticos) vence2++;
                        break;
                    case 5:
                        densidade1 = carta1.populacao / carta1.area;
                        densidade2 = carta2.populacao / carta2.area;
                        if (densidade1 < densidade2) vence1++;
                        else if (densidade2 < densidade1) vence2++;
                        break;
                }
                
                // Comparar segundo atributo
                switch(opcao2) {
                    case 1:
                        if (carta1.populacao > carta2.populacao) vence1++;
                        else if (carta2.populacao > carta1.populacao) vence2++;
                        break;
                    case 2:
                        if (carta1.area > carta2.area) vence1++;
                        else if (carta2.area > carta1.area) vence2++;
                        break;
                    case 3:
                        if (carta1.pib > carta2.pib) vence1++;
                        else if (carta2.pib > carta1.pib) vence2++;
                        break;
                    case 4:
                        if (carta1.pontos_turisticos > carta2.pontos_turisticos) vence1++;
                        else if (carta2.pontos_turisticos > carta1.pontos_turisticos) vence2++;
                        break;
                    case 5:
                        densidade1 = carta1.populacao / carta1.area;
                        densidade2 = carta2.populacao / carta2.area;
                        if (densidade1 < densidade2) vence1++;
                        else if (densidade2 < densidade1) vence2++;
                        break;
                }
                
                // Determinar vencedor
                if (vence1 > vence2) {
                    printf("\nCarta %s vence por %d a %d!\n", carta1.cidade, vence1, vence2);
                } else if (vence2 > vence1) {
                    printf("\nCarta %s vence por %d a %d!\n", carta2.cidade, vence2, vence1);
                } else {
                    printf("\nEmpate geral! %d a %d\n", vence1, vence2);
                }
                break;
                
            case 0:
                printf("\nObrigado por jogar!\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}