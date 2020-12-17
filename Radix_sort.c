#include <stdio.h>
#include <stdlib.h>


int getMax(int arr[],int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}


void Counting_sort(int arr[],int n,int pos){
    int count[10]={0},b[n];

    for(int i=0;i<n;i++){
        ++count[(arr[i]/pos)%10];
    }
    for(int i=1;i<10;i++){
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(arr[i]/pos)%10]] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = b[i];
    }

}

void Radix_sort(int arr[],int n){
    int max = getMax(arr,n);

    for(int pos=1;max/pos>0;pos*=10){
        Counting_sort(arr,n,pos);
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
            printf("enter the element %d : ",i+1);
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

        Radix_sort(arr,n); // implementation of Radix sort

//--------------------printing output array------------------------------
        printf("\nsorted array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }
        printf("\nthe time complexity of Radix sort in worst case is O(k*n) and in best case is O(k*n)\n");

}
