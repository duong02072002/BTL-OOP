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
        friend istream& operator >>(istream &is, NhanVien &NV);
        float getLuong();
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

class NhanVienBanHang : public NhanVien{
    private:
        int DonHangDaBan;
        float GiaTienMotDon;
        float Luong;
    public:
        NhanVienBanHang();
        NhanVienBanHang(int DonHangDaBan, float GiaTienMotDon, float Luong);
        ~NhanVienBanHang();
        friend istream& operator >>(istream &is, NhanVienBanHang &BH);
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
    return Luong = GiaTienMotDon *(float)DonHangDaBan;
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
    os << "Ho Va Ten La: " << BH.getHoTen() << endl;
    os << "Ma Nhan Vien La: " << BH.getMaNhanVien() << endl;
    os << "So Tuoi La: " << BH.getTuoi() << endl;
    os << "So Don Da Ban La: " << BH.DonHangDaBan << endl;
    os << "Gia Tien Mot Don Hang La: " << BH.GiaTienMotDon << endl;
    os << "Luong La: " << BH.getLuong() << endl;
    return os;
}
int main(){
    NhanVienBanHang bh;
    cin >> bh;
    cout <<bh;
    return 0;
}