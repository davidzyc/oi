#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,f,i,Min,Max,a[maxn],cnt;
double ans,b[maxn],sum[maxn],add[maxn];
bool check(double p)
{
  int i;
  for (i=1;i<=n;i++) b[i]=a[i]-p;
  for (i=1;i<=n;i++)
  {
    add[i]=add[i-1]+b[i];if (add[i]<0) add[i]=0;
    sum[i]=sum[i-1]+b[i];
  }
  for (i=1;i<=n-f+1;i++)
    if (sum[i+f-1]-sum[i-1]+add[i-1]>=0) return true;
  return false;
}
double erfen(double l,double r)
{
  double mid=(l+r)/2;
  if (r-l<=0.0001) return r;
  if (check(mid))
    return erfen(mid,r);
  return erfen(l,mid);
}
int main()
{
freopen("2018.in", "r", stdin);
freopen("2018.ans", "w", stdout);
  scanf("%d%d",&n,&f);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    Min=min(Min,a[i]);
    Max=max(Max,a[i]);
  }
  ans=erfen(Min,Max)*1000;
  printf("%d",int(ans));
  return 0;
}
