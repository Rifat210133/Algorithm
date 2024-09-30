//bfs

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N=1e5+5;
vector<int>g[N];
int vis[N];
int level[N];
int parent[N];

void bfs(int source){
	queue<int>q;
	q.push(source);
	vis[source]=1;
	parent[source]=-1;
	while(!q.empty()){
		int cur_v = q.front();
		q.pop();
		cout<<"Current Node: "<<cur_v<<" level: "<<level[cur_v]<<endl;
		for(int child: g[cur_v]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				level[child]=level[cur_v]+1;
				parent[child]=cur_v;
			}
		}
	}
}

void path_print(int node){
		if(parent[node]==-1){
			cout<<node<<" ";
			return;
		}
		path_print(parent[node]);
			cout<<node<<" ";
		
}
			
		
	

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	bfs(0);
	for(int i=1; i<=n; i++){
		cout<<" shortest path of "<< i<<" is ";
		path_print(i);
		cout<<endl;
		}
}



int main(){
	int t=1;
	while(t--){
		solve();
	}
}
