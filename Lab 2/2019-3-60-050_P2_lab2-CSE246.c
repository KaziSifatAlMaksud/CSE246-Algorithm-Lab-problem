/*
#####Job Sequencing Problem – Loss Minimization###

We are given N jobs numbered 1 to N. For each activity, let Ti denotes the number of days
required to complete the job. For each day of delay before starting to work for job i, a loss of Li
is incurred.
We are required to find a sequence to complete the jobs so that overall loss is minimized. We can
only work on one job at a time.

Input : L = {3, 1, 2, 4} and
T = {4, 1000, 2, 5}
Output : 3, 4, 1, 2
Explanation: We should first complete
Job 3, then jobs 4, 1, 2 respectively.


Input : L = {1, 2, 3, 5, 6}
T = {2, 4, 1, 3, 2}
Output : 3, 5, 4, 1, 2
Explanation: We should complete jobs
3, 5, 4, 1 and then 2 in this order.

*/
#include<stdio.h>

struct job {
    int no;
    int time;
    double  loss;
    double  lt;

}jobList[100],temp;
int main(){

int i,n,j;
printf("Enter how many job: ");
scanf("%d",&n);
for(i=0;i<n;i++){

    jobList[i].no = i+1;
    printf("Give User Input days & loss : \n");
    scanf("%d",&jobList[i].loss);
    scanf("%d",&jobList[i].time);

    jobList[i].lt = jobList[i].loss/(double)jobList[i].time;

}

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    if(jobList[j].lt<jobList[j+1].lt){
        temp = jobList[j];
        jobList[j]= jobList[j+1];
        jobList[j+1]= temp;
    }}

}
printf("Output: ");
for(i=0;i<n;i++){

    printf("%d\t",jobList[i].no);
}

}
