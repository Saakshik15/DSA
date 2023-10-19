/*
You have been given k different arrays or lists, which are sorted individually in ascending order.
You need to merge all the given arrays/lists such that the output arrays/lists should be sorted in ascending order.
  */


#include <bits/stdc++.h>

class node {
    public:
        int data;
        int row,col;
        node(int data,int i,int j) {
            this->data = data;
            row = i;
            col = j;
        }
};

class compare {
    public:
        bool operator()(node* a,node* b) {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){

    priority_queue <node*,vector<node*>,compare> pq;
    for(int i=0;i<k;i++) {
        node* tmp = new node(kArrays[i][0],i,0);
        pq.push(tmp);
    }

    vector<int> ans;

    while(!pq.empty()) {
        node* ele = pq.top();
        pq.pop();
        ans.push_back(ele->data);
        int i = ele->row;
        int j = ele->col;

        if( j+1 < kArrays[i].size() ) {
            node* tmp = new node(kArrays[i][j+1],i,j+1);
            pq.push(tmp);
        }
    }
    return ans;
}
