#include<iostream>
#define INT 0x3f3f3f3f
// Please add or modify any code whenever needed 
using namespace std;

void Floyd(int i,int j,int (&c)[110][110],int a){
	for(int k=1;k<=a;k++){
		if(c[i][k]+c[k][j]<c[i][j]) c[i][j]=c[i][k]+c[k][j];
	}
}
int main()
{
    int a,b,c[110][110],e,f,g;
    for(e=0;e<110;e++)//Éè³õÖµ
        for(f=0;f<110;f++)
        {
            if(e==f)
                c[e][f]=0;
            else
                c[e][f]=INT;
        }
    cin>>a>>b;
    while(b--)
    {
        cin>>e>>f>>g;
        c[e][f]=c[f][e]=g;
    }
    // Your code here
	int s,max;
	max=INT; 
    for(int i=1;i<=a;i++){
    	for(int j=1;j<=a;j++){
    		Floyd(i,j,c,a);
		}
	}
	for(int i=1;i<=a;i++){
		int max1=0;
		for(int j=1;j<=a;j++){
			if(c[i][j]>max1) max1=c[i][j];
		} 
			if(max1<max){
				max=max1;
				s=i;
			}
	}
	cout<<s<<" "<<max;
	return 0;
}

