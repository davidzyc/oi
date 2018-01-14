#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct Num {
    int a, b;
    bool operator < (const Num num) const{
        return this->a > num.a;
    }
};

int n, ans[1005], tot = 0, pos = 0, pre[1005], post[1005];
Num num[105], num1, num2, ntemp;
priority_queue<Num, vector<Num>, less<Num>> pq;

int main(){
    memset(pre, 0, sizeof(pre));
    memset(post, 0, sizeof(post));
    int tmp1, tmp2;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i].a;
        num[i].b = i;
        pq.push(num[i]);
    }

    sort(num, num+n);

    while(pq.size() > 1){
        num1 = pq.top();
        pq.pop();
        num2 = pq.top();
        pq.pop();
        ntemp.a = num1.a + num2.a;
        ntemp.b = min(num1.b, num2.b);
        ans[pos++] = ntemp.a;
        tot += ntemp.a;
        pq.push(ntemp);
    }

    // for(int i=0; i<n; i++){
    //     cout << num[i].a << " " << num[i].b << endl;
    // }

    cout << tot << endl;
    for(int i=0; i<pos; i++){
        cout << ans[i] << " ";
    }

    return 0;
}