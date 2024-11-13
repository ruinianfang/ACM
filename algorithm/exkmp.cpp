#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> get_z(string s) {
    ll len=s.size();
    vector<ll> z(len);
    ll l=0,r=0;
    for(ll i=1;i<len;i++) {
        if(i<=r&&z[i-l]<r-i+1)
            z[i]=z[i-l];
        else {
            z[i]=max((ll)0,r-i+1);
            while(i+z[i]<len&&s[z[i]]==s[i+z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    string s;
    cin>>s;
    vector<ll> z;
    z=get_z(s);
    ll len=s.size();
    ll ans=0,mx=0;
    for(ll i=0;i<len;i++) {
        if(z[i]<=mx&&z[i]+i==len&&ans<z[i])
            ans=z[i];
        mx=max(mx,z[i]);
    }
    string a=s.substr(0,ans);
    cout<<a;
    if(!ans)
        cout<<"Just a legend";
    return 0;
}