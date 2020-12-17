#include <stdio.h>
#include <stdlib.h>


void Insertion_sort(int arr[],int n){
    int temp,k,j;
    for(int i=1;i<n;i++){
            temp = arr[i];
            j=i-1;
        while ((j>=0)&&(temp<arr[j])){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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

        Insertion_sort(arr,n); // implementation of Insertion sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }
        printf("\nthe time complexity in worst case is O(n^2) and in best case is O(n)\n");

}
