//0/1 knapsack using dp

#include<iostream>
using namespace std;

long long knapsack(long long length, long long target, long long wt[], long long value[]){
	long long dp[length+2][target+2];
	for(int i=0; i<=length; i++){
		for(int w=0; w<=target; w++){
			if(i==0 or w==0){
				dp[i][w]=0;
			}
			else if(w>=wt[i]){
				dp[i][w]=max(dp[i-1][w],value[i]+dp[i-1][w-wt[i]]);
			}
			else{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	return dp[length][target];
}


void solve(){
	long long length,target;
	cin>>length>>target;
	long long wt[length+1],value[length+1];
	for(int i=1; i<=length; i++){
		cin>>wt[i];
	}
	for(int i=1; i<=length; i++){
		cin>>value[i];
	}
	cout<<knapsack(length, target,wt,value)<<endl;
}
	
		



int main(){
	int t=1;
	while(t--){
		solve();
	}
}
