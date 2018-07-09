#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define DB double
#define Max(a,b) ((a)>(b)?(a):(b))
const int MAXN = 100010;
DB a[MAXN];
int N, K, q[MAXN];

inline DB slope(int i, int j) {
	return (a[j] - a[i]) / (j - i);
}

int main()
{
	freopen("2018.in", "r", stdin);
	freopen("2018.ans", "w", stdout);
	int i, t, l=1, r=1, in;
	scanf("%d%d", &N, &K);
	for (i = 1; i<=N; ++i)
	{
		scanf("%d", &t);
		a[i] = a[i-1] + t;
	}
	q[r++] = 0;
	DB ans = 0;
	for (i = K; i<=N; ++i)
	{
		while (l+1 < r && slope(q[l], q[l+1]) < slope(q[l+1], i)) ++l;
		ans = Max(ans, slope(q[l], i));

		in = i - K + 1; //为了保证长度不低于K，每次将K个之前的点入队。
		while (l+1 < r && slope(q[r-2], q[r-1]) > slope(q[r-1], in)) --r;
		q[r++] = in;
	}
	ans *= 1000.0;
	t = ans;
	printf("%d\n", t);
	return 0;
}
