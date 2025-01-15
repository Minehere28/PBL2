
#include "TheMuonSV.h"
#include "ChiTietMuon.h"
#include "Sach.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>
#include <chrono>
#include <ctime>
using namespace std;

ChiTietMuon::ChiTietMuon( const string& maSV, const string& maTrangThai, 
                          const string& maSach, const Date& ngayTraSach, const Date& ngayMuon, const double& chiPhi)
    : maSV(maSV), maTrangThai(maTrangThai), 
      maSach(maSach), ngayTraSach(ngayTraSach), ngayMuon(ngayMuon), chiPhi(chiPhi)
{}

ChiTietMuon::~ChiTietMuon() {}

void ChiTietMuon::nhap() {
    cout << "Nhap Ma SV: ";
    cin >> maSV;
    cout << "Nhap Ma Sach: ";
    cin >> maSach;
    cout << "Nhap Ma Trang Thai: ";
    cin >> maTrangThai;
    cout << "Nhap Ngay Tra Sach: ";
    cin >> ngayTraSach;
    chiPhi = getChiPhi();
}

void ChiTietMuon::show() const {
    string colorReset = "\033[0m";
    string colorGreen = "\033[32m"; 
    string colorRed = "\033[31m";   
    string displayTrangThai;

    if (maTrangThai == "dangMuon") {
        displayTrangThai = "Dang muon";
    } else if (maTrangThai == "treHan") {
        displayTrangThai = "Tre han";
    } else if (maTrangThai == "daTra"){
        displayTrangThai = "Da tra";
    } else 
        displayTrangThai = maTrangThai;

    cout << left
         << setw(12) << setfill(' ') << maSach << "||";

    // Màu sắc cho trạng thái
    if (maTrangThai == "dangMuon") {
        cout << colorGreen;
    } else if (maTrangThai == "treHan") {
        cout << colorRed;
    }
    cout << setw(15) << setfill(' ') << displayTrangThai << colorReset << "||";

    // Ngày mượn
    {
        ostringstream oss;
        oss << setw(2) << setfill('0') << ngayMuon.get_day() << "/"
            << setw(2) << setfill('0') << ngayMuon.get_month() << "/"
            << ngayMuon.get_year();
        string ngayMuonStr = oss.str();
        cout << setw(16) << setfill(' ') << ngayMuonStr << "||";
    }

    // Ngày trả
    {
        ostringstream oss;
        oss << setw(2) << setfill('0') << ngayTraSach.get_day() << "/"
            << setw(2) << setfill('0') << ngayTraSach.get_month() << "/"
            << ngayTraSach.get_year();
        string ngayTraStr = oss.str();
        cout << setw(16) << setfill(' ') << ngayTraStr << "||";
    }

    cout << setw(10) << setfill(' ') << chiPhi << " VND" << endl;
}


double ChiTietMuon::tinhChiPhi(const Date& ngayHenTra) {
    Date Recent = Date().today();
    //int soNgayQuaHan = (Recent.get_day() - ngayTraSach.get_day()) + 
    //                    (Recent.get_month() - ngayTraSach.get_month()) * 30 + 
    //                    (Recent.get_year() - ngayTraSach.get_year()) * 365;
    int soNgayQuaHan = daysDifference(Recent, ngayHenTra);
    if (soNgayQuaHan > 0) {
        chiPhi = 2000 * soNgayQuaHan; // 2000 VND một ngày
    } else {
        chiPhi = 0;
    }
    return chiPhi;
}


int ChiTietMuon::daysDifference(const Date& date1, const Date& date2) {
    tm tm1 = date1.toTm();
    tm tm2 = date2.toTm();

    // Chuyển tm thành time_t
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    if (time1 == -1 || time2 == -1) {
        throw runtime_error("Không thể chuyển đổi ngày thành time_t");
    }

    // Tính số giây chênh lệch và đổi ra ngày
    int difference = difftime(time1, time2) / (60 * 60 * 24);
    return difference;
}

void ChiTietMuon::nhapUpdate() {
    cout << "Nhap Ma Sinh Vien (" << maSV << "): ";
    string input;
    getline(cin, input);
    if (!input.empty()) {
        maSV = input;
    }

    cout << "Nhap Ma Sach (" << maSach << "): ";
    getline(cin, input);
    if (!input.empty()) {
        maSach = input;
    }

    cout << "Nhap Trang Thai (dangMuon/daTra/treHan) (" << maTrangThai << "): ";
    getline(cin, input);
    if (!input.empty()) {
        if (input == "dangMuon" || input == "daTra" || input == "treHan") {
            maTrangThai = input;
        } else {
            cout << "Trang thai khong hop le. Giu nguyen gia tri cu." << endl;
        }
    }

    cout << "Nhap Ngay Tra Sach (dd/mm/yyyy) (" << ngayTraSach.toString() << "): ";
    getline(cin, input);
    if (!input.empty()) {
        try {
            int day, month, year;
            sscanf(input.c_str(), "%d/%d/%d", &day, &month, &year);
            ngayTraSach = Date(day, month, year);
        } catch (const exception& e) {
            cout << "Ngay nhap khong hop le. Giu nguyen gia tri cu." << endl;
        }
    }
}


void ChiTietMuon::setMaTT(const string& newTT) {
    if (newTT == "dangMuon" || newTT == "daTra" || newTT == "treHan") {
        maTrangThai = newTT;
    } else {
        cout << "Trang thai khong hop le. Khong thay doi." << endl;
    }
}

string ChiTietMuon::getMaSV() const {
    return maSV;
}
string ChiTietMuon::getMaSach() const {
    return this->maSach;
}
string ChiTietMuon::getMaTrangThai() const {
    return this->maTrangThai;
}

double ChiTietMuon::getChiPhi() const {
return chiPhi;
}
Date ChiTietMuon::getNgayTraSach() const {
    return ngayTraSach;
}
Date ChiTietMuon::getNgayMuon() const {
    return ngayMuon;
}
