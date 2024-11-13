#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=20004;
ll n,m,dfncnt;
vector<vector<ll>> e(N);
vector<ll> dfn(N),low(N),vis(N),pt(N),flag(N);
ll res=0;
void tarjan(ll u,ll fa){
    vis[u]=1;
    low[u]=dfn[u]=++dfncnt;
    ll cld=0;
    for(auto i:e[u]){
        if(!vis[i]){
            cld++;
            tarjan(i,u);
            low[u]=min(low[u],low[i]);
            if(fa!=u&&low[i]>=dfn[u]&&!flag[u]){
                flag[u]=1;
                res++;
            }
        }
        else if(fa!=i)
            low[u]=min(low[u],dfn[i]);
    }
    if(fa==u&&cld>=2&&!flag[u]){
        flag[u]=1;
        res++;
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    for(ll i=1;i<=n;i++) {
        if (!vis[i]) {
            dfncnt = 0;
            tarjan(i, i);
        }
    }
    cout<<res<<endl;
    for(ll i=1;i<=n;i++)
        if(flag[i]!=0)
            cout<<i<<' ';
    return 0;
}
