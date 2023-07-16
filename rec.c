#include<stdio.h>
// void rec(int n){
//     {
//         if(n>0){
//             printf("%d\t",n);
//             rec(n-1);
//         }
//     }
// }
// void rec(int n){
//     {
//         if(n>0){
//             for(int i=0; i<n; i++){
//                 printf("%d\t",n);
//             }
//             rec(n-1);
//         }
//     }
// }
void rec(int n){
    {
        if(n>0){
            
                printf("%d\t",n);
            rec(n-1);
            rec(n-1);
        }
    }
}
int main(){
    int n;
    printf("Enter the num\n");
    scanf("%d",&n);
    rec(n);
}