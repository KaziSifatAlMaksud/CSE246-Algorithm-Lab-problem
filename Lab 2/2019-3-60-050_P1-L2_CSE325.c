/*
####Job Sequencing Problem####
Given an array of jobs where every job has a deadline
and associated profit if the job is finished before the deadline.
It is also given that every job takes the single unit of time,
so the minimum possible deadline for any job is 1.
How to maximize total profit if only one job can be scheduled at a time.


Input: Four Jobs with following
deadlines and profits
JobID Deadline Profit
a 4 20
b 1 10
c 1 40
d 1 30
Output: Following is maximum
profit sequence of jobs
c, a
*/
#include<stdio.h>
#include<stdbool.h>
struct job {
    char jobID;
    int dedline;
    int profit;
}jobList[100],temp;


int min(int a,int b){
if(a<b) {
        return a;
}
else{
return b;
}
}

int main(){
int n,i,j;
bool slot[20];
int resut[20];

printf("enter number of Job: ");
scanf("%d",&n);

for( i=0;i<n;i++){
    printf("Type JobID, Deadline, Profit respactively: \n");
    scanf("%*c%c%d%d",&jobList[i].jobID,&jobList[i].dedline,&jobList[i].profit);
    printf("\n");
}

for(i=0;i<n;i++){
    slot[i] = false;
}
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(jobList[i].profit < jobList[i+1].profit){
            temp = jobList[i];
            jobList[i]= jobList[i+1];
            jobList[i+1] = temp;
        }
    }
}
for(i=0;i<n;i++){
    for(j= min(n,jobList[i].dedline)-1;j>=0;j--){
        if(slot[j] == false){
            resut[j]=i;
            slot[j] = true;
            break;
        }
    }
}
for(i=0;i<n;i++){
    if(slot[i]){
        printf("%c\t",jobList[resut[i]].jobID);
}
}



}
