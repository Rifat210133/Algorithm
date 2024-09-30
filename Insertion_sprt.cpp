

//insertion sort

#include <iostream>
#include<vector>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0; i<n; i++){
      cin>>a[i];
     
  }
  for(int i=1; i<n; i++){
      int key=a[i], j=i-1;
      while(j>-1 and a[j]>key){
          a[j+1]=a[j];
          j--;
      }
      a[j+1]=key;
      
  }
  for(int i=0; i<n; i++){
      cout<<a[i]<<" ";
  }
  cout<<endl;
}

int main() {
    int t=1;
    while(t--){
        solve();
    }
}
