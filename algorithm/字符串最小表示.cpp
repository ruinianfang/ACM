#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
using namespace std;
vector<ll> getnex(string s){
    ll n=s.size();
    vector<ll> nex(n+1,0);
    for(ll i=2,j=0;i<=n;i++){
        while(j&&s[i-1]!=s[j])
            j=nex[j];
        if(s[i-1]==s[j])
            j++;
        nex[i]=j;
    }
    return nex;
}
//字符串最小表示法
string getmin(string s) {
    ll n = s.size();
    string sec = s + s;
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (sec[(i + k) % n] == sec[(j + k) % n]) {
            k++;
        } else {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    i = min(i, j);
    return sec.substr(i, n);
}
void solve() {
    string s1,s2;
    cin>>s1>>s2;
    vector<ll> nex;
    nex=getnex(s2);
    s1=s1+s1;
    ll n=s1.size(),m=s2.size();
    for(ll i=1,j=0;i<=n;i++){
        while(j&&s1[i-1]!=s2[j])
            j=nex[j];
        if(s1[i-1]==s2[j])
            j++;
        if(j==m){
            cout<<"Yes"<<endl;
            string tmp= getmin(s2);
            cout<<tmp<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll t;
    t=1;
    while (t--)
        solve();
    return 0;
}