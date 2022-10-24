#include <iostream>
#include <vector>

#define MAXSIZE 20

class DoubleStack {
public:
  DoubleStack(std::vector<int>& arr1, std::vector<int>& arr2) {
    if (arr1.size() + arr2.size() > MAXSIZE) {
      std::cout << "Error1" << std::endl;
      return;
    }

    length1_ = arr1.size();
    length2_ = arr2.size();

    top1_ = length1_ != 0 ? (length1_ - 1) : -1;
    top2_ = length2_ != 0 ? (MAXSIZE - length2_) : -1;

    for (int i = 0; i < length1_; i++)
      data_[i] = arr1[i];

    for (int i = 0; i < length2_; i++)
      data_[MAXSIZE - i - 1] = arr2[i];
  }

  void push(int stackNum, int elem) {
    if (length1_ + length2_ == MAXSIZE) {
      std::cout << "Error2" << std::endl;
      return;
    }

    int& length = getLength(stackNum);
    length++;
    int& top = stackNum == 1 ? top1_ : top2_;
    int i = stackNum == 1 ? 1 : -1;

    top += i;
    data_[top] = elem;
  }

  int pop(int stackNum) {
    int& top = stackNum == 1 ? top1_ : top2_;
    int i = stackNum == 1 ? 1 : -1;

    if (top == -1)
      return -1;
    
    int& length = getLength(stackNum);
    length--;
    int pop_elem = data_[top];
    data_[top] = 0;
    top -= i;
    return pop_elem;
  }

  void traverse(int stackNum) {
    std::cout << "traverse:: stack" << stackNum << " start!!" << std::endl;

    int j = 0;
    int length = getLength(stackNum);
    while (j < length) {
      int i = stackNum == 1 ? (length - j - 1) : (top2_ + j);
      std::cout << data_[i] << " ";
      j++;
    }

    std::cout << std::endl;
    std::cout << "traverse:: done!!" << std::endl;
  }

  int& getLength(int stackNum) {
    return stackNum == 1 ? length1_ : length2_;
  }


private:
  int top1_;
  int top2_;
  int length1_;
  int length2_;
  int data_[MAXSIZE];
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr1{1, 2, 3, 4, 6, 8};
  std::vector<int> arr2{10, 12, 14, 16};
  DoubleStack dStack(arr1, arr2);
  dStack.traverse(1);
  dStack.traverse(2);
  dStack.push(1, 9);
  dStack.push(2, 17);
  dStack.traverse(1);
  dStack.traverse(2);
  dStack.pop(1);
  dStack.pop(2);
  dStack.traverse(1);
  dStack.traverse(2);
  return 0;
}

