#include<cstdio>
#include<iostream>

using namespace std;

int getyear(int d){
  return d / 10000;
}

int getmonth(int d){
  return (d / 100) % 100;
}

int getday(int d){
  return d % 100;
}

bool isdatelegit(int d){
  int year = getyear(d);
  int month = getmonth(d);
  int day = getday(d);
  bool isr = false;
  if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
    isr = true;
  }
  if(day <= 0){
    return false;
  }
  if(month > 0 && month <= 12){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
      if(day <= 31){
        return true;
      }else{
        return false;
      }
    }else if(month == 4 || month == 6 || month == 9 || month == 11){
      if(day <= 30){
        return true;
      }else{
        return false;
      }
    }else if(month == 2){
      if((isr == true && day <= 29) || (isr == false && day <= 28)){
        return true;
      }else{
        return false;
      }
    }
  }
  return false;
}

int main(){
  int ds, de, td, dt2, tot = 0;
  cin >> ds >> de;
  for(int dt = getyear(ds); dt <= getyear(de); dt++){
    td = 0;
    dt2 = dt;
    while(dt2 > 0){
      td *= 10;
      td += dt2 % 10;
      dt2 /= 10;
    }
    td += dt * 10000;
      // cout << getday(td) << endl;
    if(td >= ds && td <= de){
      if(isdatelegit(td)){
        tot++;
      }
    }
  }
  cout << tot;
  return 0;
}
