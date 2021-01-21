#include <stdio.h>

int* qsort2(int* a, int n);
int* qsortRecursive(int*a, int left, int right);
int partition(int* a, int left, int right);
void swap(int* a, int* b);

int main(void) {
    int arr[] = {9,5,1,0,3,6,7,6};
    qsort2(arr, 8);
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

int* qsort2(int* a, int n){
    return qsortRecursive(a, 0, n-1);
}

int* qsortRecursive(int*a, int left, int right){
    if(left >= right) return a;
    int pivot = partition(a, left, right);
    qsortRecursive(a, left, pivot-1);
    qsortRecursive(a, pivot+1, right);
    return a;
}

int partition(int* a, int left, int right){
    int pivot = a[right];
    int last = right;
    right--;
    while(left < right){
        while(a[left] < pivot && left < right){
            left++;
        }
        while(a[right] >= pivot && left < right){
            right--;
        }
        swap(&a[left], &a[right]);
    }  
    swap(&a[right], &a[last]);
    return right;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}