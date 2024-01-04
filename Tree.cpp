#include<iostream>

using namespace std;

struct SV
{
	string ma;
    string ten;
    float diem;
};

struct Node 
{
	SV Key;
	Node *Left,*Right;
};

typedef Node *Tree;

void Create(Tree &T) 
{
	T=NULL;
}

Node* CreateNode(SV x) 
{
	Node *p=new Node;
	p->Key = x;
	p->Left = p->Right =NULL;
	return p;
}

int InsNode(Tree &T, SV x) 
{
	if(T!=NULL) 
	{
	if(T->Key.ma == x.ma)
		return 0;
	if(T->Key.ma > x.ma)
		return InsNode(T->Left, x);
	else 
		return InsNode(T->Right, x);
	}
	T = CreateNode(x);
	return 1;
}

/*
int NLR(Tree T, int &dem) 
{
	if(T != NULL) 
	{
	if (isPrime(T->Key))
	{
		cout<<T->Key<<" ";
		dem+=1;
	}
	NLR (T->Left, dem);
	NLR(T->Right, dem);
	}
	return dem;
}
*/

void LRN(Tree T) 
{
	if(T != NULL) 
	{
		LRN(T->Left);
		LRN(T->Right);
		
		cout<<"############################## \n";
        cout<<"Ma: "<<T->Key.ma<<endl;
        cout<<"Ten: "<<T->Key.ten<<endl;
        cout<<"Diem: "<<T->Key.diem<<endl;
        cout<<"############################## \n";
        cout<<endl;
	}
}

int DelNode(Tree &T, SV x) 
{
	if (T==NULL) return 0;
	else if (T->Key.ma>x.ma) 
		return DelNode(T->Left, x);
	else if (T->Key.ma<x.ma) 
		return DelNode(T->Right, x);
	else {//T->Key == x
	Node *P=T;
	if (T->Left==NULL) 
		T=T->Right;
	else if (T->Right==NULL) 
		T=T->Left; 
	else 
	{ 
		Node *S = T, 
		*Q=S->Left;
	while (Q->Right!=NULL) 
	{
		S=Q; 
		Q=Q->Right;
	}
	P->Key=Q->Key;
	S->Right=Q->Left;
	delete Q;
	}
}
return 1;
}

Node* Search(Tree T, string masv) 
{
	Node *p = T;
	while(p!=NULL) 
	{
		if(masv==p->Key.ma)
	return p; 
	if(masv<p->Key.ma)
		p=p->Left; 
	if(masv>p->Key.ma)
		p=p->Right; 
	}
	return NULL; 
}




void Input(Tree &T)
{
        SV x;
        Node *p;
        cout<<"Nhap ma sinh vien: ";
        cin>>x.ma;
        cout<<"Nhap ten sinh vien: ";
        cin>>x.ten;
        cout<<"Nhap diem: ";
        cin>>x.diem;
        cin.ignore();
        InsNode(T,x);
}

int main()
{
	Tree T;
	Create(T);
	int option=1;
	while (option>0 && option<=3)
	{
    cout<<"===============QUAN LY SINH VIEN===============\n";
    cout<<"1.Them 1 sinh vien vao cay \n";
    cout<<"2.Xuat toan bo du lieu \n";
    cout<<"3.tim kiem thong tin dua theo ma sinh vien \n";
    cout<<"================================================\n";
    cout<<"Nhap lua chon cua ban: ";
    cin>>option;
    switch (option)
	{
	case 1 :
		{
			Input(T);
			break;
		}
	case 2 :
		{
			LRN(T);
			break;
		}
	case 3:
		{
			string masv;
			cout<<"Nhap ma sv muon tim: ";
			cin>>masv;
			
			Node* s=Search(T,masv);
			if (s=NULL)
				cout<<"khong co thong tin sinh vien nay";
			else
				cout<<s->Key.ten;
			break;
		}
	}
	cout<<"\n";
	cout<<"Press Enter to continue...";
	cin.get();
	cin.ignore();
	system("cls");
	}
	return 0;
}
