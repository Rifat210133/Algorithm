#include<bits/stdc++.h>
using namespace std;



void rifat(){

    //take input the size of vector
    int n;
    cin >> n;
    vector<int>a(n);
    //take input a vector
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        int key=a[i];
        int j=i-1;
        while(j>-1 and a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;

    }
    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}


int main(){
    int t=1;
    while(t--){
        rifat();
    }
}