// Single way link list

#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

class LinkList {
public:
  LinkList(vector<int>& arr) {
    init_(arr);
  };

  int length;

  int findByIndex(int index) {
    cout << "findByIndex: start to find element with index " << index << endl;

    int j = 0;
    Node* n = head->next;

    if (index < 0 || index >= length) {
      cout << "findByIndex: Error0!!" << endl;
      return -1;
    }

    while (n && j < index) {
      n = n->next;
      j++;
    }

    if (!n) {
      cout << "findByIndex: Error1!!" << endl;
      return -1;
    }

    cout << "findByIndex: the vuale is " << n->data << endl;

    return n->data;
  }

  void insertByIndex(int index, int elem) {
    cout << "Insert: start to insert " << elem << " to position " << index  << endl;

    int j = -1;
    Node* n = head;

    if (index < 0 || index > length) {
      cout << "Insert failed" << endl;
      return;
    }

    if (index == length) {
      n = tail;
    } else {
      while (n && j < index - 1) {
        n = n->next;
        j++;
      }
    }

    Node* node = new Node;
    node->data = elem;
    node->next = n->next;
    n->next = node;

    cout << "Inser done!!" << endl;
  }

  void deleteByIndex(int index) {
    cout << "deleteByIndex: index=" << index << endl;

    int j = -1;
    Node* n = head;

    if (index < 0 || index >= length) {
      cout << "findByIndex: Error0!!" << endl;
      return;
    }

    while (n && j < index - 1) {
      n = n->next;
      j++;
    }

    auto& temp = n->next;
    n->next = n->next->next;
    free(temp);

    cout << "deleteByIndex done!!!" << endl;
  }

  void traverse() {
    cout << "Traversing start!!" << endl;

    Node* n = head->next;
    
    while (n) {
      cout << n->data << " ";
      n = n->next;
    }

    cout << endl << "Traversing done!!" << endl;    
  }

  void reset(vector<int>& arr) {
    init_(arr);
  }

private:
  Node* head;
  Node* tail;

  void init_(vector<int>& arr) {
    Node* current_node = new Node;
    current_node->data = -1;
    current_node->next = NULL;

    length = arr.size();

    head = current_node;
    
    for (int i = 0; i < arr.size(); i++) {
      Node* node = new Node;
      node->data = arr[i];
      node->next = NULL;
      current_node->next = node;
      current_node = node;
    }

    tail = current_node;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> arr = {1, 3, 5, 7, 9, 11};
  LinkList linkList(arr);
  linkList.traverse();
  cout << "LinkList length: " << linkList.length << endl;
  linkList.insertByIndex(0, 0);
  linkList.traverse();
  linkList.reset(arr);
  linkList.insertByIndex(2, 4);
  linkList.traverse();
  linkList.reset(arr);
  linkList.insertByIndex(6, 12);
  linkList.traverse();
  linkList.reset(arr);
  linkList.findByIndex(0);
  linkList.findByIndex(3);
  linkList.findByIndex(5);
  linkList.deleteByIndex(0);
  linkList.traverse();
  linkList.reset(arr);
  linkList.deleteByIndex(3);
  linkList.traverse();
  linkList.reset(arr);
  linkList.deleteByIndex(5);
  linkList.traverse();
  return 0;
}

