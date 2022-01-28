/* LCS: Longest Common Subsequence (Problem Statement)
Recursive solution
Recursive DP (bottom up)
Iterative DP (top down)
Trace back
Longest repeating subsequence
*/
#include<stdio.h>
#include<string.h>
char x[100],y[100];
int max(int a,int b){
        if(a>b){
            return a;
        }
        else{
            return b;
        }
}
int LCS (char x[], char y[],int n,int m){

    if(n== 0||m== 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1 + LCS(x,y,n-1,m-1);
    }
    else{
                    return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
}
int main(){
int n,m;
gets(x);
gets(y);

n = strlen(x);
m = strlen(y);

int  len = LCS( x,y,n,m);

printf("lENGH OF LCS IS : %d",len);

}
