#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn for (ll i = 0; i < n; ++i)
#define forne for (ll i = n - 1; i >= 0; --i)
#define MOD 1000000007
#define umap unordered_map
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define vc vector
#define lw lower_bound
#define up upper_bound
#define ump unordered_map
#define max2(a,b) ((a<b)?b:a)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b) ((a>b)?b:a)
#define min3(a,b,c) min2(min2(a,b),c)
#define llr rdll()
#define ir rdi()
ll rdll();
int rdi();

/*int f(pair<int, int> a, pair<int, int> b)
{
    if (a.ff != b.ff)
        return a.ff > b.ff;
    return a.ss < b.ss;
}*/

int crossingsum(vc<int>&a, int m, int l, int h){
    //first of all assign leftsum and rightsum value INT_MIN and take a sum veriable 0;
    int left_sum=INT_MIN;
    int right_sum = INT_MIN;
    int sum=0;
    for(int i =m; i>=l; i--){
        sum+=a[i];
        left_sum=max(left_sum, sum);
    }//comppute left portion from middle;
    sum=0;
    for(int i =m; i>=h; i++){
        sum+=a[i];
        right_sum = max(right_sum, sum);
    }//compute right portion from middle
    return max(left_sum+right_sum-a[m],max(left_sum, right_sum));
    // return max value between left+right, left, and right portion

}

int maxsubarr(vc<int>&a, int l, int h){
    //if input exist this condition is always false cause l is always smaller than r
    if(l>h){
        return 0;
    }
    //if the length of the array is 1 then this condition is true
    else if(l==h){
        return a[l];
    }
    int m=(l+h)/2;//find the mid of current  left index and right index;
    return max(max(maxsubarr(a, l, m-1), maxsubarr(a, m+1, h)), crossingsum(a, m, l, h));
    // returtn max sum left, right and middle portion. for middle portion we call
    //crossingsum fuction 
}


void solve()
{

    int n;
    cin >> n;
    vc<int>a(n);
    for(int i =0; i<n; i++){
        cin >> a[i];
    }
    //take input and call the function maxsubarr
    cout<<maxsubarr(a, 0, n-1)<<endl;


    
}

int main()
{
    //freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
ll rdll()
{
    ll x;
    cin >> x;
    return x;
}
int rdi()
{
    int x;
    cin >> x;
    return x;
}
