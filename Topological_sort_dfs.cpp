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
void topo_sort(int n, vector<bool> &vis,vector<int>adj[]){
   vis[n]=1;
   for(int i=0; i<adj[n].size(); i++){
       if(!vis[adj[n][i]]){
           topo_sort(adj[n][i],vis,adj);
       }
   }
   s.push(n);
}
void solve(){
 ll n,m,u,v;
 cin >> n >> m ;

 vector<int>adj[n+1];
 vector<bool>vis(n,false);

 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
 }
 for(int i=1;i<=n;i++){
     if(!vis[i]){
     topo_sort(i,vis,adj);
     }
 }
 while(!s.empty()){
     cout<<s.top()<<endl;
     s.pop();
 }
}
int main(){
fast_IO;
test
solve();
return 0;
}