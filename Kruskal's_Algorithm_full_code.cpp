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
const ll N = 1e5 + 5;
ll parent[N], sz[N];

void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v); // Forward declaration

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int find_set(int v)
{
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

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
    cout << "Sorted Edges Are: \n\n";
    print_vector(edges);
    cout << "\n\nThe Minimum Spanning Tree is: \n";

    for (int i = 1; i <= n; i++) {
        make(i);
    }

    int total_cost = 0;
    for (auto& it : edges) {
        int a = it.second.first;
        int b = it.second.second;
        int w = it.first;
        if (find_set(a) != find_set(b)) {
            total_cost += w;
            union_sets(a, b);
            cout << a << " " << b << endl;
        }
    }
    cout << "Total Cost is: " << total_cost << endl;
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
