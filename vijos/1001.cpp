#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char name[100], max_name[100], is_minister, is_west;
    int avg_score, class_score, essay_num;
    int n, pmax = 0, temp_sum, totsum = 0;
    
    cin >> n;
    for(int z=0; z<n; z++){
        temp_sum = 0;
        memset(name, 0, sizeof(name));
        cin >> name >> avg_score >> class_score >> is_minister >> is_west >> essay_num;
        // cout << name;
        if(avg_score > 90) temp_sum += 2000;
        if(avg_score > 85){
            if(is_west == 'Y') temp_sum += 1000;
            if(class_score > 80) temp_sum += 4000;
        }
        if(class_score > 80 && is_minister == 'Y') temp_sum += 850;
        if(avg_score > 80 && essay_num > 0) temp_sum += 8000;
        totsum += temp_sum;
        if(temp_sum > pmax) {
            pmax = temp_sum;
            memset(max_name, 0, sizeof(max_name));
            strcpy(max_name, name);
        }
            // cout << name << temp_sum << endl;
    }
    cout << max_name << endl << pmax << endl << totsum;
    
    // cout << pmax << " " << totsum;
    
    return 0;
}