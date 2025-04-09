#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
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
void generateknut(int n, int H[], int *m){
    *m = (int)log2(n) - 1;
    H[0] = 1;
    for (int i = 1; i < *m; i++){
        H[i] = 2 * H[i - 1] + 1;
    }
}
void generateSedgewick(int n, int H[], int *m){
    int i = 0;
    while (1){
        int h;
        if (i % 2 == 0){
            h = 9 * (pow(2, i) - pow(2, i / 2)) + 1;
        } else{
            h = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
        }
        if (h > n) break;
        H[i] = h;
        i++;
    }
    *m = i;
}
int ShellSort(int n, int A[], int H[], int m){
    int temp = 0; int M = 0; int C = 0; int poisk = 0;

    for(int shag = m-1;shag >= 0;shag--){
        int k = H[shag];
        for(int i = k; i < n; i++){
            temp  = A[i]; M++;
            int j = i-k;
            poisk = 0;
            while(j>=0 && temp < A[j]){
                C++;
                A[j+k] = A[j]; M++;
                j = j - k;
                poisk = 1;
            }
            if (!poisk) C++;
            A[j+k] = temp;M++;
        }
    }
    return M+C;
}
int main(){
    int shellknut[5], shellsedg[5], insert[5], Hknut[20],Hsedg[20], mknut, msedg;
    printf("------------------------------------------------------------\n");
    printf("|%-5s | %-20s | %-12s | %-12s|\n", "n", "h1 ... hm", "Insert M+C", "Shell M+C");
    printf("|----------------------------------------------------------|\n");
    
    int param = 0;
    for (int n = 100; n <= 500; n += 100){
        int A[n];
        
        generateknut(n, Hknut, &mknut);
        
        fillRnd(n, A);
        shellknut[param] = ShellSort(n, A, Hknut, mknut);
        
        fillRnd(n, A);
        insert[param] = InsertSort(n, A);
        
        printf("|%-5d | ", n);
        char h_str[20] = "";
        for (int i = 0; i < mknut; i++){
            char temp[5];
            sprintf(temp, "%d ", Hknut[i]);
            strcat(h_str, temp);
        }
        printf("%-20s | %-12d | %-12d|\n", h_str, insert[param], shellknut[param]);
        printf("|----------------------------------------------------------|\n");
        param++;
    }

    printf("\n\n-----------------------------------------------------------------------------------\n");
    printf("|%-5s | %-25s | %-12s | %-20s | %-12s|\n", "n", "h1 ... hm (Кнута)", "Shell M+C", "h1 ... hm (Седжвика)", "Shell M+C");
    printf("|---------------------------------------------------------------------------------|\n");

    param = 0;
    for (int n = 100; n <= 500; n += 100){
        int A[n];

        generateknut(n, Hknut, &mknut);
        generateSedgewick(n, Hsedg, &msedg);

        fillRnd(n, A);
        shellknut[param] = ShellSort(n, A, Hknut, mknut);

        fillRnd(n, A);
        shellsedg[param] = ShellSort(n, A, Hsedg, msedg);

        fillRnd(n, A);
        insert[param] = InsertSort(n, A);

        printf("|%-5d | ", n);
        char h_knut_str[20] = "";
        for (int i = 0; i < mknut; i++){
            char temp[5];
            sprintf(temp, "%d ", Hknut[i]);
            strcat(h_knut_str, temp);
        }
        printf("%-20s | %-12d | ", h_knut_str, shellknut[param]);

        char h_sedgewick_str[20] = "";
        for (int i = 0; i < msedg; i++){
            char temp[5];
            sprintf(temp, "%d ", Hsedg[i]);
            strcat(h_sedgewick_str, temp);
        }
        printf("%-20s | %-12d|\n", h_sedgewick_str, shellsedg[param]);
        printf("|---------------------------------------------------------------------------------|\n");
        param++;
    }
    
    return 0;

}


