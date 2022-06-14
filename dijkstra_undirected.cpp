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
 ll n,m,u,v,wt,src;
 cin >> n >> m ;
 cin>>src ;

 vector<pair<int,int>>adj[n+1];
 vector<int>dis(n+1,INT_MAX);

 for(int i=0;i<m;i++){
     cin>>u>>v>>wt;
     adj[u].push_back({v,wt});
     adj[v].push_back({u,wt});
 }
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;// MIN HEAP
 pq.push({0,src});
 dis[src]=0;
 while(!pq.empty()){
     int d=pq.top().first;
     int node=pq.top().second;
     pq.pop();
     for(auto it:adj[node]){
         if(dis[node]+it.second<dis[it.first]){
             dis[it.first]=dis[node]+it.second;
             pq.push({dis[it.first], it.first});
         }
     }

 }
 for(int i=0; i<n;i++){
     cout<<dis[i]<<endl;
 }
}
int main(){
fast_IO;
//test
solve();
return 0;
}