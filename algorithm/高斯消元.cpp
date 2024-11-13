#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n;
    cin>>n;
    vector<vector<double>> fc(n+1,vector<double>(n+2));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n+1;j++)
            cin>>fc[i][j];
    }
    vector<double> ans(n+1);
    for(ll i=1;i<=n;i++){
        ll r=i;
        for(ll j=i+1;j<=n;j++){
            if(llabs(fc[r][i])<llabs(fc[j][i]))
                r=j;
        }
        if(llabs(fc[r][i]==0)){
            cout<<"No Solution";
            return 0;
        }
        if(i!=r)
            swap(fc[i],fc[r]);
        double div=fc[i][i];
        for(ll j=i;j<=n+1;j++)
            fc[i][j]/=div;
        for(ll j=i+1;j<=n;j++){
            div=fc[j][i];
            for(ll k=i;k<=n+1;k++)
                fc[j][k]-=fc[i][k]*div;
        }
    }
    ans[n]=fc[n][n+1];
    for(ll i=n-1;i>0;i--){
        ans[i]=fc[i][n+1];
        for(ll j=i+1;j<=n;j++)
            ans[i]-=fc[i][j]*ans[j];
    }
    for(ll i=1;i<=n;i++){
        cout<<fixed<<setprecision(2)<<ans[i]<<endl;
    }
    return 0;
}
