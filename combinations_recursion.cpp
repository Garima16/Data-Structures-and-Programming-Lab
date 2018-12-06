#include<iostream>
#include<algorithm>
using namespace std;

int n=0;//store number of permutations
int fixed_r=0;

void combinations(string s,int l,int h,int r,string tmp)
{
	if(r==0)
	{
		n++;
		for(int q=tmp.length()-1;q>=0;q--)//read string backwards
			cout<<tmp[q];
		cout<<endl;
		return;
	}

	for(int j=l;j<=h-r+1;j++)
	{
		tmp[r-1]=s[j];
		combinations(s,j+1,h,r-1,tmp);
	}		
}

void comb(string s,int l,int h,int r,string tmp)
{
	for(int i=l;i<=h-fixed_r+1;i++)
	{
		tmp[r-1]=s[i];//start substring from 'i'
		combinations(s,i+1,h,r-1,tmp);
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
	fixed_r=r;
	std::string tmp(r,'0'); //initialise temporary string of length=r
	int len=s.length();
	comb(s,0,len-1,r,tmp);
	cout<<"Total combinations="<<n<<endl;
	return 1;
}
