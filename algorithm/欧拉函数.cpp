#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
//求特定数欧拉
ll euler_phi(ll n) {
    ll ans = n;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

//线性求欧拉
const ll N=40005;
vector<ll> pri;
bool not_prime[N];
ll phi[N];
void pre(ll n) {
    phi[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            pri.emplace_back(i);
            phi[i] = i - 1;
        }
        for (ll pri_j : pri) {
            if (i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0) {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n;
    cin>>n;
    pre(n);
    ll ans=3;
    for(ll i=2;i<=n-1;i++)
        ans+=phi[i]*2;
    if(n==1)
        cout<<0;
    else
        cout<<ans;
    return 0;
}
