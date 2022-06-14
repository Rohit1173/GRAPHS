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
 ll n,m,u,v,src;
 cin >> n >> m ;
 cin>>src ;

 vector<int>adj[n+1];
 vector<int>dis(n+1,INT_MAX);

 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 queue<int>q;
 q.push(src);
 dis[src]=0;
 while(!q.empty()){
     int top=q.front();
     q.pop();
     for(auto it:adj[top]){
         if(dis[top]+1<dis[it]){
             dis[it]=dis[top]+1;
             q.push(it);
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