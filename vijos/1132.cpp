#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

string mid, post;
int lchild[100], rchild[100];

int pre_tree_walk(int node){
    cout << post[node];
    if(lchild[node] != -1)
        pre_tree_walk(lchild[node]);
    if(rchild[node] != -1)
        pre_tree_walk(rchild[node]);
}

int build_tree(int mid_start, int mid_end, int post_start, int post_end){
    if(mid_end - mid_start != post_end - post_start){
        // cout << "Error!!!" << endl;;
        return -1;
    }
    // cout << "Passed." << endl;
    if(mid_end == mid_start) {
        return -1;
    }
    if(post_end == post_start + 1){
        return post_start;
    }
    int mid_left_end, mid_right_start, post_mid, root;
    root = post_end - 1;
    mid_left_end = mid.find(post[post_end-1]);
    mid_right_start = mid_left_end + 1;
    post_mid = post_start + (mid_left_end - mid_start);
    lchild[root] = build_tree(mid_start, mid_left_end, post_start, post_mid);
    rchild[root] = build_tree(mid_right_start, mid_end, post_mid, root);
    // cout << root << endl;
    return root;
}

int main(){
    memset(lchild, -1, sizeof(lchild));
    memset(rchild, -1, sizeof(rchild));
    cin >> mid >> post;
    // cout << mid.length();
    pre_tree_walk(build_tree(0, mid.length(), 0, post.length()));

    return 0;
}