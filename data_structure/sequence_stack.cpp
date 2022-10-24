#include <iostream>
#include <vector>

class SequenceStack {
public:
  SequenceStack(std::vector<int>& arr) {
    length = arr.size();
    top_ = length - 1;

    for (int i = 0; i < length; i++)
      data_[i] = arr[i];
  }

  void push(int value) {
    length++;
    top_++;
    data_[top_] = value;
  }

  int pop() {
    int elem = data_[top_];
    data_[top_] = 0;
    length--;
    top_--;

    return elem;
  }

  void traverse() {
    std::cout << "traverse:: start!!" << std::endl;

    int j = 0;
    while (j < length) {
      std::cout << data_[j] << " ";
      j++;
    }

    std::cout << std::endl;
    std::cout << "traverse:: done!!" << std::endl;
  }
  

  int length;
private:
  int top_;
  int data_[20];
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4, 6, 8};
  SequenceStack sStack(arr);

  sStack.traverse();
  sStack.push(9);
  sStack.traverse();
  sStack.pop();
  sStack.pop();
  sStack.traverse();
  return 0;
}
