#include<cstdio>
#include<iostream>

using namespace std;

char c[3] = {'A', 'B', 'C'};
int v[3];
int mcnt[15] = {0};

int get_else(int a, int b){
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  v[a] = 1;
  v[b] = 1;
  for(int i=0; i<3; i++){
    if(!v[i]) return i;
  }
  return -1;
}

void print_hanoi(int f, int t, int l){
  printf("%d from %c to %c\n", l, c[f], c[t]);
}

void move_hanoi(int f, int t, int l){
  if(l == 1){
    print_hanoi(f, t, l);
    return;
  }
  int e = get_else(f, t);
  move_hanoi(f, e, l-1);
  print_hanoi(f, t, l);
  move_hanoi(e, t, l-1);
  return;
}

int main(){
  // freopen("3145_hanoi.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  mcnt[0] = 1;
  for(int i=1; i<n; i++){
    mcnt[i] = 2*mcnt[i-1]+1;
  }
  printf("%d\n", mcnt[n-1]);
  move_hanoi(0, 2, n);

  return 0;
}
