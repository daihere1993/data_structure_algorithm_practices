#include <iostream>
#include <vector>

#define MAXSIZE 1000

struct Node {
  int data;
  // cursor(游标) 
  int cur;
};

class StatisticLinkList {
public:
  StatisticLinkList() : length(0) {
    init_();
  }

  StatisticLinkList(std::vector<int>& arr) {
    resetWithVector(arr);
  }

  int length;

  void traverse() {
    std::cout << "Start traverse..." << std::endl;

    int j = 1;
    Node* cur_node = data_[MAXSIZE - 1];
    int end_cur = data_[0]->cur;

    while (j <= length) {
      cur_node = data_[cur_node->cur];
      j++;
      std::cout << cur_node->data << " ";
    }

    std::cout << std::endl;
    std::cout << "End traverse..." << std::endl;
  }

  int getByIndex(int index) {
    std::cout << "getByInde: index=" << index << std::endl;

    int j = 0;
    // Get the first node
    Node* n = data_[data_[MAXSIZE - 1]->cur];

    while (j < index) {
      n = data_[n->cur];
      j++;
    }

    std::cout << "getByindex: value=" << n->data << std::endl;
    return n->data;
  }

  void insertByIndex(int index, int value) {
    std::cout << "insertByIndex: index=" << index << ", value=" << value << std::endl;

    int j = -1;
    Node* n = data_[MAXSIZE - 1];

    while (j < index - 1) {
      n = data_[n->cur];
      j++;
    }

    int prev_index = j;
    Node* prev_node = n;
    int next_index = n->cur;
    int current_index = malloc_();
    Node* current_node = data_[current_index];
    
    prev_node->cur = current_index;
    current_node->data = value;
    current_node->cur = next_index;
    length++;

    std::cout << "insertByIndex done!!!"; 
  }

  void deleteByIndex(int index) {
    std::cout << "deleteByIndex: index=" << index << std::endl;

    int j = -1;
    Node* n = data_[MAXSIZE - 1];

    while (j < index - 1) {
      n = data_[n->cur];
      j++;
    }

    Node*& prev_node = n;
    Node*& curr_node = data_[prev_node->cur];

    int curr_index = prev_node->cur;
    int next_index = curr_node->cur;

    prev_node->cur = next_index;
    free_(curr_index);
    length--;

    std::cout << "deleteByIndex done!!";
  }

  void resetWithVector(std::vector<int>& arr) {
    init_();
    length = arr.size();

    for (int i = 1; i <= length; i++) {
      data_[i]->data = arr[i - 1];
    }
    data_[0]->cur = length + 1;
    data_[MAXSIZE - 1]->cur = 1;
  }

private:
  Node* data_[MAXSIZE];
  Node* head_node_;
  Node* tail_node_;

  void init_() {
    for (int i = 0; i < MAXSIZE; i++) {
      Node* node = (Node*)malloc(sizeof(Node));
      node->cur = i + 1;
      data_[i] = node;
    }
    data_[MAXSIZE - 1]->cur = 0;

    head_node_ = data_[0];
    tail_node_ = data_[MAXSIZE - 1];
  }

  int malloc_() {
    int i = head_node_->cur;
    head_node_->cur = data_[i]->cur;
    return i;
  }

  void free_(int index) {
    Node* curr_node = data_[index];
    curr_node->cur = head_node_->cur;
    head_node_->cur = index;
  }
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4, 6, 8};

  StatisticLinkList linkList(arr);
  linkList.traverse();
  linkList.getByIndex(0);
  linkList.getByIndex(3);
  linkList.getByIndex(arr.size() - 1);
  linkList.insertByIndex(0, 0);
  linkList.traverse();
  linkList.resetWithVector(arr);
  linkList.insertByIndex(4, 5);
  linkList.traverse();
  linkList.resetWithVector(arr);
  linkList.insertByIndex(5, 7);
  linkList.traverse();
  linkList.resetWithVector(arr);
  linkList.deleteByIndex(0);
  linkList.traverse();
  linkList.resetWithVector(arr);
  linkList.deleteByIndex(4);
  linkList.traverse();
  linkList.resetWithVector(arr);
  linkList.deleteByIndex(5);
  linkList.traverse();
  linkList.resetWithVector(arr);
  
  return 0;
}

