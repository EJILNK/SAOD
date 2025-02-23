#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void fillInc(int n, int A[]){
    for(int i = 0; i < n; i++){
        A[i] = i + 1;
    }
}
void fillDec(int n, int A[]){
    int j = 0;
    for (int i = n; i > 0; i--){
        A[j] = i;
        j++;
    }
}
void fillRnd(int n, int A[]){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        A[i] = rand()%50;
    }
}
void PrintMas(int n, int A[]){
    printf("[");
    for (int i = 0; i < n; i++){
       printf("%d ", A[i]);
    }
    printf("]\n"); 
}
int CheckSum(int n, int A[]){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    return sum;
}
int RunNumber(int n, int A[]){
    int serialNumbers = 1;
    for(int i = 1; i < n; i++){
        if(A[i]<A[i-1]){
            serialNumbers += 1;
        }
    }   
    return serialNumbers;
}
float srlenser(int n,int b){
    float a = n; float c = b;
    float srlen;
    srlen = a/c;  
    return srlen;
}
int SelectSort(int n, int A[]){
    int c; int Perestan = 0; int Sravn = 0;
    for (int i = 0; i < n-1; i++){
        int jMin = i;

        for (int j = i+1; j < n; j++){
            Sravn++; if (A[j] < A[jMin]){
                jMin = j;
                c = j;
            }
        }
        if (jMin != i){
            swap(A, i, c);
            Perestan+=3;
        }
    }

    printf("dasfsdafsaf %d \n",Sravn+Perestan);
    return Sravn+Perestan;
}
int BubbleSort(int n, int A[]){
    int Perestan = 0; int Sravn = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            Sravn++; if(A[j] < A[j-1]){
                swap(A,j-1,j); Perestan+=3;
            }
        }
    }
    return Sravn+Perestan;
}
int ShakerSort(int n, int A[]){
    int L = 0; int R = n; int k = n; int Perestan = 0; int Sravn = 0;
    while(L<R){
    for (int i = R-1; i > L; i--){
        Sravn++; if(A[i]<A[i-1]){
            swap(A,i-1,i); Perestan += 3;
            k=i;
        }
    }
    L = k;
    for (int i = L; i < R-1; i++){
        Sravn++; if(A[i]>A[i+1]){
            swap(A,i+1,i); Perestan += 3;
            k=i+1;
        }
    }
    R = k;
    }
    return Sravn+Perestan;
}
int main(){
    int d[5]; int param = 0; int shaker[5];
    int n =10;int b; int sorttype;
    int A[n];
    printf("Введите номер типа сортировки (1 - SelectSort, 2 - BubbleSort): ");
    scanf("%d",&sorttype);
    switch (sorttype){
    
    case 1:
    for(n = 10; n<101; n*=10){
    int A[n];
    printf("Выбран SelectSort: \n");
    fillInc(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    SelectSort(n,A);
    printf("Отсортированный возрастающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);

    fillDec(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    SelectSort(n,A);
    printf("Отсортированный убывающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    

    fillRnd(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    d[param] = SelectSort(n,A);
    printf("Отсортированный рандомный массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n", b);
    param++;
    }

    printf("\n");
    printf("Табличка!\n");
    printf("---------------------------------------------------\n");
    printf("|   N   |   M+C   |    Улучшенный Мфакт+Сфакт     |\n");
    printf("|       |теоретич.|  Убыв.  |   Случ.  |   Возр.  |\n");
    printf("|-------------------------------------------------|\n");
    printf("|   10  |   72    |    60   |    %d    |    45    |\n",d[0]);
    printf("|-------------------------------------------------|\n");
    printf("|  100  |  5247   |  5100   |   %d  |   4950    |\n",d[1]);
    printf("|-------------------------------------------------|\n");

    break;
    case 2:
    for(n = 100; n<501; n+=100){
    int A[n];     
    printf("Выбран BubbleSort: \n");
    fillInc(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    BubbleSort(n,A);
    printf("Отсортированный возрастающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);


    fillDec(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    BubbleSort(n,A);
    printf("Отсортированный убывающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    

    fillRnd(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    d[param] = BubbleSort(n,A);
    printf("Отсортированный рандомный массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n", b);
    param++;
    }

    printf("\n");
    printf("Табличка!\n");
    printf("---------------------------------------------------\n");
    printf("|   N   |   M+C   |         Мфакт+Сфакт           |\n");
    printf("|       |теоретич.|  Убыв.  |   Случ.  |   Возр.  |\n");
    printf("|-------------------------------------------------|\n");
    printf("|  100  |  4950   |  19800  |  %d   |  4950    |\n", d[0]);
    printf("|-------------------------------------------------|\n");
    printf("|  200  |  19900  |  79600  |  %d   |  19900   |\n", d[1]);
    printf("|-------------------------------------------------|\n");
    printf("|  300  |  44850  |  179400 |  %d  |  44850   |\n", d[2]);
    printf("|-------------------------------------------------|\n");
    printf("|  400  |  79800  |  319200 |  %d  |  79800   |\n", d[3]);
    printf("|-------------------------------------------------|\n");
    printf("|  500  |  124750 |  499000 |  %d  |  124750  |\n", d[4]);
    printf("|-------------------------------------------------|\n");

    break;
    case 3:
    printf("Выбран ShakerSort: \n");
    for(n = 100; n<501; n+=100){
    int A[n];     
    fillInc(n,A);
    BubbleSort(n,A);
    fillDec(n,A);
    BubbleSort(n,A);    
    fillRnd(n,A);
    d[param] = BubbleSort(n,A);
         
    fillInc(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);


    fillDec(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    

    fillRnd(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    shaker[param] = ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    param++;
    }

     printf("\n");
    printf("Табличка!\n");
    printf("-------------------------------------------------------------------------\n");
    printf("|   N   |        Mф+Cф пузырьковой      |         Мф+Сф шейкерной       |\n");
    printf("|       |  Убыв.  |   Случ.  |   Возр.  |  Убыв.  |   Случ.  |   Возр.  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  100  |  19800  |  %d   |  4950    |  19800  |   %d  |    99    |\n", d[0],shaker[0]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  200  |  79600  |  %d   |  19900   |  79600  |   %d  |    199   |\n", d[1],shaker[1]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  300  |  179400 |  %d  |  44850   |  179400 |   %d  |    299   |\n", d[2],shaker[2]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  400  |  319200 |  %d  |  79800   |  319200 |   %d |    399   |\n", d[3],shaker[3]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  500  |  499000 |  %d  |  124750  |  499000 |  %d  |    499   |\n", d[4], shaker[4]);
    printf("|-----------------------------------------------------------------------|\n");

    break;

    default:
    printf("Пока)\n");
    break;
}
}
