#include <stdio.h>
void bubble(int a[8], int n);
void display(int a[8], int n);
int main()
{
    FILE *myFile;
    myFile = fopen("randomnofiles.txt", "r");
    int n = 8;
    // read file into array
    int numberArray[8];
    int i;

    for (i = 0; i < 8; i++)
    {
        fscanf(myFile, "%d", &numberArray[i]);
    }

    display(numberArray, n);
    bubble(numberArray, n);
    printf("\n");
    display(numberArray, n);

    return 0;
}

void bubble(int a[8], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] >= a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void display(int a[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
