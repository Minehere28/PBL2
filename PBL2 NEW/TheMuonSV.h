#ifndef THEMUONSV_H
#define THEMUONSV_H

#include <iostream>
#include "ChiTietMuon.h"

using namespace std;

class TheMuonSV {
protected:
    string maSV; // Mã sinh viên
    string hoten;
    string lopsh;
    string chuyennganh;
    Linklist<ChiTietMuon *> danhSachMuon; // Mảng động để lưu danh sách mượn
    int soLuong;               // Số lượng sách hiện đang mượn
    int capacity;               // Sức chứa của mảng động

public:
    TheMuonSV(string _hoten, string _maSV, string _lopsh, string _chuyennganh,int soLuong = 0, int capacity =5 );
    TheMuonSV(const TheMuonSV& other);
    ~TheMuonSV();
    TheMuonSV(int capacity =5);

    void muonSach(const ChiTietMuon& chiTiet);
    void traSach(const string& maSach, const string& maTT);
    // void docSVTuFile(const string& tenFileSV);

    void showDanhSachMuon() const;
    void showTheMuonSV() const;
    void showSachTreHan() const;

    string getMa() const;  
    bool TreHanTraSach(const Date& ngayHienTai) const;
    int getSoLuongSachDangMuon() const;
    bool gioiHanMuonSach() const;
    void nhapThongTin();

    static int DemSinhVienMuon5Cuon(Linklist <TheMuonSV*>& danhSachTheMuon, int soLuongSinhVien);

    Linklist<ChiTietMuon *>& getChiTietMuon();

    string getHoTen() const;
    string getLopSH() const;
    string getChuyenNganh() const;

    void setSoLuong();

    
};

#endif 
