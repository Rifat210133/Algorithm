/*fibonacci usinf dp

#include<iostream>
using namespace std;

int fibonacci(int n){
	if(n<=1){
		return n;
	}
	
	return fibonacci(n-1)+fibonacci(n-2);
}

void solve(){
	int n;
	cin>>n;
	int result =fibonacci(n);
	cout<<result<<endl;
}


int main(){
	int t=1;
	while(t--){
		solve();
	}
}*/

/*#include<iostream>
#include<vector>

using namespace std;

int fibo(int n){
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}
	
	
	



int main(){
	int n;
	cin>>n;
	int result =fibo(n);
	cout<<result<<endl;
}*/

#include<iostream>
#include<vector>
using namespace std;

int fibodp(int n, vector<int>&memo){
	if(n<=1){
		return n;
	}
	
	if(memo[n] != -1){
		return memo[n];
	}
	memo[n]=fibodp(n-1, memo)+fibodp(n-2, memo);
	return memo[n];
}

int fibo(int n){
	vector<int>memo(n+1, -1);
	return fibodp(n, memo);
}

void solve(){
	int n;
	cin>>n;
	int result =fibo(n);
	cout<<result<<endl;
}

int main(){
	int t=1;
	while(t--){
		solve();
	}
}
	
	
