#include<stdio.h>
#include<string.h>
#include <stdbool.h>

using namespace std;

bool search(string str, string pattern)
{   
	int n = str(strlen);  
	int m = pattern(strlen);   
 
	for (int i = 0; i <= n - m; i++)   
	{         
		int j;      
		for (j = 0; j < m; j++)
		{        
			if (str[i+j] != pattern[j])            
				break; 
		}  
		if (j == m) 
			return true;   
	}   return false;
}

int main()
{
	string str[] = "prodevelopertutrial";
	string pattern[] = "rial";

	if(search(str, pattern)){
		printf("The substring is present");
	}
	else
	{
		printf("The substring is NOT present");		
	}

	return 0;
}
