const ll N=10005;
vector<ll> dfn(N),low(N),vis(N),pt(N);
ll dfncnt,sc,n,m;
stack<ll> s;
vector<vector<ll>> e(N),scc(N);
void tarjan(ll u){
    low[u]=dfn[u]=++dfncnt;
    s.emplace(u),vis[u]=1;
    for(auto i:e[u]){
        if(dfn[i]==0){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(vis[i])low[u]=min(low[u],low[i]);
    }
    if(dfn[u]==low[u]){
        sc++;
        while(s.top()!=u){
            scc[sc].emplace_back(s.top());
            vis[s.top()]=0;
            s.pop();
        }
        scc[sc].emplace_back(s.top());
        vis[s.top()]=0;
        s.pop();
    }
}
