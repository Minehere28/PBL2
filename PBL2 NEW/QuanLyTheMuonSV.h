#ifndef QUANLYTHEMUONSV_H
#define QUANLYTHEMUONSV_H

#include "Linklist.h"
#include "TheMuonSV.h"
#include "ChiTietMuon.h"
#include "Date.h"
#include <string>

using namespace std;

class QuanLyTheMuonSV {
private:
    string maQuanLy;
    Linklist<TheMuonSV *> danhSachTheMuon;

public:
    QuanLyTheMuonSV(const string &maQuanLy = "");
    ~QuanLyTheMuonSV();
    
    Linklist<TheMuonSV *> getDanhSachTheMuon() const;


    void themTheMuonSV();
    void xoaTheMuon();
    void inDanhSachMuonTheoMaSV() const;
    void inDanhSachTatCaTheMuon() const;
    void danhSachSinhVienTreHan() const;
    void themSachMuon(Linklist<GiaSach*>  dsGiaSach, Linklist<TheMuonSV *> dsTheMuon);
    void traSachMuon(Linklist<GiaSach*>  dsGiaSach, Linklist<TheMuonSV *> dsTheMuon);
    void inSinhVienMuon5Cuon() const;

    void docTheMuonTuFile(const string &tenFile, const string &tenFileChiTietMuon);
    void luuTheMuonVaoFile(const string& tenFile,const string &tenFileChiTietMuon, const Linklist<TheMuonSV*>& dsTheMuon);
    Linklist<ChiTietMuon*> docChiTietTuFile(const string &tenFile);
    void luuChiTietVaoFile(const string& tenFile, const Linklist<ChiTietMuon*>& dsChiTietSv);

    void capNhatTreHanVaChiPhi(Linklist<ChiTietMuon*>& danhSachChiTietMuon);

};

#endif
