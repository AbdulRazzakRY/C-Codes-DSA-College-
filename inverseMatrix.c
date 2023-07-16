#include<stdio.h>
int main(){
    int m,n;
    printf("Enter no. of rows i and no. columns j for 1st matrix:\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    printf("Enter the elements of the mtrix:\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("The transpose of the matrix is:\n");
     int transp_mat[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transp_mat[i][j]=arr[j][i];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d\t",transp_mat[i][j]);
        }
        printf("\n");
    }
}