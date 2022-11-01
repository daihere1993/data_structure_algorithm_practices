#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

// 将 i-j 的结点调整成大顶堆
void heap_adjust(vector<int>& nums, int start, int end) {
	int dad = start;
  int son = dad * 2 + 1;
  while (son <= end) {
    if (son + 1 <= end && nums[son] < nums[son + 1])
      son++;
    if (nums[dad] > nums[son])
      return;
    swap(nums, son, dad);
    dad = son;
    son = dad * 2 + 1;
  }
}

void heap_sort(vector<int>& nums) {
  int len = nums.size();
	for (int i = len / 2 - 1; i >= 0; i--)
		heap_adjust(nums, i, len - 1);
	for (int i = len - 1; i > 0; i--) {
		swap(nums, 0, i);
		heap_adjust(nums, 0, i - 1);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> nums{50, 10, 90, 30, 70, 40, 80, 60, 20};
	heap_sort(nums);
	for (int i : nums)
		cout << i << " ";
	cout << endl;
	return 0;
}
