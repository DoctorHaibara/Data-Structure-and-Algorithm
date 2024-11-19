#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAXLENGTH   100007

//You can add or modify any code when needed
typedef struct Record
{
    char number[19];        // 身份证号
    int distance=-1;           // 飞行距离
    int next=-1;               // 同一个哈希值的链表里的指针
}Record;

Record records[MAXLENGTH];  // 当作链表用
int head[MAXLENGTH];        // 哈希表，存放链表头结点在records表中的下标
int count=0;                  // records表中已经插入的结点数目

int hash(char *number);                     // 哈希函数，对身份证号进行散列
int find(char *number);                     // 根据身份证号查找飞行记录
// 以下是本次任务要实现的函数，代码在main()之后 
void solution();
void insert(char *number, int distance);    // 将飞行记录信息插入到表中


int main()
{
    solution();
    //std::cout<<count;
}

void solution()
{
    memset(head, -1, sizeof head);
    int n, k;
    scanf("%d %d", &n, &k);
    char number[19];
    int distance;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", number, &distance);
        if (distance < k) distance = k;
        insert(number, distance);
    }
    int m;
    scanf("%d", &m);
    int pos = -1;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", number);
        pos = find(number);
        if (pos == -1) printf("No Info\n");
        else printf("%d\n", records[pos].distance);
    }

}

/**
 * @brief 哈希函数
 * @param number 身份证号
 * @return 哈希值 
 */
int hash(char *number)
{
    long long res = 0;
    for (int i = 0; i < 17; i++) // 最后一位是前17位的校验值，可以不考虑，并不影响唯一性
        res = 10 * res + (number[i] - '0'); // 这里的实现是直接对前17位数都做了移位（计算机还可以handle~） 
    return res % MAXLENGTH;
}

/**
 * @brief 将飞行记录信息插入到哈希表中
 * @param number 身份证号
 * @param distance 飞行距离
 */
// Hint: 应该需要进行身份证号（字符串）的比较，可以用string.h中的 int strcmp(const char *str1, const char *str2)函数 https://www.runoob.com/cprogramming/c-function-strcmp.html 
void insert(char *number, int distance)
{
    // Your code here
	int pos=hash(number);
	if(records[pos].distance==-1){
		while(records[pos].next!=-1){
			pos=(pos+1)%MAXLENGTH;
		}
		records[pos].distance=distance;
		strcpy(records[pos].number,number);
		head[count++]=pos;
		return;
	}
	if(strcmp(records[pos].number,number)==0){//is the same person
		records[pos].distance+=distance;
	    return;
	} 
	else{
		while(records[pos].next!=-1){
			pos=(pos+1)%MAXLENGTH;
		}
		records[pos].next=(pos+1)%MAXLENGTH;
		pos=(pos+1)%MAXLENGTH;
		records[pos].distance=distance;
		strcpy(records[pos].number,number);
	}
}

int find(char *number)
{
    // Your code here 
    for(int i=0;i<count;i++){
    	int pos=head[i];
    	//std::cout<<pos<<std::endl;
     	do{
    		if(strcmp(number,records[pos].number)==0){
    			return pos;
			}
			pos=records[pos].next;
		}while(records[pos].next!=-1);
	}
	return -1;
}

