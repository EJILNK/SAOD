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
void SelectSort(int n, int A[]){
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
            Perestan++;
        }
    }
    printf("Сумма М+С равна %d \n", Sravn+Perestan);
}
void BubbleSort(int n, int A[]){
    int Perestan = 0; int Sravn = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            Sravn++; if(A[j] < A[j-1]){
                swap(A,j-1,j); Perestan++;
            }
        }
    }
    printf("Сумма М+С равна %d \n", Sravn+Perestan);

}
int main(){
    int n = 100; int b; int sorttype;
    int A[n];
    printf("Введите номер типа сортировки (1 - SelectSort, 2 - BubbleSort): ");
    scanf("%d",&sorttype);
    switch (sorttype){
    
    case 1:
    printf("Выбран SelectSort: \n");
    fillInc(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    SelectSort(n,A);
    printf("Отсортированный возрастающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);

    // printf("Средняя длина серий: %f \n", srlenser(n,b));

    fillDec(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    SelectSort(n,A);
    printf("Отсортированный убывающий массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    
    // printf("Средняя длина серий: %f \n", srlenser(n,b));

    fillRnd(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    SelectSort(n,A);
    printf("Отсортированный рандомный массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n", b);

    // printf("Средняя длина серий: %f \n", srlenser(n,b));
    break;
    case 2:
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
    BubbleSort(n,A);
    printf("Отсортированный рандомный массив: ");
    PrintMas(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n", b);

    break;
    default:
    printf("Пока)");
    }

}

