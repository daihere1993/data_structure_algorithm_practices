#include <iostream>
#include <vector>

struct Node {
  int data;
  struct Node* next;
};

class LinkQueue {
public:
  LinkQueue(std::vector<int>& arr) {
    length = arr.size();
    front_node_ = new Node;

    Node* cur_node = front_node_;

    for (int i = 0; i < length; i++) {
      Node* node = new Node;
      node->data = arr[i];
      cur_node->next = node;
      cur_node = node;
    }

    rear_node_ = cur_node;
    rear_node_->next = nullptr;
  }

  void enqueue(int value) {
    length++;

    Node* node = new Node;
    node->data = value;
    rear_node_->next = node;
    rear_node_ = node;
  }

  int dequeue() {
    if (length == 0) {
      std::cout << "Error1" << std::endl;
      return -1;
    }

    length--;
    Node* de_node = front_node_;
    int ret = de_node->data;
    front_node_ = front_node_->next;
    free(de_node);

    return ret;
  }

  void traverse() {
    std::cout << "traverse:: start!!" << std::endl;

    int j = 0;
    Node* cur_node = front_node_->next;
    while (j < length) {
      std::cout << cur_node->data << " ";
      cur_node = cur_node->next;
      j++;
    }

    std::cout << std::endl;
    std::cout << "traverse:: done!!" << std::endl;
  }

  int length;
private:
  Node* front_node_;
  Node* rear_node_;
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4};
  LinkQueue lQueue(arr);
  lQueue.traverse();
  lQueue.enqueue(5);
  lQueue.enqueue(6);
  lQueue.traverse();
  lQueue.dequeue();
  lQueue.dequeue();
  lQueue.traverse();

  return 0;
}

