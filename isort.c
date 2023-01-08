#include <stdio.h>
#define SIZE 50

// first question 
int shift_element (int* arr , int i){
    for (int j=0; j< i; j++){
        *(arr+i-j)= *(arr+i-j-1);
    }
}

// second question 
void insertion_sort (int* arr, int len){
    for(int i =1; i < len; i++){
        int *point = (arr+i-1);
        int counter= 0;
        while (*point >= *(arr+i))
        {
            counter ++ ;
            point --; 

            if ((point+1) == arr){
                break; 
            } 
        }
        point++;
        int tmp = *(arr+i);
        shift_element(point, counter);
        *point = tmp; 
    }

}

void printarr(int *arr, int size)
{
    printf("%d", *arr);
    for (int i = 1; i < size; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printarr(arr, SIZE);
    return 0;
}

       
   
