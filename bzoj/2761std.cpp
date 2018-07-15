
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int T,n,f;
int size,root;
struct data{int l,r,v,rnd;}tr[50001];
void rturn(int &k){int t=tr[k].l;tr[k].l=tr[t].r;tr[t].r=k;k=t;}
void lturn(int &k){int t=tr[k].r;tr[k].r=tr[t].l;tr[t].l=k;k=t;}
void insert(int &k,int x)
{
	if(k==0){size++;k=size;tr[k].v=x;tr[k].rnd=rand();return;}
	if(tr[k].v==x){f=1;return;}
	else if(x<tr[k].v){insert(tr[k].l,x);if(tr[tr[k].l].rnd<tr[k].rnd)rturn(k);}
	else {insert(tr[k].r,x);if(tr[tr[k].r].rnd<tr[k].rnd)lturn(k);}
}
int main()
{
	freopen("2761.in", "r", stdin);
	freopen("2761.ans", "w", stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(tr,0,sizeof(tr));
		root=size=0;int x;
		scanf("%d%d",&n,&x);
        f=0;insert(root,x);
        if(!f)printf("%d",x);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&x);f=0;
			insert(root,x);
			if(!f)printf(" %d",x);
		}
		printf("\n");
	}
	return 0;
}
