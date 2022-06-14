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
 vector<int>topo;
 vector<int>in_degree(n,0);
 queue<int>q;
 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     in_degree[v]++;
     
 }
 for(int i=0;i<n;i++){
     if(in_degree[i]==0){
         q.push(i);
     }
 }
 while(!q.empty()){
     int top=q.front();
     topo.push_back(top);
     q.pop();
     for(int j=0;j<adj[top].size();j++){
         in_degree[adj[top][j]]--;
         if(in_degree[adj[top][j]]==0){
             q.push(adj[top][j]);
         }

     }
 }
 for(auto it:topo){
     cout<<it<<endl;
 }

}
int main(){
fast_IO;
test
solve();
return 0;
}