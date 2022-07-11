#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	long long a;
	cin>>a;
	vector<int>all(a),cnt(2e7+10);
	for(int i=0;i<a;i++){
		cin>>all[i];
		cnt[all[i]]++;
	}
	vector<int>allp;
	vector<bool>vis(2e7+10);
	for(int i=2;i<=2e7;i++){
		if(vis[i]==0){
			allp.push_back(i);
		}
		for(int j=0;j<allp.size()&&i*allp[j]<=2e7;j++){
			vis[i*allp[j]]=1;
			if(i%allp[j]==0){
				break;
			}
		}
	}
	vector<long long>dp(2e7+10);
	for(int i=1;i<=2e7;i++){
		for(int j=i*2;j<=2e7;j+=i){
			cnt[i]+=cnt[j];
		}
		dp[i]=1ll*i*cnt[i];
	}
	for(int i=2e7;i>=1;i--){
		for(int j=0;j<allp.size()&&1ll*allp[j]*i<=2e7;j++){
			dp[i]=max(dp[i],dp[allp[j]*i]+1ll*i*(cnt[i]-cnt[allp[j]*i]));
		}
	}
	cout<<dp[1]<<endl;
}
