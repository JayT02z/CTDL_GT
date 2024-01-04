#include<iostream>
#include<string>

using namespace std;

struct HANG
{
	int ma;
	string ten;
	string trangThai;
	int soLuong;
	int donGia;
	float thanhTien;
};

struct NODE
{
	HANG data;
	NODE *pnext;
};

typedef NODE* LIST;

NODE* CreateNode(HANG h)
{
	NODE *p= new NODE;
	if (p == NULL)
		return NULL;
	p->data = h;
	p->pnext = NULL;
	return p;
}



void CreateList(LIST &l)
{
	l = NULL;
}

void Insert(LIST &l, HANG h)
{
	NODE *P = CreateNode(h);
		if (l != NULL) 
		{
			NODE *Q = l; 
			while (Q->pnext != NULL) 
				Q = Q->pnext; 
				Q->pnext = P; 
		}
	else  
		l = P;
}

void OutputList(LIST l)
{ 
	NODE *P = l;
	while(P != NULL)
	{
		cout<<" **************************************** \n";
		cout<<"Ma san pham: "<<P->data.ma <<"\n ";
		cout<<"Ten san pham: "<<P->data.ten <<"\n";
		cout<<"Trang thai san pham: "<<P->data.trangThai <<"\n";
		cout<<"So luong san pham: "<<P->data.soLuong <<"\n";
		cout<<"Don gia: "<<P->data.donGia <<"\n";
		cout<<"Thanh tien: "<<P->data.soLuong*P->data.donGia <<"\n";
		P = P->pnext;
	}
	cout<<" **************************************** \n";
}

int SumOfQuantity(LIST l)
{
	int tong=0;
	NODE *P = l;
	while(P!=NULL)
	{
	tong+=P->data.soLuong;
	P = P->pnext;
	}
	return tong;
}

void InputList(LIST &l)
{
	HANG h;
	cout<<"Nhap ma: ";
	
	cin>>h.ma;
	//getline(cin,h.Ma);
	cout<<"Nhap ten: ";
	cin.ignore();
	getline(cin,h.ten);
	cout<<"Nhap trang thai (con/het): ";
	getline(cin,h.trangThai);
	cout<<"Nhap so luong : ";
	cin>>h.soLuong;
	cout<<"Nhap don gia: ";
	cin>>h.donGia;
	Insert(l, h);
	
}

void TimMaSanPham(LIST l, int masp)
{
	NODE *P = l;
	while(P!=NULL)
	{
	if (masp==P->data.ma)
		{
		cout<<" **************************************** \n";
		cout<<"Ma san pham: "<<P->data.ma <<"\n ";
		cout<<"Ten san pham: "<<P->data.ten <<"\n";
		cout<<"Trang thai san pham: "<<P->data.trangThai <<"\n";
		cout<<"So luong san pham: "<<P->data.soLuong <<"\n";
		cout<<"Don gia: "<<P->data.donGia <<"\n";
		cout<<"Thanh tien: "<<P->data.soLuong*P->data.donGia <<"\n";
		cout<<" **************************************** \n";
		}
	P = P->pnext;
	}
}

void XuatSanPhamCon(LIST l)
{
	NODE *P = l;
	while(P!=NULL)
	{
	if (P->data.trangThai=="con")
		{
		cout<<" **************************************** \n";
		cout<<"Ma san pham: "<<P->data.ma <<"\n ";
		cout<<"Ten san pham: "<<P->data.ten <<"\n";
		cout<<"Trang thai san pham: "<<P->data.trangThai <<"\n";
		cout<<"So luong san pham: "<<P->data.soLuong <<"\n";
		cout<<"Don gia: "<<P->data.donGia <<"\n";
		cout<<"Thanh tien: "<<P->data.soLuong*P->data.donGia <<"\n";
		cout<<" **************************************** \n";
		}
	P = P->pnext;
	}
}

int DelFirst (LIST &l) 
{
	if (l==NULL) 
		return 0;
	NODE *Q=l;  
	l=l->pnext; 
	delete Q; 
	return 1; 
}

int DelPos (LIST &l, int k,int listlen) 
{
	if (k<1 || k>listlen )
		return 0; 
	if (k==1) DelFirst(l); 
	else 
	{
		NODE *P=l, *Q; 
		int i=1;
	while (i!=k-1) 
	{ 
		P=P->pnext; 
		i++; 
	}
	Q=P->pnext; 
	P->pnext=Q->pnext;  
	delete Q;
	} 
	return 1; 
}

//int XoaSanPhamHet(LIST &l,int listlen)
//{
//	NODE *P = l;
//	int i=1;
//	while(P!=NULL)
//	{
//		if (P->data.TrangThai == "het") {
//			cout << "\n" << DelPos(l, i, listlen);
//		}
//		i++;
//		P = P->pnext;
//	}
//	return 1;
//}

void XoaSanPhamHet(LIST& l)
{
	NODE* P = l;
	NODE* Q = NULL;
	int flag = 0;
	while (P != NULL)
	{
		if (P->data.trangThai == "het")
		{
			if (Q == NULL)
			{
				l = P->pnext;
				delete P;
				P = l;
				flag = 1;
			}
			else
			{
				Q->pnext = P->pnext;
				delete P;
				P = Q->pnext;
			}
		}
		else
		{
			Q = P;
			P = P->pnext;
		}
	}
	if (flag == 1)
		cout << "Xoa thanh cong!!";
}





int main()
{
	LIST l;
	CreateList(l);
	int LuaChon=1;
	int listlen=0;
	while (LuaChon!=0 && LuaChon<=6)
	{
	cout<<" =====================MENU====================== \n";
	cout<<"1/Nhap danh sach hang hoa \n";
	cout<<"2/Xuat danh sach hang hoa \n";
	cout<<"3/So luong hang hoa \n";
	cout<<"4/Tim kiem hang hoa \n";
	cout<<"5/Xuat danh sach hang hoa o trang thai con \n";
	cout<<"6/Xoa hang hoa o trang thai het \n";
	cout<<" =============================================== \n";
	cout<<"Nhap lua chon cua ban: ";
	cin>>LuaChon;
	switch (LuaChon)
	{
	case 1 :
		{
			InputList(l);
			listlen++;
			break;
		}
	case 2 :
		{
			OutputList(l);
			break;
		}
	case 3 :
		{
			cout<<"So luong hang hoa cac loai la: "<<SumOfQuantity(l)<<"\n";
			break;
		}
	case 4 :
		{
			int masp;
			cout<<"Nhap ma san pham muon tim: ";
			cin>> masp;
			TimMaSanPham(l,masp);
			break;
		}
	case 5 :
		{
			XuatSanPhamCon(l);
			break;
		}
	case 6 :
		{
			XoaSanPhamHet(l);
			break; 
		}
	}
	
	cout<<"\n";
	cout<<listlen;
	cout<<"Press any key to continue...";
	cin.ignore();
	cin.get();

	
	system("cls");
}
	
	return 0;
}
