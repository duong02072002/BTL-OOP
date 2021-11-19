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
        float getLuong();
        int getTuoi();
        string getHoTen();
        string getMaNhanVien();
        void setHoTen(string);
        void setMaNhanVien(string);
        void setTuoi(int);
        virtual void DocFiLe(ifstream &ifs, NhanVien &NV);
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
void NhanVien::setHoTen(string){
    this->HoTen = HoTen;
}
void NhanVien::setMaNhanVien(string){
    this->MaNhanVien = MaNhanVien;
}
void NhanVien::setTuoi(int){
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
void NhanVien::DocFiLe(ifstream &ifs, NhanVien &NV){
    fflush(stdin);
    getline(ifs, NV.HoTen);
    fflush(stdin);
    getline(ifs, NV.MaNhanVien);
    fflush(stdin);
    ifs >> NV.Tuoi;
    char ss[5];
	ifs.getline(ss, 3);
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
        void setDonHangDaBan(int);
        void setGiaTienMotDon(float);
        void setLuong(float);
        void DocFiLe(ifstream &ifs, NhanVienBanHang &BH);
        void GhiFiLe(ofstream &ofs);
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
    return Luong = GiaTienMotDon *(float)DonHangDaBan;
}
void NhanVienBanHang::setDonHangDaBan(int){
    this->DonHangDaBan = DonHangDaBan;
}
void NhanVienBanHang::setGiaTienMotDon(float){
    this->GiaTienMotDon = GiaTienMotDon;
}
void NhanVienBanHang::setLuong(float){
    this->Luong = Luong;
}
istream& operator >>(istream &is, NhanVienBanHang &BH){
    NhanVien *nv = static_cast<NhanVien *>(&BH);
    is >> *nv;
    fflush(stdin);
    cout << "Nhap So Don Da Ban Trong Ngay La: ";
    is >> BH.DonHangDaBan;
    fflush(stdin);
    cout << "Nhap Gia Tien Mot Don Hang: ";
    is >> BH.GiaTienMotDon; 
    fflush(stdin);
    return is;
}
ostream& operator << (ostream &os, NhanVienBanHang &BH){
    os << left << setw(20) << BH.getHoTen() << setw(15) << BH.getMaNhanVien() << setw(15) << BH.getTuoi() 
    << setw(15) << BH.DonHangDaBan << setw(15) << BH.GiaTienMotDon << setw(15) << BH.getLuong() << endl;
    return os;
}
void NhanVienBanHang::DocFiLe(ifstream &ifs, NhanVienBanHang &BH){
    NhanVien::DocFiLe(ifs,BH);
    fflush(stdin);
    ifs >> BH.DonHangDaBan;
    fflush(stdin);
    ifs >> BH.GiaTienMotDon; 
    char ss[5];
	ifs.getline(ss, 3);
}
void NhanVienBanHang::GhiFiLe(ofstream &ofs){
    ofs << left << setw(20) << getHoTen() << setw(15) << getMaNhanVien() << setw(15) << getTuoi() 
    << setw(15) << getDonHangDaBan() << setw(15) << getGiaTienMotDon() << setw(15) << getLuong() << endl;
    fflush(stdin);
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
        void TimKiem(NhanVienBanHang &bh);
        void TimKiemMaNV();
        void Max(NhanVienBanHang &bh);
        void MaxLuong();
        void Tong(NhanVienBanHang &bh);
        void TinhTong();
        void SapXep(NhanVienBanHang &bh);
        void SapXepNV();
        void XoaNV();
        void InFiLe();
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
    cout << left << setw(20) << "Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" 
    << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
    Node *n = pHead;
    while(n != NULL){
        cout << n->data;
        n = n->pNext;
    }
    cout << endl;
	delete n;
}
void QuanLyNhanVien::TimKiem(NhanVienBanHang &bh){
    string Ma;
    Node *temp = pHead;
    fflush(stdin);
    cout << "Nhap Ma Can Tim: ";
    getline(cin,Ma);
    fflush(stdin);
    while(temp != NULL){
        if(temp->data.getMaNhanVien() == Ma){
            cout << "Nhan Vien Co Trong Danh Sach: " << endl << temp->data << endl;
            break;
        }
        temp=temp->pNext; 
        if(temp == NULL){
            cout << "Nhan Vien Khong Ton Tai" << endl;
        }
    }
}
void QuanLyNhanVien::TimKiemMaNV(){ 
        NhanVienBanHang data;
        TimKiem(data);
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
    Node *pDel = pHead;     
    Node *pPre = NULL;  
    while(pDel != NULL){
        if(pDel->data.getHoTen() == n){
            cout << "Danh Sach Sau Khi Xoa: " << endl;
            break;
        }
        pPre = pDel;
        pDel = pDel -> pNext;
    }
    if(pDel == NULL){
        cout << "Nhan Vien Khong Ton Tai";
    }
    else {
        // Xoa Dau
        if(pDel == pHead){
            pHead = pHead->pNext;
            pDel->pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
        // Xoa cuoi
        else if(pDel -> pNext == NULL){
            pTail = pPre;
            pPre -> pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
        // Xoa giua
        else{
            pPre -> pNext = pDel -> pNext;
            pDel -> pNext = NULL;
            delete pDel;
            pDel = NULL; 
      }
    }
}
void QuanLyNhanVien::InFiLe(){
    NhanVienBanHang data[10];
    ifstream ifs("DOCNHANVIEN.TXT", ios::in);
    int n;
    ifs >> n;
    char ss[5];
	ifs.getline(ss, 3);
    for(int i = 0; i < n; i++){
        data[i].DocFiLe(ifs,data[i]);
        ThemVaoCuoi(data[i]);
    }
    ofstream ofs("GHINHANVIEN.TXT",ios::out);
    ofs << "Thong Tin Nhan Vien:\n";
    ofs << left << setw(20) << "Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" 
    << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
    for( int i = 0; i < n; i++){
        data[i].GhiFiLe(ofs);
    }
    ofs.close();
    ifs.close();
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
        cout << "9. Thoat Chuong Trinh." << endl;
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
        case 8:
            InFiLe();
            break;
        case 9:
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
