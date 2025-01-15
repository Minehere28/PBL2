#include "GiaSach.h"
#include <fstream>
#include <iostream>
using namespace std;


GiaSach::GiaSach(const string& maGiaSach): maGiaSach(maGiaSach), soLuongSach(0) {}

GiaSach::GiaSach(const GiaSach& gs): maGiaSach(gs.maGiaSach), dsSach(gs.dsSach), soLuongSach(gs.soLuongSach) {}

GiaSach::~GiaSach() {
    for (int i = 0; i < dsSach.size(); ++i) {
        delete dsSach[i];
    }
}

void GiaSach::themSach(Sach* s) {
    dsSach.add(s);
    ++soLuongSach;
}

void GiaSach::setMaGiaSach(const string& ma){
	this->maGiaSach = ma;
}

void GiaSach::xoaSach(const string& id) {
    string colorReset = "\033[0m";
    string redText = "\033[31m";
    bool found = false;
    for (int i = 0; i < dsSach.size(); ++i) {
        if (dsSach[i]->getId() == id) {
            Sach* deleteData = new Sach(*dsSach[i]);
            dsSach.remove(i);
            --soLuongSach;
            found = true;
            cout <<redText<< endl<< "Xoa sach thanh cong !" << endl;
            deleteData->display();
            cout << colorReset;
            delete deleteData;
            break;
        }
    }
    if (!found) {
        throw runtime_error("Khong tim thay Sach voi ID: " + id);
    }
}

void GiaSach::xoaSach(int index) {
    if (index < 0 || index >= soLuongSach) {
        throw logic_error("Index out of range!");
    }
    delete dsSach[index];
    dsSach.remove(index);
    --soLuongSach;
}

void GiaSach::hienThiDanhSachSach() const {
    string colorReset = "\033[0m";
    string boldText = "\033[1m";
    // cout << "Danh sach cac quyen sach tai gia sach ma: " << maGiaSach << ":\n";
    cout << boldText<< setw(10) << setfill('_') << "Ma sach" << " ||";
    cout << setw(20) << setfill('_') << "Ten sach" << " ||";
    cout << setw(20) << setfill('_') << "Tac gia" << " ||";
    cout << setw(20) << setfill('_') << "Loai sach" << " ||";
    cout << setw(20) << setfill('_') << "Trang thai" << " ||";
    cout << setw(10) << setfill('_') << "Ngay xuat ban" <<colorReset<< endl;


    for (int i = 0; i < dsSach.size(); ++i) {
        dsSach[i]->display(); 
        cout << endl;
    }
}

void GiaSach::timSach(const string& id) const {
    string colorReset = "\033[0m";
    string greenText = "\033[32m";

    bool found = false;
    for (int i = 0; i < dsSach.size(); ++i) {
        if (dsSach[i]->getId() == id) {
            cout << endl << "Thong tin Sach voi ID: " << id << "\n";
            cout << greenText;
            dsSach[i]->display();
            cout << colorReset << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        throw runtime_error("Khong tim thay Sach voi ID: " + id);
    }
}

void GiaSach::capNhatSachID(const string& id) {
    string colorReset = "\033[0m";
    string greenText = "\033[32m";
	bool found = false;
    for (int i = 0; i < dsSach.size(); ++i) {
        if (dsSach[i]->getId() == id) {
            cout << "Cap nhat sach voi ID: " << id << ":\n";
            dsSach[i]->nhapUpdate();
            found = true;
            cout << endl <<greenText<< "Cap nhat sach thanh cong!" << endl;
            dsSach[i]->display();
            cout << endl << colorReset;
            break;
        }
    }
    if (!found) {
        throw runtime_error("Khong tim thay Sach voi ID: " + id);
    }
}

int GiaSach::getSoLuongSach() const {
    return soLuongSach;
}

Linklist<Sach *> GiaSach::getDanhSachSach() const {
    return dsSach;
}

string GiaSach::getMaGiaSach(){
	return maGiaSach;
}

void GiaSach::capNhatSach(int index, Sach* s) {
    if (index < 0 || index >= soLuongSach) {
        throw out_of_range("Index khong hop le");
    }
    *dsSach[index] = *s;
}

Sach* GiaSach::operator[](int index) {
    if (index < 0 || index >= soLuongSach) {
        throw logic_error("Index out of range!");
    }
    return dsSach[index];
}

GiaSach& GiaSach::operator=(const GiaSach& gs) {
    if (this != &gs) {
        this->maGiaSach = gs.maGiaSach;
        this->dsSach = gs.dsSach;
        this->soLuongSach = gs.soLuongSach;
    }
    return *this;
}

void GiaSach::show(){
    
    cout << setw(10) << setfill('_') << this->maGiaSach << "||";
    cout << setw(10) << setfill('_') << this->soLuongSach << "||";	
}
