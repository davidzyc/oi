#include<cstdio>
#include<iostream>

using namespace std;

int n;
int a[10][10][10] = {0};
int m[10][10][10] = {0};
int opx[10], opy[10], opd[10];
int gbreak = 0;

void print_mat(int k){
  for(int i=1; i<=5; i++){
    for(int j=1; j<=7; j++){
      cout<<a[k][i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int natural_fall(int k){
  int flag = 0;
  int tm[10][10];
  for(int i=1; i<=5; i++){
    for(int j=1; j<=5; j++){
      tm[i][j] = a[k][i][j];
    }
  }
  for(int i=1; i<=5; i++){
    int j,  jc;
    for(j = 0, jc = 1;jc <= 7; ++jc){
      if(a[k][i][jc]) a[k][i][++j] = a[k][i][jc];
    }
    for(j++; j<=7; j++){
      a[k][i][j] = 0;
    }
  }
  for(int i=1; i<=5; i++){
    for(int j=1; j<=5; j++){
      if(tm[i][j] != a[k][i][j]) flag = 1;
    }
  }
  return flag;
}

void mark_remove(int k){
  for(int i=1; i<=5; i++){
    for(int j=3; j<=7; j++){
      if(a[k][i][j] == a[k][i][j-1] && a[k][i][j-1] == a[k][i][j-2]){
        m[k][i][j] = m[k][i][j-1] = m[k][i][j-2] = 1;
      }
    }
  }
  for(int j=1; j<=7; j++){
    for(int i=3; i<=5; i++){
      if(a[k][i][j] == a[k][i-1][j] && a[k][i-1][j] == a[k][i-2][j]){
        m[k][i][j] = m[k][i-1][j] = m[k][i-2][j] = 1;
      }
    }
  }
  for(int i=1; i<=5; i++){
    for(int j=1; j<=7; j++){
      // cout << m[k][i][j] << " ";
      if(m[k][i][j]){
        // cout << "HI";
        m[k][i][j] = 0;
        a[k][i][j] = 0;
      }
    }
    // cout << endl;
  }
  // print_mat(k);
  return;
}

void process_fall(int k){
  // print_mat(k);
  natural_fall(k);
  mark_remove(k);
  while(natural_fall(k)){
    // print_mat(k);
    mark_remove(k);
  }
  return;
}

void cp(int k){
  for(int i=1; i<=5; i++){
    for(int j=1; j<=7; j++){
      a[k][i][j] = a[k-1][i][j];
    }
  }
}

void dfs(int k){
  if(k == n+1){
    int flag = 1;
    for(int i=1; i<=5; i++){
      for(int j=1; j<=7; j++){
        if(a[n][i][j]) flag = 0;
      }
    }
    if(flag){
      // cout << "FIND";
      for(int i=1; i<=n; i++){
        printf("%d %d %d\n", opx[i] - 1, opy[i] - 1, opd[i]);
      }
      gbreak = 1;
      // return 0;
    }
    return;
  }

  // int t;
  for(int i=1; i<=4; i++){
    for(int j=1; j<=7; j++){
      cp(k);
      if(a[k][i][j] == a[k][i+1][j]) continue;
      if(!a[k][i][j]){
        opx[k] = i+1;
        opy[k] = j;
        opd[k] = -1;
      }else{
        opx[k] = i;
        opy[k] = j;
        opd[k] = 1;
      }
      swap(a[k][i][j], a[k][i+1][j]);
      process_fall(k);
      dfs(k+1);
      if(gbreak) break;
    }
    if(gbreak) break;
  }
  return;
}

int main(){
  int t;
  scanf("%d", &n);
  for(int i=1; i<=5; i++){
    int j = 0;
    for(scanf("%d", &t); t; scanf("%d", &t)){
      a[0][i][++j] = t;
    }
  }
  // process_fall(0);
  // print_mat(0);
  dfs(1);
  if(gbreak){
    return 0;
  }

  printf("-1");

  return 0;
}
