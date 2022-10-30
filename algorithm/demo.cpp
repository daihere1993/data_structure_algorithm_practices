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
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> ret;
      int start = 0;
      int end = nums.size() - 1;
      sort(nums.begin(), nums.end());
      while (start < end) {
        int sum = nums[start] + nums[end];
        if (sum == target) {
          ret.push_back(start);
          ret.push_back(end);
          return ret;
        } else if (sum < target) {
          start++;
        } else {
          end--;
        }
      }
      return ret;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> v{3, 2, 4};
  Solution s;
  s.twoSum(v, 6);
  return 0;
}

