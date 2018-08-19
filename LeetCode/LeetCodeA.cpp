//
//  LeetCodeA.cpp
//  binaryTreePractice
//
//  Created by zengbailiang on 2018/8/18.
//  Copyright © 2018年 zengbailiang. All rights reserved.
//

#include "LeetCodeA.hpp"

//[1,2,3,1,14]
/*
 dp值为当前最大的到达数
 dp[i] = max(arr[i],dp[i - 1] - 1);
 return  dp[arr.size() - 1] >=1 ? true:false;
 */
bool canJumpDp(vector<int>& nums)
{
    if(nums.size() <= 1) return true;
    vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size() - 1; i ++) {
        dp[i] = max(dp[i-1] - 1,nums[i]);
    }
    
    return dp[nums.size() - 1] >= 1 ? true : false;
}

bool canJumpGreed(vector<int>& nums)
{
    if(nums.size() <= 1) return true;
    
    int currentMaxStep = nums[0];
    for (int i = 1; i < nums.size() - 1; ++i) {
        currentMaxStep --;//每前进一步就需要减1
        if (nums[i] > currentMaxStep) { //如果在能前进的范围内，获取到更多的可用步数，就更新步数
            currentMaxStep = nums[i];
        }
    }
    
    return currentMaxStep >= 1 ? true : false;
}

bool subCanJump(vector<int> & nums,int right)
{
    if(nums.size() <= 1) return true;
    
    //每个左边的点都有可能到达终点
    for (int i = right; i >=0; i--) {
        //如果该位置可到达终点
        if(nums[i] >= right - i)
        {
            //递归查找该位置本身是否可达
            return subCanJump(nums,right - 1);
        }
    }
    return false;
}
bool canJumpRecursion(vector<int>& nums)
{
    return subCanJump(nums, (int)nums.size() -1);
}

//45此解法Leetcode不通过。输入很大的时候，时间超时。
/*
 
 */
int jump(vector<int>& nums) {
    vector<int> dp(nums.size(),0);
    for (int i = 1; i < nums.size(); i ++) {
        for (int j = 0; j < i ; j ++) {
            if (nums[j] + j >= i) { //每一个能到达 i的都有机会更新dp[i]
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[nums.size() - 1];
}

//45贪心算法
int jumpGreed(vector<int>& nums)
{
    int minjump = 0;
    int currentFarthest =0 ,end = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
     //更新目前可达最远处
        currentFarthest = max(nums[i] + i, currentFarthest);
        
        if (i == end && end <nums.size()) {
            //到了本次必须跳跃的位置。
            minjump ++;
            //更新下一次必须跳跃的位置。为当前可达的最远处
            end = currentFarthest;
        }
    }
    return minjump;
}
