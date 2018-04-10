#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAXD = 4;
const int MAXN = 10005;
int gn, curd, base, y;
int st, ed, ans;
bool loopend;
int v[MAXN];
queue<int> q;

int main(){
    scanf("%d", &gn);
    while(gn--){
        memset(v, 0, sizeof(v));
        while(!q.empty()){
            q.pop();
        }
        scanf("%d%d", &st, &ed);
        v[st] = 1;
        loopend = false;
        q.push(st);
        if(st == ed){
            printf("0\n");
            continue;
        }
        ans = -1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(loopend){
                break;
            }
            int pot = 1;
            for(int i=0; i<MAXD; i++){
                curd = (x/pot)%10;
                base = x - curd * pot;
                for(int j=0; j<10; j++){
                    y = base + j * pot;
                    if(y == ed){
                        ans = v[x];
                        loopend = true;
                    }
                    if(y < 1000 || y%6 != 0 || v[y]) continue;
                    v[y] = v[x] + 1;
                    q.push(y);
                }
                pot *= 10;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
