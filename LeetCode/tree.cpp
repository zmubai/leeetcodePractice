//
//  tree.cpp
//  binaryTreePractice
//
//  Created by zengbailiang on 2018/8/12.
//  Copyright © 2018年 zengbailiang. All rights reserved.
//

#include "tree.hpp"

typedef char ElementType;

typedef struct Node
{
    ElementType value;
    struct Node *leftNode;
    struct Node *rightNode;
}Node,*BInTree;

void createBinaryTree(BInTree *tree)
{
    if (*tree != NULL) {
        return;
    }
    else
    {
        ElementType ch;
        scanf("%c",&ch);
        if (ch == '#') {
            *tree = NULL;
        }
        else
        {
            tree = (BInTree*)malloc(sizeof(struct Node));
            if (*tree != NULL) {
                (*tree) ->value = ch;
                printf("fille in %c ",(*tree)->value);
                createBinaryTree(&(*tree) ->leftNode);
                createBinaryTree(&(*tree)->rightNode);
            }
        }
    }
}

void priftBinaryTree(BInTree *tree)
{
    if (*tree != NULL) {
        printf("%c ",(*tree)->value);
        priftBinaryTree(&(*tree)->leftNode);
        priftBinaryTree(&(*tree)->rightNode);
    }
}

void createAction()
{
    BInTree tree;
    createBinaryTree(&tree);
    priftBinaryTree(&tree);
}

//递归前序遍历
void preOrder(BInTree tree)
{
    if (tree != NULL) {
        printf("%c ",tree->value);
        preOrder(tree->leftNode);
        preOrder(tree->rightNode);
    }
}

void middleOrder(BInTree tree)
{
    if (tree != NULL) {
        middleOrder(tree->leftNode);
        printf("%c ",tree->value);
        middleOrder(tree->rightNode);
    }
}

void rearOrder(BInTree tree)
{
    if(tree != NULL)
    {
        preOrder(tree->leftNode);
        preOrder(tree->rightNode);
        printf("%c ",tree->value);
    }
}

#pragma mark - 非递归遍历
void preOrder1(BInTree tree)
{
    stack<BInTree> sk;
    
    BInTree cur = tree;
    
    while (tree != NULL || !sk.empty()) {
        //这一步理解很重要。打印各级根节点，并打印最左边的叶子节点。
        while (cur != NULL) {
            cout<<cur->value <<"";//打印各级根节点，直到最后打印左叶子节点
            sk.push(cur);
            cur = cur->leftNode;
        }
        
        //when cur.leftNode = Null
        if (!sk.empty()) {
            cur = sk.top();//执行上面的while循环后，左叶子节点已经输出。获取当前的根节点
            sk.pop();
            cur = cur->rightNode;//移到右节点，执行同样的处理
        }
    }
}

//非递归中序遍历
void middleOrder2(BInTree tree)
{
    stack<BInTree> sk;
    BInTree cur = tree;
    
    while (cur != NULL || !sk.empty()) {
        while (cur != NULL) {
            sk.push(cur);
            cur = cur->leftNode;
        }
        if (!sk.empty()) {
            cur = sk.top();
            sk.pop();
            cout<< cur->value<<"";//左节点打印完，top出来的就是根节点。||每一个左节点是上一级的左节点，同时也可能为下级的跟节点。每一个节点都可能是根节点。
            cur = cur->rightNode;
        }
    }
}

