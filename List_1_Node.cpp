#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

Node* CreateNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
		return p;
	p->data = x;
	p->pNext = NULL;
	return p;
}

typedef Node* List;

void CreateList(List& L)
{
	L = NULL;
}

void Output_List(List L)
{
	Node* p = L;
	cout << "\n[ ";
	while (p != NULL) {
		cout << p->data << " , ";
		p = p->pNext;
	}
	cout << "]";
}

int LenList(List L)
{
	Node* p = L;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}

int Search(List L, int x)
{
	Node* p = L;
	int i = 1;
	while (p != NULL && p->data != x)
	{
		p = p->pNext;
		i++;
	}
	if (p != NULL)
		return i; //tra ve vi tri tim thay
	else
		return 0; //tra ve 0 neu kh tim thay
}

void InsertFirst(List& L, int x)
{
	Node* p = CreateNode(x); //tao node p chua du lieu x
	p->pNext = L; //cho p tro den Node ma L dang tro
	L = p; //cho L tro ve p
}

void InsertLast(List& L, int x)
{
	Node* p = CreateNode(x);
	if (L != NULL) { //truong hop ds kh rong
		Node* Q = L; //tao Node Q de duyet ds
		while (Q->pNext != NULL)
			Q = Q->pNext; //cho node Q tro den cuoi
		Q->pNext = p; //cho node cuoi tro ve P
	}
	else
		L = p;
}

int InsertPosition(List& L, int x, int pos)
{
	Node* p, * Q = L;
	int i = 1;
	p = CreateNode(x); //tao Node p
	if (pos <= 1)
		InsertFirst(L, x); //chen vao vi tri dau tien
	else if (pos > LenList(L))
		InsertLast(L, x);//chen vao vi tri cuoi ds
	else {
		while (i != pos - 1) {
			i++;
			Q = Q->pNext; //den Node k - 1
		}
		p->pNext = Q->pNext;
		Q->pNext = p;
	}
	return 1;
}

int DeleteFirst(List& L, int& x)
{
	if (L == NULL)
		return 0; // Xoa that bai
	Node* Q = L;//cho Node Q tro den dau ds
	x = L->data;//lay du lieu de dung (neu can)
	L = L->pNext; //L tro den Node thu 2 trong ds
	delete Q; //giai phong vung nho Q
	return 1; //Xoa thanh cong
}

int DeleteLast(List& L, int& x)
{
	if (L == NULL)
		return 0; // Xoa that bai
	if (L->pNext == NULL) {
		DeleteFirst(L, x); return 1; //Xoa thanh cong
	}
	Node* p = L, * Q;
	while (p->pNext->pNext != NULL)
		p = p->pNext;
	Q = p->pNext;
	x = Q->data;
	p->pNext = NULL;
	delete Q; //Giai phong vung nho
	return 1; //Xoa thanh cong
}

int DeletePosition(List& L, int& x, int pos) {
	if (pos < 1 || pos > LenList(L))
		return 0; //xoa that bai
	if (pos == 1)
		DeleteFirst(L, x);
	else {
		Node* p = L, * Q;
		int i = 1;
		while (i != pos - 1) {
			p = p->pNext;
			i++;
		}
		Q = p->pNext;
		p->pNext = Q->pNext;
		x = Q->data;
		delete Q;
	}
	return 1; //xoa thanh cong
}

int DeleteEqual(List& L, int x) {
	if (L == NULL)
		return 0;
	while (Search(L, x) != 0)
		DeletePosition(L, x, Search(L, x)); //trong khi van tim thay x thi tiep tuc xoa
	return 1; // Xoa thanh cong
}

void InputList(List& L) {
	int x;
	cout << "x = ";
	cin >> x;
	InsertFirst(L, x);
}

int menu() {
	cout << "________MENU________" << endl;
	cout << "1. Them phan tu vao danh sach lien ket" << endl;
	cout << "2. In cac phan tu co trong danh sach" << endl;
	cout << "3. In do dai cua danh sach" << endl;
	cout << "4. Tim kiem phan tu trong danh sach " << endl;
	cout << "5. Xoa phan tu trong danh sach " << endl;
	cout << "=====================" << endl;
	int option;
	cout << "\nMoi nhap lua chon: ";
	cin >> option;
	return option;
}

int main()
{
	List L;
	CreateList(L);
	while (true)
	{
		system("cls");
		int chose = menu();

		switch (chose) {
		case 1:
			int element;
			cout << "Moi nhap: ";
			cin >> element;
			InsertLast(L, element);
			break;
		case 2:
			Output_List(L);
			break;
		case 3:
			cout << "\nDo dai cua danh sach la: " << LenList(L);
			break;
		case 4:
			int eleFind;
			cout << "Nhap phan tu muon tim kiem: ";
			cin >> eleFind;
			if (Search(L, eleFind) == 0)
				cout << "Phan tu khong co trong danh sach" << endl;
			else
				cout << "Phan tu o vi tri thu " << Search(L, eleFind) << " trong danh sach" << endl;
			break;
		case 5:
			int delElement;
			cout << "Nhap phan tu muon xoa: ";
			cin >> delElement;
			if (DeleteEqual(L, delElement) == 1)
				cout << "Da xoa thanh cong!" << endl;
			else
				cout << "Xoa that bai! (Phan tu muon xoa khong co trong danh sach)" << endl;
			break;
		default:
			cout << "Lua chon khong hop le!!!!";
		}
		cout << "Ban co muon tiep tuc chuong trinh 1/0: ";
		bool is_continue;
		cin >> is_continue;

		if (!is_continue) {
			break;
		}
	}
}
