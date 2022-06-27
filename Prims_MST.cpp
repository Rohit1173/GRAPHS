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
 ll n,m,u,v,wt;
 cin >> n >> m ;

 vector<int>key(n,INT_MAX);
 vector<bool>mst(n,false);
 vector<int>parent(n,-1);
 vector<pair<int,int>>adj[n+1];
 
 for(int i=0;i<m;i++){
     cin>>u>>v>>wt;
     adj[u].push_back({v,wt});
     adj[v].push_back({u,wt});
 }
 
 priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; //MIN HEAP
 pq.push({0,0});
 key[0]=0;
 while(!pq.empty()){
    int index=pq.top().second;
    pq.pop();
   mst[index]=true;
   for(auto it:adj[index]){
      if(!mst[it.first]&&key[it.first]>it.second){
        key[it.first]=it.second;
        pq.push({key[it.first],it.second});
        parent[it.first]=index;
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
