#include "TheMuonSV.h"
#include "ChiTietMuon.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;

TheMuonSV::TheMuonSV (int capacity){}

TheMuonSV::TheMuonSV(string _hoten, string _maSV, string _lopsh, string _chuyennganh,int soLuong, int capacity)
    : hoten(_hoten), maSV(_maSV), lopsh(_lopsh), chuyennganh(_chuyennganh), soLuong(soLuong), capacity(capacity) {}


TheMuonSV::TheMuonSV(const TheMuonSV& other)
    : hoten(other.hoten), maSV(other.maSV), lopsh(other.lopsh), chuyennganh(other.chuyennganh), soLuong(other.soLuong), capacity(other.capacity) {
    for (int i = 0; i < other.danhSachMuon.size(); ++i) {
        danhSachMuon.add(new ChiTietMuon(*other.danhSachMuon[i]));
    }
}


TheMuonSV::~TheMuonSV() {
    for (int i = 0; i < danhSachMuon.size(); ++i){
        delete danhSachMuon[i];
    }
}


void TheMuonSV::muonSach(const ChiTietMuon& chiTiet) {
    if (gioiHanMuonSach()) {
        danhSachMuon.add(new ChiTietMuon(chiTiet));
        cout << "Them chi tiet muon thanh cong!!" << endl;
    } else {
        cout << "Sinh vien da muon du gioi han 5 quyen sach.\n";
    }
}


void TheMuonSV::traSach(const string& maSach, const string& maTT) {
    for (int i = 0; i < danhSachMuon.size(); ++i) {
        if (danhSachMuon[i]->getMaSach() == maSach) {
            if (danhSachMuon[i]->getMaTrangThai() == "treHan") {
                // Tính chi phí trả muộn
                double chiPhiTreHan = danhSachMuon[i]->tinhChiPhi(danhSachMuon[i]->getNgayTraSach());
                cout << "Sach co ma " << maSach << " da bi tra tre.\n";
                cout << "Chi phi tre han: " << chiPhiTreHan << " VND\n";
            }
            // Xóa sách khỏi danh sách mượn
            delete danhSachMuon[i];
            danhSachMuon.remove(i);
            cout << "Da tra sach co ma: " << maSach << "\n";
            return;
        }
    }
    cout << "Khong tim thay sach co ma: " << maSach << " trong danh sach muon.\n";
}

void TheMuonSV::showTheMuonSV() const {
    string colorReset = "\033[0m";
    string boldText = "\033[1m";

    cout << endl;
    cout << boldText << "Thong tin sinh vien:\n" << colorReset ;
    cout << left
         << setw(8)  << "Ma SV: " << maSV 
         << setw(15) << " | Ho ten: " << hoten
         << setw(10) << " | Lop: " << lopsh
         << setw(20) << " | Chuyen nganh: " << chuyennganh
         << setw(5) << " | So sach muon: " << soLuong 
         << endl;
    cout << endl;
    return;
}

void TheMuonSV::showDanhSachMuon() const {
    string colorReset = "\033[0m";
    string colorBlue = "\033[34m"; // Xanh dương
    string boldText = "\033[1m";
    string underlineText = "\033[4m";

    showTheMuonSV(); // Hiển thị thông tin sinh viên

    if (danhSachMuon.size() == 0 || soLuong == 0) {
        cout <<underlineText << "Sinh vien chua muon sach nao.\n" <<colorReset;
    } else {
        cout << boldText
             << setw(12) << setfill(' ') << "Ma Sach"  <<"||"
             << setw(15) << setfill(' ') << "Trang Thai" << "||"
             << setw(16) << setfill(' ') << "Ngay Muon" << "||"
             << setw(16) << setfill(' ') << "Han Tra"<< "||"
             << setw(10) << setfill(' ') << "Phi Tre Han" << colorReset << endl;
        cout << string(70, '-') << endl;

        // In từng sách mượn với hàm `ChiTietMuon::show`
        for (int j = 0; j < danhSachMuon.size(); ++j) {
            if (danhSachMuon[j]->getMaTrangThai() != "daTra") {
                danhSachMuon[j]->show();
            }
        }
    }
    cout << string(85, '=') << endl;
}

void TheMuonSV::showSachTreHan() const {
    string colorReset = "\033[0m";
    string boldText = "\033[1m";
    showTheMuonSV();

    cout << boldText
             << setw(12) << setfill(' ') << "Ma Sach"  <<"||"
             << setw(15) << setfill(' ') << "Trang Thai" << "||"
             << setw(16) << setfill(' ') << "Ngay Muon" << "||"
             << setw(16) << setfill(' ') << "Han Tra"<< "||"
             << setw(10) << setfill(' ') << "Phi Tre Han" << colorReset << endl;
        cout << string(70, '-') << endl;

    for (int j = 0; j < danhSachMuon.size(); ++j) {
        if (danhSachMuon[j]->getMaTrangThai() == "treHan") {
            danhSachMuon[j]->show();
        }
    }
    cout << string(70, '_') << endl;
}

bool TheMuonSV::TreHanTraSach(const Date& ngayHienTai) const {
    for (int i = 0; i < danhSachMuon.size(); ++i) {
        if (danhSachMuon[i]->getMaTrangThai() == "treHan") {
            return true; // Có ít nhất một sách bị trễ hạn
        }
    }
    return false; 
}


int TheMuonSV::getSoLuongSachDangMuon() const {
    return soLuong;
}

bool TheMuonSV::gioiHanMuonSach() const {
    return soLuong < 5;
}

int TheMuonSV::DemSinhVienMuon5Cuon (Linklist<TheMuonSV*>& danhSachTheMuon, int soLuongSinhVien) {
    int dem = 0;
    for (int i = 0; i < soLuongSinhVien; ++i) {
        if (danhSachTheMuon[i]->getSoLuongSachDangMuon() == 5) {
            ++dem;
        }
    }
    return dem;
}

void TheMuonSV::nhapThongTin(){
	cout << "Nhap thong tin the muon:" << endl;

    cout << "Nhap ho ten sinh vien: ";
    getline(cin, this->hoten);
    
    cout << "Nhap ma sinh vien:";
    cin >> this->maSV;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout << "Nhap lop sinh hoat:";
    cin >> this->lopsh;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Nhap chuyen nganh: ";
    getline(cin, this->chuyennganh);
}

Linklist<ChiTietMuon *>& TheMuonSV::getChiTietMuon() {
    return danhSachMuon;
}

string TheMuonSV::getHoTen() const {
    return this->hoten;
}
string TheMuonSV::getLopSH() const{
    return this->lopsh;
}
string TheMuonSV::getChuyenNganh() const{
    return this->chuyennganh;
}


string TheMuonSV::getMa() const {
    return this->maSV;
}

void TheMuonSV::setSoLuong() {
    if (gioiHanMuonSach()) soLuong++;
}