/*1. You are given n number of integer as well as a sum.
 You have to compute whether the sum is made by the given integers or not.
  Design a recursive DP [Bottom up] solution for it.*/
#include <stdio.h>
int isSubsetSum(int set[], int n, int sum)
{
	if (sum == 0){
        return 1;
	}
	if (n == 0){
        return 0;
	}
	if (set[n - 1] > sum){
        return isSubsetSum(set, n - 1, sum);
	}
    else{
            return isSubsetSum(set, n - 1, sum)|| isSubsetSum(set, n - 1, sum - set[n - 1]);
    }

}

int main()
{
    int s,n;
	int set[20];
	printf("enter how many integer number: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%d",&set[i]);
	}
	//7, 2, 5
	//14
	printf("\nenter the sum: ");
	int sum = scanf("%d",&s);
	if (isSubsetSum(set, n, sum) == 1)
		printf("Subset with the given sum exists");
	else
		printf("No subset with given sum");
	return 0;
}

