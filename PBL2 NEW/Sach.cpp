#include "Sach.h"
#include "Date.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <limits>

Sach::Sach(): maSach(""), tenSach(""), tacGia(""), ngayXuatBan(), loaiSach(""), trangThai("Chua muon")
{}
Sach::Sach(string id, string name, string author, string loai, string status, Date date)
: maSach(id), tenSach(name), tacGia(author), ngayXuatBan(date), loaiSach(loai),trangThai(status) {}
Sach::Sach(const Sach &sach) : maSach(sach.maSach), tenSach(sach.tenSach), tacGia(sach.tacGia), ngayXuatBan(sach.ngayXuatBan), loaiSach(sach.loaiSach)
{}
Sach::~Sach(){}

void Sach::nhap(){
	cout << "Nhap ma sach: ";
    cin >> this->maSach;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten sach: ";
    getline(cin, this->tenSach);
    
    cout << "Nhap ten tac gia: ";
    getline(cin, this->tacGia);

    cout << "Nhap ngay nhan(ngay/thang/nam): " << endl;
    cin >> ngayXuatBan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    this->trangThai = "Chua muon";

    string loaiSachText;
    int loaiSach = 0;  // Khoi tao bien loai sach

    while (true) {
        cout << "Chon loai sach de them: " << endl;
        cout << "1. Sach giao trinh" << endl;
        cout << "2. Sach tham khao" << endl;
        cout << "3. Sach khac" << endl;
        cout << "Loai sach: ";
        cin >> loaiSach;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (loaiSach) {
            case 1:
                loaiSachText = "GiaoTrinh";
                break;
            case 2:
                loaiSachText = "ThamKhao";
                break;
            case 3:
                loaiSachText = "Khac";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
                continue;  
        }
        break;  
    }
    
    this->loaiSach =  loaiSachText; 

}

void Sach::display() {


 	cout << setw(10) << setfill('_') << this->maSach << " ||";
    cout << setw(20) << setfill('_') << this->tenSach << " ||";
    cout << setw(20) << setfill('_') << this->tacGia << " ||";
    cout << setw(20) << setfill('_') << this->displayLoaiSach() << " ||";
    cout << setw(20) << setfill('_') << this->trangThai << " ||";
    int d, m, y;
    d = ngayXuatBan.get_day();
    m = ngayXuatBan.get_month();
    y = ngayXuatBan.get_year();
    ostringstream oss;
    oss << d << "/" << m << "/" << y;
    string tmp = oss.str();
    cout << setw(10) << setfill('_') << tmp;
}

string Sach::getId(){
    return maSach;
}

string Sach::getName(){
    return tenSach;
}

string Sach::getAuthor(){
    return tacGia;
}

Date Sach::getDate(){
    return ngayXuatBan;
}

string Sach::getType(){
    return loaiSach;
}

void Sach::setType(const string& type) {
    loaiSach = type;
}

string Sach::displayLoaiSach() const {
    if (loaiSach == "GiaoTrinh") return "Sach giao trinh";
    else if (loaiSach == "ThamKhao") return "Sach tham khao";
    else if (loaiSach == "Khac") return "Sach khac";
    else return "Sach";
}


void Sach::docFile(ifstream& file) {
    string maSach, tenSach, tacGia, loaiSach, ngayXB;
    getline(file, maSach, ';');
    getline(file, tenSach, ';');
    getline(file, tacGia, ';');
    getline(file, loaiSach, ';');
    getline(file, trangThai, ';');
    getline(file, ngayXB);

    this->maSach = maSach;
    this->tenSach = tenSach;
    this->tacGia = tacGia;
    this->loaiSach = loaiSach;
    this->trangThai = trangThai;

    istringstream dateStream(ngayXB);
    int day, month, year;
    dateStream >> day >> month >> year;
    this->ngayXuatBan = Date(day, month, year);

}

void Sach::displayTrangThai() const {
    cout << "Trang thai sach: " << trangThai << endl;
}

void Sach::setTrangThai(const string& status){
	trangThai = status;
}

string Sach::getTrangThai() const {
    return trangThai;
}

//string Sach::toString() const{
//	ostringstream oss;
//    oss << day << "/" << month << "/" << year;
//    return oss.str();
//}

void Sach::nhapUpdate() {
    string textEffect = "\033[7m";
    string colorReset = "\033[0m";

    cout << endl << "Giu nguyen gia tri cu: " << textEffect << "[ENTER]" << endl << colorReset;
    string input;

    // Nhập mã sách
    cout << endl <<  "Nhap ma sach (" << maSach << "): ";
    getline(cin, input);
    if (!input.empty()) {
        maSach = input;
    }

    // Nhập tên sách
    cout << "Nhap ten sach (" << tenSach << "): ";
    getline(cin, input);
    if (!input.empty()) {
        tenSach = input;
    }

    // Nhập tên tác giả
    cout << "Nhap ten tac gia (" << tacGia << "): ";
    getline(cin, input);
    if (!input.empty()) {
        tacGia = input;
    }

    // Nhập ngày xuất bản
    cout << "Nhap ngay xuat ban (ngay/thang/nam) (" << ngayXuatBan.toString() << "): ";
    getline(cin, input);
    if (!input.empty()) {
        try {
            int day, month, year;
            if (sscanf(input.c_str(), "%d %d %d", &day, &month, &year) == 3) {
                ngayXuatBan = Date(day, month, year);
            } else {
                throw invalid_argument("Invalid date format");
            }
        } catch (const exception& e) {
            cout << "Ngay xuat ban khong hop le. Giu nguyen gia tri cu." << endl;
        }
    }

    // Nhập trạng thái
    cout << "Nhap trang thai (Chua muon/Da muon) (" << trangThai << "): ";
    getline(cin, input);
    if (!input.empty()) {
        trangThai = input;
    }

    // Nhập loại sách
    cout << "Loai sach hien tai: " << this->displayLoaiSach() << endl;
    cout << "Chon loai sach de cap nhat (1: Sach giao trinh, 2: Sach tham khao, 3: Sach khac): ";
    int loaiSachInput;
    cin >> loaiSachInput;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa buffer đầu vào
    switch (loaiSachInput) {
        case 1:
            loaiSach = "GiaoTrinh";
            break;
        case 2:
            loaiSach = "ThamKhao";
            break;
        case 3:
            loaiSach = "Khac";
            break;
        default:
            cout << "Lua chon khong hop le, giu nguyen loai sach cu." << endl;
            break;
    }
}
