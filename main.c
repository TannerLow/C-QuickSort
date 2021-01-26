#include <stdio.h> //access to printf

int* qsort2(int* a, int n); //Required Function Quicksorts array a with n elements

int* qsortRecursive(int*a, int left, int right); //Recursive quicksort, gets wrapped by qsort2
int partition(int* a, int left, int right); //Partitions the array in range [left, right]
void swap(int* a, int* b); //Swaps the value of two pointers

int main(void) { //main function header
    int arr[] = {9,5,1,0,3,6,7,6}; //given array
    qsort2(arr, 8); //call to quicksort
    for(int i = 0; i < 8; i++){ //for loop to iterate over array
        printf("%d ", arr[i]); //print current element it's pointing to
    }
    return 0; //return 0 to indicate a successful execution
}

int* qsort2(int* a, int n){ //qsort2 header, takes array a and size n, returns pointer to sorted array
    return qsortRecursive(a, 0, n-1); //calls recursive quicksort on array a in range [0, n)
}

int* qsortRecursive(int*a, int left, int right){ //recursive qsort header, qsorts a in range [left, right]
    if(left >= right) return a; //if range is size 1 or less then return because it's already sorted
    int pivot = partition(a, left, right); //partition [left,right] to get the pivot
    qsortRecursive(a, left, pivot-1); //qsort left side of pivot
    qsortRecursive(a, pivot+1, right); //qsort right side of pivot
    return a; //return pointer to sorted array
}

//rarranges array such that all values less than selected pivot are placed to the left of the pivot
//and all values greater than or equal to pivot are placed to the right of the pivot
int partition(int* a, int left, int right){ //partition header 
    int pivot = a[right]; //store value of pivot position, pivot picked as rightmost element
    int last = right; //store position of the pivot
    right--; //move right so its not pointing to the pivot
    while(left < right){ //loop while the left and right pointers have not met
        while(a[left] < pivot && left < right){ //loop while left pointer value is less than pivot
            left++; //increment left pointer 
        }
        while(a[right] >= pivot && left < right){ //loop while right pointer value is >= pivot
            right--; //decrement right pointer
        }
        swap(&a[left], &a[right]); //swap values pointed to by left and right 
    }  
    swap(&a[right], &a[last]); //put pivot to its proper spot in the array section
    return right; //return pivot position
}

void swap(int* a, int* b){ //swap header, swaps values pointed to by a and b
    int temp = *a; //store value pointed to by a
    *a = *b; //store value pointed to by b in a
    *b = temp; //store value pointed to by b in b
}
