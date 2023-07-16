#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void select_keyword(arr);
char* replaceWord(char* s,char* oldW,char* newW);
int main()
{
    int arr[20],i;
    printf("enter the words\n");
    scanf("%d",&arr[20]);
    void select_keyword(arr);
}
void select_keyword(arr)
{
    char x[20];
     printf("enter the new keyword\n");
    gets(x);
     if(x==arr){
        replaceWord(arr,x);
     }
    
    else
        exit(0);
}


// Function to replace a string with another
// string
char *replaceWord(char* s,char* oldW,char* newW)
{
    char* result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
 
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
 
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
 
    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, oldW) == s) {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

}