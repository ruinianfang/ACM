ll gcd1;
void exgcd(long long a,long long b,long long & x,long long & y){
    if(!b){
        gcd1=a;
        x=1,y=0;
    }
    else{
        exgcd(b,a%b,y,x);
        y-=a/b*x;
    }
}