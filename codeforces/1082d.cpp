#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e5+7;

int n, m = 1;
int deg[MAXN];
int mk[MAXN];
int seq[MAXN], qn = 0;
int from[MAXN], to[MAXN], head[MAXN], nxt[MAXN];
int gdep = 0, dep[MAXN], v[MAXN];

void add_edge(int tf, int tt){
  ++m;
  from[m] = tf;
  to[m] = tt;
  nxt[m] = head[tf];
  head[tf] = m;
}

void dfs(int x){
  v[x] = 1;
  for(int e=head[x]; e; e=nxt[e]){
    int y = to[e];
    if(v[y]) continue;
    dfs(y);
    gdep = max(gdep, dep[x] + 1 + dep[y]);
    dep[x] = max(dep[x], dep[y] + 1);
  }
}

int main(){
  int ga = 1;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &deg[i]);
    if(deg[i] > 1) {
      seq[++qn] = i;
    }else if(deg[i] == 1){
      mk[i] = 1;
    }else{
      ga = 0;
    }
  }

  if(!ga){
    printf("NO\n");
    return 0;
  }

  for(int i=2; i<=qn; i++){
    add_edge(seq[i], seq[i-1]);
    add_edge(seq[i-1], seq[i]);
    -- deg[seq[i]];
    -- deg[seq[i-1]];
  }
  // for(int i=1; i<=qn ;i++) cout << seq[i] << " ";
  int cur = 1;
  int headmk = 0, tailmk = 0;
  for(int i=1; i<=n; i++){
    if(mk[i] == 1){
      if(!headmk){
        -- deg[seq[1]];
        add_edge(seq[1], i);
        add_edge(i, seq[1]);
        headmk = 1;
        continue;
      }else if(!tailmk){
        -- deg[seq[qn]];
        add_edge(seq[qn], i);
        add_edge(i, seq[qn]);
        tailmk = 1;
        continue;
      }
      while(deg[seq[cur]] <= 0){
        if(cur > qn){
          ga = 0;
          break;
        }
        ++cur;
      }
      if(ga == 0) break;
      // cout << deg[seq[cur]] << " ";
      -- deg[seq[cur]];
      add_edge(i, seq[cur]);
      add_edge(seq[cur], i);
    }
  }

  if(!ga){
    printf("NO\n");
    return 0;
  }

  dfs(1);

  printf("YES %d\n%d\n", gdep, m/2);
  for(int i=2; i<=m; i+=2){
    printf("%d %d\n", from[i], to[i]);
  }

  return 0;
}
