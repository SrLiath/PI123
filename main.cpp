#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    setlocale(LC_ALL,"Portuguese");

    string doencas[20] = {"diabete", "diabetes", "hipertensao"};
    char procurarDoenca[20];
    char tentarNovamente;
    bool achou;

       //navegacao
    int navegacao;
    int navegacaoDoenca;

    //dados do usuario
    char nome[30] = {};
    int idade = 0;

    telaUm:

    if(nome[0] == 0 && idade == 0){

            system("clear||cls");
            printf("Olá usuário, Seja Bem Vindo\n\n");
            printf("Informe seu nome: ");
            gets(nome);

            while (nome[0] == 0){
                system("clear||cls");
                printf("Percebi que você não digitou seu nome.\nPor favor digite seu nome: \n");
                gets(nome);
            }

            printf("Informe a sua idade: ");
            scanf("%d", &idade);

            while (idade <= 0){
                system("clear||cls");
                printf("Por favor informe uma idade válida\n");
                scanf("%d", &idade);
                system("clear||cls");
            }

    }

    system("clear||cls");
    printf("----------------------------------------------------------------------\n");
    printf("Seja bem vindo %s.\nNosso aplicativo tem o objetivo de ajudar você que está com problemas de saúde.\nVamos lhe ajudar listando todos os alimentos que deve comer e evitar de comer, e dicas para melhorar sua saúde\n\nNome: %s\nIdade: %d\n\n", nome, nome, idade);

    printf("\n^+---------------------------------------------^+");
    printf("\n1 - Listar as doencas\n");
    printf("\n2 - Informar a doenca\n");
    printf("\n^+---------------------------------------------^");
    scanf("%d", &navegacao);

    if(navegacao == 1){

        telaDois:


        system("cls");
        printf("Por favor navegue com os números abaixo\nSeu nome: %s\nSua idade: %d\n\n", nome, idade);
        printf("1 - Diabetes\n2 - Colesterol\n3 - Tela Inicial\n");
        scanf("%d", &navegacaoDoenca);

        if(navegacaoDoenca == 1){

            system("clear||cls");

            FILE *arq;
            char Linha[100];
            char *result;
            int i = 1;

            // Abre um arquivo TEXTO para LEITURA
            arq = fopen("diabetes.txt", "r");
            if (arq == NULL)  // Se houve erro na abertura
            {
                printf("Problemas na abertura do arquivo\n");
                return 0;
            }
            while (!feof(arq))
            {
                // Lê uma linha (inclusive com o '\n')
                result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
                if (result)  // Se foi possível ler
                printf("%s\n",Linha);
                i++;
            }

            fclose(arq);

            printf("\n1 - Tela Anterior");
            scanf("%d", &navegacao);

            if(navegacao == 1){
                goto telaDois;
            }

        }
        else if (navegacaoDoenca == 2){
            system("clear||cls");
            printf("A dupla hábitos alimentares saudáveis e prática regular de exercícios físicos é capaz de manter as taxas de colesterol bom (HDL) e ruim (LDL) em perfeito equilíbrio, afastando de perto o risco de infarto e derrame cerebral, além de outras doenças como o Mal de Alzheimer. Quem sofre com o problema sabe bem que a solução para este mal não está nas pílulas. Nem que você siga à risca os horários e as doses dos remédios, sem controlar a alimentação, as taxas de colesterol jamais entram nos eixos. Mas o contrário até pode acontecer: há quem aprenda a montar pratos saudáveis e, desta forma, passe longe da farmácia. A seguir, confira a lista de alimentos, para encampar uma batalha contra o colesterol alto e sair vencedor (sem, é claro, abrir mão de comer bem).\n");
            printf("\nPEIXES\n\nEles são excelente fonte de ácido graxo ômega 3, um tipo de gordura boa, do tipo insaturada, encontrada nos peixes de água fria, como salmão, atum e truta. “A gordura insaturada ajuda na redução dos níveis de triglicerídeos e colesterol total do sangue; reduz o risco de formação de coágulos, além de tornar o sangue mais fluido; sendo, portanto, importante aliada na prevenção das doenças cardiovasculares”, explica nutricionista da Unifesp Ana Maria Figueiredo Ramos.\n\nAVEIA\n\nAlém das fibras insolúveis, a aveia contém uma fibra solúvel chamada betaglucana, que exerce efeitos benéficos ao nosso organismo. Ela retarda o esvaziamento gástrico, promovendo maior saciedade, melhora a circulação, controla a glicemia (açúcar no sangue) e inibe a absorção de gordura (colesterol). “A aveia diminui as concentrações de colesterol total, lipídios totais e triglicerídeos de forma significativa e aumenta a fração do bom colesterol (HDL)”, explica nutricionista da Unifesp Ana Maria Figueiredo Ramos.\n\n");
            printf("1- Tela Anterior");
            scanf("%d", &navegacao);
            if(navegacao == 1){
                goto telaDois;
            }
        }
        else {
            goto telaUm;
        }

    }
    else if (navegacao == 2){

        telaTres:

            do {
            system("clear||cls");
            printf("Informe o nome da doença:\n");
            fflush(stdin);
            gets(procurarDoenca);

            int size = sizeof(doencas)/sizeof(doencas[0]);

            for (int i = 0; i < size; i++){
                if (strlwr(procurarDoenca) == doencas[i]){

                    printf("Hipertensão:\nAlimentos que devem ser consumidos em maiores quantidades\n\nA dieta orienta para o aumento no consumo diário de alimentos ricos em fibras, proteínas, cálcio, potássio, magnésio e gorduras insaturadas, como: ");
                    printf("- frutas;\n-carnes magras: preferir peixes, frango e cortes magros de carnes vermelhas;\n- gorduras boas: castanhas, amendoim, nozes, avelãs, azeite;\n-grãos integrais, como aveia, farinha de trigo integral, arroz integral e quinoa;-legumes e verduras;\n-leite e derivados desnatados.\nÉ importante observar que além de adotar uma alimentação saudável, a prática regular de atividades físicas também ajuda a reduzir a pressão arterial, além de controlar o peso e auxiliar na melhora geral da saúde.\n");
                    printf("Deseja pesquisar novamente? Y para sim, N para não ou V para voltar\n");
                    scanf("%c", &tentarNovamente);

                    if (tolower(tentarNovamente) == ('y')){
                        goto telaTres;
                    }

                    else if(tolower(tentarNovamente) == ('v')){
                        goto telaUm;
                    }

                    achou = true;
                }
            }

            if (achou == true){
                break;
            }

            printf("Infelizmente não temos essa doença na nossa base de dados\n");
            printf("Deseja pesquisar novamente? Y para sim, N para não ou V para voltar\n");
            scanf("%c", &tentarNovamente);

            if(tolower(tentarNovamente) == 'v'){
                goto telaUm;
            }

            } while (tolower(tentarNovamente) == 'y');

            printf("Obrigado por usar nosso aplicativo. Se Cuide!!\n\n");
    }

    return 0;

}

