#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//----------------------- MAX HEAP----------------------------
void maxHeapify(int arr[], int n, int i){
    int largest  = i;
    int left = (i*2) + 1;
    int right = (i*2) + 2;
    if((arr[left]>=arr[largest])&&(left<n)){
        largest = left;
    }
    if((arr[right]>=arr[largest])&&(right<n)){
        largest = right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void maxHeap_sort(int arr[],int n){

    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);  // building max heap
    }

    for(int i = n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);  // removing the elements from the heap
        maxHeapify(arr,i,0);
    }

}

//----------------------- MIN HEAP----------------------------
void minHeapify(int arr[], int n, int i){
    int smallest  = i;
    int left = (i*2) + 1;
    int right = (i*2) + 2;
    if((arr[left]<=arr[smallest])&&(left<n)){
        smallest = left;
    }
    if((arr[right]<=arr[smallest])&&(right<n)){
        smallest = right;
    }
    if(smallest!=i){
        swap(&arr[smallest],&arr[i]);
        minHeapify(arr,n,smallest);
    }
}

void minHeap_sort(int arr[],int n){

    for(int i=n/2-1;i>=0;i--){
        minHeapify(arr,n,i);  // building max heap
    }

    for(int i = n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);  // removing the elements from the heap
        minHeapify(arr,i,0);
    }

}

// MAIN
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

        maxHeap_sort(arr,n); // implementation of Heap sort

//--------------------printing output array (max heap)------------------------------
        printf("\nsorted array  (max heap): ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr[i]);
        }

//==================taking/generating input ==============================

    printf("\nenter the number of elements in the array\n");
    scanf("%d",&n);
    int arr_2[n];
    printf("press 1 to give manual input else 0 for random input\n");
    scanf("%d",&a);
    if (a==1){
        for (int i=0;i<n;i++){
            printf("enter the element %d : ", i+1);
            scanf("%d",&arr_2[i]);
        }
    }
    else {
        for (int i=0;i<n;i++){
            arr_2[i] = (1+rand()%40);
        }
    }

//--------------------printing input array------------------------------
        printf("input array  : ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr_2[i]);
        }

        minHeap_sort(arr_2,n); // implementation of Heap sort
//--------------------printing output array (max heap)------------------------------
        printf("\nsorted array  (min heap): ");
        for (int i=0;i<n;i++){
            printf("%d  ",arr_2[i]);
        }
        printf("\nthe time complexity in worst case and best case is O(n*log(n))\n");

}
