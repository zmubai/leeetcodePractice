//
//  LeetCodeA.hpp
//  binaryTreePractice
//
//  Created by zengbailiang on 2018/8/18.
//  Copyright © 2018年 zengbailiang. All rights reserved.
//

#ifndef LeetCodeA_hpp
#define LeetCodeA_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class LeetCodeA
{
  
public:
    
    /*45跳跃游戏2*/
    int jump(vector<int>& nums);
    /*55跳跃游戏*/
    bool canJumpDp(vector<int>& nums);
    bool canJumpGreed(vector<int>& nums);
    bool canJumpRecursion(vector<int>& nums);
};

#endif /* LeetCodeA_hpp */
