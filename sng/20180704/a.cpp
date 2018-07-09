#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e6+7;

int n;
string s[MAXN];
int id[MAXN], sd[MAXN], ed[MAXN];

bool cmp(int a, int b){
  int cur = 0;
  while(sd[a]+cur<ed[a] && sd[b]+cur<ed[b]){
    if(s[a][sd[a]+cur] != s[b][sd[b]+cur]) return s[a][sd[a]+cur] < s[b][sd[b]+cur];
    ++cur;
  }
  if(sd[a]+cur<ed[a]){
    return false;
  }
  if(sd[b]+cur<ed[b]){
    return true;
  }
  cur = 0;
  while(cur<sd[a]-1 && cur<sd[b]-1){
    if(s[a][cur] != s[b][cur]) return s[a][cur] > s[b][cur];
    ++cur;
  }
  if(cur<sd[a]-1){
    return true;
  }
  if(cur<sd[b]-1){
    return false;
  }
  // cout << "HI";
  return false;
}

void parse_email(int eid){
  int cur = 0;
  while(s[eid][cur] != '@') ++cur;
  sd[eid] = cur + 1;
  ed[eid] = s[eid].length();
  return;
}

int main(){

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    cin >> s[i];
    parse_email(i);
    id[i] = i;
  }
  sort(id, id+n, cmp);

  for(int i=0; i<n; i++){
    cout << s[id[i]] << endl;
  }

  return 0;
}
