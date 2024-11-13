#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=1e5+5;
ll n,m,dfncnt;
vector<vector<ll>> e;
vector<ll> low,dfn,f;
ll ans;
void init(ll x){
    ans=x*(x-1)/2;
    low.assign(x+1,0),dfn.assign(x+1,0),f.assign(x+1,0);
    e.assign(x+1,vector<ll>(0));
    dfncnt=0;
}
void tarjan(ll u,ll fa){
    f[u]=fa;
    low[u]=dfn[u]=++dfncnt;
    for(auto i:e[u]){
        if(i==fa)continue;
        if(dfn[i]!=0){
            low[u]=min(low[u],dfn[i]);
            continue;
        }
        tarjan(i,u);
        ll num=dfncnt-dfn[i]+1;
        low[u]=min(low[u],low[i]);
        if(low[i]>dfn[u])
            ans=min(ans,num*(num-1)/2+(n-num)*(n-num-1)/2);
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        init(n);
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            e[u].emplace_back(v),e[v].emplace_back(u);
        }
        tarjan(1,0);
        cout<<ans<<endl;
    }
    return 0;
}