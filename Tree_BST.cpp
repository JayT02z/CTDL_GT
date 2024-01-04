#include <iostream>
#include <string>

struct NODE {
	int data;

	NODE* pleft;
	NODE* pright;
};

typedef NODE* tree;

NODE* createNode(int x) {
	NODE* p = new NODE;

	if (p == NULL) return p;

	p->data = x;
	p->pleft = NULL;
	p->pright = NULL; 

	return p;
}

void createTree(tree& t, int x) {
	NODE* p = createNode(x);
	if (t == NULL) t = p;
	else {
		if (t->data == x) return;
		else if (t->data > x) createTree(t->pleft, x);
		else
			createTree(t->pright, x);
	}
}

int delNode(tree& t, int x) {
	if (t == NULL) return 0;
	else if (t->data > x) return delNode(t->pleft, x);
	else if (t->data < x) return delNode(t->pright, x);
	else {
		NODE* p = t;
		
		if (t->pleft == NULL) t = t->pright; //Node chi co cay con phai
		else if (t->pright == NULL) t = t->pleft; //Node chi co cay con trai
		else {
			NODE* s = t,
				* q = s->pleft; //s la cha cua q, q la Node phai nhat cua cay con trai cua p
			while (q->pright != NULL) {
				s = q;
				q = q->pright;
			}
			p->data = q->data;
			s->pright = q->pleft;
			delete q;
		}
	}

	return 1;
}

int main() {

}