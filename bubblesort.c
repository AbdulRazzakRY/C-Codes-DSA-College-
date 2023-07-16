#include <stdio.h>
void bubble(int a[50], int n);
void display(int a[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
void main()
{
    int a[50], n, i;
    printf("Enter the array size\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    display(a, n);
    bubble(a, n);
    printf("\n");
    display(a, n);
}
void bubble(int a[], int n)
{
    int temp;                       // Temperory variable
    for (int i = 0; i < n - 1; i++) // Outer loop that runs till n-1 times
    {
        for (int j = 0; j < n - i - 1; j++) // Inner loop that runs for n-i-1 times assending order
        {
            if (a[j] >= a[j + 1]) // If present array element is greater than next array element goes in
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp; // Swaps the elements in assending order
            }
        }
    }
}
