#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

using namespace std;



void getInfo(const char doenca[30]){

            FILE *arq;
            char Linha[100];
            char *result;
            int i = 1;

            // Abre um arquivo TEXTO para LEITURA
            arq = fopen(doenca, "r");
            if (arq == NULL)  // Se houve erro na abertura
            {
                printf("Problemas na abertura do arquivo\n");
            }
            while (!feof(arq))
            {
                 // L� uma linha (inclusive com o '\n')
                result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n'
                if (result) // Se foi poss�vel ler
                printf("%s\n",Linha);
                i++;
            }

            fclose(arq);
}

void minusculo(char s1[], char s2[]){

    int i = 0;
    while(s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
}

int main()
{

    setlocale(LC_ALL,"Portuguese");

    char doencas[9][30] = {"", "hipertensao", "ansiedade", "anemia", "asma", "diabetes", "colesterol", "bronquite", "insonia"};
    char doenca[30];
    int size = sizeof(doencas)/sizeof(doencas[0]);
    char txt[] = {".txt"};
    char infoAdulto[] = {"info/adulto/"};
    char infoCrianca[] = {"info/crianca/"};
    char resposta[50];
    char tentarNovamente;
    char doencaMinusculo[30];
       //navegacao
    int navegacao;
    int navegacaoDoenca;

    //dados do usuario
    char nome[30] = {};
    int idade = 0;

    telaUm:

    if(nome[0] == 0 && idade == 0){
            system("clear||cls");
            printf("Ola usuario, Seja Bem Vindo\n\n");
            printf("Informe seu nome: ");
            gets(nome);
            while (nome[0] == 0){
                system("clear||cls");
                printf("Percebi que vocc nao digitou seu nome.\nPor favor digite seu nome: \n");
                gets(nome);
            }
            printf("Informe a sua idade: ");
            scanf("%d", &idade);

            while (idade <= 0){
                system("clear||cls");
                printf("Por favor informe uma idade valida\n");
                scanf("%d", &idade);
                system("clear||cls");
            }
    }

    system("clear||cls");
    printf("----------------------------------------------------------------------\n");
    printf("Seja bem vindo %s.\nNosso aplicativo tem o objetivo de ajudar voce que esta com problemas de saude.\nVamos lhe ajudar listando todos os alimentos que deve comer e evitar de comer de acordo com a doenca escolhida, e dicas para melhorar sua saude\n\nNome: %s\nIdade: %d\n\n", nome, nome, idade);
    printf("\n^+---------------------------------------------^+");
    printf("\n1 - Listar as doencas\n");
    printf("\n2 - Informar a doenca\n");
    printf("\n^+---------------------------------------------^");
    scanf("%d", &navegacao);


    if(navegacao == 1)
    {
        if(idade >= 18)
        {
            telaAdulto:

            system("cls");
            printf("Por favor navegue com os numeros abaixo\nSeu nome: %s\nSua idade: %d\n\n", nome, idade);
            printf("---------------------------------------------------------------------------------------------------------------\n");
            //19

            printf("1 - Hipertensao  |\n2 - Ansiedade    |\n3 - Anemia       |\n4 - Asma         |\n5 - Diabetes     |\n6 - Colesterol   |\n7 - Bronquite    |\n8 - Insonia      |");
            scanf("%d", &navegacaoDoenca);

            if (navegacaoDoenca == 0 ){
                printf("Digite um numero valido!!");
                Sleep(3000);
                goto telaAdulto;
            }
                for (int i = 1; i < size; i++){
                    strcpy(doenca, doencas[navegacaoDoenca]);

                    if(navegacaoDoenca < size){
                        if(strcmp(doencas[navegacaoDoenca], doenca) == 0){
                            system("clear||cls");
                            strcpy(resposta, infoAdulto);
                            strcat(resposta, doenca);
                            strcat(resposta, txt);
                            getInfo(resposta);
                            printf("\n1 - Tela Anterior ou qualquer outra tecla para tela inicial do programa");
                            scanf("%d", &navegacao);
                            if(navegacao == 1)goto telaAdulto;
                            else goto telaUm;
                        }
                    }
                }
        }
        else {

                telaCrianca:

                system("cls");
                printf("Ola percebi que voce e um pequeno gafanhoto que esta na fase de crescimento, vamos lhe ajudar mostrando os melhores alimentos para seu crescimento!!\nSeu nome: %s\nSua idade: %d\n\n", nome, idade);
                printf("---------------------------------------------------------------------------------------------------------------\n");
                //19

                printf("1 - Hipertensao  |\n2 - Ansiedade    |\n3 - Anemia       |\n4 - Asma         |\n5 - Diabetes     |\n6 - Colesterol   |\n7 - Bronquite    |\n8 - Insonia      |\n\n");
                scanf("%d", &navegacaoDoenca);

                if (navegacaoDoenca == 0 ){
                    printf("Digite um numero valido!!");
                    Sleep(3000);
                    goto telaCrianca;
                }

                for (int i = 1; i < size; i++){
                    strcpy(doenca, doencas[navegacaoDoenca]);
                    if(navegacaoDoenca < size){
                        if(strcmp(doencas[navegacaoDoenca], doenca) == 0){
                            system("clear||cls");
                            strcpy(resposta, infoCrianca);
                            strcat(resposta, doenca);
                            strcat(resposta, txt);
                            getInfo(resposta);

                            informarNovamente:
                            printf("\n1 - Tela Anterior ou qualquer outra tecla para tela inicial do programa");
                            scanf("%d", &navegacao);
                            if(navegacao == 1)goto telaCrianca;
                            else if(isdigit(navegacao)) goto telaUm;
                            else{goto informarNovamente;}
                        }
                    }
                }
        }
                printf("Nao encontrado na nossa base de dados!!");
                printf("\nDeseja pesquisar novamente? Y para sim, V para voltar na tela anterior ou qualquer tecla para sair\n");
                fflush(stdin);
                scanf("%c", &tentarNovamente);

                if (tolower(tentarNovamente) == ('y'))goto telaCrianca;
                else if(tolower(tentarNovamente) == ('v'))goto telaUm;
                else system("EXIT");

    }
    else if (navegacao == 2){

        telaTres:

            do {
            system("clear||cls");
            printf("Ola, aqui nesta categoria voce tem a opcao de digitar o nome da doenca que deseja consultar.\n\nInforme o nome da doenca:\n");
            fflush(stdin);
            gets(doenca);
                if(idade >= 18){
                    for (int i = 1; i <= size; i++){
                        minusculo(doenca,doencaMinusculo);
                        if(strcmp(doencas[i], doencaMinusculo) == 0){
                            strcpy(resposta, infoAdulto);
                            strcat(resposta, doenca);
                            strcat(resposta, txt);
                            getInfo(resposta);
                            printf("\nDeseja pesquisar novamente? Y para sim, V para voltar ou qualquer tecla para sair\n");
                            scanf("%c", &tentarNovamente);
                            if (tolower(tentarNovamente) == ('y'))goto telaTres;
                            else if(tolower(tentarNovamente) == ('v'))goto telaUm;
                        }
                    }
                }
                else {
                    for (int i = 1; i <= size; i++){
                        minusculo(doenca,doencaMinusculo);
                        if(strcmp(doencas[i], doencaMinusculo) == 0){
                            strcpy(resposta, infoCrianca);
                            strcat(resposta, doenca);
                            strcat(resposta, txt);
                            getInfo(resposta);
                            printf("\nDeseja pesquisar novamente? Y para sim, V para voltar ou qualquer tecla para sair\n");
                            scanf("%c", &tentarNovamente);
                            if (tolower(tentarNovamente) == ('y'))goto telaTres;
                            else if(tolower(tentarNovamente) == ('v'))goto telaUm;
                        }
                    }
                }
            printf("Infelizmente nao temos essa doenca na nossa base de dados\n");
            printf("\nDeseja pesquisar novamente? Y para sim, V para voltar ou qualquer tecla para sair\n");
            scanf("%c", &tentarNovamente);

            if(tolower(tentarNovamente) == 'v')goto telaUm;
            }while (tolower(tentarNovamente) == 'y');
                printf("Obrigado por usar nosso aplicativo. Se Cuide!!\n\n");
    }
    return 0;

}











