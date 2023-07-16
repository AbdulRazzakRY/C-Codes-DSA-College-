#include <stdio.h>
int array_sum(int arr[], int n)
{
    int sum = 0;                // Initilizing sum
    for (int i = 0; i < n; i++) // Loop till last/n elements of array
    {
        sum = sum + arr[i]; // Adds sum=previous+next element of the array
    }
    return sum; // Returns total sum of the elements of array
}

int fibon(int n)
{
    if (n <= 1) // If input n is less than or equal to 1
        return n; //  Returns n
    else
        return fibon(n-1) + fibon(n-2); /* It calls the fibon funcution several times 
                                           in recursion and return if n<=1*/
}
  int arraysum(int a[], int n)
 {
    if (n == 0) 
   {
        return 0;
    }
    else 
   {
        return a[n-1] + arraysum(a, n-1);
    }
}
int main()
{
    int sum = 0;
    int n = 16;
    int array[] = {1, 2, 3, 4, 5};
    sum = arraysum(array,5);
    printf("%d\n", sum);
    return 0;
}
