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
int parent[100000];
int node_rank[100000];
void makeset(int n){
for(int i=0;i<n;i++){
    parent[i] =i;
    node_rank[i]=0;
 }
}
int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]); // added parent[node] for path compression
}
void node_union(int x,int y){
    int a=findpar(x);
    int b=findpar(y);
    if(node_rank[a]==node_rank[b]){
        parent[b]=a;
        node_rank[a]++;
    }
    else if(node_rank[a]<node_rank[b]){
        parent[a]=b;
    }
    else{
        parent[b]=a;
    }

}
void solve(){
  makeset(2);
  ll u,v;
  cin >> u >> v;
  if(findpar(2)!=findpar(3)){
    cout<<"DIFF COMPONENTS"<<endl;
  }
  else{
    cout<<"SAME COMPONENT"<<endl;
  }
}
int main(){
fast_IO;
test
solve();
return 0;
}