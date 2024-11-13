#include<bits/stdc++.h>
using namespace std;
int n[1000005],c=1;
void minheap(int x){
    int l=x*2;
    int r=x*2+1;
    int lag;
    if(n[l]<n[x]&&l<c)
        lag=l;
    else
        lag=x;
    if(n[r]<n[lag]&&r<c)
        lag=r;
    if(lag!=x) {
        swap(n[x], n[lag]);
        minheap(lag);
    }
}
void buildminheap(int x){
    x=x/2;
    while(x>=1){
        minheap(x);
        x=x/2;
    }
}
void del(int x){
    swap(n[x],n[c-1]);
    n[c-1]=0;
    c--;
    minheap(x);
}
int main(){
    int num;
    cin>>num;
    while(num-->0){
        int a;
        cin>>a;
        if(a==1){
            scanf("%d",&n[c++]);
            buildminheap(c-1);
        }
        if(a==2)
            cout<<n[1]<<endl;
        if(a==3){
            del(1);
        }
    }
    return 0;
}