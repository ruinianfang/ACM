#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=500005;
ll n,m,dfncnt,root,cnt;
vector<vector<pair<ll,ll>>> e(N);
vector<vector<ll>> ans(N);
vector<ll> dfn(N),low(N);
stack<ll> s;
void tarjan(ll u,ll in){
    low[u]=dfn[u]=++dfncnt;
    s.emplace(u);
    for(auto i:e[u]){
        if(i.second==in)continue;//判断重边
        if(dfn[i.first]==0)
            tarjan(i.first,i.second);
        low[u]=min(low[u],low[i.first]);
    }
    if(dfn[u]==low[u]){
        cnt++;
        ans[cnt].emplace_back(u);
        while(s.top()!=u){
            ans[cnt].emplace_back(s.top());
            s.pop();
        }
        s.pop();
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;
        cin>>u>>v;
        if(u!=v){
            e[u].emplace_back(v,i);
            e[v].emplace_back(u,i);
        }
    }
    for(ll i=1;i<=n;i++){
        if(dfn[i]==0){
            dfncnt=0;
            tarjan(i,0);
        }
    }
    cout<<cnt<<endl;
    for(ll i=1;i<=cnt;i++){
        cout<<ans[i].size()<<' ';
        for(ll j:ans[i])
            cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}
