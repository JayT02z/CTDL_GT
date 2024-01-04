#include<iostream>
#include<string>
using namespace std;

struct SV {
	string ma;
	string ten;
	float diem;
};

struct NODE {
    SV data;
    NODE *next;
};

struct QUEUE {
    NODE *front;
    NODE *rear;
};

void Init(QUEUE &q) {
    q.front = NULL;
    q.rear = NULL;
}

NODE* CreateNode (SV stu) 
{
    NODE *p;
    p = new NODE;

    if (p==NULL) 
    	return NULL;
    p->data = stu;
    p->next = NULL;
    return p;
}

int IsEmpty(QUEUE q) {
    if (q.front == NULL)
        return 1;

    return 0;
}

void Add(QUEUE &q, NODE *NewNode) {

    if(q.front == NULL){
        q.front = NewNode;
        q.rear = NewNode;
    }
    else{
        q.rear->next = NewNode;
        q.rear = NewNode;
    }
}

SV Remove(QUEUE &q){
    SV stu;
    NODE *p = NULL;
    if (!IsEmpty(q)){
        p = q.front;
		stu = p->data;
        q.front = q.front->next;
        delete p;

        if (q.front==NULL){
            q.rear = NULL;
        }
    }
    return stu;
}

void Input(QUEUE &q)
{
        SV stu;
        NODE *p;
        cout << "Nhap ma sinh vien: ";
        getline(cin, stu.ma);

        cout << "Nhap ten sinh vien: ";
        getline(cin, stu.ten);

        cout << "Nhap diem: ";
        cin >> stu.diem;
        cin.ignore();

        p = CreateNode(stu);
        Add(q,p);
}

void Output(QUEUE q)
{

    for(NODE *p = q.front; p!= NULL; p=p->next)
	{
		cout << "****************************** \n";
        cout << "Ma: " << p->data.ma << endl;
        cout << "Ten: " << p->data.ten << endl;
        cout << "Diem: " << p->data.diem << endl;
        cout << "****************************** \n";
        cout << endl;
        
    }
}

int menu() {
    cout << "________QUAN LY SINH VIEN________" << endl;
    cout << "1. Them sinh vien vao QUEUE" << endl;
    cout << "2. In cac sinh vien co trong QUEUE" << endl;
    cout << "3. Lay thong tin cua sinh vien dau QUEUE ra ngoai" << endl;
    cout << "=================================" << endl;
    int option;
    cout << "\nMoi nhap lua chon: ";
    cin >> option;
    return option;
}

int main() {

    QUEUE q;
    Init(q);
    SV stu;
    while (true)
    {
        system("cls");
        int chose = menu();
        cin.ignore();

        switch (chose) {
        case 1:
            Input(q);
            break;
        case 2:
            Output(q);
            break;
        case 3:
            stu = Remove(q);
            cout << "Sinh vien duoc lay ra: " << endl;
            cout << "Ma sinh vien: " << stu.ma << endl;
            cout << "Ten sinh vien: " << stu.ten << endl;
            cout << "Diem sinh vien: " << stu.diem << endl;
            break;
        default:
            cout << "Lua chon khong hop le!!!";
        }
        cout << "Ban co muon tiep tuc chuong trinh 1/0: ";
        bool is_continue;
        cin >> is_continue;

        if (!is_continue)
            break;
    }

    return 0;
}
