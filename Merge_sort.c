#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int b[ub+1],k=lb;

    while((i<=mid)&&(j<=ub)){
        if(arr[i]<=arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j<=ub){
        b[k] = arr[j];
        j++;
        k++;
    }

    for(int i=lb;i<=ub;i++){
        arr[i] = b[i];
    }
}

void Merge_sort(int arr[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid = (lb+ub)/2;
        Merge_sort(arr,lb,mid);
        Merge_sort(arr,mid+1,ub);
        Merge(arr,lb,mid,ub);
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

        Merge_sort(arr,0,n-1); // implementation of Merge sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }

        printf("\nthe time complexity of Merge sort in both worst case and best case is O(n*log(n))\n");
}
