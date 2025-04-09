#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
        A[i] = rand()%(2*n);
    }
}
void PrintMas(int n, int A[]){
    printf("[");
    for (int i = 0; i < n; i++){
       printf("%d ", A[i]);
    }
    printf("]\n"); 
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

int BinarySearchFirstVersion(int n, int A[], int X){
    int L = 0; int R = n-1; bool find = false; int C = 0;
    while (L <= R){
        int m = (L+R)/2;
        C++; if (A[m] == X){
            find = true; printf("Элемент %d найден на позиции %d\n", A[m], m+1);
            return C;
        }
        C++; if (A[m] < X) L = m+1;
        else R = m-1;
    } 
    printf("Элемент не найден!!!!\n");     
    return C;
}
int BinarySearchSecondVersion(int n, int A[], int X){
    int L = 0; int R = n-1; int C = 0;
    while (L < R){
        int m = (L+R)/2;
        C++; if (A[m] < X) L = m+1;
            else R = m;
    } 
    C++;
    return C;
}
int BSearchAll1(int n, int A[], int X){
    int L = 0, R = n - 1, C = 0;
    while (L <= R){
        int m = (L + R) / 2;
        C++;
        if (A[m] == X){
            int left = m, right = m; bool search = false;
            while (left >= 0 && A[left] == X) {
                left--;
                C++;
                search = true;
            }
            if (!search) C++;
            search = false;
            while (right < n && A[right] == X) {
                right++;
                C++;
                search = true;
            }
            if (!search) C++;
            return C;
        }
        C++;
        if (A[m] < X) L = m + 1;
        else R = m - 1;
    }  
    return C;
}
int BSearchAll2(int n, int A[],int X){
    int L = 0, R = n - 1, C = 0;
    while (L < R){
        int m = (L + R) / 2;
        C++;
        if (A[m] < X) L = m + 1;
        else R = m;
    } 
    C++;
    if (A[R] == X){
        int right = R; bool search = false;
        while (right < n && A[right] == X) {
            C++;
            printf("Элемент %d найден на позиции %d\n", A[right], right + 1);
            right++;
            search = true;
        }
        if (!search) C++;
        return C;
    }
    else{
        printf("Элемент не найден!!!!\n");
    }     
    return C;
}


int main(){
    int X; int firstver[10]; int secondver[10];
    int sizes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    
    printf("Введите число, которое нужно найти: ");
    scanf("%d", &X);
    
    for(int i = 0; i < 10; i++){
        int n = sizes[i];
        int fis = 2 * log2(n);
        printf("\nC теоретическое 1 вер: %d, 2 вер: %d\n",fis, fis/2+1);
        int A[n];
        fillRnd(n,A);
        ShakerSort(n,A);
        
        firstver[i] = BinarySearchFirstVersion(n,A,X);
        secondver[i] = BinarySearchSecondVersion(n,A,X);
    }
    printf("\nТрудоёмкость двоичного поиска элемента:\n");
    printf("-------------------------------------\n");
    printf("|   N   | Cф I версия | Cф II версия|\n");
  
    for(int i = 0; i < 10; i++){
        int n = sizes[i];
        printf("| %4d  |     %4d    |     %4d    |\n", n, firstver[i], secondver[i]);
    }
    
    printf("-------------------------------------\n");

    for(int i = 0; i < 10; i++){
        int n = sizes[i];
        printf("В массиве размера %d:\n", n);
        int A[n];
        fillRnd(n, A);
        ShakerSort(n,A);
        firstver[i] = BSearchAll1(n, A, X);
        secondver[i] = BSearchAll2(n, A, X);
    }
    printf("\nТрудоёмкость двоичного поиска всех элементов:\n");
    printf("-----------------------------------------------\n");
    printf("|   N   | Cф All I версия  | Cф All II версия |\n");
    printf("-----------------------------------------------\n");
    
    for(int i = 0; i < 10; i++){
        int n = sizes[i];
        printf("| %4d  |       %4d       |       %4d       |\n", n, firstver[i], secondver[i]);
    }
    
    printf("-----------------------------------------------\n");
    
    return 0;

    
    return 0;


}


