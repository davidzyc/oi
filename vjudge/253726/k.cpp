#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 20;

int gn, n = 0;
int num[MAXN];
char s[MAXN];
int sn, segnum[MAXN];
int gcnt = 0;

int main(){

  while(true){
    n = 0;
    memset(num, 0, sizeof(num));
    gcnt = 0;

    // for(int i=0; i<n; i++){
    // while(gn){
    //   num[n] = gn % 10;
    //   gn /= 10;
    //   ++n;
    // }
    // }

    scanf("%s", s);
    n = strlen(s);
    if(s[0] == 'E') break;
    // cout << n;
    for(int i=0; i<n; i++){
      num[i] = s[n-1-i] - '0';
      // cout << num[i];
    }
    // cout << endl;

    for(int i=0; i<(1<<(n-1)); i++){
      sn = 0;
      memset(segnum, 0, sizeof(segnum));
      segnum[sn] = num[n-1];
      for(int j=n-2; j>=0; j--){
        if(i&(1<<j)){
          ++sn;
        }
        segnum[sn] *= 10;
        segnum[sn] += num[j];
      }
      if(sn == 0) continue;
      int gsum = 0, tsum = 0;
      for(int i=0; i<=sn; i++){
        gsum += segnum[i];
        // cout << segnum[i] << " ";
      }
      for(int i=0; i<sn; i++){
        gsum -= segnum[i];
        tsum += segnum[i];
        if(gsum == tsum) gcnt++;
      }
      // cout << endl;
    }

    printf("%d\n", gcnt);
  }

  return 0;
}
