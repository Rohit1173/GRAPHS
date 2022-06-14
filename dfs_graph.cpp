#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define endl '\n' 
#define setbits   __builtin_popcountll
#define msort(v)  sort((v).begin(),(v).end())
#define all(c)  (c).begin(), (c).end()
#define fill(container, value)  memset((container), (value), sizeof(container))
#define test ll t; cin >> t; while (t--)
#define fast_IO    ios_base::sync_with_stdio(false);    cin.tie(NULL);
 vector<int>dfs;
void my_dfs(int node,vector<bool> &vis,vector<int>adj[]){
    dfs.push_back(node);
    vis[node] = true;
    for(int i=0;i<adj[node].size();i++){
        if(!vis[adj[node][i]]){
            my_dfs(adj[node][i],vis,adj);
        }
    }
}
void solve(){
 ll n,m,u,v;
 cin >> n >> m ;

 vector<int>adj[n+1];
 vector<bool>vis(n,false);

 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 for(int i=1;i<=n;i++){
     if(!vis[i]){
     my_dfs(i,vis,adj);
     }
 }
    
}
int main(){
fast_IO;
test
solve();
return 0;
}