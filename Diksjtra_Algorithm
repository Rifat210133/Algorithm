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

vector<pair<int, int>> v[10000];
vector<int> w(1000, INT_MAX);
int vist[10000];
int parent[10000];
void print(int i)
{
    if (i == 0)
        return;
    cout << " ";
    cout << parent[i];
    print(parent[i]);
}
void dijkstra(int s)
{
    set<pair<int, int>> st;
    st.insert({ 0, s });
    w[s] = 0;
    while (st.size() > 0) {
        pair<int, int> p = *st.begin();
        int wt = p.first;
        int node = p.second;
        st.erase(st.begin());
        if (vist[node] == 1) {
            continue;
        }
        for (auto child : v[node]) {
            if (w[child.first] > w[node] + child.second) {
                w[child.first] = w[node] + child.second;
                st.insert({ w[child.first], child.first });
                parent[child.first] = node;
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        v[x].push_back({ y, w });
        v[y].push_back({ x, w });
    }
    dijkstra(0);
    for (int i = 0; i < node; i++) {
        cout << "node = " << i << endl;
        cout << "cost = " << w[i] << endl;
        cout << i;
        print(i);
        cout << endl
             << endl;
        ;
    }
}
