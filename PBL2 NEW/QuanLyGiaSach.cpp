#include "QuanLyGiaSach.h"
#include "GiaSach.h"
#include "Sach.h"

int QuanLyGiaSach::soLuongGiaSach = 0;

QuanLyGiaSach::QuanLyGiaSach(const string &maQuanLy) : maQuanLy(maQuanLy)
{
}
QuanLyGiaSach::QuanLyGiaSach(const QuanLyGiaSach &qly) : maQuanLy(qly.maQuanLy), dsGiaSach(qly.dsGiaSach)
{
    soLuongGiaSach = qly.soLuongGiaSach;
}
QuanLyGiaSach::~QuanLyGiaSach()
{
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        delete dsGiaSach[i];
    }
}

void QuanLyGiaSach::themGiaSach(GiaSach *gs)
{
    dsGiaSach.add(gs);
    ++soLuongGiaSach;
}
void QuanLyGiaSach::xoaGiaSach(const string &id)
{
    bool found = false;
    for (int i = 0; i < dsGiaSach.size(); i++)
    {
        if (dsGiaSach[i]->getMaGiaSach() == id)
        {
            QuanLyGiaSach::dsGiaSach.remove(i);
            soLuongGiaSach--;
            found = true;
            break;
        }
    }
    if (!found)
    {
        throw runtime_error("Khong tim thay Gia sach voi ID: " + id);
    }
}
void QuanLyGiaSach::xoaGiaSach(int index)
{
    if (index < 0 || index >= soLuongGiaSach)
    {
        throw logic_error("Index out of range!");
    }
    delete dsGiaSach[index];
    dsGiaSach.remove(index);
    --soLuongGiaSach;
}
void QuanLyGiaSach::hienThiDSGiaSach() const
{
    cout << "Danh sach cac gia sach" << endl
         << "Ma quan ly:" << maQuanLy << ":" << endl;
    cout << setw(10) << setfill('_') << "Ma gia sach";
    cout << setw(10) << setfill('_') << "So luong sach";

    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        dsGiaSach[i]->show();
        cout << endl;
    }
}

void QuanLyGiaSach::themSachVaoGiaSach(const string &maGiaSach, Sach *sach)
{
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        if (dsGiaSach[i]->getMaGiaSach() == maGiaSach)
        {
            dsGiaSach[i]->themSach(sach);
            cout << "Them sach thanh cong!" << endl;
            return;
        }
    }
    cout << "Ma gia sach khong ton tai!" << endl;
}

void QuanLyGiaSach::showMaGiaSach() const
{
    string colorReset = "\033[0m";
    string boldText = "\033[1m";
    cout << "\nCac ma gia sach hien co: "<< boldText;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        cout << dsGiaSach[i]->getMaGiaSach() << " ";
    }
    cout << colorReset;
}

void QuanLyGiaSach::themSachVaoGSDaCo(Linklist<GiaSach *> dsGiaSach)
{
    string colorReset = "\033[0m";
    string greenText = "\033[32m";
    showMaGiaSach();
    cout << "\nNhap ma gia sach de them sach: ";
    string maGS;
    //                            cin.ignore();
    getline(cin, maGS);

    bool found = false;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        string maGiaSachTrongDanhSach = dsGiaSach[i]->getMaGiaSach();

        if (dsGiaSach[i]->getMaGiaSach() == maGS)
        {
            Sach *sach = new Sach();
            sach->nhap();
            if (sach == NULL)
            {
                cout << "Khong the tao sach!" << endl;
                break;
            }
            dsGiaSach[i]->themSach(sach);
            cout << endl << "Them sach thanh cong!" << endl;
            cout << greenText;
            sach->display();
            cout << colorReset;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Ma gia sach khong ton tai!" << endl;
    }
}

Linklist<GiaSach *> &QuanLyGiaSach::getDSGiaSach()
{
    return dsGiaSach;
}

void QuanLyGiaSach::themSachVaoGSMoi(Linklist<GiaSach *> dsGiaSach)
{
    string colorReset = "\033[0m";
    string greenText = "\033[32m";
    // Nhap ma gia sach moi
    cout << "Nhap ma gia sach moi: ";
    string maGiaSachMoi;
    cin >> maGiaSachMoi;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Them sach vao gia sach moi
    Sach *sach = new Sach();
    sach->nhap();
    if (sach == NULL)
    {
        cout << "Khong the tao sach!" << endl;
        return;
    }
    GiaSach *giaSachMoi = new GiaSach();
    giaSachMoi->setMaGiaSach(maGiaSachMoi);
    giaSachMoi->themSach(sach);
    dsGiaSach.add(giaSachMoi);
    ++soLuongGiaSach;
    cout << endl<< "Them sach thanh cong!" << endl;
    cout << greenText;
    cout << "Ma gia sach: " << maGiaSachMoi << endl;
    sach->display();
    cout << colorReset;

}

