#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(vector<ll> n) {
    if(n.size()==1&&n[0]==1)
        return false;
    return true;
}
vector<ll> mul(vector<ll> &a,ll b) {
    vector<ll> c;
    for(ll i=0,t=0;i<a.size()||t;i++) {
        if(i<a.size())
            t+=a[i]*b;
        c.emplace_back(t%(ll)(1e16));
        t/=1e16;
    }
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}
vector<ll> div(vector<ll> &a,ll b) {
    vector<ll> c;
    ll r=0;
    for(ll i=a.size()-1;i>=0;i--) {
        r=r*1e16+a[i];
        c.emplace_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}
vector<ll> add(vector<ll> &a,ll b) {
    vector<ll> c;
    a[0]+=b;
    for(ll i=0,t=0;i<a.size()||t;i++) {
        t+=a[i];
        c.emplace_back(t%(ll)1e16);
        t/=1e16;
    }
    while(c.size()>1&&c.back()==0)
        c.pop_back();
    return c;
}
void show(vector<ll> &a) {
    cout<<a.back();
    for(ll i=a.size()-2;i>=0;i--)
        cout<<setw(16)<<setfill('0')<<a[i];
    cout<<endl;
}
vector<ll> max(vector<ll> &a,vector<ll> &b) {
    if(a.size()>b.size())
        return a;
    if(a.size()<b.size())
        return b;
    for(ll i=a.size()-1;i>=0;i--) {
        if(a[i]>b[i])
            return a;
        if(a[i]<b[i])
            return b;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    string s;
    cin>>s;
    vector<ll> n;
    for(ll i=s.size()-1;i>=0;i-=16) {
        ll st=max((ll)0,i-16+1),len=i-st+1;
        n.emplace_back(stoi(s.substr(st,len)));
    }
    ll cnt=0;
    while(check(n)) {
        if(n[0]%2==0)
            n=div(n,2);
        else {
            n=mul(n,3);
            n=add(n,1);
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}