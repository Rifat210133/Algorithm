#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long MOD = 1000000007;
#define sz(x) (ll)(x).size()
#define rd ({ll x; cin >> x; x; })
#define dbg(x) cerr << (#x) << " = " << (x) << endl
// #define cerr if(0)cerr
#define xx first
#define yy second

void Solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n), brr(n);
    vector<pair<ll, ll>>v;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i =0; i<n; i++){
        cin >> brr[i];
        v.push_back({brr[i], arr[i]});
    }
    sort(v.begin(), v.end());
    ll ans = 1;
    ll k = v[0].xx, d = v[0].xx;
    for(auto it = v.begin()+1; it!=v.end(); it++){
        if(it->yy > k){
            ans++;
            k = max(k, it->xx);
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
// Coded by Md. Rifat Al Hasan (@Mr.Hacker.)