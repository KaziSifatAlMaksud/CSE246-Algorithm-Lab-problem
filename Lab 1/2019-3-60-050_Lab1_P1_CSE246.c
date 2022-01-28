/*1. You are given n numbers of coin. Supply of each coin is infinite.
You are also given an amount m.
Your task is to calculate minimum number of coins
that are required to make the change of the given amount m.
*/

#include <stdio.h>

int main()
{   int n,co,m;
    int coinList[20];
    int coins[20];
    printf("Enter the amount: ");
	scanf("%d",&m);
    printf("number of coin:" );
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&co);
        coins[i] = co;
    }


	printf("Following is minimal number"
		"of change for %d: ",m);
    int k=0;
    for (int i = n - 1; i >= 0;i--) {
		while (m >= coins[i]) {
        	m = m - coins[i];

			coinList[k] = coins[i];
			k++;
		}
	}
	for(int j=0;j<k;j++){
        printf("%d,",coinList[j]);
	}

}
