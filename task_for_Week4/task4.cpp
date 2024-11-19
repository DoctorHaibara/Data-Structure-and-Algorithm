#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define maxsize 100001
// ×¢£ºYou can add/modify any package or code as you need
using namespace std;

/*6 2
3 ann bob joe
2 jim zoe
jim 0 20
bob 0 15
ann 0 30
amy 0 2
zoe 1 61
joe 3 10*/

struct friends
{
    char fri[maxsize][4];
}circle[101]; // ÅóÓÑÈ¦

struct QueueData
{
    char name[4];
    int time;
    int pime;
}queue[maxsize];

void addqueue(struct QueueData* queue,int current_time,int* rear){
	while(queue[*rear].time<=current_time){
		(*rear)++;
	}
}

int get_position(int i,struct QueueData* queue,struct friends* circle,int m,int *nums){
	int n1;//n1=number of the circle n2=position in the circle
	bool f=false;
	for(int j=0;j<m;j++){
		for(int k=0;k<nums[j];k++){
			if(strcmp(queue[i].name,circle[j].fri[k])==0){
		       n1=j;
			   f=true;		
			}
		}
	}
	if(!f) return -1;
	
	int i1=i-1;//
	while(i1>=0){//search for friend in the queue
		for(int k=0;k<nums[n1];k++){//compare with it in the circle
			if(strcmp(queue[i1].name,circle[n1].fri[k])==0){
				//cout<<queue[i1].name<<" "<<queue[i].name;
		      return i1;	
			}
		}
		i1--;
	}
}

void insert(int i,int p,struct QueueData* queue){
	//p is the position of the closest freind
	if(p==-1||i==p+1){
		return;
	}
	else{
		queue[100]=queue[i];
		for(int j=i-1;j>p;j--){
			queue[j+1]=queue[j];
		}
		queue[p+1]=queue[100];
	}
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    // Your code here
    
    int nums[m];//the size of each circle
    for(int i=0;i<m;i++){
    	scanf("%d",&nums[i]);
    	for(int j=0;j<nums[i];j++){
    		scanf("%s",circle[i].fri[j]);
		}
	}
	
	/*for(int i=0;i<m;i++){
		cout<<i<<endl;
		for(int j=0;j<nums[i];j++){
			cout<<circle[i].fri[j]<<" ";
		}
		cout<<endl;
	}*/
	
	
	for(int i=0;i<n;i++){
		scanf("%s %d %d",queue[i].name,&queue[i].time,&queue[i].pime);
		if(queue[i].pime>=60) queue[i].pime=60;
	}
	
	int times[n];//time spent by each person
	int current_time=0;
	int front,rear;
	front=rear=0;
	for(int i=0;i<n;i++) times[i]=0;
	queue[front].pime++;
	while(front!=n){
		int r=rear;
		addqueue(queue,current_time,&rear);//add new members into the queue
		if(r!=rear&&r!=0&&rear<n){
			for(int i=r;i<=rear;i++){
		       int p=get_position(i,queue,circle,m,nums);//if has no friends return -1 else return the positon of the friend
		       //if(p!=-1) cout<<p<<" "<<r<<" "<<rear<<endl;
		       //cout<<i<<" "<<p<<endl;
			   insert(i,p,queue); //insert into the queue
		    } 
		}
		
		queue[front].pime--;
		//cout<<front<<"->"<<queue[front].pime<<" "<<current_time<<endl;
		if(queue[front].pime==0){
			//cout<<current_time<<endl;
			times[front+1]=current_time-queue[front+1].time;
			//cout<<times[front+1]<<endl; 
			front++;
		}
		
		//delete members in the queue and calculate the time spent
		current_time++;		//move on
	}
	
	int sum=0;
	for(int i=0;i<n;i++){
		cout<<queue[i].name<<endl;
		sum+=times[i];
	}
	
	cout<<(float)sum/n;
	
    return 0;
}
