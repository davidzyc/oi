#include <cstdio>
#define N 100010
using namespace std;
int inline read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void swap(int &x,int &y){int t=x;x=y,y=t;}
int ch[N][2],val[N],dis[N],f[N],n,m;
int merge(int x,int y)
{
    if (x==0 || y==0)
        return x+y;
    if (val[x]>val[y] || (val[x]==val[y] && x>y))
        swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    f[ch[x][1]]=x;
    if (dis[ch[x][0]]<dis[ch[x][1]])
        swap(ch[x][0],ch[x][1]);
    dis[x]=dis[ch[x][1]]+1;
    return x;
}
int getf(int x)
{
    while(f[x]) x=f[x];
    return x;
}
void pop(int x)
{
    val[x]=-1;
    f[ch[x][0]]=f[ch[x][1]]=0;
    merge(ch[x][0],ch[x][1]);
}
main()
{
    n=read(),m=read();
    dis[0]=-1;
    for (int i=1;i<=n;i++)
        val[i]=read();
    for (int i=1;i<=m;i++)
    {
        int com=read();
        if (com==1)
        {
            int x=read(),y=read();
            if (val[x]==-1 || val[y]==-1)
                continue;
            if (x==y)
                continue;
            int fx=getf(x),fy=getf(y);
            merge(fx,fy);
        }
        else
        {
            int x=read();
            if (val[x]==-1)
                puts("-1");
            else
            {
                int y=getf(x);
                printf("%d\n",val[y]);
                pop(y);
            }
        }
    }
}
