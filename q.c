#include<stdio.h>
#include<Stdlib.h>
#include<string.h>
void read_lines(char lines[10][100], int *num_lines) {
    char line[100];
    while (*num_lines < 10) {
        fgets(line, 100, stdin);
        if (line[0] == '\n') {
            break;
        }
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
}
int Length(char *strings)
{
    int i;
    for(i=0;strings[i]!='\0';++i);

    return i;
}
void read_linesFromFile(char lines[10][100], int *num_lines) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open file input.txt");
        return;
    }
    char line[100];
    while (*num_lines < 10 && fgets(line, 100, file) != NULL) {
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
    fclose(file);
}
void search(char *pat,char *txt)
{
    int n=Length(txt);
    int m=Length(pat);

    for(int i=0;i<n-m;i++)
    {
        int j;
        for( j=0;j<m;j++)
        {
            if(txt[i+j]!=pat[j])
                break;
        }
            if(j==m)
                printf("%s\n",txt);

    }
}
int main(){
 char lines[10][100];
    int num_lines = 0;

    // Read lines from user input
    printf("Enter up to %d lines of text, or an empty line to stop:\n", 10);
    read_lines(lines, &num_lines);
    printf("Reading from the file\n");
    read_linesFromFile(lines, &num_lines);
    char pat[10]="ould";
    for(int i=0;i<10;i++)
    {
        search(pat,lines[i]);
    }

}
