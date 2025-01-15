#include "QuanLyTheMuonSV.h"
#include "QuanLyGiaSach.h"
#include "TheMuonSV.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include <algorithm>
#include <cctype>
#include <locale>
#include <limits>

string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}

QuanLyTheMuonSV::QuanLyTheMuonSV(const string &maQuanLy) : maQuanLy(maQuanLy) {}

QuanLyTheMuonSV::~QuanLyTheMuonSV()
{
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        delete danhSachTheMuon[i];
    }
}

void QuanLyTheMuonSV::themTheMuonSV()
{
    TheMuonSV *theMuon = new TheMuonSV();
    theMuon->nhapThongTin();
    if (theMuon == NULL)
    {
        cout << "Khong the tao the muon!" << endl;
        return;
    }
    danhSachTheMuon.add(theMuon);
    string colorReset = "\033[0m";
    string greenText = "\033[32m";

    cout << endl << "Them the muon thanh cong!\n";
    cout << greenText;
    theMuon->showTheMuonSV();
    cout << colorReset;
}

void QuanLyTheMuonSV::xoaTheMuon()
{
    string colorReset = "\033[0m";
    string redText = "\033[31m";

    string maSV;
    cout << "Nhap ma sinh vien:";
    cin >> maSV;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getMa() == maSV)
        {
            TheMuonSV* deleteData = new TheMuonSV(*danhSachTheMuon[i]);
            delete danhSachTheMuon[i];
            danhSachTheMuon.remove(i);
            cout <<redText<< endl<< "Xoa the muon thanh cong !" << endl;
            deleteData->showTheMuonSV();
            cout << colorReset;
            return;
        }
    }
    cout << "Khong tim thay ma sinh vien: " << maSV << endl;
}

void QuanLyTheMuonSV::inDanhSachMuonTheoMaSV() const
{
    string maSV;
    cout << "Nhap ma sinh vien:";
    cin >> maSV;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getMa() == maSV)
        {
            danhSachTheMuon[i]->showDanhSachMuon();
            return;
        }
    }
    cout << "Khong tim thay ma sinh vien: " << maSV << endl;
}

void QuanLyTheMuonSV::inDanhSachTatCaTheMuon() const
{
    cout << "Danh sach tat ca the muon:\n";
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        TheMuonSV *theMuon = danhSachTheMuon[i];
        if (theMuon == nullptr)
            continue;
        theMuon->showDanhSachMuon();
    }
}

void QuanLyTheMuonSV::danhSachSinhVienTreHan() const
{
    string colorReset = "\033[0m";
    string boldText = "\033[1m";
    Date ngayHienTai = Date().today();
    cout << "Danh sanh sinh vien tre han: " << endl;
    int count = 0;
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->TreHanTraSach(ngayHienTai))
        {
            danhSachTheMuon[i]->showSachTreHan();
            count++;
        }
    }
    if (!count)
        cout << "Khong co sinh vien tre han" << endl;
    else
        cout << "Tong sinh vien tre han: " <<boldText << count << " sinh vien." << colorReset<< endl;
}

