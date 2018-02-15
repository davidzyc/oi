// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<queue>
// #define MAXN 105
// #define MAXM 20005
// #define INF 2100000000
// using namespace std;
//
// int from[MAXM], to[MAXM], w[MAXM], first[MAXN], nxt[MAXM], vis[MAXM];
//
// int dis[MAXN];
//
// int main(){
//   int n, m;
//   while(cin >> n >> m){
//     int t1, t2, tw;
//     memset(nxt, -1, sizeof(nxt));
//     memset(first, -1, sizeof(first));
//     for(int i=0; i<m; i++){
//       cin >> t1 >> t2 >> tw;
//       from[i*2] = to[i*2+1] = t1;
//       from[i*2+1] = to[i*2] = t2;
//       w[i*2] = w[2*i+1] = tw;
//       nxt[i*2] = first[t1];
//       nxt[i*2+1] = first[t2];
//       first[t1] = i*2;
//       first[t2] = i*2+1;
//     }
//     int ans = INF;
//     for(int i=1; i<=n; i++){
//       memset(vis, 0, sizeof(vis));
//       for(int j=1; j<=n; j++){
//         dis[j] = INF;
//       }
//       dis[i] = 0;
//       queue<int> q;
//       q.push(i);
//       while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         // for(int k=1; k<=n; k++){
//         int e = first[node];
//         while(e != -1){
//           if(!vis[e/2]){
//             if(dis[to[e]] < INF){
//               ans = min(ans, dis[to[e]] + dis[node] + w[e]);
//               dis[to[e]] = min(dis[to[e]], dis[node] + w[e]);
//             }else{
//               dis[to[e]] = dis[node] + w[e];
//               q.push(to[e]);
//             }
//             vis[e/2] = 1;
//           }
//           e = nxt[e];
//         }
//       }
//     }
//     if(ans < INF){
//       cout << ans << endl;
//     }else{
//       cout << "No Solution." << endl;
//     }
//   }
//
//   return 0;
// }

#include<cstdio>
#include<iostream>
#define MAXN 105
#define INF 100000000
using namespace std;

int n, m;
int o[MAXN][MAXN];
int f[MAXN][MAXN];

int main(){
  int tfrom, tto, tw;
  while(cin >> n >> m){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        o[i][j] = f[i][j] = INF;
      }
    }
    for(int i=0; i<m; i++){
      cin >> tfrom >> tto >> tw;
      o[tfrom][tto] = o[tto][tfrom] = f[tfrom][tto] = f[tto][tfrom] = min(o[tfrom][tto], tw);
    }
    int gans = INF;
    for(int k=1; k<=n; k++){
      for(int i=1; i<k; i++){
        for(int j=i+1; j<k; j++){
          // if(f[i][j] < INF && o[i][k] < INF && o[k][j] < INF){
            gans = min(gans, f[i][j]+o[i][k]+o[k][j]);
          // }
        }
      }
      for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          if(i == j) continue;
          f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        }
      }
    }
    if(gans < INF){
      cout << gans << endl;
    }else{
      cout << "No solution." << endl;
    }
  }

  return 0;
}
