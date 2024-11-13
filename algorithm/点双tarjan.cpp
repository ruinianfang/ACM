#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=500005;
ll n,m,dfncnt,root,cnt;
vector<vector<ll>> e(N),dcc(N);
vector<ll> dfn(N),low(N);
vector<bool> cut(N);
stack<ll> s;
void tarjan(ll u){
    dfn[u]=low[u]=++dfncnt;
    s.emplace(u);
    if(u==root&&e[u].empty()){
        dcc[++cnt].emplace_back(u);
        return;
    }
    ll f=0;
    for(ll i:e[u]){
        if(!dfn[i]){
            tarjan(i);
            low[u]=min(low[u],low[i]);
            if(low[i]>=dfn[u]){//关键
                if(++f>1||u!=root)cut[u]=true;
                cnt++;
                ll tmp;
                do {
                    dcc[cnt].emplace_back(s.top());
                    tmp=s.top();
                    s.pop();
                }
                while(tmp!=i);
                dcc[cnt].emplace_back(u);
            }
        }
        else{
            low[u]=min(low[u],dfn[i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        if(u!=v){//自环
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
    }
    for(ll i=1;i<=n;i++){
        if(dfn[i]==0){
            root=i;
            tarjan(i);
        }
    }
    cout<<cnt<<endl;
    for(ll i=1;i<=cnt;i++){
        cout<<dcc[i].size()<<' ';
        for(ll j:dcc[i])
            cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}
