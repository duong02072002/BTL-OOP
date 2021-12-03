#include<bits/stdc++.h>

#include <Windows.h>

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
        string getHoTen();
        string getMaNhanVien();
        int getTuoi();
        void setHoTen(string);
        void setMaNhanVien(string);
        void setTuoi(int);
        void DocFiLe(ifstream &ifs, NhanVien &NV);
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

string NhanVien::getHoTen(){
    return HoTen;
}

string NhanVien::getMaNhanVien(){
    return MaNhanVien;
}

int NhanVien::getTuoi(){
    return Tuoi;
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
        void ThemVaoCuoi(NhanVienBanHang bh);
        void Nhap();     
        void Xuat();   
        void TimKiemMa();
        void Max(NhanVienBanHang bh);
        void MaxLuong();
        void TinhTong();
        void SapXep(NhanVienBanHang bh);
        void SapXepNV();
        void XoaNV();
        void DocFiLe();
        void GhiFiLe();
        void Menu();    
        
};

Node* QuanLyNhanVien::getHead(){
    return pHead;
}

Node* QuanLyNhanVien::getTail(){
    return pTail;
}

void QuanLyNhanVien::ThemVaoCuoi(NhanVienBanHang bh){
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
    cout << "\t\t\t\t\t\t\t\t\t\t\t************** NHAP NHAN VIEN ****************" << endl << endl;;
    cout << "\t\t\t\t\t\t\t\t\t\t\tNhap So Nhan Vien Ban Hang: ";
    cin >> n;
    fflush(stdin);
    for(int i=0; i < n; i++){
        NhanVienBanHang data;
        cin >> data;
        ThemVaoCuoi(data);
    }
    cout << endl;
} 

void QuanLyNhanVien::Xuat(){
    cout << "\t\t\t\t\t\t\t\t\t******************************** DANH SACH NHAN VIEN *********************************" << endl;
    cout << left <<"\t\t\t\t\t\t\t\t\t"<< setw(20) << "Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
    cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
    Node *n = pHead;
    while(n != NULL){
        cout << "\t\t\t\t\t\t\t\t\t";
        cout << n->data;
        n = n->pNext;
    }
    cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl << endl;
	delete n;
}

void QuanLyNhanVien::TimKiemMa(){
    string MaNV,MaNV1;
    Node *temp = pHead;
    int dem=0;
    fflush(stdin);
    cout << "\t\t\t\t\t\t\t\t\t\t\tNhap Ma Can Tim: ";
    getline(cin,MaNV);
    fflush(stdin);
    for(temp=pHead ; temp!=NULL ; temp=temp->pNext){
        MaNV1=temp->data.getMaNhanVien();
        if(MaNV == MaNV1){
            cout << "\t\t\t\t\t\t\t\t\t******************************** DANH SACH NHAN VIEN *********************************" << endl;            
            cout << left <<"\t\t\t\t\t\t\t\t\t"<<setw(20) <<"Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
            cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t\t\t";
            cout << temp->data;
            cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl << endl;
            dem++;
         }
     }
    if(dem==0){
        cout << "\t\t\t\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\tNhan Vien Khong Ton Tai" << endl << endl;
    }
} 

void QuanLyNhanVien::Max(NhanVienBanHang bh){
    Node *Max = new Node (bh);
    Node *temp = pHead;

    while (temp != NULL){
        if(temp->data.getLuong() > Max->data.getLuong()){
           Max->data = temp->data;
        }
        temp = temp->pNext;
    }
    cout <<"\t\t\t\t\t\t\t\t\t\t\tNhan Vien Co Luong Cao Nhat:" << endl;
    cout << "\t\t\t\t\t\t\t\t\t******************************** DANH SACH NHAN VIEN *********************************" << endl;
    cout << left <<"\t\t\t\t\t\t\t\t\t"<<setw(20) <<"Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
    cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl;
    cout <<"\t\t\t\t\t\t\t\t\t";
    cout << Max->data;
    cout << "\t\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------" << endl << endl;
}

void QuanLyNhanVien::MaxLuong(){
    NhanVienBanHang data;
    Max(data);
}
void QuanLyNhanVien::TinhTong(){
    Node *temp = pHead;
    float Sum = 0;
    while(temp != NULL){
        Sum += temp->data.getLuong();
        temp = temp->pNext;
    }
    cout << "\t\t\t\t\t\t\t\t\t\t\t************ DANH SACH NHAN VIEN *************" << endl  << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\tTong Luong Cua Nhan Vien La: " << Sum << endl;
    cout << endl;
}

