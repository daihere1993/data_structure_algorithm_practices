#include <iostream>
#include <vector>

struct Node {
  int data;
  struct Node* next;
};

class CircularLinkList {
public:
  CircularLinkList(std::vector<int>& arr) {
    length = arr.size();
    head = new Node();

    int i = 0;
    Node* cur_node = head;
    while (i < length) {
      Node* n = new Node();
      n->data = arr[i];
      cur_node->next = n;
      cur_node = n;
      i++;
    }

    cur_node->next = head;
    rear = cur_node;
  }

  CircularLinkList(CircularLinkList& cLinkList1, CircularLinkList& cLinkList2) {
    length = cLinkList1.length + cLinkList2.length;
    head = new Node();

    int i = 0, j = 0;
    Node* cur_node = head;
    while (i < cLinkList1.length) {
      Node* n = new Node;
      n->data = cLinkList1.getByindex(i);
      cur_node->next = n;
      cur_node = n;
      i++;
    }

    while (j < cLinkList2.length) {
      Node* n = new Node;
      n->data = cLinkList2.getByindex(j);
      cur_node->next = n;
      cur_node = n;
      j++;
    }

    cur_node->next = head;
    rear = cur_node;
  }

  int getByindex(int index) {
    int j = 0;
    Node* n = head->next;

    while (j < index) {
      n = n->next;
      j++;
    }

    return n->data;
  }

  void traverse() {
    std::cout << "traverse:: start!!" << std::endl;

    int i = 0;
    Node* n = head->next;

    if (!n) {
      std::cout << "Error1" << std::endl;
      return;
    }

    while (n && i < length) {
      std::cout << n->data << " ";
      n = n->next;
      i++;
    }

    std::cout  << std::endl;
    std::cout << "traverse:: end!!" << std::endl;
  }

  void concat(CircularLinkList& cLinkList) {
    rear->next = cLinkList.head->next;
    free(cLinkList.head);
    rear = cLinkList.rear;
    rear->next = head;

    length = length + cLinkList.length;
  }

  int length;
  Node* head;
  Node* rear;
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr1{1, 2, 3, 4, 6, 8};
  CircularLinkList cLinkList1{arr1};
  cLinkList1.traverse();

  std::vector<int> arr2{10, 11, 12};
  CircularLinkList cLinkList2{arr2};
  cLinkList2.traverse();

  CircularLinkList cLinkList3{cLinkList1, cLinkList2};
  cLinkList3.traverse();

  cLinkList1.concat(cLinkList2);
  cLinkList1.traverse();
  return 0;
}
