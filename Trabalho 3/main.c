#include <stdio.h>
#include <stdlib.h>

void LimparTela();
void InsertionSort(int Array[], int Informados);
void SelectionSort(int Array[], int Informados);
void BubbleSort(int Array[], int Informados);
void TrocaValores(int *xp, int *yp);
int Ctd, CtdAux, Comparacoes, Trocas;

int main()
{
    int Array[24];
    int Restante = 25;
    int Informados = 0;
    int ValorInserir;

    do {
        LimparTela();
        printf("X--------------------------------X\n");
        printf("| INFORME UM VALOR ENTRE 1 E 100 |\n");
        printf("|                                |\n");
        printf("| INFORME 0 PARA PROSSEGUIR      |\n");
        printf("| IMEDIATAMENTE A ORDENACAO      |\n");
        printf("X----------------------X----------X\n");
        printf("| VALORES RESTANTES %d |\n", Restante);
        printf("X----------------------X\n");
        scanf("%d", &ValorInserir);

        if (ValorInserir != 0){
            Array[Informados] = ValorInserir;
            Informados++;
            Restante--;
        }
    }while(Restante > 0 && ValorInserir != 0);

    InsertionSort(Array, Informados);
    SelectionSort(Array, Informados);
    BubbleSort(Array, Informados);


    /*PrintArray(Array, Informados); */
return 0;
}

void InsertionSort(int Array[], int Informados){
    int Insertion[24];
    Comparacoes = 0;
    Trocas = 0;

    /* CRIA CÓPIA DO VETOR PRINCIPAL */
    memcpy(Insertion, Array, sizeof(Insertion));

    int Troca;

    for (Ctd = 1; Ctd < Informados; Ctd++) {
        Troca = Insertion[Ctd];
        CtdAux = Ctd - 1;
        Comparacoes++;

        while (CtdAux >= 0 && Insertion[CtdAux] > Troca) {
            Insertion[CtdAux + 1] = Insertion[CtdAux];
            CtdAux = CtdAux - 1;
            Comparacoes++;
            Trocas++;
        }
        Insertion[CtdAux + 1] = Troca;
    }

    PrintArray(Insertion, Informados);
    printf("\nINSERCTION: Comparacoes: %d Trocas: %d\n", Comparacoes, Trocas);
}

void SelectionSort(int Array[], int Informados){
    int PosMenor;
    int Selection[24];
    Comparacoes = 0;
    Trocas = 0;

    /* CRIA CÓPIA DO VETOR PRINCIPAL */
    memcpy(Selection, Array, sizeof(Selection));


    for (Ctd = 0; Ctd < Informados-1; Ctd++)
    {
        PosMenor = Ctd;
        Comparacoes++;
        for (CtdAux = Ctd + 1; CtdAux < Informados; CtdAux++){
            Comparacoes++;
            if (Selection[CtdAux] < Selection[PosMenor]){
                PosMenor = CtdAux;
            }
        }

        TrocaValores(&Selection[PosMenor], &Selection[Ctd]);
        Trocas++;
    }

    printf("SELECTION.: Comparacoes: %d Trocas: %d\n", Comparacoes, Trocas);
    /*PrintArray(Selection, Informados);*/

}

void BubbleSort(int Array[], int Informados){
    int Troca;
    int Bubble[24];
    Comparacoes = 0;
    Trocas = 0;

    /* CRIA CÓPIA DO VETOR PRINCIPAL */
    memcpy(Bubble, Array, sizeof(Bubble));

    for(CtdAux = 0; CtdAux < Informados -1; CtdAux++){
        Comparacoes++;
        for(Ctd = 0; Ctd < Informados - 1; Ctd++){
            Comparacoes++;
            if (Bubble[Ctd] > Bubble[Ctd + 1]){
                Troca = Bubble[Ctd + 1];
                Bubble[Ctd + 1] = Bubble[Ctd];
                Bubble[Ctd] = Troca;
                Trocas++;
            }
        }
    }

    printf("BUBBLE....: Comparacoes: %d Trocas: %d\n", Comparacoes, Trocas);
    /*PrintArray(Bubble, Informados); */
}

void PrintArray(int Array[], int Informados){
    printf("\n");
    for(Ctd = 0; Ctd < Informados; Ctd++){
        printf("%d ", Array[Ctd]);
    }
    printf("\n");
}


void LimparTela(){
    #ifdef _WIN32
    system("cls");

    #elif __linux__
    system("clear");

    #endif
}


void TrocaValores(int *Valor1, int *Valor2)
{
    int VlrTMP = *Valor1;
    *Valor1 = *Valor2;
    *Valor2 = VlrTMP;
}
