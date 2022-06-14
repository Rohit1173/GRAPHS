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
bool cycle(int n,vector<bool>&vis,vector<bool>&rec_vis,vector<int>adj[]){
    vis[n] = true;
   for(int i=0;i<adj[n].size();i++){
        if(!vis[adj[n][i]]){
            if(cycle(adj[n][i],vis,rec_vis,adj)){
                return true;
            }
        }
         else if(rec_vis[adj[n][i]]){
            return true;
        }   
   }
   rec_vis[n]=0;
   return false;
}
void solve(){
  ll n,m,u,v;
 cin >> n >> m ;

 vector<int>adj[n+1];
 vector<bool>vis(n,false);
 vector<bool>rec_vis(n,false);

  for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
 }
 for(int i=0;i<n;i++){
     if(!vis[i]){
         if(cycle(i,vis,rec_vis,adj)){
             cout<<"TRUE"<<endl;
         }
         else{
             cout<<"FALSE"<<endl;
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