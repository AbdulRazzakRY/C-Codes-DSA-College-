#include <stdio.h>
#include <string.h>
void read_file(char[10][200], int n)
{
    FILE *file = fopen("myfile.txt", "r");
    if (file == NULL)
    {
        printf("Could not open myfile.txt");
        return;
    }
    char str[100];
    while (n < 10 && fgets(str, 100, file) != NULL)
    {
        strncpy(str[n], str, 100);
        (n)++;
    }
    fclose(file);
}
int main()
{
    char str[10][200];
    int n = 0;
    while (1)
    {
        printf("Enter the no. of lines to be read max 10\n");
        scanf("%d", &n);
        if (n <= 10)
        {
            for (int i = 0; i < n; i++)
            {
                fgets(str, 100, stdin);
                if (str[0] == '\n')
                {
                    break;
                }
                strncpy(str[n], str, 100);
            }
        }
        else
        {
            printf("Not Valid\n");
        }
    }
}