#include <iostream>
#include <vector>
#include <math.h>

struct Node {
  int data;
  struct Node *prior;
  struct Node *next;
};

class DoublyLinkList {
public:
  DoublyLinkList(std::vector<int>& arr) {
    length = arr.size();
    head_ = new Node;
    
    int j = 0;
    Node* cur_node = head_;
    while (j < length) {
      Node* node = new Node;
      node->data = arr[j];
      node->prior = cur_node;
      cur_node->next = node;
      cur_node = node;
      j++;
    }

    rear_ = cur_node;
    rear_->next = head_;
    head_->prior = rear_;
  }

  int length;
  
  int getByIndex(int index) {
    Node* node = getNodeByIndex(index);
    std::cout << "getByIndex: index=" << index << ", value=" << node->data << std::endl;
    return node->data;
  }

  Node* getNodeByIndex(int index) {
    int j = 0;
    bool is_reverse = index < 0;
    index = std::abs(index);
    Node* cur_node = is_reverse ? head_ : head_->next;

    while (j < index) {
      cur_node = is_reverse ? cur_node->prior : cur_node->next;
      j++;
    }

    return cur_node;
  }
  
  void insertByIndex(int index, int value) {
    Node* cur_node = getNodeByIndex(index);
    Node* prev_node = cur_node->prior;

    Node* node = new Node;
    node->data = value;
    node->next = cur_node;
    cur_node->prior = node;
    prev_node->next = node;
    node->prior = prev_node;
    length++;
  }

  void removeByIndex(int index) {
    Node* cur_node = getNodeByIndex(index);
    Node* prev_node = cur_node->prior;
    Node* next_node = cur_node->next;

    prev_node->next = next_node;
    next_node->prior = prev_node;
    free(cur_node);
    length--;
  }

  void traverse() {
    std::cout << "traverser start!!" << std::endl;  
    
    int j = 0;
    Node* cur_node = head_->next;

    while (j < length) {
      std::cout << cur_node->data << " ";
      cur_node = cur_node->next;
      j++;
    }

    std::cout << std::endl << "traverser end!!" << std::endl;
  }

  void r_traverse() {
    std::cout << "r_traverse start!!" << std::endl;  
    
    int j = 0;
    Node* cur_node = rear_;

    while (j < length) {
      std::cout << cur_node->data << " ";
      cur_node = cur_node->prior;
      j++;
    }

    std::cout << std::endl << "r_traverse end!!" << std::endl;
  }

protected:
  Node* head_;
  Node* rear_;
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4, 6, 8};
  DoublyLinkList dLinkList{arr};
  dLinkList.traverse();
  dLinkList.r_traverse();
  dLinkList.getByIndex(0);
  dLinkList.getByIndex(3);
  dLinkList.getByIndex(5);
  dLinkList.getByIndex(-1);
  dLinkList.getByIndex(-2);
  dLinkList.insertByIndex(0, 0);
  dLinkList.traverse();
  dLinkList.r_traverse();
  dLinkList.removeByIndex(0);
  dLinkList.traverse();
  dLinkList.r_traverse();

  return 0;
}
