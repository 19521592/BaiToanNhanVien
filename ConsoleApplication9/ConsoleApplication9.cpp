#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class GiaSuc
{
protected:
    int TongSoLuong, TongLitSua, SoCon;
    int SoLuong, Sua;
    string TiengKeu;
public:
    void NhapTieng();
    void NhapSoLuong()
    {
        cout << "Nhap so luong gia suc ban dau: "; cin >> SoLuong;
    }
    void TinhSoCon()
    {
        srand(time(0));
        int k = rand() % 2 + 1;
        SoCon = k;
    }
    void TinhSua();
    void XuatTieng();
    int laySoLuongGS(){
        return SoLuong;
    }
    int laySoCon() {
        return SoCon;
    }
};

class Bo :public GiaSuc
{
public:
    Bo* Cow[100];
    void NhapTieng()
    {
        TiengKeu = "Boooooo!!";
    }
    void NhapSoLuong()#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
        using namespace std;
    class NhanVien {
    protected:
        string HoTen, NgaySinh;
        double Luong, LuongCoBan;
    public:
        virtual void Nhap();
        virtual void Xuat();
        virtual void TinhLuong();
        virtual double LayLuong();
        virtual NhanVien* TimKiem(string TenNhanVien);
    };
    class NVVanPhong :public NhanVien {
    protected:
        int SoNgayLamViec, TroCap;
    public:
        void Nhap();
        void Xuat();
        void TinhLuong();
        double LayLuong();
        NhanVien* TimKiem(string TenNhanVien);
    };
    class NVSanXuat :public NhanVien {
    protected:
        int SoSanPham;
    public:
        void Nhap();
        void Xuat();
        void TinhLuong();
        double LayLuong();
        NhanVien* TimKiem(string TenNhanVien);
    };
    class NVQuanLy :public NhanVien {
    protected:
        double HeSoChucVu;
        double Thuong;
    public:
        void Nhap();
        void Xuat();
        void TinhLuong();
        double LayLuong();
        NhanVien* TimKiem(string TenNhanVien);
    };
    class CongTy {
    protected:
        double Luong;
        int SoLuongNhanVien;
        NhanVien* DanhSachNV[100];
    public:
        void Nhap();
        NhanVien* TimKiem(string TenNhanVien);
        void TinhLuong();
        double TongLuong();
        void Xuat();
    };
    int main()
    {
        CongTy ABC;
        ABC.Nhap();
        ABC.Xuat();
        string Ten;
        cout << "\nNhap ten nhan vien can tim: ";
        cin.ignore();
        getline(cin, Ten);
        if (ABC.TimKiem(Ten) != NULL) {
            ABC.TimKiem(Ten)->Xuat();
        }
        else cout << "Khong co nhan vien nay.";
    }
    void CongTy::Nhap() {
        cout << "Nhap so luong nhan vien trong cong ty: ";
        cin >> SoLuongNhanVien;
        cout << "Loai nhan vien: ";
        cout << "\n 1: Nhan vien van phong; 2: Nhan vien san xuat; 3: Nhan vien quan ly.";
        for (int i = 0; i < SoLuongNhanVien; i++) {
            int j;
            cout << "\n Loai nhan vien: ";
            cin >> j;
            switch (j) {
            case 1:
                DanhSachNV[i] = new NVVanPhong;
                break;
            case 2:
                DanhSachNV[i] = new NVSanXuat;
                break;
            case 3:
                DanhSachNV[i] = new NVQuanLy;
                break;
            }
            DanhSachNV[i]->Nhap();
        }
    }
    void CongTy::Xuat() {
        cout << "So luong nhan vien trong cong ty: " << SoLuongNhanVien;
        for (int i = 0; i < SoLuongNhanVien; i++) {
            DanhSachNV[i]->Xuat();
        }
        TinhLuong();
        cout << "\nTong luong cua cong ty la: " << setprecision(15) << TongLuong();
    }
    void CongTy::TinhLuong() {
        double Tong = 0;
        for (int i = 0; i < SoLuongNhanVien; i++) {
            Tong += DanhSachNV[i]->LayLuong();
        }
        Luong = Tong;
    }
    double CongTy::TongLuong() {
        return Luong;
    }
    NhanVien* CongTy::TimKiem(string TenNhanVien) {
        for (int i = 0; i < SoLuongNhanVien; i++) {
            if (DanhSachNV[i]->TimKiem(TenNhanVien) != NULL) {
                return DanhSachNV[i]->TimKiem(TenNhanVien);
            }
        }
        return NULL;
    }
    void NVVanPhong::Nhap() {
        cout << "\nHo ten: "; cin.ignore(); getline(cin, HoTen);
        cout << "\nNgay sinh: "; cin >> NgaySinh;
        cout << "\nLuong co ban: "; cin >> LuongCoBan;
        cout << "\nSo ngay lam viec: "; cin >> SoNgayLamViec;
        cout << "\nTro cap: "; cin >> TroCap;
    }
    void NVVanPhong::Xuat() {
        cout << "\nHo ten: " << HoTen;
        cout << "\nNgay sinh: " << NgaySinh;
        cout << "\nLuong co ban: " << setprecision(15) << LuongCoBan;
        cout << "\nSo ngay lam viec: " << SoNgayLamViec;
        cout << "\nTro cap: " << TroCap;
        TinhLuong();
        cout << "\nLuong: " << setprecision(15) << LayLuong();
    }
    void NVVanPhong::TinhLuong() {
        Luong = LuongCoBan + SoNgayLamViec * 100000 + TroCap;
    }
    double NVVanPhong::LayLuong() {
        return Luong;
    }
    NhanVien* NVVanPhong::TimKiem(string TenNhanVien) {
        if (TenNhanVien == HoTen) {
            return this;
        }
        return NULL;
    }
    void NVSanXuat::Nhap() {
        cout << "\nHo ten: "; cin.ignore(); getline(cin, HoTen);
        cout << "\nNgay sinh: "; cin >> NgaySinh;
        cout << "\nLuong co ban: "; cin >> LuongCoBan;
        cout << "\nSo san pham: "; cin >> SoSanPham;
    }
    void NVSanXuat::Xuat() {
        cout << "\nHo ten: " << HoTen;
        cout << "\nNgay sinh: " << NgaySinh;
        cout << "\nLuong co ban: " << setprecision(15) << LuongCoBan;
        cout << "\nSo san pham: " << SoSanPham;
        TinhLuong();
        cout << "\nLuong: " << setprecision(15) << LayLuong();
    }
    NhanVien* NVSanXuat::TimKiem(string TenNhanVien) {
        if (TenNhanVien == HoTen) {
            return this;
        }
        return NULL;
    }
    void NVSanXuat::TinhLuong() {
        Luong = LuongCoBan + SoSanPham * 2000;
    }
    double NVSanXuat::LayLuong() {
        return Luong;
    }
    void NVQuanLy::Nhap() {
        cout << "\nHo ten: "; cin.ignore(); getline(cin, HoTen);
        cout << "\nNgay sinh: "; cin >> NgaySinh;
        cout << "\nLuong co ban: "; cin >> LuongCoBan;
        cout << "\nHe so chuc vu: "; cin >> HeSoChucVu;
        cout << "\nThuong: "; cin >> Thuong;
    }
    void NVQuanLy::Xuat() {
        cout << "\nHo ten: " << HoTen;
        cout << "\nNgay sinh: " << NgaySinh;
        cout << "\nLuong co ban: " << setprecision(15) << LuongCoBan;
        cout << "\nHe so chuc vu: " << HeSoChucVu;
        cout << "\nThuong: " << Thuong;
        TinhLuong();
        cout << "\nLuong: " << setprecision(15) << LayLuong();
    }
    NhanVien* NVQuanLy::TimKiem(string TenNhanVien) {
        if (TenNhanVien == HoTen) {
            return this;
        }
        return NULL;
    }
    void NVQuanLy::TinhLuong() {
        Luong = LuongCoBan * HeSoChucVu + Thuong;
    }
    double NVQuanLy::LayLuong() {
        return Luong;
    }
    void NhanVien::Nhap() {
        return;
    }
    void NhanVien::Xuat() {
        return;
    }
    void NhanVien::TinhLuong() {
        return;
    }
    double NhanVien::LayLuong() {
        return Luong;
    }
    NhanVien* NhanVien::TimKiem(string TenNhanVien) {
        if (TenNhanVien == HoTen) {
            return this;
        }
        return NULL;
    }





