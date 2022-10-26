#include <iostream>
#include <string>


struct Node {
  char data;
  struct Node *lchild, *rchild;
};

typedef Node* BiTree;

void preorderTraverse(BiTree& t) {
  if (t == nullptr)
    return;
  std::cout << t->data;
  preorderTraverse(t->lchild);
  preorderTraverse(t->rchild);
}

void inorderTraverse(BiTree& t) {
  if (t == nullptr)
    return;
  inorderTraverse(t->lchild);
  std::cout << t->data;
  inorderTraverse(t->rchild);
}

void postorderTraverse(BiTree& t) {
  if (t == nullptr)
    return;
  postorderTraverse(t->lchild);
  postorderTraverse(t->rchild);
  std::cout << t->data;
}

void createBiTree(std::string& source, BiTree& t, int& i) {
  char data = source[i++];
  if (data == '#')
    t = nullptr;
  else {
    t = new Node;
    t->data = data;
    createBiTree(source, t->lchild, i);
    createBiTree(source, t->rchild, i);
  }
}

int main(int argc, char const *argv[])
{
  int i = 0;
  BiTree t;
  std::string str{"ABDH#K###E##CFI###G#J##"};
  createBiTree(str, t, i);
  std::cout << "PreorderTraverse: ";
  preorderTraverse(t);
  std::cout << std::endl;
  std::cout << "InorderTraverse: ";
  inorderTraverse(t);
  std::cout << std::endl;
  std::cout << "PostorderTraverse: ";
  postorderTraverse(t);
  std::cout << std::endl;
  return 0;
}
