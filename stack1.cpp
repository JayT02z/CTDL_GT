#include<iostream>
#include<string>
using namespace std;

struct SV
{
    string iD;
    string name;
    float score;
};

struct NODE{
    SV data;
    NODE *next;
};

struct STACK{
    NODE *top;
};

void Init(STACK &s){
    s.top = NULL;
}

NODE* CreateNode (SV x) {
    NODE *p;
    p = new NODE;

    if (p == NULL) {
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

int IsEmpty(STACK s){
    return s.top == NULL;
}

void Push(STACK &s, NODE *NewNode){
    NewNode->next = s.top;
    s.top = NewNode;
}

SV Pop(STACK &s){
    SV x;
    NODE *p = NULL;
    if (!IsEmpty(s)){
        p = s.top;
        x = p -> data;
        s.top = s.top -> next;
        delete p;
    }
    return x;
}

void Input(STACK &s) {
    SV x;
    NODE *p;
    cout << "Nhap ma sinh vien: ";
    getline(cin, x.iD);

    cout << "Nhap ten sinh vien: ";
    getline(cin, x.name);

    cout << "Nhap diem: ";
    cin >> x.score;
    cin.ignore();
    p = CreateNode(x);
    Push(s, p);
}

int menu() {
    cout << "________QUAN LY SINH VIEN________" << endl;
    cout << "1. Them sinh vien vao STACK" << endl;
    cout << "2. In cac sinh vien co trong STACK" << endl;
    cout << "3. Lay thong tin cua sinh vien dau ngan xep" << endl;
    cout << "=================================" << endl;
    int option;
    cout << "\nMoi nhap lua chon: ";
    cin >> option;
    return option;
}

void Output(STACK s) {
    for(NODE *p = s.top; p != NULL; p = p->next){
        cout << "______________________________ \n";
        cout << "Ma: "<<p->data.iD << endl;
        cout << "Ten: "<<p->data.name << endl;
        cout << "Diem: "<<p->data.score << endl;
        cout << "______________________________ \n";
        cout << endl;
    }
}

int main()
{
    STACK s;
    Init(s);
    SV stu;
    while (true)
    {
        system("cls");
        int chose = menu();
        cin.ignore();

        switch (chose) {
        case 1:
            Input(s);
            break;
        case 2:
            Output(s);
            break;
        case 3:
            stu = Pop(s);
            cout << "Ma sinh vien: " << stu.iD << endl;
            cout << "Ten sinh vien: " << stu.name << endl;
            cout << "Diem sinh vien: " << stu.score << endl;
            break;
        default:
            cout << "Lua chon khong hop le!!!";
        }
        cout << "Ban co muon tiep tuc chuong trinh 1/0: ";
        bool is_continue;
        cin >> is_continue;

        if (!is_continue) {
            break;
        }
    }
    return 0;
}

