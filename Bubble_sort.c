#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void Bubble_sort(int arr[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
            flag =0;
        for (int j=0;j<n-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]); // passing address to the function
                flag = 1;
            }
        }
    if(flag == 0)
        break;
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

        Bubble_sort(arr,n); // implementation of bubble sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }
        printf("the time complexity of Bubble sort in worst case is O(n^2) and in best case is O(n)\n");

}
