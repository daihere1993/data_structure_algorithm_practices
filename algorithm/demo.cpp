#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target) {
      vector<vector<int>> ret;
      while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum == target) {
          vector<int> v;
          v.push_back(-target);
          v.push_back(nums[start]);
          v.push_back(nums[end]);
          ret.push_back(v);
          start++;
          end--;
          while (start < end && nums[start] == nums[start-1]) {
            start++;
          }
          while (start < end && nums[end] == nums[end+1]) {
            end--;
          }
        } else if (sum < target) {
          start++;
        } else {
          end--;
        }
      }
      return ret;
    }
    // 1. 对数组排序，避免出现重复的结果
    // 2. 将 threeSum 转化为 twoSum 的问题
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ret;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
          continue;
        }
        auto v = twoSum(nums, i+1, nums.size()-1, -nums[i]);
        ret.insert(ret.begin(), v.begin(), v.end());
      }
      return ret;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> v{-2, 0, 1, 1, 2};
  Solution s;
  s.threeSum(v);
  return 0;
}

