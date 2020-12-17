#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void Selection_sort(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
            min = i;
        for (int j=i;j<n-1;j++){
            if (arr[min]>arr[j]){
                swap(&arr[min],&arr[j]); // passing address to the function
            }
        }
    }
}


int main()
{
    //-----------------taking/generating input --------------------------
    int n,a;
    printf("enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("press 1 to give manual input else 0 for random input\n");
    scanf("%d",&a);
    if (a==1){
        for (int i=0;i<n;i++){
            printf("enter the element %d : ", i+1);
            scanf("%d",&arr[i]);
        }
    }
    else {
        for (int i=0;i<n;i++){
            arr[i] = (1+rand()%40);
        }
    }

//--------------------printing input array------------------------------
        printf("input array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }

        Selection_sort(arr,n); // implementation of bubble sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }
        printf("\nthe time complexity in worst case is O(n^2) and in best case is O(n^2)\n");

}
