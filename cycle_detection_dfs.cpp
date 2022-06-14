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
bool dfs_cycle(int n,int par,vector<bool> &vis,vector<int> adj[]){
    vis[n]=true;
    for(int i=0;i<adj[n].size();i++){
        if(!vis[adj[n][i]]){
            if(dfs_cycle(adj[n][i],n,vis,adj)){
                return true;
            }
        }
        else if(par!=adj[n][i]){
            return true;
        }
    }
    return false;
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
     if(dfs_cycle(i,-1,vis,adj)){
         cout<<"TRUE"<<endl;
         return ;
     }
     }
 }
 cout<<"FALSE"<<endl;
    

}
int main(){
fast_IO;
test
solve();
return 0;
}