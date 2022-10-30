#include <iostream>
#include <string>

typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode {
  char data;
  PointerTag ltag, rtag;
  struct BiThrNode *lchild, *rchild;
} *BiThrTree;

void createBiThrTree(std::string& source, BiThrTree& t, int& index) {
  if (index == -1) {
    t = new BiThrNode;
    t->ltag = Link;
    t->rtag = Thread;
    index++;
    createBiThrTree(source, t->lchild, index);
  } else {
    char data = source[index++];
    if (data == '#') {
      t = nullptr;
    } else {
      t = new BiThrNode;
      t->data = data;
      createBiThrTree(source, t->lchild, index);
      if (t->lchild) t->rtag = Link;
      createBiThrTree(source, t->rchild, index);
      if (t->rchild) t->rtag = Link;
    }
  }
}

// 中序线索化
BiThrTree pre = nullptr;
void inThreading(BiThrTree& t) {
  if (t) {
    inThreading(t->lchild);
    if (not t->lchild) {
      t->lchild = pre;
      t->ltag = Thread;
    }
    if (not pre->rchild) {
      pre->rchild = t;
      pre->rtag = Thread;
    }
    pre = t;
    inThreading(t->rchild);
  }
}

void inorderThreading(BiThrTree& t) {
  pre = t;
  inThreading(t->lchild);
  pre->rchild = t;
  pre->rtag = Thread;
  t->rchild = pre;
}

void visit(char data) {
  std::cout << data << " ";
}

void inorderTraverse_thr(BiThrTree& t) {
  BiThrTree p;
	p = t->lchild; /* p指向根结点 */
	while(p != t)
	{ /* 空树或遍历结束时,p==T */
		while(p->ltag == Link)
			p=p->lchild;
		visit(p->data);
		while(p->rtag == Thread && p->rchild != t)
		{
			p=p->rchild;
			visit(p->data); /* 访问后继结点 */
		}
		p=p->rchild;
	}

  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  int index = -1;
  BiThrTree t;
  std::string str{"ABDH##I##EJ###CF##G##"};
  createBiThrTree(str, t, index);
  inorderThreading(t);
  inorderTraverse_thr(t);
  return 0;
}