//非递归后续遍历
void realOrder2(BInTree tree)
{
    stack<BInTree> sk;
    BInTree cur = NULL;
    BInTree pre = NULL;//上一个打印的元素
    if (tree != NULL) {
        sk.push(tree);
        while (!sk.empty()) {
            cur = sk.top();
            //如果左右节点都为空，代表可以打印。或者前一个节点为其左节点或者右节点，也可答应。因为压栈的顺序是左右。如果前一个打印的节点为其左节点，那么代表其没有右节点。如果前一个节点为右节点代表左右节点都打印完了，当前节点也可以打印了。
            if ((cur->leftNode == NULL && cur->rightNode == NULL)
                ||(pre == cur->leftNode || pre == cur->rightNode)) {
                cout << cur->value<< "";
                pre = cur;
                sk.pop();
            }
            else
            {
                if (cur->leftNode != NULL)
                    sk.push(cur->leftNode);
                if (cur->rightNode != NULL)
                    sk.push(cur->rightNode);
            }
        }
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

tree::tree()
{
    
}

tree::~tree()
{
    
}

//中序遍历
vector<int> tree:: inorderTraversal(TreeNode* root)
{
    vector<int> object;
    stack<TreeNode*> sk;
    TreeNode *cur = root;
    while (cur != NULL || !sk.empty()) {
        
        while (cur->left != NULL) {
            sk.push(cur);
            cur = cur->left;
        }
        if (!sk.empty()) {
            cur = sk.top();
            object.push_back(cur->val);
            sk.pop();
            cur = cur->right;
        }
    }
    return object;
}

void tree:: subSortedArrayToBST(vector<int>& nums,int lefIdx,int rigIdx)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode *leftNode = NULL;
    TreeNode *rightNode = NULL;
    if (rigIdx - lefIdx > 1) {
        int mid = (lefIdx + rigIdx) / 2;
        node -> val = nums.at(mid);
//        leftNode  = subSortedArrayToBST(nums,lefIdx,mid - 1);
//        rightNode = subSortedArrayToBST(nums, mid + 1, rigIdx);
    }
    else if (rigIdx > lefIdx)
    {
        leftNode = (TreeNode *)malloc(sizeof(struct TreeNode));
        leftNode->val = nums.at(lefIdx);
        leftNode->left = NULL;
        leftNode->right = NULL;
        node->val = nums.at(rigIdx);
    }
    else
    {
        node->val = nums.at(lefIdx);
    }
    node->left = leftNode;
    node->right = rightNode;
//    return node;
}
void tree:: sortedArrayToBST(vector<int>& nums)
{
    if (!nums.size()) {
//        return NULL;
    }
    else
    {
        subSortedArrayToBST(nums, 0, nums.size()-1);
    }
}

void tree::layerOrder(vector<vector<int>> *vr,TreeNode* root,int index)
{
    if (root != NULL) {
        
        if (vr->size() > index) {
            vector<int> *temp = &(vr->at(index));
            temp->push_back(root->val);
        }
        else
        {
            vector<int> temp;
              temp.push_back(root->val);
        }
      
        index++;
        layerOrder(vr, root->left, index);
        layerOrder(vr, root->right, index);
    }
}

vector<vector<int>> tree:: levelOrder(TreeNode* root)
{
    vector<vector<int>> vt;
    layerOrder(&vt, root, 0);
    return vt;
}

//[7,1,5,3,6,4]
int tree::maxProfit(vector<int>& prices)
{
    
    if (prices.size() == 0) {
        return  0;
    }
    
    int currentWantBuyPrice = prices.at(0);
    int currentWantSellPrice = prices.at(0);
    
    int profit = 0;
    bool needTradeLast = false;
    for (int i = 0; i < prices.size(); i ++) {
        if (currentWantSellPrice > prices.at(i)) {
            profit += currentWantSellPrice - currentWantBuyPrice;
            currentWantBuyPrice = prices.at(i);
            currentWantSellPrice = prices.at(i);
        }
        else if (prices.at(i) > currentWantBuyPrice || prices.at(i) > currentWantSellPrice) {
            currentWantSellPrice = prices.at(i);
            if (i == prices.size() - 1) {
                needTradeLast = true;
            }
        }
        else if (prices.at(i) < currentWantBuyPrice) {
            currentWantBuyPrice = prices.at(i);
            currentWantSellPrice = prices.at(i);
        }
    }
    if (true) {
        profit += currentWantSellPrice - currentWantBuyPrice;
    }
    return profit;
}

//左到右有序的情况
int tree::findContentChildren(vector<int>& g, vector<int>& s)
{
    
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int sum = 0 ;
    int i = 0;
    int j = 0;
    while (i < g.size() && j < s.size()) {
        if (g.at(i) <= s.at(j)) {
            i ++;
            j ++;
            sum ++;
        }
        else
        {
            j ++;
        }
    }
    return sum;
}

//去掉重复字符
string tree::removeDuplicateLetters(string s)
{
    if (s.length() == 0) {
        return "";
    }
    
    vector<int> counts(26,0);
    for(char c : s)
    {
        counts[c - 'a'] += 1;
    }
    
    int currentMinPos = 0;
    
    for(int i = 0 ; i < s.length(); i ++)
    {
        char c = s.at(i);
        //记录pos，pos左边元素在pos右边均存在，这个是右下面的条件确定的。
        if(counts[currentMinPos] < counts[c - 'a'])
            currentMinPos = i ;
            
        counts[c - 'a'] -= 1;
        //遇到pos右边第一个不可或缺元素的位置时，跳出
        if (counts[c - 'a'] == 0) {
            break;
        }
    
    }
    
    char posC = s.at(currentMinPos);
    string subString = s.substr(currentMinPos + 1);
    unsigned long  index = subString.find(posC);
    while (index != s.npos) {
        subString = subString.replace(posC, 1, "");
        index = subString.find(posC);
    }
    
    string res =  "";
    res += posC;
    
    return res + removeDuplicateLetters(subString);
}

