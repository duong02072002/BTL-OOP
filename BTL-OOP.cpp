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
        friend ostream& operator >>(ostream &os, NhanVien &NV);
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
ostream& operator << (ostream &os, NhanVien &NV){
    os << "Ho Va Ten La: " << NV.getHoTen()<< endl;
    os << "Ma Nhan Vien La: " << NV.getMaNhanVien() << endl;
    os << "So Tuoi La: " << NV.getTuoi() << endl;
    return os;
}
int main(){
    NhanVien bh;
    cin >> bh;
    cout << bh;
    return 0;
}
