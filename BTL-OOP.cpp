#include<bits/stdc++.h>

using namespace std;

class NhanVien{
    private:
        string HoTen;
        string MaNhanVien;
        int Tuoi;
    public:
        NhanVien();
        NhanVien(string HoTen, string MaNhanVien, int Tuoi);
        ~NhanVien();
        friend istream& operator >> (istream &is, NhanVien &NV);
        friend ostream& operator << (ostream &os, NhanVien &NV);
        int getTuoi();
        string getHoTen();
        string getMaNhanVien();
        void setHoTen();
        void setMaNhanVien();
        void setTuoi();
        void setLuong();
};
NhanVien::NhanVien(){
    HoTen = " ";
    MaNhanVien = " ";
    Tuoi = 0;
}
NhanVien::NhanVien(string HoTen, string MaNhanVien, int Tuoi){
    this->HoTen = HoTen;
    this->MaNhanVien = MaNhanVien;
    this->Tuoi = Tuoi;
}
NhanVien::~NhanVien(){

}
int NhanVien::getTuoi(){
    return Tuoi;
}
string NhanVien::getHoTen(){
    return HoTen;
}
string NhanVien::getMaNhanVien(){
    return MaNhanVien;
}
void NhanVien::setHoTen(){
    this->HoTen = HoTen;
}
void NhanVien::setMaNhanVien(){
    this->MaNhanVien = MaNhanVien;
}
void NhanVien::setTuoi(){
    this->Tuoi = Tuoi;
}
istream& operator >>(istream &is, NhanVien &NV){
    fflush(stdin);
    cout << "Nhap Ho Va Ten: ";
    getline(is, NV.HoTen);
    fflush(stdin);
    cout << "Nhap Ma Nhan Vien: ";
    getline(is, NV.MaNhanVien);
    fflush(stdin);
    cout << "Nhap So Tuoi: ";
    is >> NV.Tuoi;
    return is;
}
ostream& operator << (ostream &os, NhanVien &NV){
    os << "Ho Va Ten La: " << NV.getHoTen() << endl;
    os << "Ma Nhan Vien La: " << NV.getMaNhanVien() << endl;
    os << "So Tuoi La: " << NV.getTuoi() << endl;
    return os;
}


class NhanVienBanHang : public NhanVien{
    private:
        int DonHangDaBan;
        float GiaTienMotDon;
        float Luong;
    public:
        NhanVienBanHang();
        NhanVienBanHang(int DonHangDaBan, float GiaTienMotDon, float Luong);
        ~NhanVienBanHang();
        friend istream& operator >> (istream &is, NhanVienBanHang &BH);
        friend ostream& operator << (ostream &os, NhanVienBanHang &BH);
        int getDonHangDaBan();
        float getGiaTienMotDon();
        float getLuong();
        void setDonHangDaBan();
        void setGiaTienMotDon();
        void setLuong();
};
NhanVienBanHang::NhanVienBanHang() : NhanVien(){
    DonHangDaBan = 0;
    GiaTienMotDon = 0.0;
}
NhanVienBanHang::NhanVienBanHang(int DonHangDaBan, float GiaTienMotDon, float Luong){
    this->DonHangDaBan = DonHangDaBan;
    this->GiaTienMotDon = GiaTienMotDon;
    this->Luong = Luong;
}
NhanVienBanHang::~NhanVienBanHang(){

}
int NhanVienBanHang::getDonHangDaBan(){
    return DonHangDaBan;
}
float NhanVienBanHang::getGiaTienMotDon(){
    return GiaTienMotDon;
}
float NhanVienBanHang::getLuong(){
    return Luong = (float)GiaTienMotDon *(float)DonHangDaBan;
}
void NhanVienBanHang::setDonHangDaBan(){
    this->DonHangDaBan = DonHangDaBan;
}
void NhanVienBanHang::setGiaTienMotDon(){
    this->GiaTienMotDon = GiaTienMotDon;
}
void NhanVienBanHang::setLuong(){
    this->Luong = Luong;
}
istream& operator >>(istream &is, NhanVienBanHang &BH){
    NhanVien *nv = static_cast<NhanVien *>(&BH);
    is >> *nv;
    fflush(stdin);
    cout << "Nhap So Don Da Ban: ";
    is >> BH.DonHangDaBan;
    fflush(stdin);
    cout << "Nhap Gia Tien Mot Don Hang: ";
    is >> BH.GiaTienMotDon; 
    return is;

}
ostream& operator << (ostream &os, NhanVienBanHang &BH){
    NhanVien *nv = static_cast<NhanVien *>(&BH);
    os << *nv;
    os << "So Don Da Ban La: " << BH.DonHangDaBan << endl;
    os << "Gia Tien Mot Don Hang La: " << BH.GiaTienMotDon << endl;
    os << "Luong La: " << BH.getLuong() << endl;
    return os;
}

