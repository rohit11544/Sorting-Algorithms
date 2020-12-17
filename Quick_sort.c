#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partation(int arr[],int lb,int ub){
    int pivot = arr[(lb+ub)/2];
    int start = lb;
    int end = ub;
    while(start<end){
        while(arr[start]<=pivot)
            start++;
        while(arr[end]>pivot)
            end--;
        if(start<end)
            swap(&arr[start],&arr[end]);
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void Quick_sort(int arr[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc = partation(arr,lb,ub);
        Quick_sort(arr,lb,loc-1);
        Quick_sort(arr,loc+1,ub);
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

        Quick_sort(arr,0,n-1); // implementation of bubble sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }
        printf("\nthe time complexity in worst case is O(n^2) and in the best case is O(n*log(n)) : ");

}