void QuanLyGiaSach::xoaSachTheoID()
{
    cout << "Nhap ID sach can xoa: ";
    string id;
    cin >> id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool found = false;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        try
        {
            GiaSach *giaSach = dsGiaSach[i];
            giaSach->xoaSach(id);
            found = true;
            break;
        }
        catch (const runtime_error &)
        {
        }
    }

    if (!found)
    {
        cout << "Khong tim thay sach voi ID nay!" << endl;
    }
}

void QuanLyGiaSach::hienThiSachTrongGiaSach() const
{
    showMaGiaSach();
    cout << "\nNhap ma gia sach de hien thi sach: ";
    string maGiaSach;
    cin >> maGiaSach;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        if (dsGiaSach[i]->getMaGiaSach() == maGiaSach)
        {
            dsGiaSach[i]->hienThiDanhSachSach();
            return;
        }
    }
    cout << "Ma gia sach khong ton tai!" << endl;
}

void QuanLyGiaSach::hienThiDanhSachTatCaGiaSach() const
{
    string colorReset = "\033[0m";
    string greenText = "\033[32m";
    string boldText = "\033[1m";
    cout << "So luong gia sach: " << dsGiaSach.size() << endl;

    cout << "\nHien thi tat ca sach:" << endl;
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        cout << boldText <<greenText << "Gia sach " << dsGiaSach[i]->getMaGiaSach() << ":" << colorReset << endl;
        dsGiaSach[i]->hienThiDanhSachSach();
    }
}

void QuanLyGiaSach::timSachTheoID() const
{
    cout << "Nhap ID sach can tim: ";
    string id;
    cin >> id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        try
        {
            dsGiaSach[i]->timSach(id);
            return;
        }
        catch (const runtime_error &)
        {
        }
    }
    cout << "Khong tim thay sach voi ID nay!" << endl;
}

void QuanLyGiaSach::capNhatSachTheoID()
{
    
    cout << "Nhap ID sach can cap nhat: ";
    string id;
    cin >> id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < dsGiaSach.size(); ++i)
    {
        try
        {
            dsGiaSach[i]->capNhatSachID(id);
            return;
        }
        catch (const runtime_error &)
        {
        }
    }
    cout << "Khong tim thay sach voi ID nay!" << endl;
}


#include "Linklist.h"

void QuanLyGiaSach::docSachTuFile(const string& tenFile) {
    ifstream file(tenFile.c_str());
    if (!file.is_open()) {
        cerr << "Khong the mo file " << tenFile << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maSach, tenSach, tacGia, loaiSach,trangThai, ngayXB, maGiaSach;

        getline(ss, maSach, ';');
        getline(ss, tenSach, ';');
        getline(ss, tacGia, ';');
        getline(ss, loaiSach, ';');
        getline(ss, trangThai, ';');
        getline(ss, ngayXB, ';');
        getline(ss, maGiaSach);

        Date ngayXuatBan;
        int day, month, year;
        sscanf(ngayXB.c_str(), "%d %d %d", &day, &month, &year);
        ngayXuatBan = Date(day, month, year);

        Sach* sach = new Sach(maSach, tenSach, tacGia, loaiSach,trangThai, ngayXuatBan);

        GiaSach* giaSach = NULL;
        for (int i = 0; i < dsGiaSach.size(); i++) {
            if (dsGiaSach[i]->getMaGiaSach() == maGiaSach) {
                giaSach = dsGiaSach[i];
                break;
            }
        }

        if (!giaSach) {
            giaSach = new GiaSach(maGiaSach);
            dsGiaSach.add(giaSach);
        }

        giaSach->themSach(sach);
    }

    file.close();
}

void QuanLyGiaSach::luuSachVaoFile(const string& tenFile) {
    ofstream file(tenFile.c_str());
    if (!file.is_open()) {
        cerr << "Khong the mo file " << tenFile << " da ghi du lieu." << endl;
        return;
    }

    for (int i = 0; i < dsGiaSach.size(); ++i) {
        GiaSach* giaSach = dsGiaSach[i];
        Linklist<Sach*> dsSach = giaSach->getDanhSachSach();

        for (int j = 0; j < dsSach.size(); ++j) {
            Sach* sach = dsSach[j];
            file << sach->getId() << ";"
                 << sach->getName() << ";"
                 << sach->getAuthor() << ";"
                 << sach->getType() << ";"
                 << sach->getTrangThai() << ";"
                 << sach->getDate().toString() << ";"
                 << giaSach->getMaGiaSach() << endl;
        }
    }

    file.close();
    cout << "Du lieu da duoc luu vao file " << tenFile << " thanh cong!" << endl;
}


