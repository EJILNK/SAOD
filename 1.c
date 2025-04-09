#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
void pereop(int n, int A[], int B[]){
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }
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
    return Sravn+Perestan;
}
int BubbleSort(int n, int A[]){
    int B[n];
    for (int i = 0; i < n;i++){
        B[i] = A[i];
    }
    int Perestan = 0; int Sravn = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            Sravn++; if(B[j] < B[j-1]){
                swap(B,j-1,j); Perestan+=3;
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
int InsertSort(int n, int A[]){
    int temp = 0; int j = 0; int M = 0; int C = 0; int poisk = 0;
    for(int i = 1; i < n; ++i){
        temp = A[i];M++;
        j = i-1;
        while(j >= 0 && temp < A[j]){
            C++;
            A[j+1] = A[j];M++;
            j--;
            poisk = 1;
        }
        if (!poisk){
            C++;
        }
        A[j+1] = temp;M++;
    }   
    return M+C;
}


int main(){
    int d[5]; int param = 0; int shaker[5]; int shakerinc[5]; int shakerdec[5]; int dinc[5]; int ddec[5]; int ncount[5]; int teomc[5];
    int n = 10;int b; int sorttype;
    
    printf("Введите номер типа сортировки (1 - SelectSort, 2 - BubbleSort, 3 - ShakerSort, 4 - InsertSort, 5 - Сравнение): ");
    scanf("%d",&sorttype);
    switch (sorttype){
    
    case 1:
    printf("Выбран SelectSort: \n");
    for(n = 10; n<101; n*=10){
    int A[n];
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
    printf("Выбран BubbleSort: \n");
    for(n = 100; n<501; n+=100){
    int A[n];     
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
    dinc[param] = BubbleSort(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    shakerinc[param] = ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    fillDec(n,A);
    ddec[param] = BubbleSort(n,A);    
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    shakerdec[param] = ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    fillRnd(n,A);
    d[param] = BubbleSort(n,A);
         
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    shaker[param] = ShakerSort(n,A);
    b = RunNumber(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    printf("Кол-во серий после сортировки: %d \n\n", b);
    ncount[param] = n;
    param++;
    }

     printf("\n");
    printf("Табличка!\n");
    printf("-------------------------------------------------------------------------\n");
    printf("|   N   |        Mф+Cф пузырьковой      |         Мф+Сф шейкерной       |\n");
    printf("|       |  Убыв.  |   Случ.  |   Возр.  |  Убыв.  |   Случ.  |   Возр.  |\n");
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d   |  %d    |  %d  |   %d  |    %d    |\n",ncount[0], ddec[0], d[0], dinc[0],shakerdec[0],shaker[0],shakerinc[0]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d   |  %d   |  %d  |   %d  |    %d   |\n",ncount[1], ddec[1], d[1], dinc[1],shakerdec[1],shaker[1],shakerinc[1]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  %d  |  %d |  %d  |  %d   |  %d |   %d  |    %d   |\n",ncount[2], ddec[2], d[2], dinc[2],shakerdec[2],shaker[2],shakerinc[3]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  %d  |  %d |  %d  |  %d   |  %d |  %d  |    %d   |\n",ncount[3], ddec[3], d[3], dinc[3],shakerdec[3],shaker[3],shakerinc[3]);
    printf("|-----------------------------------------------------------------------|\n");
    printf("|  %d  |  %d |  %d  |  %d  |  %d |  %d  |    %d   |\n",ncount[4], ddec[4], d[4], dinc[4],shakerdec[4], shaker[4], shakerinc[4]);
    printf("|-----------------------------------------------------------------------|\n");

    break;

    case 4:
    printf("Выбран Insertsort: \n");
    for(n = 100; n<501; n+=100){
    int A[n];
    fillInc(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    dinc[param] = InsertSort(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));

    fillDec(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    ddec[param] =InsertSort(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    

    fillRnd(n,A);
    printf("Контрольная сумма до сортировки: %d \n", CheckSum(n,A));
    d[param] = InsertSort(n,A);
    printf("Контрольная сумма после сортировки: %d \n", CheckSum(n,A));
    ncount[param] = n;
    teomc[param] = (n*(n-1))/2 + (n*(n-1))/2+2*n-2;
    param++;
    }
    printf("\n");
    printf("Табличка!\n");
    printf("---------------------------------------------------\n");
    printf("|   N   |   M+C   |         Мфакт+Сфакт           |\n");
    printf("|       |теоретич.|  Убыв.  |   Случ.  |   Возр.  |\n");
    printf("|-------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d  |  %d    |   %d    |\n",ncount[0],teomc[0], ddec[0], d[0],dinc[0]);
    printf("|-------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d  |  %d   |   %d    |\n", ncount[1],teomc[1], ddec[1], d[1],dinc[1]);
    printf("|-------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d  |  %d   |   %d    |\n", ncount[2],teomc[2], ddec[2], d[2],dinc[2]);
    printf("|-------------------------------------------------|\n");
    printf("|  %d  |  %d |  %d |  %d   |   %d   |\n", ncount[3],teomc[3],ddec[3], d[3],dinc[3]);
    printf("|-------------------------------------------------|\n");
    printf("|  %d  |  %d |  %d |  %d  |   %d   |\n", ncount[4],teomc[4],ddec[4], d[4],dinc[4]);
    printf("|-------------------------------------------------|\n");
    break;

    case 5:
    printf("Выбрано сравнение сортировок: \n");
    for(n = 100; n<501; n+=100){
    int A[n];int B[n];
    
    fillRnd(n,A);
    pereop(n,A,B);
    d[param] = SelectSort(n,B);
    pereop(n,A,B);
    dinc[param] = BubbleSort(n,B);
    pereop(n,A,B);
    shaker[param] = ShakerSort(n,B);
    ddec[param] = InsertSort(n,A);
    ncount[param] = n;
    param++;
    }

    printf("\n");
    printf("Табличка!\n");
    printf("-----------------------------------------------------\n");
    printf("|   N   |                  Мфакт+Сфакт              |\n");
    printf("|       |  Select  |  Bubble  |  Shaker  |  Insert  |\n");
    printf("|---------------------------------------------------|\n");
    printf("|  %d  |   %d   |  %d   |  %d   |   %d   |\n",ncount[0],d[0], dinc[0], shaker[0],ddec[0]);
    printf("|---------------------------------------------------|\n");
    printf("|  %d  |   %d  |  %d   |  %d   |   %d  |\n", ncount[1],d[1], dinc[1], shaker[1],ddec[1]);
    printf("|---------------------------------------------------|\n");
    printf("|  %d  |   %d  |  %d  |  %d   |   %d  |\n", ncount[2],d[2], dinc[2], shaker[2],ddec[2]);
    printf("|---------------------------------------------------|\n");
    printf("|  %d  |   %d  |  %d  |  %d  |   %d  |\n", ncount[3],d[3],dinc[3], shaker[3],ddec[3]);
    printf("|---------------------------------------------------|\n");
    printf("|  %d  |  %d  |  %d  |  %d  |  %d  |\n", ncount[4],d[4],dinc[4], shaker[4],ddec[4]);
    printf("|---------------------------------------------------|\n");
    break;
    
    default:
    printf("Пока)\n");
    break;
    }
}
