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
bool dfs(int n,vector<int>&col,vector<int>adj[]){
            if(col[n]==-1){
                col[n]=1;
            }
            for(int i=0;i<adj[n].size();i++){
                if(col[adj[n][i]]==-1){
                    col[adj[n][i]]=1+col[n];
                   if(!dfs(adj[n][i],col,adj)){
                       return false;
                   }
                }
                else if(col[adj[n][i]]==col[n]){
                    return false;
                }
            }
            return true;
}
void solve(){
 ll n,m,u,v;
 cin >> n >> m ;

 vector<int>adj[n+1];
 vector<int>col(n,-1);

 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 for(int i=0;i<n;i++){
       if(col[i]==-1){
           if(!dfs(i,col,adj)){
               cout<<"FALSE"<<endl;
               return;
           }          
       }
 }
 cout<<"YES"<<endl;
}
int main(){
fast_IO;
test
solve();
return 0;
}