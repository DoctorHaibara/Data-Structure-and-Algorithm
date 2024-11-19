#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>
#include <iostream>

#define MAXSIZE 5000009
#define MAXLENGTH 50
#define MAX 10
#define MIN 3
//You can add or modify any code when needed

/*

2
aaa bbb ccc
#
aaa ccc
#
1
1  2
*/

typedef struct HashEntry *Cell; /* ɢ�б�Ԫ���� */
typedef struct HashEntry
{
    char word[MAX+1];
    bool Isfull=false; 
}hash_table_one; //һ����ϣ��Ľṹ���������ʾ 

typedef struct file_information *File;
typedef struct file_information
{
    int number;  
    Cell Cells; //һ���ļ��еĴʻ�����ϣ���У���Ϊ������ҪƵ���Ĳ���Ͳ��ң� 
    double same;
}file_one;

File Input(); //����һ���ļ���������ݣ���ʵ�֣� 
// ��Ҫ��ʵ�ֵĺ���1�� ע�⣺���Զ�������Ĳ�����ʵ�ְ�һ���ʻ���뵽һ���ļ��е�ɢ�б��� 
void Insert(char* word,File file); 
int hash(const char input_word[]); //��ȡ�ַ�ӳ������֣���ʵ�� 
//ʹ�õ�������̽�⣡
// ��Ҫ��ʵ�ֵĺ���2�� ������Ƚϲ������ͬ�ʻ�ı��� 
void Compare(File one, File two);

int main()
{
    int N, M, i;
    scanf("%d",&N); // �ļ����� 
    File file[N+1];
    for ( i = 1; i <= N; i++) // ����ÿһ���ļ������� 
        file[i]=Input(); 
    scanf("%d",&M); // ��ѯ���� 
    for (i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        a<b?Compare(file[a],file[b]):Compare(file[b],file[a]); // ���ļ������Ⱥ�˳���
    }
    system("pause");
    return 0;
}

File Input()
{
	// һ���ļ�file������ݵĳ�ʼ��
    File file=(File)malloc(sizeof(file_one));
    file->Cells=(Cell)malloc(sizeof(hash_table_one)*MAXSIZE);
    file->number=file->same=0;
    memset(file->Cells,0,sizeof(hash_table_one)*MAXSIZE); // �ⲽ�������ļ�file�ṹ���е�ɢ�б�H�������Ԫ��ȫ����ֵΪ0 

    bool sybool=true; // ͨ���Ƿ������� '#' �����һ���ļ����ݵ����� 
    while (sybool)    
    {
        char *word=(char*)malloc(sizeof(char)*MAXLENGTH);
        int i;
        for ( i = 0; i < MAXLENGTH; i++)
        {
            char mid;
            scanf("%c",&mid);
            if (mid == '#')
                sybool=false;
            if (isalpha(mid)) // ���ú����������ж�һ���ַ��Ƿ�Ϊ��ĸ��������ַ��򷵻ط��㣬���򷵻��� 
                word[i]=tolower(mid); // ���ַ�Сд������������Ĵ�Сд�� 
            else
                break;
        }
        (i>=10)?(word[10]='\0'):(word[i]='\0'); 
        if (i >= 3)  //�����ַ����ȴ��ڵ���3ʱ�ŷŽ���ϣ��
            Insert(word,file); // ��Ҫʵ�����������ܿ��ܱ��벻�� 
        free(word);
    }
    return file; // ����һ�������������ݵ��ļ� 
}

// һ���ַ����Ĺ�ϣ����ֵ 
int hash(const char input_word[])
{
    long long sum=0,i;
    for ( i = 0; input_word[i] != '\0'; i++)
        sum=sum * 27 + (input_word[i] - 'a'); // �����int������handle����Ϊ7�����ϵĵ��� 
    return sum % MAXSIZE;
}
void Insert(char* word,File file)
{
    // Your code here 
    int i=0,sum=0;
    int position=hash(word);
    
    while(file->Cells[position].Isfull&&strcmp(file->Cells[position].word,word)!=0){
    	position=(position+1)%MAXSIZE;
	}
	//std::cout<<"pos"<<position<<std::endl;
	if(strcmp(file->Cells[position].word,word)!=0){
	    strcpy(file->Cells[position].word,word);
	    file->Cells[position].Isfull=true;
	    file->number++;	
	}
   
}
void Compare(File one, File two)
{
	// Your code here 
	int num1=one->number;
	int num2=two->number;
	int same=0;
	int i=0,j=0;
	//std::cout<<num1<<" "<<num2<<std::endl;
		while(num1){//search
		while(!one->Cells[i].Isfull){
			//std::cout<<i<<std::endl;
			i++;
		}
        j=i;
		while(two->Cells[j].Isfull&&strcmp(two->Cells[j].word,one->Cells[i].word)!=0){//error occur
			//std::cout<<j<<std::endl; 
		   j++;
		}
		if(strcmp(two->Cells[j].word,one->Cells[i].word)==0){
			same++;
			//std::cout<<two->Cells[j].word<<std::endl;
		}
		
		if(one->Cells[i].Isfull) {
		    num1--;
			i++; 
		}//one word found 
	}
	//std::cout<<same<<std::endl;
	double result=(double)same/(one->number+two->number-same)*100;
	printf("%.1f",result);
	std::cout<<"%"<<std::endl;
}


