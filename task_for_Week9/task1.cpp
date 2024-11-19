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

typedef struct HashEntry *Cell; /* 散列表单元类型 */
typedef struct HashEntry
{
    char word[MAX+1];
    bool Isfull=false; 
}hash_table_one; //一个哈希表的结构，用数组表示 

typedef struct file_information *File;
typedef struct file_information
{
    int number;  
    Cell Cells; //一个文件中的词汇存进哈希表中（因为我们需要频繁的插入和查找） 
    double same;
}file_one;

File Input(); //输入一个文件的相关数据（已实现） 
// 需要你实现的函数1， 注意：请自定义所需的参数。实现把一个词汇插入到一个文件中的散列表中 
void Insert(char* word,File file); 
int hash(const char input_word[]); //获取字符映射的数字！已实现 
//使用的是线性探测！
// 需要你实现的函数2， 在这里比较并输出共同词汇的比例 
void Compare(File one, File two);

int main()
{
    int N, M, i;
    scanf("%d",&N); // 文件总数 
    File file[N+1];
    for ( i = 1; i <= N; i++) // 输入每一个文件的内容 
        file[i]=Input(); 
    scanf("%d",&M); // 查询总数 
    for (i = 0; i < M; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        a<b?Compare(file[a],file[b]):Compare(file[b],file[a]); // 按文件名的先后顺序比
    }
    system("pause");
    return 0;
}

File Input()
{
	// 一个文件file相关内容的初始化
    File file=(File)malloc(sizeof(file_one));
    file->Cells=(Cell)malloc(sizeof(hash_table_one)*MAXSIZE);
    file->number=file->same=0;
    memset(file->Cells,0,sizeof(hash_table_one)*MAXSIZE); // 这步函数把文件file结构体中的散列表H数组里的元素全部赋值为0 

    bool sybool=true; // 通过是否输入了 '#' 来完成一个文件内容的输入 
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
            if (isalpha(mid)) // 内置函数，用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零 
                word[i]=tolower(mid); // 把字符小写化（忽略输入的大小写） 
            else
                break;
        }
        (i>=10)?(word[10]='\0'):(word[i]='\0'); 
        if (i >= 3)  //单词字符长度大于等于3时才放进哈希表！
            Insert(word,file); // 你要实现这个，否则很可能编译不了 
        free(word);
    }
    return file; // 返回一个包含输入内容的文件 
}

// 一个字符串的哈希函数值 
int hash(const char input_word[])
{
    long long sum=0,i;
    for ( i = 0; input_word[i] != '\0'; i++)
        sum=sum * 27 + (input_word[i] - 'a'); // 如果是int，则不能handle长度为7及以上的单词 
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


