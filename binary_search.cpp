//binary search

#include<iostream>
using namespace std;

int binary_search(int arr[], int low, int high, int target){
	if(low>high){
		return -1;
	}
	int mid=(low+high)/2;
	if (target==arr[mid]){
		return mid;
	}
	else if(arr[mid]>target){
		return binary_search(arr, low, mid-1,target);
	}
	else{
		return binary_search(arr,mid+1, high,target);
	}
}

void solve(){
	int n;
	cin>>n;
	int arr[n],freq[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		freq[arr[i]]=i+1;
	}
	int target;
	cin>>target;
	cout<<binary_search(arr,0, n-1, target);
}


int main(){
	int t=1;
	while(t--){
		solve();
	}
}
