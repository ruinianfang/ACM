#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5050, M = 2e5 + 10;//节点数和边数

struct E {//边的信息
    ll v, w, x;//v节点w权重x下一条边
} e[M * 2];//存边

ll n, m, h[N], cnte;//cnte第几条边，h节点的边的头指针

void adde(ll u, ll v, ll w) { e[++cnte] = E{v, w, h[u]}, h[u] = cnte; }//向图中添加边，更新头指针
//S存节点和距离

class cmp{
public:
    bool operator()(pair<ll,ll> a,pair<ll,ll> b){
        return a.second>b.second;
    }
};//小顶堆

priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> q;//1是点，2是dis
ll dis[N];//存从源点到节点i的最短距离，初始化源点0,其余无穷大
bool vis[N];//标记顶点i是否被访问，被加入设为true

ll res = 0, cnt = 0;//res总权重，cnt顶点数

void Prim() {
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.emplace(1,0);
    while (!q.empty()) {
        if (cnt >= n) break;
        ll u = q.top().first, d = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ++cnt;
        res += d;
        for (ll i = h[u]; i; i = e[i].x) {
            ll v = e[i].v, w = e[i].w;
            if (w < dis[v]) {
                dis[v] = w, q.emplace(v, w);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        adde(u,v,w);
        adde(v,u,w);
    }
    Prim();
    if(cnt==n)
        cout<<res;
    else
        cout<<"orz";
    return 0;
}
