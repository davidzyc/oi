#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("1858.in", "w", stdout);
    srand(time(NULL));
    int n = 100000, m = 100000;
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; i++) printf("%d ", rand() % 2);
    printf("\n");
    for(int i = 1; i <= m; i++) {
        int caozuo = rand() % 5;
        printf("%d ", caozuo);
        int l = rand() % n;
        printf("%d ", l);
        int tmp = (n - 1 - l + 1);
        int r = l + rand() % tmp;
        printf("%d\n", r);
    }
    return 0;
}
