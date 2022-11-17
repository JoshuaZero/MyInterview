#include "departArray.h"
#include <vector>
#include <iostream>

using namespace std;

DepartArray::DepartArray() {
   cout << "DepartArray constructor" << endl;
}

DepartArray::~DepartArray() {
   cout << "~DepartArray destructor" << endl;
}


bool DepartArray::IsDepartToArray(vector<int>& nums) {
   int len = nums.size();
   if (len == 0)
      return false;
   int sum = 0;
   if (sum % 2 == 1) 
      return false;
   int sum_init = (sum>>2) + 1;
   vector<vector<bool>> dp(len+1, vector<bool>(sum_init, false));
   for (int i = 0; i < len+1; i++) {
       dp[i][0] = true;
   }
   for (int j = 1; j <= len; j++) {
       for (int k = 1; k <= sum_init-1; k++) {
           if (k - nums[j-1] < 0) {
              dp[j][k] = dp[j-1][k];
	   }
	   else {
               dp[j][k] = dp[j-1][k] || dp[j-1][k-nums[j-1]];
	   }
       }
   }

   return dp[len][sum_init-1];
}
