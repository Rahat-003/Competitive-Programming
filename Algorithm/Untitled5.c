#include<stdio.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
int A[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }

    printf("\n");

    int B[m][n];

    for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                scanf("%d",&B[i][j]);-
            }
    }

    int c[m][n];

    puts("");

    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            c[i][j]=A[i][j]*B[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }










return 0;
}
