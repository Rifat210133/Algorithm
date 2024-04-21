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

ll n, m;
ll cost_parent[100005];
ll parent[100005];
vector<ll> value(100005, INT_MAX);

void print_path(ll node)
{
    if (node == -1) {
        return;
    }
    print_path(parent[node]);
    cout << node << " ";
}

void bell_man_ford(vector<pair<ll, pair<ll, ll>>>& edges)
{
    parent[0] = -1;
    value[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto it : edges) {
            ll a = it.second.first;
            ll b = it.second.second;
            ll w = it.first;
            if (value[a] + w < value[b]) {
                value[b] = value[a] + w;
                parent[b] = a;
            }
        }
    }
    for (auto it : edges) {
        ll a = it.second.first;
        ll b = it.second.second;
        ll w = it.first;
        if (value[a] + w < value[b]) {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Node: " << i << " Cost: " << value[i] << " Path: ";
        print_path(i);
        cout << endl;
    }
}

void Solve()
{
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[i] = { w, { a, b } };
    }

    bell_man_ford(edges);
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
