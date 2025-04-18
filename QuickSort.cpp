#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int C = 0, M = 0;

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

int QuickSortVer1(int A[], int L, int R, int currDepth, int &maxDepth){
    int tmp = A[L]; int i = L; int j = R; int Search = 0;
    if (currDepth > maxDepth) maxDepth = currDepth;
    while(i<=j){
        while(A[i]<tmp){
            C++;
            i++;
            Search = 1;
        }
        if(!Search) C++;
        Search = 0;
        while(A[j]>tmp){
            C++;
            j--;
            Search = 1;
        }
        if(!Search) C++;
        Search = 0;
        if(i<=j){
            swap(A,i,j); M+=3;
            i++;
            j--;
        }
    }
    if(L<j){
        QuickSortVer1(A,L,j,currDepth+1,maxDepth);
    }
    if(i<R){
        QuickSortVer1(A,i,R,currDepth+1,maxDepth);
    }
    return 0;
}

int QuickSortVer2(int A[], int L, int R, int currDepth, int &maxDepth){
    while (L < R){
        if (currDepth > maxDepth) maxDepth = currDepth;

        int tmp = A[L];
        int i = L;
        int j = R;

        while (i <= j){
            while (A[i] < tmp){
                C++;
                i++;
            }
            C++;

            while (A[j] > tmp){
                C++;
                j--;
            }
            C++;

            if (i <= j){
                swap(A, i, j); M += 3;
                i++;
                j--;
            }
        }

        if (j - L > R - i){
            if (i < R) QuickSortVer2(A, i, R, currDepth + 1, maxDepth);
            R = j;
        } else{
            if (L < j) QuickSortVer2(A, L, j, currDepth + 1, maxDepth);
            L = i;
        }
    }
    return 0;
}

int main(){
    
    printf("Трудоёмкость Метода Хоара:\n");
    printf("--------------------------------------------------\n");
    printf("|%-5s | %-48s |\n", "  n", "        QuickSort (Mфакт+Сфакт)");
    printf("|%-5s | %-15s | %-15s | %-15s |\n", "", "   Убыв.", "   Случ.", "   Возр.");
    printf("--------------------------------------------------\n");

    for (int n = 100; n <= 500; n+=100){
        int sum1 = 0, sum2 = 0, sum3 = 0; int MaxDepth = 0; C=0 , M=0;
        int A[n]; 
        fillDec(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        sum1 = C+M;
        
        C=0 , M=0;
        fillInc(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        sum2 = C+M;
        C=0 , M=0;
        
        fillRnd(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        sum3 = C+M;
        

        printf("|%-5d | %-11d | %-11d | %-11d |\n", n, sum1, sum3, sum2);
        printf("|------------------------------------------------|\n");

    }

    printf("Глубина рекурсии:\n");
    printf("--------------------------------------------------------------------------\n");
    printf("|%-5s | %-30s | %-30s |\n", "  n", "        QuickSort1", "          QuickSort2");
    printf("|%-5s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "", " Убыв.  ", " Случ.  ", " Возр.  "," Убыв.  ", " Случ.  ", " Возр.  ");
    printf("--------------------------------------------------------------------------\n");

    for (int n = 100; n <= 500; n+=100){
        int recdepth11 = 0, recdepth12 = 0, recdepth13 = 0, recdepth21 = 0, recdepth22 = 0, recdepth23 = 0; int MaxDepth = 0;
        int A[n]; 

        fillDec(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        recdepth11 = MaxDepth;
        
        MaxDepth = 0;

        fillInc(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        recdepth12 = MaxDepth;
        
        MaxDepth = 0;
        
        
        fillRnd(n,A);
        QuickSortVer1(A,0,n-1,1,MaxDepth);
        recdepth13 = MaxDepth;
        
        MaxDepth = 0;

        fillDec(n,A);
        QuickSortVer2(A,0,n-1,1,MaxDepth);
        recdepth21 = MaxDepth;
        
        MaxDepth = 0;

        fillInc(n,A);
        QuickSortVer2(A,0,n-1,1,MaxDepth);
        recdepth22 = MaxDepth;
        
        MaxDepth = 0;
        
        
        fillRnd(n,A);
        QuickSortVer2(A,0,n-1,1,MaxDepth);
        recdepth23 = MaxDepth;
        
        MaxDepth = 0;
        


        printf("|%-5d | %-8d | %-8d | %-8d | %-8d | %-8d | %-8d |\n", n, recdepth11, recdepth13, recdepth12, recdepth21, recdepth23, recdepth22);
        printf("|------------------------------------------------------------------------|\n");

    }

    
}