/*
 要求：
给定一个只包含正整数的非空数组，判断该数组能否分成两个和相等的子数组。

样例：
输入[1,5,11,5] 返回 true . 可以分为[1,5,5]和[11]
输入[1,2,3,5]    返回false. 无法分为相等的两个子数组 
*/

#ifndef _DEPARTARRAY_H_
#define _DEPARTARRAY_H_

#include<vector>

using namespace std;

class DepartArray {
public:
    DepartArray();
    ~DepartArray();
    bool IsDepartToArray(vector<int>& nums);

private:
};

#endif //_DEPARTARRAY_H_
