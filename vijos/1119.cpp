#include<cstdio>
#include<iostream>
#include<cmath>
#define MAXN 105
#define MAXNODE 405
#define INF 2100000000
using namespace std;

int x[MAXNODE], y[MAXNODE], t[MAXN];
double adjm[MAXNODE][MAXNODE];
int s, tair, a, b;

void get4p(int sid){
  int maxd = 0, maxi, td;
  for(int i=0; i<3; i++){
    td = ( x[4*sid+(i%3)] - x[4*sid+((i+1)%3)] ) * ( x[4*sid+(i%3)] - x[4*sid+((i+1)%3)] ) + ( y[4*sid+(i%3)] - y[4*sid+((i+1)%3)] )*( y[4*sid+(i%3)] - y[4*sid+((i+1)%3)]);
    // cout << x[4*sid+((i)%3)] << " " << x[4*sid+((i+1)%3)] << " " << y[4*sid+((i)%3)] << " " << y[4*sid+((i+1)%3)] << " | ";
    // cout << 4*sid+(i%3) << " " << 4*sid+((i+1)%3) << " | ";
    if(td > maxd){
      maxd = td;
      maxi = i;
    }
    // cout << " | " << td << " ";
  }
  x[4*sid+3] = x[4*sid+(maxi%3)] + x[4*sid+((maxi+1)%3)] - x[4*sid+((maxi+2)%3)];
  y[4*sid+3] = y[4*sid+(maxi%3)] + y[4*sid+((maxi+1)%3)] - y[4*sid+((maxi+2)%3)];
  // cout << maxi << " " << x[4*sid+3] << " " << y[4*sid+3] << endl;
}

int main(){
  cin >> s >> tair >> a >> b;
  for(int i=0; i<s; i++){
    cin >> x[i*4+0] >> y[i*4+0] >> x[i*4+1] >> y[i*4+1] >> x[i*4+2] >> y[i*4+2] >> t[i];
    get4p(i);
  }
  for(int i=0; i<s*4; i++){
    for(int j=0; j<s*4; j++){
      if(i == j){
        adjm[i][j] = adjm[j][i] = 0.0;
        // continue;
      }else{
        if(i/4 == j/4){
          adjm[i][j] = adjm[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) * t[i/4];
        }else{
          adjm[i][j] = adjm[j][i] = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) * tair;
        }
      }
      // printf("%.1f ", adjm[i][j]);
    }
    // cout << endl;
  }
  //
  // for(int i=0; i<4*s; i++){
  //   cout << x[i] << " " << y[i] << endl;
  // }

  for(int k=0; k<4*s; k++){
    for(int i=0; i<4*s; i++){
      for(int j=0; j<4*s; j++){
        adjm[i][j] = min(adjm[i][j], adjm[i][k]+adjm[k][j]);
      }
    }
  }

  double ansmin = INF*1.0;
  a--;
  b--;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      ansmin = min(ansmin, adjm[a*4+i][b*4+j]);
    }
  }

  printf("%.2f\n", ansmin);

  return 0;
}
