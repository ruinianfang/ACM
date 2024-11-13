niyuan[1]=1;
for(int i=2;i<=n;i++)
    niyuan[i]=(p-(p/i))*niyuan[p%i]%p;