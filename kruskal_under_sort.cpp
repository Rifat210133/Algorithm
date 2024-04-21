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

bool Comparator(pair<ll, pair<ll, ll>>& a, pair<ll, pair<ll, ll>>& b)
{
    if (a.first == b.first) {
        if (a.second.first == b.second.first) {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

void print_vector(vector<pair<ll, pair<ll, ll>>>& edges)
{
    for (auto it : edges) {
        cout << "weight " << it.first << " edge: " << it.second.first << " " << it.second.second << endl;
    }
}

void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[i] = { w, { a, b } };
    }
    sort(edges.begin(), edges.end(), Comparator);
    print_vector(edges);
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}
// Coded by Md. Rifat Al Hasan (@Mr.Hacker.)
