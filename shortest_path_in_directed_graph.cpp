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
stack<int>s;
void topo(int node,vector<bool> &vis,vector<pair<int,int>>adj[]){
 vis[node] = true;
 for(auto it:adj[node]){
     topo(it.first,vis,adj);
 }
 s.push(node);
}
void solve(){
 ll n,m,u,v,wt,src;
 cin >> n >> m >>src;

 vector<pair<int,int>>adj[n+1];
 vector<bool>vis(n+1,false);
 vector<int>dis(n+1,INT_MAX);
 dis[src]=0;
 for(int i=0;i<m;i++){
     cin>>u>>v,wt;
     adj[u].push_back({v,wt});
 }
 for(int i=1;i<=n;i++){
     if(!vis[i]){
     topo(i,vis,adj);
     }
 }
 while(!s.empty()){
    int top=s.top();
     s.pop();
    if(dis[top]!=INT_MAX){
    for(auto it:adj[top]){
        if(dis[top]+it.second<dis[it.first]){
            dis[it.first]=dis[top]+it.second;
        }
    }
    }
 }
}
int main(){
fast_IO;
test
solve();
return 0;
}