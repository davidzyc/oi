
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<11)+10;
int n,m;
LL temp[MAX],dp[MAX],bin[15];
bool mark[MAX];

bool check(int i){
	while(i){
		if(i&1){
			i>>=1;
			if(!(i&1))return false;//第j列是1则第j+1列必须是1
			i>>=1;//继续判断下一列
		}else i>>=1;//继续判断下一列
	}
	return true;
}

void Init(){
	memset(mark,false,sizeof mark);
	memset(temp,0,sizeof temp);
	for(int i=0;i<bin[m];++i){//初始化第一行和可以到达什么状态
		if(check(i))temp[i]=1,mark[i]=true;
	}
}

void DP(){
	for(int k=2;k<=n;++k){
		for(int i=0;i<bin[m];++i)dp[i]=0;
		for(int i=0;i<bin[m];++i){
			for(int j=0;j<bin[m];++j){
				if((i|j) != bin[m]-1)continue;//每一位或之后必须每一位是1(综合前面3种情况和分析可知)
				if(!mark[i&j])continue;//由初始化和前面分析三种情况分析可知i&j必须得到和初始化可以到达的状态一样才行
				dp[i]+=temp[j];//i可以从j到达,则增加j的方案数
			}
		}
		for(int i=0;i<bin[m];++i)temp[i]=dp[i];
	}
}

int main(){
	bin[0]=1;
	for(int i=1;i<12;++i)bin[i]=2*bin[i-1];
	while(~scanf("%d%d",&n,&m),n+m){
		if(n<m)swap(n,m);//始终保持m<n,提高效率
		Init();
		DP();
		printf("%lld\n",temp[bin[m]-1]);//输出最后一行到达时的状态必须全部是1
	}
	return 0;
}
