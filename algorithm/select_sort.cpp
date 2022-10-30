#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void select_sort(std::vector<int>& nums) {
  int min;
  for (int i = 0; i < nums.size()-1; i++) {
    min = i;
    for (int j = i+1; j < nums.size(); j++) {
      if (nums[min] > nums[j])
        min = j;
    }
    if (min != i)
      swap(nums, i, min);
  }
}

int main(int argc, char const *argv[])
{
  vector<int> nums{2, 5, 1, 9, 4, 7};
  select_sort(nums);
  for (int i : nums)
    cout << i << " ";
  cout << endl;
  return 0;
}
