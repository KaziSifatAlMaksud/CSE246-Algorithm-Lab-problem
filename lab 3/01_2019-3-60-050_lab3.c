/*1. Activity selection problem: Given a set of activities, along with the starting and finishing time of
each activity, find the maximum number of activities performed by a single person assuming that
a person can only work on a single activity at a time.

Example
3,7
2,4
5,8
6,9
1,11
10,12
0,3
Output: 3*/
#include<stdio.h>

struct ass{
int start;
int end;
}arr[100],tmp;
int main()
{
    int i,j;
	int n,x,y;
	printf("enter how many number: ");
	scanf("%d",&n);
	printf("enter element of start,ending value : \n");
	for(int i =0;i<n;i++){
        scanf("%d",&x);
         scanf("%d",&y);
        arr[i].start =x;
        arr[i].end =y;
	}


    for(int i= 0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if (arr[j].end >arr[j+1].end){
                tmp = arr[j];
                arr[j] =arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    int c=0;
	printf ("Following activities are selected: ");
	i = 0;
	printf("%d ", i);
	for (j = 0; j < n; j++)
	{
	if (arr[j].start >= arr[i].end)
	{
		printf ("%d ", j);
		i = j;
		c++;
	}
	}
	printf("Output: %d",c+1);
}

