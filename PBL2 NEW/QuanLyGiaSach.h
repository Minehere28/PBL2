#ifndef QUANLYGIASACH_H
#define QUANLYGIASACH_H

#include "Linklist.h"
#include "GiaSach.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class QuanLyGiaSach {
	protected:
		string maQuanLy;
	    Linklist<GiaSach *> dsGiaSach;
	    static int soLuongGiaSach;
	public:
		QuanLyGiaSach(const string &maQuanLy = "");
	    QuanLyGiaSach(const QuanLyGiaSach &qly);
	    ~QuanLyGiaSach();
	
	    void themGiaSach(GiaSach* gs);
	    void xoaGiaSach(const string& id);
	    void xoaGiaSach(int index);
	    void hienThiDSGiaSach() const;
	    
	    // void themGiaSachMoi(string maGiaSach, Sach* sach);
	    void themSachVaoGiaSach(const string& maGiaSach, Sach* sach);
	    
	    
	    
	    
	    void showMaGiaSach() const;	    
	    void themSachVaoGSDaCo(Linklist<GiaSach*>  dsGiaSach);
	    void themSachVaoGSMoi(Linklist<GiaSach*>  dsGiaSach);
	    Linklist<GiaSach *>& getDSGiaSach();
	    void xoaSachTheoID();
		void hienThiDanhSachTatCaGiaSach() const;
		void hienThiSachTrongGiaSach() const;
		void timSachTheoID() const;
		void capNhatSachTheoID();

		void docSachTuFile(const string& tenFile);
    	void luuSachVaoFile(const string& tenFile);
	    
};


#endif
