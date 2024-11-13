#include<bits/stdc++.h>//最短路加分层图
#define ll long long
#define maxn 2005
using namespace std;
struct cmp {
public:
    bool operator()(pair<ll,ll> a,pair<ll,ll> b){//f是dis s是节点
        return a.first>b.first;
    }
};
vector<pair<ll,ll>> e[maxn];//f是目的地，s是权重
vector<ll> dis(maxn),vis(maxn);
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, cmp> q;
void dijkstra(ll n, ll s) {//s出发，n目的
    dis.assign(maxn,10000000000000005);
    dis[s] = 0;
    q.emplace(0, s);
    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
            ll v = ed.first, w = ed.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(dis[v], v);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll d;
            cin>>d;
            e[i].emplace_back(j,d);
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            e[i+n].emplace_back(j+n,e[i][j-1].second*b+c);
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<n;j++)
            e[i][j].second*=a;
        e[i].emplace_back(i+n,0);
    }
    dijkstra(2*n,1);
    cout<<dis[2*n];
    return 0;
}
