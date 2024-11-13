#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=3e5+5;
vector<ll> g[N],tin(N),tout(N),id(N),par(N);
ll T=0;
void dfs(ll u,ll p){
    id[u]=tin[u]=tout[u]=T++;
    for(auto i:g[u]){
        if(i!=p){
            dfs(i,u);
            par[i]=u;
            tout[u]=tout[i];
        }
    }
}
vector<ll> p(N);
ll ok(ll i){
    if(p[i]==1){
        if(i==1)
            return 1;
        return 0;
    }
    ll ant=p[i-1];
    if(par[p[i]]==ant)  return 1;//前一个是父节点
    if(tin[ant]!=tout[ant])return 0;
    ll pa=par[p[i]];
    if(tin[ant]<tin[pa]||tin[ant]>tout[pa])return 0;
    return 1;//是兄弟节点的叶子节点
}
void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<=n;i++)
        g[i].clear();
    T=0;
    for(ll i=2;i<=n;i++){
        ll fa;
        cin>>fa;
        g[fa].emplace_back(i);
    }
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }
    dfs(1,0);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        cnt+=ok(i);
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        set<ll> in;
        in.insert(x),in.insert(y);//会对前后自己三个节点产生影响。
        if(x-1>=1) in.insert(x-1);
        if(x+1<=n) in.insert(x+1);
        if(y-1>=1) in.insert(y-1);
        if(y+1<=n) in.insert(y+1);
        for(auto i:in)
            cnt-=ok(i);
        swap(p[x],p[y]);
        for(auto i:in)
            cnt+=ok(i);
        cout<<(cnt==n?"YES":"NO")<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
