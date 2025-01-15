#ifndef SACH_H
#define SACH_H
#include <string>
#include "Date.h"

using namespace std;

class Sach{
	protected:
        string maSach;
        string tenSach;
        string tacGia;
        Date ngayXuatBan;
        string loaiSach;
        string trangThai;
    public:
        Sach();
        Sach(string id, string name, string author, string type,string status, Date date);
        Sach (const Sach &sach);
        ~Sach();
        void nhap();
        void nhapUpdate();
        void display();
        string getId();
        string getName();
        string getAuthor();
        Date getDate();
        string getType();
        void setType(const string& type); 
        
        void docFile(ifstream& file);
        
        void setTrangThai(const string& status);
        string getTrangThai() const; 
        void displayTrangThai() const;
        string displayLoaiSach() const; 
                
};

#endif
