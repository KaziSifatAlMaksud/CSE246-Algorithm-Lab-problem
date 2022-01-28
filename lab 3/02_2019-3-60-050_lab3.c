/*Minimize the sum of Product: You are given two arrays, A and B, of equal size N. The task is to
find the minimum value of A[0] * B[0] + A[1] * B[1] +...+ A[N-1] * B[N-1], where shuffling of
elements of arrays A and B is allowed.
Example 1:
Input:
N = 3
A[] = {3, 1, 1}
B[] = {6, 5, 4}
Output:
23
Explanation:
1*6+1*5+3*4 = 6+5+12
= 23 is the minimum sum
Example 2:
Input:
N = 5
A[] = {6, 1, 9, 5, 4}
B[] = {3, 4, 8, 2, 4}
Output:
80
Explanation:
2*9+3*6+4*5+4*4+8*1
=18+18+20+16+8
= 80 is the minimum sum*/
#include<stdio.h>

int main()
{
    int tmp;
	int n,x,y;
	int a[100],b[100];
	printf("enter how many number: ");
	scanf("%d",&n);
	printf("enter element of A : \n");
	for(int i =0;i<n;i++){
        scanf("%d",&x);
        a[i] =x;
	}
	printf("enter element of B : \n");
		for(int i =0;i<n;i++){
        scanf("%d",&y);
        b[i]= y;
	}
    for(int i= 0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (a[j] >a[j+1]){
                tmp = a[j];
                a[j] =a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i= 0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (b[j] <b[j+1]){
                tmp = b[j];
                b[j] =b[j+1];
                b[j+1] = tmp;
            }
        }
    }
    int sum =0;
    for(int i=0;i<n;i++){
            int value = a[i]*b[i];
        sum = sum + value;
    }
    printf("Output: %d",sum);


}

