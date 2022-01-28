/*
3. Assigning mice to hole: There are N Mice and N holes are placed in a straight line. Each hole can
accommodate only 1 mouse. A mouse can stay at his position, move one step right from x to x + 1,
or move one step left from x to x -1. Any of these moves consumes 1 minute. Assign mice to holes
so that the time when the last mouse gets inside a hole is minimized.

Example:
Input: positions of mice are:
4 -4 2
Positions of holes are:
4 0 5
Output: 4
Assign mouse at position x = 4 to hole at
Position x = 4 : Time taken is 0 minutes
Assign mouse at position x=-4 to hole at
Position x = 0 : Time taken is 4 minutes
Assign mouse at position x=2 to hole at
Position x = 5 : Time taken is 3 minutes
After 4 minutes all of the mice are in the holes.
Since, there is no combination possible where
the last mouse's time is less than 4,
Answer = 4.
Input: positions of mice are:
-10, -79, -79, 67, 93, -85, -28, -94
Positions of holes are:
-2, 9, 69, 25, -31, 23, 50, 78
Output: 102

*/
#include <bits/stdc++.h>
using namespace std;

int assignHole(int mices[], int holes[],int n, int m)
{
	if (n != m)
		return -1;
	sort(mices, mices + n);
	sort(holes, holes + m);
	int max = 0;
	for(int i = 0; i < n; ++i)
	{
		if (max < abs(mices[i] - holes[i]))
			max = abs(mices[i] - holes[i]);
	}
	return max;
}

int main()
{   int n,m;
    int mices[20],holes[20];
    printf("Enter the number of mices, holes: ");
    scanf("%d %d",&n,&m);
    printf("positions of mice are: ");
    for(int i=0;i< n;i++){
        scanf("%d",&mices[i]);

    }
    printf("Positions of holes are: ");
    for(int j=0;j<m;j++){
        scanf("%d",&holes[j]);

    }
	int minTime = assignHole(mices, holes, n, m);

	printf("The last mouse gets into the hole in time: %d\n",minTime);


	return 0;
}
