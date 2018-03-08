#include<cstdio>
#include<iostream>
#include<stack>

using namespace std;

struct node{
  char c;
  int on;
  int locked;
};

char c;
int parseon(){
  int rtn = 0;
  while((c=getchar())!='('){}
  c = getchar();
  if(c == '1'){
    rtn = 0;
    while((c=getchar())!=')'){}
  }else if(c == 'n'){
    // while((c=getchar())!='^'){}
    getchar();
    while((c=getchar())!=')'){
      rtn *= 10;
      rtn += c - '0';
    }
  }
  while((c=getchar())!='\n'){}
  return rtn;
}

int main(){
  // freopen("2029.txt", "r", stdin);
  int nnn;
  cin >> nnn;
  for(int iii=0; iii<nnn; iii++){
    stack<node> s;
    int locked = 0;
    int v[27] = {0};
    bool err = false;
    int n, on, cnt=0, onans = 0;
    scanf("%d", &n);
    on = parseon();
    // printf("%d\n", on);

    for(int i=0; i<n; i++){
      c = getchar();

      if(c == 'F'){
        int fromn = 0, ton = 0;
        bool fromt = false, tot = false;
        char curc;
        getchar();
        curc = getchar();
        getchar();
        c = getchar();
        if(c >= '0' && c <= '9'){
          fromn += c - '0';
          while((c=getchar())!=' '){
            fromn *= 10;
            fromn += c - '0';
          }
        }else if(c == 'n'){
          getchar();
          fromt = true;
        }

        c = getchar();
        if(c >= '0' && c <= '9'){
          ton += c - '0';
          while((c=getchar())!='\n'){
            ton *= 10;
            ton += c - '0';
          }
        }else if(c == 'n'){
          getchar();
          tot = true;
        }

        int tempnon = 0, tempnlocked = 0;
        node tempn;
        if(v[curc-'a']) err = true;
        v[curc-'a'] = 1;
        if(!fromt && tot){
          tempnon = 1;
          tempnlocked = 0;
        }else if(fromt && !tot){
          tempnon = 0;
          tempnlocked = 1;
        }else if(fromt && tot){
          tempnon = 0;
          tempnlocked = 0;
        }else if(!fromt && !tot){
          if(fromn <= ton){
            tempnon = 0;
            tempnlocked = 0;
          }else{
            tempnon = 0;
            tempnlocked = 1;
          }
        }
        tempn.c = curc;
        tempn.on = tempnon;
        tempn.locked = tempnlocked;
        s.push(tempn);
        if(tempnlocked) locked++;
        cnt += tempnon;
        if(!locked) onans = max(onans, cnt);

      }else if(c == 'E'){

        node tempn;
        tempn = s.top(); s.pop();
        locked -= tempn.locked;
        cnt -= tempn.on;
        v[tempn.c - 'a'] = 0;

        while((c=getchar())!='\n'){}
      }
    }

    if(err || cnt){
      cout << "ERR" << endl;
    }else{
      if(onans == on){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
