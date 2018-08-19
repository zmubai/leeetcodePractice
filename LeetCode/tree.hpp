//
//  tree.hpp
//  binaryTreePractice
//
//  Created by zengbailiang on 2018/8/12.
//  Copyright © 2018年 zengbailiang. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <vector>
#include <string.h>
#include <stack>
#include <iostream>

using namespace std;

class tree {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
public:
    tree();
    ~tree();
    vector<int> inorderTraversal(TreeNode* root);
    void subSortedArrayToBST(vector<int>& nums,int left,int right);
    void sortedArrayToBST(vector<int>& nums);
    vector<vector<int>> levelOrder(TreeNode* root);
    
    void layerOrder(vector<vector<int>> *vr,TreeNode* root,int index);
    
    //贪心
    int maxProfit(vector<int>& prices);
    int findContentChildren(vector<int>& g, vector<int>& s);
    string removeDuplicateLetters(string s);
};
#endif /* tree_hpp */