void QuanLyTheMuonSV::themSachMuon(Linklist<GiaSach *> dsGiaSach, Linklist<TheMuonSV *> dsTheMuon)
{
    string maSV, maSach;
    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);
    // maSV = trim(maSV);
    cout << "Nhap ma sach: ";
    getline(cin, maSach);

    // Kiểm tra mã sinh viên
    bool svTonTai = false;
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getMa() == maSV)
        {
            svTonTai = true;
            break;
        }
    }

    if (!svTonTai)
    {
        cout << "Khong tim thay ma sinh vien: " << maSV << endl;
        return; 
    }

    // Kiểm tra mã sách
    Sach *sachMuon = nullptr;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        Linklist<Sach *> dsSach = dsGiaSach[i]->getDanhSachSach(); 
        for (int j = 0; j < dsSach.size(); ++j)
        { // Duyệt qua danh sách con
            if ((dsSach)[j]->getId() == maSach)
            { // Kiểm tra mã sách
                sachMuon = dsSach[j];
                break;
            }
        }
        if (sachMuon != nullptr)
        {
            break; 
        }
    }

    if (sachMuon == nullptr)
    {
        cout << "Khong tim thay ma sach: " << maSach << endl;
        return; 
    }

    if (sachMuon->getTrangThai() == "Da muon")
    {
        cout << "Sach hien dang duoc muon.\n";
        return;
    }

    Date ngayMuon = Date().today();
    Date ngayTra = Date().createDueDate(3, ngayMuon);
    ChiTietMuon chiTiet(maSV, "dangMuon", maSach, ngayTra);
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getMa() == maSV)
        {
            if (danhSachTheMuon[i]->gioiHanMuonSach())
            {
                danhSachTheMuon[i]->muonSach(chiTiet);
                danhSachTheMuon[i]->setSoLuong();
                // qua Sach doi ma Trang thai
                sachMuon->setTrangThai("Da muon");
                cout << "Muon sach thanh cong!" << endl;
                cout << "Ngay muon: " << ngayMuon << endl;
                cout << "Ngay tra: " << ngayTra << endl;
                return;
            }
            cout << "Sinh vien da muon du gioi han 5 quyen sach.\n";
            return;
        }
    }
    cout << "Khong tim thay ma sinh vien: " << maSV << endl;
}

void QuanLyTheMuonSV::traSachMuon(Linklist<GiaSach *> dsGiaSach, Linklist<TheMuonSV *> dsTheMuon)
{
    string maSV, maSach;
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Nhap ma sach: ";
    cin >> maSach;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    TheMuonSV *svMuon = nullptr;
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getMa() == maSV)
        {
            svMuon = danhSachTheMuon[i];
            break;
        }
    }

    if (svMuon == nullptr)
    {
        cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
        return;
    }
    Sach *sachMuon = nullptr;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        Linklist<Sach *> dsSach = dsGiaSach[i]->getDanhSachSach();
        for (int j = 0; j < dsSach.size(); ++j)
        { // Duyệt qua danh sách con
            if ((dsSach)[j]->getId() == maSach)
            { // Kiểm tra mã sách
                sachMuon = dsSach[j];
                break;
            }
        }
        if (sachMuon != nullptr)
        {
            break; 
        }
    }

    if (sachMuon == nullptr)
    {
        cout << "Khong tim thay ma sach: " << maSach << endl;
        return; 
    }

    Linklist<ChiTietMuon *> dsMuonSV = svMuon->getChiTietMuon();
    bool sachTonTai = false;
    for (int i = 0; i < dsMuonSV.size(); ++i)
    {
        if (dsMuonSV[i]->getMaSach() == maSach)
        {
            sachTonTai = true;
            // Xóa sách khỏi ds mượn của SV
            svMuon->traSach(maSach, dsMuonSV[i]->getMaTrangThai());
            sachMuon->setTrangThai("Chua muon");
            break;
        }
    }

    if (!sachTonTai)
    {
        cout << "Khong tim thay sach co ma: " << maSach << " trong danh sach muon cua sinh vien.\n";
        return;
    }
    cout << "Khong tim thay thong tin muon tra phu hop!" << endl;
}

void QuanLyTheMuonSV::inSinhVienMuon5Cuon() const
{
    cout << "Danh sach sinh vien da muon du 5 cuon sach:\n";
    for (int i = 0; i < danhSachTheMuon.size(); ++i)
    {
        if (danhSachTheMuon[i]->getSoLuongSachDangMuon() == 5)
        {
            danhSachTheMuon[i]->showTheMuonSV();
        }
    }
}
#include "Linklist.h"

Linklist<TheMuonSV *> QuanLyTheMuonSV::getDanhSachTheMuon() const
{
    return danhSachTheMuon;
}