void QuanLyNhanVien::SapXep(NhanVienBanHang bh){
    Node *n = new Node (bh);
    for(Node *bh1 = pHead; bh1 != NULL; bh1 = bh1->pNext){
        for(Node *bh2 = bh1->pNext; bh2 != NULL; bh2 = bh2->pNext){
            if(bh1->data.getLuong() < bh2->data.getLuong()){
                n->data  = bh1->data;
                bh1->data  = bh2->data;
                bh2->data  = n->data;
            }
        }
    }
    cout <<"\t\t\t\t\t\t\t\t\t\t\tDanh Sach Sau Khi Sap Xep La: " << endl;
}

void QuanLyNhanVien::SapXepNV(){
    NhanVienBanHang data;
    SapXep(data);
} 

void QuanLyNhanVien::XoaNV(){
    string n;
    fflush(stdin);
    cout << "\t\t\t\t\t\t\t\t\t\t\t**********************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\tNhap Ten Nhan Vien Can Xoa: ";
    getline(cin,n);
    fflush(stdin);
    cout << endl;
    Node *pDel = pHead;
    Node *pPre = NULL;
    while(pDel != NULL){
        if(pDel->data.getHoTen() == n){
            cout << "\t\t\t\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\tNhan Vien Da Duoc Xoa" << endl << endl; 
            cout << "\t\t\t\t\t\t\t\t\t\t\tDanh Sach Sau Khi Xoa La:" << endl;
            break;
        }
        pPre = pDel;
        pDel = pDel->pNext;
    }
    if(pDel == NULL){
        cout << "\t\t\t\t\t\t\t\t\t\t\t**********************************************" << endl << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\tNhan Vien Khong Ton Tai" << endl << endl;
    }
    else {
        if(pDel == pHead){
            pHead = pHead->pNext;
            pDel->pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
        else if(pDel -> pNext == NULL){
            pTail = pPre;
            pPre -> pNext = NULL;
            delete pDel;
            pDel = NULL;
        }
        else{
            pPre -> pNext = pDel -> pNext;
            pDel -> pNext = NULL;
            delete pDel;
            pDel = NULL; 
        }
    }
}

void QuanLyNhanVien::DocFiLe(){
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
    ifs.close();
}

void QuanLyNhanVien::GhiFiLe(){
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
    ofstream ofs("GHINHANVIEN.TXT",ios::out | ios::app);
    ofs << "Thong Tin Nhan Vien:\n";
    ofs << "******************************** DANH SACH NHAN VIEN *********************************" << endl << endl;
    ofs << left <<setw(20) <<"Ten" << setw(15) << "Ma" << setw(15) << "Tuoi" << setw(15) << "So Don" << setw(15) << "Gia Don" << setw(15) << "Luong" << endl;
    ofs << "--------------------------------------------------------------------------------------" << endl;
    for( int i = 0; i < n; i++){
        data[i].GhiFiLe(ofs);
    }
    ofs << "--------------------------------------------------------------------------------------" << endl;
    ofs.close();
    ifs.close();
}

void QuanLyNhanVien::Menu(){
    int chon;
    while(1){
    	cout << "\t\t\t\t\t\t\t\t\t\t\t******************** MENU **************************\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|1. " << "Nhap Danh Sach Nhan Vien.                      |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|2. " << "Xuat Danh Sach Nhan Vien.                      |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|3. " << "Sap Xep Theo Luong.                            |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|4. " << "Nhan Vien Co Luong Cao Nhat.                   |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|5. " << "Tong Luong Cua Tat Ca Nhan Vien.               |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|6. " << "Tim Kiem Nhan Vien.                            |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|7. " << "Xoa Mot Nhan Vien.                             |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|8. " << "Doc Du Lieu Tu FiLe.                           |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|9. " << "Ghi Du Lieu Ra FiLe.                           |\n" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t|10." << "Thoat Chuong Trinh.                            |\n" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t****************************************************" << endl;
        cout << setw(5) << left << "\t\t\t\t\t\t\t\t\t\t\t=>" << "Lua Chon Cua Ban: ";
        cin >> chon;
        cout << endl;
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
            TimKiemMa();
            break;
        case 7:
            XoaNV();
            Xuat();
            break;
        case 8:
            DocFiLe();
            cout << endl <<"\t\t\t\t\t\t\t\t\t\t\tDa Lay Thong Tin Tu FiLe~~~" << endl << endl;
            break;
        case 9:
            GhiFiLe();
            cout << "\t\t\t\t\t\t\t\t\t\t\tDa In Vao FiLe GHINHANVIEN.TXT~~~" << endl << endl;
            break;
        case 10:
            cout <<"\t\t\t\t\t\t\t\t\t\t\t\t\tGOOD BYE!!!" << endl << endl;
            exit(1);
            break;
        default:
            cout << "\t\t\t\t\t\t\t\t\t\t\tLua Chon Cua Ban Khong Hop Le!!!" << endl << endl;
            break;
        }
    }
}

int main(){
    system("color E4");	
    QuanLyNhanVien nv;
    nv.Menu();
    system ("pause");
    return 0;
}
