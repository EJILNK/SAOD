#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


double teorMCheap = 0;

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
double calculateTheoretical(int n) {
    double total = 0;
    for (int i = n / 2; i >= 0; i--) {
        int L = i + 1;
        int R = n;
        total += (log2(R/L) + 2) + 2 * (log2(R/L));
    }
    return total;
}


int HeapBuild(int A[], int L, int R){
    int tmp; int C = 0; int M = 0;
    M++; tmp = A[L]; int i = L;
    while(1){
        int j = 2 * i;
         if(j>R) break;
         if(j<R){
            C++;
            if(A[j+1]<=A[j]){
                j++;
            }
        }
        C++; if(tmp<=A[j]) break;
        A[i] = A[j]; M++;
        i = j;
    }
    A[i] = tmp; M++;
    return M+C;
}
int Heapf(int A[], int n){
    int MC = 0;
    for(int i = n/2; i >= 0; i--){
        MC += HeapBuild(A,i,n-1);
    }
    return MC;
}

int HeapSort(int A[], int n){
    int L = n/2; int M = 0; int MC = 0;
    while(L>=0){
        MC+=HeapBuild(A,L,n-1);
        L--;
    }
    int R = n-1;
    while (R>0){
        swap(A,0,R);M+=3;
        R--;
        MC+=HeapBuild(A,0,R);
    }
    MC = MC + M;
    return MC;
}

int main(){
    int HeapInc = 0, HeapDec = 0, HeapRnd = 0, teorMCheapDec = 0;
    printf("Трудоёмкость построения пирамиды:\n");
    printf("------------------------------------------------\n");
    printf("|%-5s | %-10s | %-33s |\n", "  n", "   M+C", "  Mфакт+Сфакт");
    printf("|%-5s | %-18s | %-10s | %-10s | %-10s |\n", "", "теоретич.", "Убыв.", "Случ.", "Возр.");
    printf("------------------------------------------------\n");

    for (int n = 100; n <= 500; n+=100){
        int A[n]; HeapInc = 0, HeapDec = 0, HeapRnd = 0, teorMCheapDec = 0; teorMCheap = 0;
        
        fillDec(n,A);
        HeapDec = Heapf(A,n);
        teorMCheapDec = calculateTheoretical(n);
        

        fillInc(n,A);
        HeapInc = Heapf(A,n);

        fillRnd(n,A);
        HeapRnd = Heapf(A,n);


        printf("|%-5d | %-10d | %-6d | %-6d | %-6d |\n", n, teorMCheapDec, HeapDec, HeapRnd, HeapInc);
        printf("|----------------------------------------------|\n");

    }

    printf("\nТрудоёмкость пирамидальной сортировки:\n");
    printf("-----------------------------------\n");
    printf("|%-5s | %-26s |\n", "  n", "    HeapSort (Mф+Cф)");
    printf("|%-5s | %-10s | %-10s | %-10s |\n", "", "Убыв.", "Случ.", "Возр.");
    printf("-----------------------------------\n");

    for (int n = 100; n <= 500; n+=100){
        int A[n]; HeapInc = 0, HeapDec = 0, HeapRnd = 0;

        fillDec(n,A);
        HeapDec = HeapSort(A,n);
        
        
        fillInc(n,A);
        HeapInc = HeapSort(A,n);
    
        fillRnd(n,A);
        HeapRnd = HeapSort(A,n);
        // PrintMas(n,A);
        
        printf("|%-5d | %-6d | %-6d | %-6d |\n", n, HeapDec, HeapRnd, HeapInc);
        printf("|---------------------------------|\n");

    }

    
}