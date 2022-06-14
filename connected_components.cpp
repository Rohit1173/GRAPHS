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
ll vis[100001];
vector<ll>v[100001];
void dfs(ll node){
     vis[node]=1;
     for(ll i=0;i<v[node].size();i++){
         if(!vis[v[node][i]]){
             dfs(v[node][i]);
         }
     }
}
void solve(){
    ll n, q,a,b;
    cin >> n >> q;
    for (ll i = 0; i < q; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); 

    }
    ll cnt=0;
    for(ll i = 1; i <= n; i++){
       if(!vis[i]){  
           dfs(i);
           cnt++;
       }

    }
    cout<<cnt<<endl;
}
int main(){
fast_IO;
//test
solve();
return 0;
}