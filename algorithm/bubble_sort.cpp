#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void bubble_sort(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = nums.size() - 2; j >= i; j--) {
      if (nums[j] > nums[j+1]) {
        swap(nums, j, j+1);
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  vector<int> nums{2, 5, 1, 9, 4, 7};
  bubble_sort(nums);
  for (int i : nums)
    cout << i << " ";
  cout << endl;
  return 0;
}
