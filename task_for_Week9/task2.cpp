#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAXLENGTH   100007

//You can add or modify any code when needed
typedef struct Record
{
    char number[19];        // ���֤��
    int distance=-1;           // ���о���
    int next=-1;               // ͬһ����ϣֵ���������ָ��
}Record;

Record records[MAXLENGTH];  // ����������
int head[MAXLENGTH];        // ��ϣ���������ͷ�����records���е��±�
int count=0;                  // records�����Ѿ�����Ľ����Ŀ

int hash(char *number);                     // ��ϣ�����������֤�Ž���ɢ��
int find(char *number);                     // �������֤�Ų��ҷ��м�¼
// �����Ǳ�������Ҫʵ�ֵĺ�����������main()֮�� 
void solution();
void insert(char *number, int distance);    // �����м�¼��Ϣ���뵽����


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
 * @brief ��ϣ����
 * @param number ���֤��
 * @return ��ϣֵ 
 */
int hash(char *number)
{
    long long res = 0;
    for (int i = 0; i < 17; i++) // ���һλ��ǰ17λ��У��ֵ�����Բ����ǣ�����Ӱ��Ψһ��
        res = 10 * res + (number[i] - '0'); // �����ʵ����ֱ�Ӷ�ǰ17λ����������λ�������������handle~�� 
    return res % MAXLENGTH;
}

/**
 * @brief �����м�¼��Ϣ���뵽��ϣ����
 * @param number ���֤��
 * @param distance ���о���
 */
// Hint: Ӧ����Ҫ�������֤�ţ��ַ������ıȽϣ�������string.h�е� int strcmp(const char *str1, const char *str2)���� https://www.runoob.com/cprogramming/c-function-strcmp.html 
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

