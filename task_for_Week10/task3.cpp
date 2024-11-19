#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#define MAXLEAF 50
#define MAXNODE 2*MAXLEAF-1
#define MAXWEIGHT 10000
#define MAXBIT 100
// Note: you can add or delete any code/functions whenever needed
typedef struct character
{
    char ch;
    int count=0;
}CHARACTER;             //记录原文本文件中出现的字符及相应出现次数的类型
typedef struct hnodetype
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    char value;
    int i;
}HNodeType;             //哈夫曼树的结点定义
typedef struct huffcodetype
{
    int bit[MAXBIT];
    int start;
}HCodeType;             //记录每个字符哈夫曼编码
typedef struct heap
{
    HNodeType node[MAXNODE+1];
    int n;
}HEAP;                  //最小堆的类型定义
void Statistic(CHARACTER chars[],int &n);                       //统计原文本中出现的字符及其使用频率
void Display(CHARACTER chars[],int n);                          //打印原文本中出现的字符及其使用频率
void CreateHT(HNodeType huffnode[],int n,CHARACTER chars[]);    //构建哈夫曼树 
void Coding(HNodeType huffnode[],HCodeType huffcode[],int n);   //构建哈夫曼编码表
void Calculate(CHARACTER chars[],int n,int chnum);              //计算压缩率(待实现)
void Display(HNodeType huffnode[],HCodeType huffcode[],int n);  //打印哈夫曼编码表（待实现）
void CodingFile(HNodeType huffnode[],HCodeType huffcode[],int n,int &chnum);    //将文本编码并存入文件（待实现） 
void Decoding(HNodeType huffnode[],int n);                                      //将编码文件译码恢复（待实现）