void QuanLyTheMuonSV::capNhatTreHanVaChiPhi(Linklist<ChiTietMuon *> &danhSachChiTietMuon)
{
    Date ngayHienTai = Date().today();
    for (int i = 0; i < danhSachChiTietMuon.size(); ++i)
    {
        ChiTietMuon *chiTiet = danhSachChiTietMuon[i];
        if (chiTiet == nullptr)
            continue;

        // Kiểm tra ngày trả sách
        if (chiTiet->getNgayTraSach() < ngayHienTai && chiTiet->getMaTrangThai() != "daTra")
        {
            chiTiet->setMaTT("treHan");
            double chiPhi = chiTiet->tinhChiPhi(chiTiet->getNgayTraSach());
            // cout << "Ma sach " << chiTiet->getMaSach()
            //      << " cua sinh vien " << chiTiet->getMaSV()
            //      << " bi tre han. Chi phi: " << chiPhi << " VND" << endl;
        }
    }
}

void QuanLyTheMuonSV::docTheMuonTuFile(const string &tenFileTheMuon, const string &tenFileChiTietMuon)
{
    ifstream file(tenFileTheMuon.c_str());
    if (!file.is_open())
    {
        cerr << "Khong the mo file " << tenFileTheMuon << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string maSV, hoten, lopsh, chuyennganh, soluongsach;
        getline(ss, maSV, ',');
        maSV = trim(maSV);
        getline(ss, hoten, ',');
        getline(ss, lopsh, ',');
        getline(ss, chuyennganh, ',');
        getline(ss, soluongsach);
        int soLuong = stoi(soluongsach);

        TheMuonSV *theMuon = new TheMuonSV(hoten, maSV, lopsh, chuyennganh, soLuong);
        danhSachTheMuon.add(theMuon);
    }

    file.close();
    // cout << "Doc du lieu tu file " << tenFileTheMuon << " thanh cong!\n";

    Linklist<ChiTietMuon *> danhSachChiTietMuon = docChiTietTuFile(tenFileChiTietMuon);

    for (int i = 0; i < danhSachChiTietMuon.size(); ++i)
    {
        ChiTietMuon *chiTiet = danhSachChiTietMuon[i];
        bool found = false;

        for (int j = 0; j < danhSachTheMuon.size(); ++j)
        {
            if (danhSachTheMuon[j]->getMa() == chiTiet->getMaSV())
            {
                danhSachTheMuon[j]->getChiTietMuon().add(chiTiet); // Gán chi tiết mượn
                found = true;
                break;
            }
        }

        if (!found)
        {
            cerr << "Khong tim thay sinh vien voi maSV: " << chiTiet->getMaSV() << endl;
        }
    }

}

void QuanLyTheMuonSV::luuTheMuonVaoFile(const string &tenFileTheMuon, const string &tenFileChiTietMuon, const Linklist<TheMuonSV *> &dsTheMuon)
{
    ofstream file(tenFileTheMuon.c_str());
    if (!file.is_open())
    {
        cerr << "Khong the mo file " << tenFileTheMuon << " de ghi du lieu." << endl;
        return;
    }

    for (int i = 0; i < dsTheMuon.size(); ++i)
    {
        TheMuonSV *theMuon = dsTheMuon[i];
        if (theMuon == nullptr)
            continue;

        file << theMuon->getMa() << ","          
             << theMuon->getHoTen() << ","      
             << theMuon->getLopSH() << ","     
             << theMuon->getChuyenNganh() << "," 
             << theMuon->getSoLuongSachDangMuon() << endl;
    }

    file.close();
    cout << "Du lieu da duoc luu vao file " << tenFileTheMuon << " thanh cong!\n";

    Linklist<ChiTietMuon *> allChiTietMuon;
    for (int i = 0; i < dsTheMuon.size(); ++i)
    {
        Linklist<ChiTietMuon *> &chiTietMuon = dsTheMuon[i]->getChiTietMuon();
        for (int j = 0; j < chiTietMuon.size(); ++j)
        {
            allChiTietMuon.add(chiTietMuon[j]);
        }
    }
    luuChiTietVaoFile(tenFileChiTietMuon, allChiTietMuon);
}

