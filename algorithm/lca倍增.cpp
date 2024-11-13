#include<bits/stdc++.h>
#define ll long long
#define MXN 500005
using namespace std;
vector<ll> edge[MXN];
vector<ll> w[MXN];
ll n,m;
ll fa[MXN][31],cost[MXN][31],dep[MXN];
ll s;
void dfs(ll root,ll fno){
    fa[root][0]=fno;
    dep[root]=dep[fa[root][0]]+1;
    for(ll i=1;i<31;i++){
        fa[root][i]=fa[fa[root][i-1]][i-1];
        cost[root][i]=cost[fa[root][i-1]][i-1]+cost[root][i-1];
    }
    ll sz=edge[root].size();
    for(ll i=0;i<sz;i++){
        if(edge[root][i]==fno)continue;
        cost[edge[root][i]][0]=w[root][i];
        dfs(edge[root][i],root);
    }
}

ll lca(ll x,ll y){//返回权重，可改成返回节点
    if(dep[x]>dep[y])swap(x,y);//y要比x深
    ll tmp=dep[y]-dep[x],ans=0;
    for(ll j=0;tmp;j++,tmp>>=1)
        if(tmp&1)ans+=cost[y][j],y=fa[y][j];
    if(y==x)return ans;
    for(ll j=30;j>=0&&y!=x;j--){
        if(fa[x][j]!=fa[y][j]){
            ans+=cost[x][j]+cost[y][j];
            x=fa[x][j];
            y=fa[y][j];
        }
    }
    ans+=cost[x][0]+cost[y][0];
    return ans;
}
void init(){
    memset(fa,0,sizeof fa);
    memset(cost,0,sizeof cost);
    memset(dep,0,sizeof dep);
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        w[i].clear();
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>s;
    init();
    for(ll i=1;i<n;i++){
        ll x,y,z;
        cin>>x>>y;
        edge[x].emplace_back(y);
        edge[y].emplace_back(x);
        z=1;
        w[x].emplace_back(z);
        w[y].emplace_back(z);
    }
    dfs(s,0);
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
    return 0;
}
