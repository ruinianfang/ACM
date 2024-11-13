#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<int> G[105];//图
int in[105];  // 存储每个结点的入度
bool toposort() {
    vector<int> L;
    queue<int> S;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) S.push(i);
    while (!S.empty()) {//bfs
        int u = S.front();
        S.pop();
        L.push_back(u);
        for (auto v : G[u]) {
            if (--in[v] == 0) {
                S.push(v);
            }
        }
    }
    if (L.size() == n) {
        for (auto i : L) cout << i << ' ';
        return true;
    } else {
        return false;//有环
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(ll i=1;i<=n;i++){
        while(true){
            ll x;
            cin>>x;
            if(x==0)
                break;
            G[i].emplace_back(x);
            in[x]++;
        }
    }
    toposort();
    return 0;
}