Linklist<ChiTietMuon *> QuanLyTheMuonSV::docChiTietTuFile(const string &tenFile)
{
    Linklist<ChiTietMuon *> danhSachChiTietMuon;
    ifstream file(tenFile.c_str());
    if (!file.is_open())
    {
        cerr << "Khong the mo file " << tenFile << endl;
        return danhSachChiTietMuon;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string maSV, maSach, maTrangThai, ngayM, ngayT, phi;
        int dayM, monthM, yearM;
        int dayT, monthT, yearT;
        double chiPhi = 0.0;

        getline(ss, maSV, ',');
        maSV = trim(maSV);
        getline(ss, maSach, ',');
        maSach = trim(maSach);
        getline(ss, maTrangThai, ',');
        maTrangThai = trim(maTrangThai); 
        getline(ss, phi, ',');

        try
        {
            chiPhi = stod(phi);
        }
        catch (...)
        {
            cerr << "Loi chuyen doi chi phi: " << phi << endl;
            chiPhi = 0;
        }

        getline(ss, ngayM, ',');
        stringstream ngayMuonSS(ngayM);
        if (!(ngayMuonSS >> dayM >> monthM >> yearM))
        {
            cerr << "Invalid date format for ngayMuon: " << ngayM << endl;
            continue;
        }

        getline(ss, ngayT, ',');
        stringstream ngayTraSS(ngayT);
        if (!(ngayTraSS >> dayT >> monthT >> yearT))
        {
            cerr << "Invalid date format for ngayTra: " << ngayT << endl;
            continue;
        }
        try
        {
            Date ngayMuon(dayM, monthM, yearM);
            Date ngayTra(dayT, monthT, yearT);

            ChiTietMuon *chiTiet = new ChiTietMuon(maSV, maTrangThai, maSach, ngayTra, ngayMuon, chiPhi);
            danhSachChiTietMuon.add(chiTiet);
        }
        catch (const runtime_error &e)
        {
            cerr << "Loi khi khoi tao ngay: " << e.what() << endl;
        }
    }

    file.close();
    // cout << "Doc du lieu tu file " << tenFile << " thanh cong!\n";

    //cap nhat lai theo date now
    capNhatTreHanVaChiPhi(danhSachChiTietMuon);

    return danhSachChiTietMuon;
}

void QuanLyTheMuonSV::luuChiTietVaoFile(const string &tenFile, const Linklist<ChiTietMuon *> &dsChiTietSv)
{
    if (dsChiTietSv.size() == 0)
    {
        cerr << "Danh sach chi tiet muon rong. Khong co du lieu de luu." << endl;
        return;
    }

    ofstream file(tenFile.c_str());
    if (!file.is_open())
    {
        cerr << "Khong the mo file " << tenFile << " de ghi du lieu." << endl;
        return;
    }

    for (int i = 0; i < dsChiTietSv.size(); ++i)
    {
        ChiTietMuon *chiTiet = dsChiTietSv[i];
        if (chiTiet == nullptr)
            continue;

        file << chiTiet->getMaSV() << ","        // Mã sinh viên
             << chiTiet->getMaSach() << ","      // Mã sách
             << chiTiet->getMaTrangThai() << "," // Trạng thái
             << chiTiet->getChiPhi() << ","
             << chiTiet->getNgayMuon().toString() << ","
             << chiTiet->getNgayTraSach().toString() << endl; // Ngày trả sách
    }

    file.close();
    cout << "Du lieu da duoc luu vao file " << tenFile << " thanh cong!\n";
}
