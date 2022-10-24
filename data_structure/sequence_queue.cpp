#include <iostream>
#include <vector>

#define MAXSIZE 5

class SequenceQueue {
public:
  SequenceQueue(std::vector<int>& arr) {
    length = arr.size();
    front_ = 0;
    rear_ = length - 1;

    for (int i = 0; i < length; i++) {
      data_[i] = arr[i];
    }
  }

  void enqueue(int value) {
    if (length == MAXSIZE)
      return;

    length++;
    rear_ = (rear_ + 1)%MAXSIZE;
    data_[rear_] = value;
  }

  int dequeue() {
    if (length == 0) return -1;

    length--;
    int ret = data_[front_];
    data_[front_] = 0;
    front_ = (front_ + 1)%MAXSIZE;

    return ret;
  }

  void traverse() {
    std::cout << "traverse:: start!!" << std::endl;

    int j = 0;
    while (j < length) {
      int index = front_ + j;

      if (index >= MAXSIZE) {
        index = MAXSIZE - index;
      }
      std::cout << data_[index] << " ";
      j++;
    }

    std::cout << std::endl;
    std::cout << "traverse:: done!!" << std::endl;
  }

  int length;
private:
  int front_;
  int rear_;
  int data_[MAXSIZE];
};

int main(int argc, char const *argv[])
{
  std::vector<int> arr{1, 2, 3, 4};
  SequenceQueue sQueue(arr);
  sQueue.traverse();
  sQueue.enqueue(5);
  sQueue.dequeue();
  sQueue.enqueue(6);
  sQueue.traverse();
  return 0;
}
