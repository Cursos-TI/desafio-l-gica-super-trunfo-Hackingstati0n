#include <stdio.h>
#include <string.h>

// Desafio Jogo Triunfo LV: "Aventureiro(Estacio)"
// Adicionei alguma cores de acordo com os valores ACSII de cada cor
#define NEGRITO "\033[1m"
#define RESET "\033[0m"
#define AMARELO "\033[33m"
#define VERDE "\033[32m"

// Esse bloco reserva a estrutura
typedef struct {
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Essa parte para exibir a arte ASCII: Assim deixa a entrada mais divertida!
void exibirArteAscii() {
    printf(NEGRITO AMARELO " _____           _           _            ____________ \n" RESET);
    printf(NEGRITO VERDE "/  __ \\         | |         | |           | ___ \\ ___ \\\n" RESET);
    printf(NEGRITO AMARELO "| /  \\/ __ _  __| | __ _ ___| |_ _ __ ___ | |_/ / |_/ /\n" RESET);
    printf(NEGRITO VERDE "| |    / _` |/ _` |/ _` / __| __| '__/ _ \\| ___ \\    / \n" RESET);
    printf(NEGRITO AMARELO "| \\__/\\ (_| | (_| | (_| \\__ \\ |_| | | (_) | |_/ / |\\ \\ \n" RESET);
    printf(NEGRITO VERDE " \\____/\\__,_|\\__,_|\\__,_|___/\\__|_|  \\___/\\____/\\_| \\_|\n" RESET);
    printf(NEGRITO "                                                       \n" RESET);
    printf(NEGRITO "                                                       \n" RESET);
    printf(NEGRITO VERDE "Feito por: David A. Mascaro (Estacio)\n" RESET);
    printf("\n");
}

// Aqui adicionei uma função para cadastrar uma carta, removi acentos pq nao consigo fazer ele ler 
void cadastrarCarta(Carta *carta) {
    printf("Digite o codigo da cidade:\n");
    scanf("%d", &carta->codigo);

    printf("Digite o nome da cidade:\n");
    getchar(); // Limpa o buffer do teclado antes de usar fgets, aqui ele pode bugar
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0; // Remove o caractere de nova linha '\n'

    printf("Digite a populacao da cidade:\n");
    scanf("%d", &carta->populacao);

    printf("Digite a area da cidade (km²):\n");
    scanf("%f", &carta->area);
    while ((getchar()) != '\n'); // Limpa o buffer de entrada

    printf("Digite o PIB da cidade (em bilhoes):\n");
    scanf("%f", &carta->pib);
    while ((getchar()) != '\n'); // Limpa o buffer de entrada novamente

    printf("Digite o numero de pontos turisticos:\n");
    scanf("%d", &carta->pontosTuristicos);
}

// Agora ele vai ler a função para exibir informações de uma carta
void exibirCarta(Carta carta) {
    printf("\nInformações da Carta:\n");
    printf("=============================\n");
    printf(NEGRITO "Código da cidade: " RESET "%d\n", carta.codigo);
    printf("=============================\n");
    printf(NEGRITO "Nome da cidade: " RESET "%s\n", carta.nome);
    printf("=============================\n");
    printf(NEGRITO "Populacao: " RESET "%d\n", carta.populacao);
    printf("=============================\n");
    printf(NEGRITO "Area (km²): " RESET "%.2f\n", carta.area);
    printf("=============================\n");
    printf(NEGRITO "PIB (em bilhoes): " RESET "%.2f\n", carta.pib);
    printf("=============================\n");
    printf(NEGRITO "Pontos turisticos: " RESET "%d\n", carta.pontosTuristicos);
}

// Aqui a função para comparar cartas
void compararCartas(Carta carta1, Carta carta2) {
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos turisticos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Como parte do LV Aventureiro, adicionei o switch
    switch (opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao)
                printf("Carta 1 vence em Populaçao!\n");
            else if (carta1.populacao < carta2.populacao)
                printf("Carta 2 venceu em Populaçao!\n");
            else
                printf("Empate em Populacao!\n");
            break;
        case 2:
            if (carta1.area > carta2.area)
                printf("Carta 1 venceu em Area!\n");
            else if (carta1.area < carta2.area)
                printf("Carta 2 venceu em Area!\n");
            else
                printf("Empate em Area!\n");
            break;
        case 3:
            if (carta1.pib > carta2.pib)
                printf("Carta 1 venceu em PIB!\n");
            else if (carta1.pib < carta2.pib)
                printf("Carta 2 venceu em PIB!\n");
            else
                printf("Empate em PIB!\n");
            break;
        case 4:
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Carta 1 venceu em Pontos turísticos!\n");
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("Carta 2 venceu em Pontos turísticos!\n");
            else
                printf("Temos Um Empate em Pontos turísticos!\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    // Exibindo a arte ASCII
    exibirArteAscii();

    // Menu interativo
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Carta 1\n");
        printf("2. Cadastrar Carta 2\n");
        printf("3. Comparar Cartas\n");
        printf("4. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCarta(&carta1);
                exibirCarta(carta1);
                break;
            case 2:
                cadastrarCarta(&carta2);
                exibirCarta(carta2);
                break;
            case 3:
                compararCartas(carta1, carta2);
                break;
            case 4:
                printf("Ate mais! Obrigado por jogar...\n");
                break;
            default:
                printf("Ops opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
