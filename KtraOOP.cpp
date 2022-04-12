#include<iostream.h>
#include<iomanip.h>
using namespace std;
class SANPHAM
{
	protected:
	char ma[20],ten[20];
	float dongia;
	public:
	SANPHAM(char *ma=" ", char *ten=" ", float dongia=0)
	{
		strcpy(this->ma,ma);
		strcpy(this->ten,ten);
		this->dongia=dongia;
	}
	~SANPHAM(){}
	void nhap()
	{
		fflush(stdin);
		cout<<"Nhap ma hang hoa: "; cin.getline(ma,20);
		cout<<"Nhap ten hang hoa: "; cin.getline(ten,20);
		cout<<"Nhap don gia: "; cin>>dongia;
	}
	void xuat()
	{
		cout <<setw(5)<<ma
			<<setw(8)<<ten
			<<setw(9)<<dongia;
	}
	char *getMa()
	{
		return ma;
	}
	float getDG()
	{
		return dongia;
	}
	char *getTen()
	{
		return ten;
	}
};
struct HSD
{
	int ngay,thang,nam;
};
class THUOC:public SANPHAM
{
	private:
	char loaithuoc[20], thanhphan[20];
	HSD hsd;
	public:
	void nhap()
	{
		SANPHAM::nhap();
		fflush(stdin);
		cout<<"Nhap loai thuoc: "; cin.getline(loaithuoc,20);
		cout<<"Nhap thanh phan thuoc: "; cin.getline(thanhphan,20);
		cout<<"Nhap han su dung: \n";
		cout<<"\tNhap ngay: "; cin>>hsd.ngay;
		cout<<"\tNhap thang: "; cin>>hsd.thang;
		cout<<"\tNhap nam: "; cin>>hsd.nam;
	}
	void xuat()
	{
		SANPHAM::xuat();
		cout <<setw(12)<<loaithuoc
			<<setw(12)<<thanhphan
			<<setw(9)<<hsd.ngay
			<<setw(1)<<"/"
			<<setw(1)<<hsd.thang
			<<setw(1)<<"/"
			<<setw(1)<<hsd.nam
			<<setw(8)<<Giathanh()
			<<endl;
	}
	friend istream& operator >>(istream &is,THUOC &a)
	{
		a.nhap();
	}
	friend ostream& operator <<(ostream &os,THUOC a)
	{
		a.xuat();
	}
	float Giathanh()
	{
		return dongia*1.1;
	}
	char *getTP()
	{
		return thanhphan;
	}
};
void Tieude()
{
	cout <<setw(5)<<"Ma"
		<<setw(5)<<"||"
		<<setw(5)<<"Ten"
		<<setw(5)<<"||"
		<<setw(10)<<"Don gia"
		<<setw(5)<<"||"
		<<setw(13)<<"Loai thuoc"
		<<setw(5)<<"||"
		<<setw(10)<<"Thanh phan"
		<<setw(5)<<"||"
		<<setw(10)<<"Han su dung"
		<<setw(5)<<"||"
		<<setw(10)<<"Thanh tien"
		<<endl;
}
void In_thong_tin(THUOC a[],int n)
{
	cout<<"Thong tin vua nhap o dang bang:\n";
	Tieude();
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
void Tim_ma(THUOC a[],int n)
{
	char timkiem[20];
	fflush(stdin);
	cout<<"Nhap ma thuoc can tim: "; cin.getline(timkiem,20);
	Tieude();
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].getMa(),timkiem)==0)
		cout<<a[i];
	}
}
void Tim_thanh_phan(THUOC a[],int n)
{
	char timkiem[20];
	fflush(stdin);
	cout<<"Nhap thanh phan co trong thuoc can tim: "; cin.getline(timkiem,20);
	Tieude();
	for(int i=0;i<n;i++)
	{
		if(strcmpi(a[i].getTP(),timkiem)==0)
		cout<<a[i];
	}
}
void So_luong(THUOC a[],int n)
{
	int dem=0;
	Tieude();
	for(int i=0;i<n;i++)
	{
		if(a[i].getDG()==500000)
		cout<<a[i];
	}
}
void Sap_xep(THUOC a[], int n)
{
	cout<<"Danh sach thuoc co don gia>200.000 theo thu tu tang dan cua ten san pham:\n";
	Tieude();
	for(int i=0;i<n;i++)
	{
		if(a[i].getDG()>200000)
		for(int j=i+1;j<n;j++)
		{
			if(strcmpi(a[i].getTen(),a[i].getTen())==1)
			swap(a[i],a[j]);
		}
		cout<<a[i];
	}
}
void MENU(THUOC a[],int &n)
{
	int chon;
	do{
		cout<<"****************************MENU**************************************************\n";
		cout<<"**1. In danh sach da nhap o dang bang.                  					  **\n";
		cout<<"**2. In thuoc co ma nhap tu ban phim.                   					  **\n";
		cout<<"**3. Tim thuoc co thanh phan Paracetamol                					  **\n";
		cout<<"**4. Dem so luong thuoc co don gia 500.000.             					  **\n";
		cout<<"**5. In ra danh sach thuoc co don gia>200 theo thu tu tang dan cua ten san pham.**\n";
		cout<<"**0. Thoat.                                             					  **\n";
		cout<<"**********************************************************************************\n";
		cout<<"Nhap lua chon: "; cin>>chon;
		switch(chon)
		{
			case 1:
			{
				In_thong_tin(a,n);
				break;
			}
			case 2:
			{
				Tim_ma(a,n);
				break;
			}
			case 3:
			{
				Tim_thanh_phan(a,n);
				break;
			}
			case 4:
			{
				So_luong(a,n);
				break;
			}
			case 5:
			{
				Sap_xep(a,n);
				break;
			}
			case 0:
			{
				cout<<"THOAT.\n";
			}
		}
	}while(chon!=0);
}

int main()
{
	int n;
	cout<<"Nhap so luong: "; cin>>n;
	THUOC *a=new THUOC[n];
	for(int i=0;i<n;i++)
	{
		cout<<"------------Loai thuoc thu "<<i+1<<"--------------------\n";
		cin>>a[i];
	}
	MENU(a,n);
	return 0;
}
