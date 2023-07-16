// C program to find minimum sum of product
// of two arrays with k operations allowed on
// first array.
#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum product
int minproduct(int a[], int b[], int n, int k)
{
    int diff = 0, res = 0,temp;
    for (int i = 0; i < n; i++)
    {
        int pro = a[i] * b[i]; // Find product of current elements and update result
        res = res + pro;
        if (pro < 0 && b[i] < 0)          // If both product and b[i] are negative, we must
            temp = (a[i] + 2 * k) * b[i]; // increase value of a[i] to minimize result.

        else if (pro < 0 && a[i] < 0) // If both product and a[i] are negative, we must

            temp = (a[i] - 2 * k) * b[i]; // decrease value of a[i] to minimize result.

        else if (pro > 0 && a[i] < 0)
            temp = (a[i] + 2 * k) * b[i];

        else if (pro > 0 && a[i] > 0)
            temp = (a[i] - 2 * k) * b[i]; // Similar to above two cases for positive product.
        int d = abs(pro - temp); // Check if current difference becomes higher than
        if (d > diff)            // the maximum difference so far.
            diff = d;
    }
    return res - diff;
}

// Driver function
int main()
{
    int a[] = {2, 3, 4, 5, 4};
    int b[] = {3, 4, 2, 3, 2};
    int n = 5, k = 3;
    printf("%d ", minproduct(a, b, n, k));
    return 0;
}

// This code is contributed by Sania Kumari Gupta
