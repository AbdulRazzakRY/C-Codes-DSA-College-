// Quick sort in C

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high)  //to find the partition position
{
  int pivot = array[high]; // select the rightmost element as pivot
  int i = (low - 1);  // pointer for greater element
  for (int j = low; j < high; j++)  // traverse each element of the array compare them with the pivot
{
    if (array[j] <= pivot) { 
      i++;
      swap(&array[i], &array[j]); // swap element at i with element at j
    }
  }
  swap(&array[i + 1], &array[high]);  // swap the pivot element with the greater element at i
  return (i + 1);   // return the partition point
}
void quickSort(int array[], int low, int high) {
  if (low < high) {  
    int pi = partition(array, low, high);  /* find the pivot element such that smaller than pivot 
                                             are on left greater than pivot are on right */
    quickSort(array, low, pi - 1);     // recursive call on the left of pivot
    quickSort(array, pi + 1, high);   // recursive call on the right of pivot
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main() {
  int data[] = {82, 37, 24, 18, 02, 79, 56};
  
  int n = sizeof(data) / sizeof(data[0]);
  
  printf("Unsorted Array\n");
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}