# include <iostream>
# include <map>
# include <string>

using namespace std;
// Note: your can use the built-in "map" class to create heap. Or define the heap from scratch. 

int Hash(string s,int p,map<int,string>& mp){
	int sum=0;
	for(int i=s.length()-3;i<s.length();i++){
		int t=s[i]-'A';
		sum=sum<<5;
		sum+=t;
	}
	int pos=sum%p;
	//std::cout<<sum<<" ";
	if(mp.count(pos)==0){
		return pos;
	}
	else{
		int i=1;
		int f=1;
		while(mp.find((pos+f*i*i+p)%p)!=mp.end()){//error occur 
			if(f==-1) i++;
			f=-f;
		}
		//std::cout<<" 111 "<<(pos+f*i*i+p)%p<<std::endl;
		return (pos+f*i*i+p)%p;
	}
}
int main()
{
	// Your code here
    map<int,string> mp;
    mp[-1]="null"; 
    int n,p;
    std::cin>>n>>p;
    for(int i=0;i<n;i++){
    	string tmp;
    	std::cin>>tmp;
    	int position=Hash(tmp,p,mp);
    	if(position!=-1){
    		mp[position]=tmp;
    		std::cout<<position;
    		if(i!=n-1) std::cout<<" ";
		}
	}
	return 0;
}
