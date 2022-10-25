#include <iostream>
#include <vector>

#define MAXSIZE 20

class SqBiTree {
public:
  SqBiTree(std::vector<int> arr) {
    for (int i = 0; i < MAXSIZE; i++) {
      if (i < arr.size()) {
        data_[i] = arr[i];
      } else {
        data_[i] = 0;
      }
    }
  }

  int getValue(int index) {
    return data_[index];
  }

  bool isEmptyNode(int index) {
    return index >= MAXSIZE || data_[index] == 0;
  }
private:
  int data_[MAXSIZE];
};

void visit(SqBiTree& t, int index) {
  std::cout << t.getValue(index) << " ";
}

void preorderTraverse(SqBiTree& t, int index = 0) {
  int left = 2*index+1;
  int right = 2*index+2;
  visit(t, index);

  if (not t.isEmptyNode(left)) {
    preorderTraverse(t, left);
  }
  if (not t.isEmptyNode(right)) {
    preorderTraverse(t, right);
  }
}

void inorderTraverse(SqBiTree& t, int index = 0) {
  int left = 2*index+1;
  int right = 2*index+2;

  if (not t.isEmptyNode(left)) {
    inorderTraverse(t, left);
  }
  visit(t, index);
  if (not t.isEmptyNode(right)) {
    inorderTraverse(t, right);
  }
}

void postoderTraverse(SqBiTree& t, int index = 0) {
  int left = 2*index+1;
  int right = 2*index+2;

  if (not t.isEmptyNode(left)) {
    inorderTraverse(t, left);
  }
  if (not t.isEmptyNode(right)) {
    inorderTraverse(t, right);
  }
  visit(t, index);
}

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 0, 5, 0, 7, 0, 0, 10};
  SqBiTree t(arr);
  preorderTraverse(t);
  std::cout << std::endl;
  inorderTraverse(t);
  std::cout << std::endl;
  postoderTraverse(t);
  std::cout << std::endl;
  return 0;
}

