#include <iostream>
#include <vector>

struct Node {
  int data;
  struct Node *next;
};

class LinkStack {
public:
  LinkStack(std::vector<int>& arr) {
    length = arr.size();
    Node* prev_node = nullptr;

    for (int i = 0; i < length; i++) {
      Node* node = new Node;
      node->data = arr[i];
      if (prev_node)
        node->next = prev_node;
      else
        node->next = nullptr;
      prev_node = node;
    }

    top_ = prev_node;
  }

  void push(int value) {
    Node* node = new Node;
    node->data = value;
    node->next = top_;
    top_ = node;
    length++;
  }

  int pop() {
    Node* node = top_;
    int ret = node->data;
    top_ = top_->next;
    length--;
    free(node);
    return ret;
  }

  void traverse() {
    std::cout << "traveerse:: start!!" << std::endl;

    int j = 0;
    Node* curr_node = top_;

    while (j < length) {
      std::cout << curr_node->data << " ";
      curr_node = curr_node->next;
      j++;
    }

    std::cout << std::endl;
    std::cout << "traveerse done!!" << std::endl;
  }

  int length;
private:
  Node* top_;
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4, 6, 8};
  LinkStack lStack(arr);
  lStack.traverse();
  lStack.push(9);
  lStack.traverse();
  lStack.pop();
  lStack.traverse();
  return 0;
}

