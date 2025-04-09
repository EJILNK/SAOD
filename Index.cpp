#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

typedef struct{
    unsigned int ID;
    char name[20];
    char surname[20];
    char job_title[20];
    char phoneNumber[20];
} Employee;

int sortKey = 1;

int compareEmployees(Employee a, Employee b){
    int cmp = 0;
    switch (sortKey){
        case 1:
            cmp = strcmp(a.surname, b.surname);
            if (cmp == 0) cmp = strcmp(a.name, b.name);
            break;
        case 2:
            cmp = strcmp(a.job_title, b.job_title);
            if (cmp == 0){
                cmp = strcmp(a.surname, b.surname);
                if(cmp == 0) cmp = strcmp(a.name, b.name);
            }
            break;
    }
    return cmp;
}

int binarySearch(Employee arr[], int index[], int n, char *key, int keytype){
    int left = 0, right = n - 1, mid;
    while (left <= right){
        mid = left + (right - left) / 2;
        int cmp = (keytype == 1)? strcmp(arr[index[mid]].surname, key) : strcmp(arr[index[mid]].job_title, key);
        if (cmp == 0){
            while (mid > 0 && ((keytype == 1 && strcmp(arr[index[mid - 1]].surname, key) == 0) || 
                                (keytype == 2 && strcmp(arr[index[mid - 1]].job_title, key) == 0))){
                mid--;
            }
            return mid;
        }
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void search(Employee arr[], int index[], int n, char *key, int keytype){
    int pos = binarySearch(arr, index, n, key, keytype);
    if (pos == -1){
        printf("Нет сотрудников с указанным ключом поиска: %s\n", key);
        return;
    }
    printf("\nСотрудники найдены:\n");
    printf("%-5s %-10s %-10s %-15s %-15s\n", "ID", "Surname", "Name", "Job Title", "Phone");
    printf("---------------------------------------------------------\n");
    while (pos < n && ((keytype == 1 && strcmp(arr[index[pos]].surname, key) == 0) || 
    (keytype == 2 && strcmp(arr[index[pos]].job_title, key) == 0))){
        int idx = index[pos];
        printf("%-5d %-10s %-10s %-15s %-15s\n", arr[idx].ID, arr[idx].surname, arr[idx].name, arr[idx].job_title, arr[idx].phoneNumber);
        pos++;
    }

}

void InsertSort(int index[], Employee arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = index[i];
        int j = i - 1;
        while (j >= 0 && compareEmployees(arr[temp], arr[index[j]]) < 0){
            index[j + 1] = index[j];
            j--;
        }
        index[j + 1] = temp;
    }
}

void inputEmployees(Employee arr[], int n){
    for (int i = 0; i < n; i++){
        arr[i].ID = i + 1;
        printf("Введите данные %d сотрудника (Фамилия Имя Должность Номер): ", i + 1);
        scanf("%19s %19s %19s %19s", arr[i].surname, arr[i].name, arr[i].job_title, arr[i].phoneNumber);
    }
}

void printEmployees(Employee arr[], int n){
    printf("\n%-5s %-10s %-10s %-15s %-15s\n", "ID", "Surname", "Name", "Job Title", "Phone");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++){
        printf("%-5d %-10s %-10s %-15s %-15s\n", arr[i].ID, arr[i].surname, arr[i].name, arr[i].job_title, arr[i].phoneNumber);
    }
}

void printEmployeesByIndex(Employee arr[], int index[], int n){
    printf("\n%-5s %-10s %-10s %-15s %-15s\n", "ID", "Surname", "Name", "Job Title", "Phone");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++){
        int idx = index[i];
        printf("%-5d %-10s %-10s %-15s %-15s\n", arr[idx].ID, arr[idx].surname, arr[idx].name, arr[idx].job_title, arr[idx].phoneNumber);
    }
}

int main(){
    Employee employees[SIZE] ={
    {1, "Egor", "Ryazantsev", "Programmer", "89998024056"},
    {2, "Alexander", "Karev", "Programmer", "89993493191"},
    {3, "Artem", "Shaporin", "Manager", "89994115259"},
    {4, "Alexander", "Ryazantsev", "Seller", "89993438797"},
    {5, "Andrey", "Gritsenko", "HR", "89991313335"}
    };

    int indexbySurname[SIZE]; int indexbyjob[SIZE];
    
    // inputEmployees(employees, SIZE);
    
    for (int i = 0; i < SIZE; i++){
        indexbySurname[i] = i;
        indexbyjob[i] = i; 
    }

    InsertSort(indexbySurname, employees, SIZE);
    sortKey = 2;
    InsertSort(indexbyjob, employees, SIZE);

    system("clear");

    printf("Оригинальный справочник:\n");
    printEmployees(employees, SIZE);
    
    
    printf("\nОтсортированный справочник по фамилии:\n");
    printEmployeesByIndex(employees, indexbySurname, SIZE);

    printf("\nОтсортированный справочник по должности:\n");
    printEmployeesByIndex(employees, indexbyjob, SIZE);


    char searchKey[20];
    printf("\nВведите фамилию для поиска: ");
    scanf("%19s", searchKey);
    
    search(employees, indexbySurname, SIZE, searchKey, 1);

    printf("\nВведите должность для поиска: ");
    scanf("%19s", searchKey);
    
    search(employees, indexbyjob, SIZE, searchKey, 2);

    
    return 0;
}