#include<bits/stdc++.h>//用差分可以做区间和
#define ll long long
using namespace std;
ll n,w;
ll c[1000006];
ll lowbit(ll x) {//最后1和后面的0组成的数
    return x & -x;
}
ll getsum(ll x) {  // a[1]..a[x]的和
    ll ans = 0;
    while (x > 0) {
        ans = ans + c[x];
        x = x - lowbit(x);
    }
    return ans;
}
void add(ll x, ll k) {
    while (x <= n) {  // 不能越界
        c[x] = c[x] + k;
        x = x + lowbit(x);
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>w;
    while(w--){
        char op;
        ll a,b;
        cin>>op>>a>>b;
        if(op=='x')
            add(a,b);
        else
            cout<<getsum(b)-getsum(a-1)<<'\n';
    }
    return 0;
}