void Insert(HEAP &heap,HNodeType item);     //向堆里插入元素
HNodeType Delete(HEAP &heap);               //取堆顶元素并删除
void CreateHT_heap(HNodeType huffnode[],CHARACTER chars[],int n,HEAP &heap);    //用最小堆优化构建哈夫曼树的过程
int main()
{
    CHARACTER chars[MAXLEAF];
    HNodeType huffnode[MAXNODE];
    HCodeType huffcode[MAXLEAF];
    HEAP heap;heap.n=0;
    int n=0,chnum=0;
    Statistic(chars,n);
    Display(chars,n);
    CreateHT(huffnode,n,chars);
    //CreateHT_heap(huffnode,chars,n,heap);
    Coding(huffnode,huffcode,n);
    Display(huffnode,huffcode,n);
    CodingFile(huffnode,huffcode,n,chnum);
    Calculate(chars,n,chnum);
    Decoding(huffnode,n);
}
void Statistic(CHARACTER chars[],int &n)    //统计原文本中出现的字符及其使用频率
{
    FILE *f=NULL;
    if((f=fopen("original.txt","r"))==NULL)
    {
        printf("Fail to open original.txt!\n");
        exit(0);
    }
    char ch;
    int i=0,j=0,flag=0;;
    fscanf(f,"%c",&ch);
    chars[i].ch=ch;
    chars[i].count++;
    //printf("%c",chars[i].ch);
    i++;
    while(ch!='#')  //从文件读入文本，以#标记结束
    {
        fscanf(f,"%c",&ch);
        flag=0;
        if(ch!='#')
        {
            for(j=0;j<i;j++)
            {
                if(ch==chars[j].ch)  //如果读入的字符已被记录，则将出现次数+1
                {
                    chars[j].count++;
                    flag=1;
                    //printf("%c",chars[j].ch);
                    break;
                }
            }
            if(flag==0)
            {
                chars[i].ch=ch;
                chars[i].count++;
                //printf("%c",chars[i].ch);
                i++;
            }
        }
    }
    n=i;
    fclose(f);
}
void CreateHT(HNodeType huffnode[],int n,CHARACTER chars[])     //构建哈夫曼树
{
    int i,j,w1,w2,x1,x2;
    for(i=0;i<2*n-1;i++)        //初始化
    {
        huffnode[i].weight=chars[i].count;
        huffnode[i].parent=-1;
        huffnode[i].lchild=-1;
        huffnode[i].rchild=-1;
        huffnode[i].value=chars[i].ch;
    }
    for(i=0;i<n-1;i++)
    {
        w1=w2=MAXWEIGHT;
        x1=x2=0;
        for(j=0;j<n+i;j++)      //寻找权值最小的两个结点
        {
            if(huffnode[j].parent==-1&&huffnode[j].weight<w1)
            {
                w2=w1;
                x2=x1;
                w1=huffnode[j].weight;
                x1=j;
            }
            else if(huffnode[j].parent==-1&&huffnode[j].weight<w2)
            {
                w2=huffnode[j].weight;
                x2=j;
            }
        }
        huffnode[x1].parent=n+i;
        huffnode[x2].parent=n+i;
        huffnode[n+i].lchild=x1;
        huffnode[n+i].rchild=x2;
        huffnode[n+i].weight=w1+w2;
        huffnode[n+i].value='#';
    }
}
void CreateHT_heap(HNodeType huffnode[],CHARACTER chars[],int n,HEAP &heap)  //利用堆优化哈夫曼树的构建
{
    int i;
    HNodeType node1,node2;
    for(i=0;i<2*n-1;i++)
    {
        huffnode[i].weight=chars[i].count;
        huffnode[i].parent=-1;
        huffnode[i].lchild=-1;
        huffnode[i].rchild=-1;
        huffnode[i].value=chars[i].ch;
        huffnode[i].i=i;
        if(i<n)
            Insert(heap,huffnode[i]);
    }
    for(i=0;i<n-1;i++)
    {
        node1=Delete(heap);
        node2=Delete(heap);
        huffnode[node1.i].parent=n+i;
        huffnode[node2.i].parent=n+i;
        huffnode[n+i].lchild=node1.i;
        huffnode[n+i].rchild=node2.i;
        huffnode[n+i].weight=node1.weight+node2.weight;
        huffnode[n+i].i=n+i;
        huffnode[n+i].value='#';
        Insert(heap,huffnode[n+i]);
    }
}
void Coding(HNodeType huffnode[],HCodeType huffcode[],int n)        //构建字符的哈夫曼编码表
{
    HCodeType temp;
    int p,c;
    for(int i=0;i<n;i++)
    {
        huffcode[i].start=MAXBIT-1;
        c=i,p=huffnode[i].parent;
        while(p!=-1)
        {
            if(c==huffnode[p].lchild)
                huffcode[i].bit[huffcode[i].start]=0;
            else
                huffcode[i].bit[huffcode[i].start]=1;
            c=p;
            p=huffnode[p].parent;
            huffcode[i].start--;
        }
        huffcode[i].start++;
    }
}
void Display(HNodeType huffnode[],HCodeType huffcode[],int n) //打印哈夫曼编码表
{
    // Your code here
    for(int i=0;i<n;i++){
    	std::cout<<huffnode[i].value<<":";
    	for(int j=huffcode[i].start;j<=MAXBIT-1;j++){
    		std::cout<<huffcode[i].bit[j];
		}
		std::cout<<std::endl;
	}
}
void CodingFile(HNodeType huffnode[],HCodeType huffcode[],int n,int &chnum)     //对原文本编码并将编码写入文件
{
    FILE *fo=NULL;
    FILE *fc=NULL;
    if((fo=fopen("original.txt","r"))==NULL)
    {
        printf("Fail to open original.txt!\n");
        exit(0);
    }
    if((fc=fopen("compressed.txt","w"))==NULL)
    {
        printf("Fail to open compressed.txt!\n");
        exit(0);
    }
    char ch;
    do
    {
        fscanf(fo,"%c",&ch);
        if(ch!='#')
        {
            // Your code here
            for(int j=0;j<n;j++)
            {
                if(ch==huffnode[j].value)  //the chracter was found 
                {
                    for(int i=huffcode[j].start;i<=MAXBIT-1;i++){
                    	fprintf(fc,"%c",'0'+huffcode[j].bit[i]);
                    	chnum++;
					}
					break;
                }
            }
        }
    } while (ch!='#');
    fclose(fo);
    fclose(fc);
}
void Decoding(HNodeType huffnode[],int n)   //译码
{
    FILE *fc=NULL,*fd=NULL;
    if((fc=fopen("compressed.txt","r"))==NULL)
    {
        printf("Fail to open compressed.txt!\n");
        exit(0);
    }
    if((fd=fopen("decoding.txt","w"))==NULL)
    {
        printf("Fail to open decoding.txt!\n");
        exit(0);
    }
    char code[100000];
    fscanf(fc,"%s",code);
    int i=0,j=0,temp=2*n-2;
    for(i=0;code[i]!='\0';i++);
    while(j<i)
    {
        // Your code here
        if(code[j++]=='0'){
        	temp=huffnode[temp].lchild;
		}
		else{
			temp=huffnode[temp].rchild;
		}
		if(huffnode[temp].value!='#'){
			fprintf(fd,"%c",huffnode[temp].value);
			temp=2*n-2;
		}
    }
    fclose(fc);
    fclose(fd);
}
void Display(CHARACTER chars[],int n)   
{
    int total=0;
    double f=0;
    for(int i=0;i<n;i++)
    {
        total=total+chars[i].count;
    }
    for(int i=0;i<n;i++)
    {
        printf("frequency of %c is %f\n",chars[i].ch,chars[i].count*1.0/total);
    }
}
void Calculate(CHARACTER chars[],int n,int chnum)   //计算压缩率
{
    int total=0;
    // Your code here
    for(int i=0;i<n;i++){
    	total+=chars[i].count;
	}
    printf("Compression rate is %f%%",chnum*1.0/8/total*100);
}
void Insert(HEAP &heap,HNodeType item)
{
    int i;
    if(heap.n<MAXNODE-1)
    {
        i=heap.n+1;
        while(i!=1&&item.weight<heap.node[i/2].weight)
        {
            heap.node[i]=heap.node[i/2];
            i/=2;
        }
        heap.node[i]=item;
        heap.n++;
    }
}
HNodeType Delete(HEAP &heap)
{
    int parent=1,child=2;
    HNodeType item,temp;
    if(heap.n>0)
    {
        item=heap.node[1];
        temp=heap.node[heap.n--];
        while(child<=heap.n)
        {
            if(child<heap.n&&heap.node[child].weight>heap.node[child+1].weight)
                child++;
            if(temp.weight<=heap.node[child].weight) break;
            heap.node[parent]=heap.node[child];
            parent=child;
            child*=2;
        }
        heap.node[parent]=temp;
        return item;
    }
}

