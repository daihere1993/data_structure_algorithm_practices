#include <iostream>
#include <vector>

using namespace std;

class SqList {
public:
  SqList(): length(0) {}
  int data[20];
  int length;

  int findByIndex(int index) {
    return data[index];
  }

  void insertByIndex(int index, int elem) {
    if (index < length) {
      int k = length - 1;
      while (k >= index) {
        data[k + 1] = data[k];
        k--;
       }
    }

    data[index] = elem;
    length++;
  }

  void deleteByIndex(int index) {
    for (int i = index; i < length - 1; i++) {
      data[i] = data[i + 1];
    }
    data[length - 1] = 0;
    length--;
  }

  void traverse() {
    cout << "The whole list is: ";
    for (int i = 0; i < length; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main(int argc, char const *argv[])
{
  SqList part;
  SqList list;
  list.insertByIndex(0, 1);
  list.insertByIndex(1, 2);
  list.insertByIndex(2, 3);
  list.traverse();
  cout << "first element: " << list.findByIndex(0) << endl;
  cout << "second element: " << list.findByIndex(1) << endl;
  list.deleteByIndex(0);
  list.traverse();
  
  return 0;
}

