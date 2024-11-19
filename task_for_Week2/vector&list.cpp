//vector&list
#include <list>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	list<int> l;
	vector<int> v;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		l.push_back(i);
		v.push_back(i);
	}
	cout<<l.size()<<" "<<v.size()<<endl;
}
