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
void solve(){
 ll n,m,u,v;
 cin >> n >> m ;
 vector<int>adj[n+1];
 vector<bool>vis(n+1,false);
   vector<int>bfs;
 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 for(int i=1;i<=n;i++){
     if(!vis[i]){
         vis[i] = true;
         queue<int>q;
         q.push(i);
         while(!q.empty()){
             int top=q.front();
             q.pop();
             bfs.push_back(top);
             for(int j=0;j<adj[top].size();j++){
                 if(!vis[adj[top][j]]){
                     q.push(adj[top][j]);
                     vis[adj[top][j]]=true;
                 }
             }
         }
     }
 }
 for(int i=0;i<bfs.size();i++){
     cout<<bfs[i]<<" "<<endl;
 }
 

}
int main(){
fast_IO;
test
solve();
return 0;
}