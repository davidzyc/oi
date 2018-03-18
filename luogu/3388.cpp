#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+7;
int n, m;
vector<int> to[MAXN];
vector<int> cutp;
int cnt = 0;
int previsit[MAXN] = {0};
int low[MAXN] = {0};
int root;

void tarjan(int cur){
  bool is_cut = false;
  int flag = 0;
  previsit[cur] = low[cur] = ++cnt;
  for(int i=0; i<to[cur].size(); i++){
    int t = to[cur][i];
    if(!previsit[t]){
      tarjan(t);
      low[cur] = min(low[cur], low[t]);
      if(low[t] >= previsit[cur]){
        ++flag;
        if(flag > 1 || cur != root){
          is_cut = true;
        }
      }
    }else{
      low[cur] = min(low[cur], previsit[t]);
    }
  }
  if(is_cut){
    cutp.push_back(cur);
  }
  return;
}

int main(){
  scanf("%d %d", &n, &m);
  int f, t;
  for(int i=0; i<m; i++){
    scanf("%d%d", &f, &t);
    to[f].push_back(t);
    to[t].push_back(f);
  }
  for(int i=1; i<=n; i++){
    if(!previsit[i]){
      root = i;
      tarjan(i);
    }
  }
  sort(cutp.begin(), cutp.end());
  cout << cutp.size() << endl;
  for(int i=0; i<cutp.size(); i++){
    printf("%d ", cutp[i]);
  }
  return 0;
}
