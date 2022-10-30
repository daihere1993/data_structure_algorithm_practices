#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

void insert_sort(vector<int>& nums) {
  int temp, j;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[i-1]) {
      temp = nums[i];
      for (j = i-1; nums[j] > temp; j--)
        nums[j+1] = nums[j];
      nums[j+1] = temp;
    }
  }
}

int main(int argc, char const *argv[])
{
  vector<int> nums{2, 5, 1, 9, 4, 7};
  insert_sort(nums);
  for (int i : nums)
    cout << i << " ";
  cout << endl;
  return 0;
}