    {
        NhapSoLuong();
    }
    void TinhSoLuong()
    {
        TinhSoLuong();
    }
    void TinhSua()
    {
        srand(time(NULL));
        int k = rand() % 21;
    }
    void XuatTieng()
    {
        cout << TiengKeu;
    }
};

class De :public GiaSuc
{
public:
    De* Goat[100];
    void NhapTieng()
    {
        TiengKeu = "abeeeeeeee!!";
    }
    void NhapSoLuong()
    {
        NhapSoLuong();
    }
    void TinhSoLuong()
    {
        TinhSoLuong();
    }
    void TinhSua()
    {
        srand(time(NULL));
        int k = rand() % 6;
    }
    void XuatTieng()
    {
        cout << TiengKeu;
    }
};

class Cuu :public GiaSuc
{
public:
    Cuu* Sheep[100];
    void NhapTieng()
    {
        TiengKeu = "Beeeeee!!";
    }
    void NhapSoLuong()
    {
        NhapSoLuong();
    }
    void TinhSoLuong()
    {
        TinhSoLuong();
    }
    void TinhSua()
    {
        srand(time(NULL));
        int k = rand() % 11;
    }
    void XuatTieng()
    {
        cout << TiengKeu;
    }
};

class Farm
{
protected:
    int TongSoCon[3], TongLitSua[3];
    GiaSuc* GS[3];
public:
    Bo B;
    De D;
    Cuu C;
    void TinhTongCon()
    {
        TongSoCon[0] = 0;
        for (int i = 0; i < B.laySoLuongGS(); i++) {
            TongSoCon[0] += B.laySoCon();
        }
        TongSoCon[1] = 0;
        for (int i = 0; i < D.laySoLuongGS(); i++) {
            TongSoCon[1] += D.laySoCon();
        }
        TongSoCon[2] = 0;
        for (int i = 0; i < C.laySoLuongGS(); i++) {
            TongSoCon[2] += C.laySoCon();
        }
    }
};