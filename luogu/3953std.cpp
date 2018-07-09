#include<deque>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register int
#define fp(i,a,b) for(re i=a,I=b;i<=I;++i)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
char ss[1<<17],*A=ss,*B=ss;
inline char gc(){return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?-1:*A++;}
template<class T>inline void sdf(T&x){
    char c;T y=1;while(c=gc(),(c<48||57<c)&&c!=-1)if(c=='-')y=-1;x=c^48;
    while(c=gc(),47<c&&c<58)x=(x<<1)+(x<<3)+(c^48);x*=y;
}
using namespace std;
const int N=1e5+5,M=2e5+5;
typedef int arr[N];
struct eg{int nx,to,w;}e[M<<1],E[M];
int T,n,m,K,P,ce=1,Ce,ans,*dis,f[N][55];arr dis1,disn,fi1,fin,vis,in,q,Fi,id,da;
namespace seg{
    int tr[N<<2],sgt;
    inline void Set(re n){sgt=1;while(sgt<=n)sgt<<=1;--sgt;tr[0]=N-1;}
    inline void clr(){fp(i,1,(sgt<<1)+1)tr[i]=0;}
    inline int cmp(const re&a,const re&b){return dis[a]<dis[b]?a:b;}
    inline void mdy(re x,re w){for(re i=x+sgt;dis[tr[i]]>w;i>>=1)tr[i]=x;dis[x]=w;}
    inline void del(re x){tr[x+=sgt]=0;x>>=1;while(x)tr[x]=cmp(tr[x<<1],tr[x<<1|1]),x>>=1;}
}
using namespace seg;
void dij(re s,re*Dis,re*fi){
    dis=Dis;memset(dis,9,4*(n+1));clr();mdy(s,0);
    fp(T,1,n){
        re u=tr[1];del(u);
        for(re i=fi[u],v;i;i=e[i].nx)
            if(dis[v=e[i].to]>dis[u]+e[i].w)
                mdy(v,dis[u]+e[i].w);
    }
}
inline void add(re u,re v,re w,re*fi){e[++ce]=(eg){fi[u],v,w};fi[u]=ce;}
inline void ADD(re u,re v){E[++Ce]=(eg){Fi[u],v,0};Fi[u]=Ce;}
inline bool comp(const re&a,const re&b){return dis1[a]==dis1[b]?id[a]<id[b]:dis1[a]<dis1[b];}
bool topsort(){
    re h=1,t=0;
    fp(i,1,n)if(!in[i])q[++t]=i;
    while(h<=t){
        re u=q[h++];
        for(re i=Fi[u],v;i;i=E[i].nx)
            if(!--in[v=E[i].to])q[++t]=v;
    }
    fp(i,1,n)id[q[i]]=i;
    fp(i,1,n)if(in[i]&&dis1[i]+disn[i]<=K+dis1[n])return 1;
    return 0;
}
inline void mod(re&a){a>=P?a-=P:0;}
int main(){
    #ifndef ONLINE_JUDGE
        file("park");
    #endif
    sdf(T);
    while(T--){
        memset(fi1,0,sizeof fi1);memset(fin,0,sizeof fin);
        memset(Fi,0,sizeof Fi);ce=Ce=ans=0;
        sdf(n);sdf(m);sdf(K);sdf(P);re u,v,w;Set(n);
        while(m--){
            sdf(u),sdf(v),sdf(w),add(u,v,w,fi1),add(v,u,w,fin);
            if(!w)ADD(u,v),++in[v];
        }
        dij(1,dis1,fi1);dij(n,disn,fin);;
        if(topsort()){puts("-1");continue;}
        memset(f,0,sizeof f);f[1][0]=1;
        fp(i,1,n)da[i]=i;sort(da+1,da+n+1,comp);
        fp(k,0,K)fp(p,1,n)
            for(re u=da[p],d=dis1[u],i=fi1[u];i;i=e[i].nx)
                if(e[i].w-dis1[e[i].to]+d+k<=K)
                    mod(f[e[i].to][e[i].w-dis1[e[i].to]+d+k]+=f[u][k]);
        fp(k,0,K)mod(ans+=f[n][k]);
        printf("%d\n",ans);
    }
return 0;
}