class Node {
    public:
        NhanVienBanHang data;
        Node *pNext;
        Node(NhanVienBanHang data){
            this->data = data;
            pNext = NULL;
        }
};
class QuanLyNhanVien {
    private:
        Node *pHead;
        Node *pTail;
        int size;
    public:
        QuanLyNhanVien(){
            pHead = NULL;
            pTail = NULL;
            size = 0;
        };
        ~QuanLyNhanVien(){};
        Node *getHead();
        Node *getTail();  
        void Nhap();     
        void Xuat();   
        void ThemVaoCuoi(NhanVienBanHang &bh);
        void Tong(NhanVienBanHang &bh);
        void TinhTong();
        void Max(NhanVienBanHang &bh);
        void MaxLuong();
        void TimKiem(NhanVienBanHang &bh);
        void TimKiemMaNV();
        void SapXep(NhanVienBanHang &bh);
        void SapXepNV();
        void XoaNV();
        void Menu();
};
Node* QuanLyNhanVien::getHead(){
    return pHead;
}
Node* QuanLyNhanVien::getTail(){
    return pTail;
}
void QuanLyNhanVien::ThemVaoCuoi(NhanVienBanHang &bh){
    Node *pNode = new Node(bh); 
    if(size == 0){
        pHead = pTail = pNode;
    } else {
        pTail->pNext = pNode;
        pTail = pNode;
    }
    size++;
}   
void QuanLyNhanVien::Nhap(){
    int n;
    cout << "Nhap So Nhan Vien Ban Hang: ";
    cin >> n;
    fflush(stdin);
    for(int i=0; i < n; i++){
        NhanVienBanHang data;
        cin >> data;
        ThemVaoCuoi(data);
    }
} 
void QuanLyNhanVien::Xuat(){
    Node *n = pHead;
    while(n != NULL){
        cout << n->data;
        n = n->pNext;
    }
    cout << endl;
	delete n;
}
void QuanLyNhanVien::Tong(NhanVienBanHang &bh){
    Node *temp = pHead;
    float Sum = 0;
    while(temp != NULL){
        Sum += temp->data.getLuong();
        temp = temp->pNext;
    }
    cout << "Tong Luong Cua Nhan Vien La: " << Sum << endl;
}
void QuanLyNhanVien::TinhTong(){
    NhanVienBanHang data;
    Tong(data);
}
void QuanLyNhanVien::Max(NhanVienBanHang &bh){
    Node *Max = new Node (bh);
    Node *temp = pHead;

    while (temp != NULL){
        if(temp->data.getLuong() > Max->data.getLuong()){
           Max->data = temp->data;
        }
        temp = temp->pNext;
    }
    cout <<"NV Co Luong Lon Nhat La: " << endl << Max->data << endl;
}
void QuanLyNhanVien::MaxLuong(){
    NhanVienBanHang data;
    Node *pNext;
    Max(data);
}
void QuanLyNhanVien::TimKiem(NhanVienBanHang &bh){
    Node* n = new Node(bh);
    int Dem = 0;
    string TimMa;
    fflush(stdin);
    cout << "Nhap Ma Can Tim: ";
    getline(cin,TimMa);
    fflush(stdin);
    for(n = pHead; n != NULL; n = n->pNext){
        if( n->data.getMaNhanVien() == TimMa ){
            Dem++;
            cout << "Nhan Vien Co Trong Danh Sach" << endl << n->data << endl;
        }
    }
    if(Dem == 0){
        cout << "Nhan Vien Khong Ton Tai" << endl;
    }
}
void QuanLyNhanVien::TimKiemMaNV(){
    NhanVienBanHang data;
    TimKiem(data);
}
void QuanLyNhanVien::SapXep(NhanVienBanHang &bh){
    Node *n = new Node (bh);
    for(Node *bh1 = pHead; bh1 != NULL; bh1 = bh1->pNext){
        for(Node *bh2 = pHead; bh2 != NULL; bh2 = bh2->pNext){
            if(bh1->data.getLuong() > bh2->data.getLuong()){
                n->data  = bh1->data;
                bh1->data  = bh2->data;
                bh2->data  = n->data;
            }
        }
    }
    n = n->pNext;
    cout <<"Danh Sach Sau Khi Sap Xep La: " << endl;
}
void QuanLyNhanVien::SapXepNV(){
    NhanVienBanHang data;
    SapXep(data);
} 
void QuanLyNhanVien::XoaNV(){
    string n;
    fflush(stdin);
    cout << "Nhap Ten Nhan Vien Can Xoa: ";
    getline(cin,n);
    fflush(stdin);
    Node *p = pHead;
    if(p == NULL){
        cout << "Khong Co Gia Tri";
    }
    else {
        Node *pPre = NULL;
        while(p != NULL){
            if(p->data.getHoTen() == n){
                break;
            }
            pPre = p;
            p = p->pNext;
            cout << "Danh Sach Nhan Vien Sau Khi Xoa:" << endl;
        }
        if(p == NULL){
            cout << "Nhan Vien Khong Ton Tai";
        }
        else {
            if(p == pHead){
                pHead = pHead->pNext;
                p->pNext = NULL;
                delete p;
                p = NULL;
            }
            else{
                pPre->pNext = p->pNext;  
                p->pNext = NULL;
                delete p;
                p = NULL;
            }
        }
    }
}
void QuanLyNhanVien::Menu(){
    int chon;
    while(1){
    	cout << "-----------------MENU------------------" << endl;
        cout << "1. Nhap Danh Sach Nhan Vien." << endl;
        cout << "2. Xuat Danh Sach Nhan Vien." << endl;
        cout << "3. Sap Xep Theo Luong." << endl;
        cout << "4. Nhan Vien Co Luong Cao Nhat." << endl;
        cout << "5. Tong Luong Cua Tat Ca Nhan Vien." << endl;
        cout << "6. Tim Kiem Nhan Vien." << endl;
        cout << "7. Xoa Mot Nhan Vien." << endl;
        cout << "8. In Ra FiLe." << endl;
        cout << "9. Thoat Chuong Trinh (ESC)." << endl;
        cout << "------------------------------------------" << endl;
        cout << "=> Lua Chon Cua Ban: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            Nhap();
            break;
        case 2:
        	Xuat();
    		break;
    	case 3:
    		SapXepNV();   
            Xuat();    
    		break;
        case 4:
            MaxLuong();
            break;
        case 5:
        	TinhTong();
        	break;
        case 6:
            TimKiemMaNV();
            break;
        case 7:
            XoaNV();
            Xuat();
            break;
        // case 8:
        case 0:
            cout << "GOOD BYE." << endl;
            exit(1);
            break;
        default:
            cout << "Lua Chon Cua Ban Khong Hop Le." << endl;
            break;
        }
    }
}
int main(){
    QuanLyNhanVien nv;
    nv.Menu();
    return 0;
}
