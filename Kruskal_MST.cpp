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
int findpar(int node,vector<int>& par){
    if(node==par[node]){
        return node;
    }
    return par[node]=findpar(par[node],par);
}
void node_union(int x,int y,vector<int>&par,vector<int>&rank){
  int a=findpar(x,par);
  int b=findpar(y,par);
  if(rank[a]<rank[b]){
    par[a]=b;
  }
  else if(rank[a]>rank[b]){
    par[b]=a;
  }
  else{
    par[b]=a;
    rank[a]++;
  }
}
void solve(){
 ll n,m,u,v,wt;
 cin >> n >> m ;
 vector<int>rank(n);
 vector<int>par(n);
 vector<pair<int,int>>mst;
 for(int i=0;i<n;i++){
    par[i]=i;
    rank[i]=0;
 }
 vector<vector<ll>>adj;
  for(int i=0;i<m;i++){
     cin>>u>>v>>wt;
     adj.push_back({wt,u,v});
 }
 sort(adj.begin(),adj.end());
 int total_weight=0;
 for(auto it:adj){
    if(findpar(it[1],par)!=findpar(it[2],par)){
        total_weight+=it[0];
        mst.push_back({it[1],it[2]});
       node_union(it[1],it[2],par,rank);
    }
 }
 cout<<total_weight<<endl;
 for(auto it:mst){
    cout<<it.first<<" "<<it.second<<endl;
 }

}
int main(){
fast_IO;
//test
solve();
return 0;
}