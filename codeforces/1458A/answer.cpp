#include<bits/stdc++.h>
using namespace std;

long long mygcd(long long a,long long b){
	if(a>b){
		swap(a,b);
	}
	if(b%a==0){
		return a;
	}
	return mygcd(a,b%a);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long>alla,allb(m);
	set<long long>st;
	for(long long i=0;i<n;i++){
		long long d;
		cin>>d;
		if(st.count(d)!=0){
			continue;
		}
		alla.push_back(d);
		st.insert(d);
	}
	sort(alla.begin(),alla.end());
	long long pgcd;
	for(long long i=1;i<alla.size();i++){
		alla[i]-=alla[0];
	}
	if(alla.size()>=2){
		pgcd=alla[1];
	}
	for(long long i=2;i<alla.size();i++){
		pgcd=mygcd(pgcd,alla[i]);
	}
	for(long long i=0;i<m;i++){
		cin>>allb[i];
		long long res=mygcd(pgcd,alla[0]+allb[i]);
		if(alla.size()==1){
			res=alla[0]+allb[i];
		}
		cout<<res<<" ";
	}
	cout<<endl;
}
