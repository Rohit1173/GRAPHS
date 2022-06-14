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
 cin >> n>> m; //n->no.of nodes & m->no.of edges
 ll adj[n+1][n+1];

 for(ll i=0; i<m; i++){
      cin>>u>>v;
      adj[u][v]=1;
      adj[v][u]=1;
 }

}
int main(){
fast_IO;
test
solve();
return 0;
}