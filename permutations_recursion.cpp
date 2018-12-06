#include<iostream>
#include<algorithm>
using namespace std;
int n=0;
void permute(string s,int l,int h,int r,string tmp)
{
	if(r==0)
	{
		n++;
		for(int q=tmp.length()-1;q>=0;q--)//read string backwards
			cout<<tmp[q];
		cout<<endl;
		return;
	}
	for(int i=l;i<=h;i++)
	{
		std::swap(s[l],s[i]);
		tmp[r-1]=s[l];
		permute(s,l+1,h,r-1,tmp);
		std::swap(s[l],s[i]);
	}
}

int main()
{
	string s;
	cout<<"Enter string:";
	cin>>s;
	cout<<"enter length of substring:";
	int r;
	cin>>r;
	std::string tmp(r,'0'); //initialise temporary string of length=r
	int len=s.length();
	permute(s,0,len-1,r,tmp);
	cout<<"Total permutations:"<<n<<endl;
	return 1;
}
