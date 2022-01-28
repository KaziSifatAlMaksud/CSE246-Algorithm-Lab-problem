/*
######Minimum Number of Platforms Required for a Railway######
Given arrival and departure times of all trains that reach a railway station, the task is to find the
minimum number of platforms required for the railway station so that no train waits. We are given
two arrays which represent arrival and departure times of trains that stop.
Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}
dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation: There are at-most three trains at a time (time between 11:00 to 11:20)

Input: arr[] = {9:00, 9:40}
dep[] = {9:10, 12:00}
Output: 1
Explanation: Only one platform is needed.
*/
#include<stdio.h>


int main(){
    int plat_needed = 1;
    int result = 1;
    int n;
    int arr[100];
    int dep[100];
    printf("How many Number: ");
    scanf("%d",&n);
    printf("Input: \n");
    printf("arrible: \n");
    for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
    }
    printf("departure time: \n");
    for(int i=0;i<n;i++){
     scanf("%d",&dep[i]);
    }
    for (int i = 0; i < n; i++) {
		plat_needed = 1;

		for (int j = i + 1; j < n; j++) {
			if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])){
                plat_needed++;
			}

		}
    if(result<plat_needed){
        result = plat_needed;
    }

	}
	printf("Minimum number of platforms required: %d",result);
}




