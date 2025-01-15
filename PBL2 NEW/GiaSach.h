#ifndef GIASACH_H
#define GIASACH_H

#include "Linklist.h"
#include "Sach.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

using namespace std;

class GiaSach {
protected:
    string maGiaSach;
    Linklist<Sach*> dsSach;
    int soLuongSach;

public:
    GiaSach(const string& maGiaSach = "");
    GiaSach(const GiaSach& gs);
    ~GiaSach();

    void themSach(Sach* s);
    void xoaSach(const string& id);
    void xoaSach(int index);
    void hienThiDanhSachSach() const;

    void timSach(const string& id) const;
    int getSoLuongSach() const;
    string getMaGiaSach();
    void setMaGiaSach(const string& ma);
    

    Linklist<Sach *> getDanhSachSach() const;

    void capNhatSach(int index, Sach* s);
    void capNhatSachID (const string& id);
    
    void show();

    Sach* operator[](int index);
    GiaSach& operator=(const GiaSach& gs);
};

#endif 

