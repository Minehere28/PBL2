#ifndef CHITIETMUON_H
#define CHITIETMUON_H

#include "Date.h"
#include "Linklist.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


class ChiTietMuon {
protected:
    string maSach;
    string maSV;
    double chiPhi;
    Date ngayTraSach;
    Date ngayMuon; 
    string maTrangThai; //dangMuon, daTra, treHan
    

public:
    ChiTietMuon(const string& maSV = "", const string& maTrangThai = "", 

                const string& maSach = "", const Date& ngayTraSach = Date(), const Date& ngayMuon = Date(), const double& chiPhi =0);

    ~ChiTietMuon();
    void nhap();
    void nhapUpdate();
    void show() const;
    double tinhChiPhi(const Date& ngayHenTra);
        int daysDifference(const Date& date1, const Date& date2);


    void setMaTT(const string& newTT);

    string getMaSV() const;
    string getMaSach() const;
    string getMaTrangThai() const;
    double getChiPhi() const;
    Date getNgayTraSach() const;
    Date getNgayMuon() const; 


};

#endif  
