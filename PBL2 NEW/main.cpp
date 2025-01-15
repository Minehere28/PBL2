#include <iostream>
#include <cstdlib> // Cho system("cls")
#ifdef _WIN32
#include <windows.h> // Windows-specific Sleep
#else
#include <unistd.h> // POSIX-specific sleep
#endif

#include "LinkList.cpp"
#include "Date.cpp"
#include "Sach.cpp"
#include "GiaSach.cpp"
#include "TheMuonSV.cpp"
#include "ChiTietMuon.cpp"
#include "QuanLyGiaSach.cpp"
#include "QuanLyTheMuonSV.cpp"
#include "menu.cpp"
using namespace std;

QuanLyGiaSach qlgs("QLGS001");
QuanLyTheMuonSV qltm("QLTM001");

int main()
{
    start();

    try
    {
        // Đọc dữ liệu sách từ file
        qlgs.docSachTuFile("sach.txt");
    }
    catch (const exception &e)
    {
        cerr << "Loi khi doc file sach: " << e.what() << endl;
    }

    try
    {
        // Đọc dữ liệu thẻ mượn từ file
        qltm.docTheMuonTuFile("themuon.txt", "chitietmuon.txt");
    }
    catch (const exception &e)
    {
        cerr << "Loi khi doc file the muon: " << e.what() << endl;
    }

    int luaChon;
    do
    {
        menu();
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
        { // Quản lý sách
            int luaChonSach;
            do
            {
                clearAndShowBookMenu();
                cin >> luaChonSach;
                cin.ignore();

                switch (luaChonSach)
                {
                case 1:
                { // Thêm sách
                    int luaChonThemSach;
                    do
                    {
                        clearAndAddBookMenu();
                        cout << "Lua chon cua ban: ";
                        cin >> luaChonThemSach;
                        cin.ignore();
                        clearScreen();

                        switch (luaChonThemSach)
                        {
                        case 1:
                        { // Thêm sách vào giá sách hiện có
                            clearAndAddBookMenu();
                            qlgs.themSachVaoGSDaCo(qlgs.getDSGiaSach());
                            break;
                        }
                        case 2:
                        { // Tạo giá sách mới và thêm sách
                            clearAndAddBookMenu();
                            qlgs.themSachVaoGSMoi(qlgs.getDSGiaSach());
                            break;
                        }
                        case 0:
                            cout << "Quay lai menu quan ly sach." << endl;
                            break;
                        default:
                            cout << "Lua chon khong hop le! Vui long thu lai." << endl;
                            break;
                        }
                        if (luaChonThemSach != 0)
                        {
                            cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                            cin.get(); 
                        }
                    } while (luaChonThemSach != 0);
                    break;
                }
                case 2:
                { // Xóa sách theo ID
                    qlgs.xoaSachTheoID();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get(); 
                    break;
                }
                case 3:
                { // Hiển thị danh sách sách

                    int luaChonHienThi;
                    do
                    {
                        clearAndDisplayBookMenu();
                        cout << "Lua chon cua ban: ";
                        cin >> luaChonHienThi;
                        cin.ignore();
                        clearScreen();

                        switch (luaChonHienThi)
                        {
                        case 1:
                        { // Hiển thị sách theo mã giá sách
                            clearAndDisplayBookMenu();
                            qlgs.hienThiSachTrongGiaSach();
                            break;
                        }
                        case 2:
                        { // Hiển thị tất cả sách
                            clearAndDisplayBookMenu();
                            qlgs.hienThiDanhSachTatCaGiaSach();
                            break;
                        }
                        case 0:
                            cout << "Quay lai menu quan ly sach." << endl;
                            break;
                        default:
                            cout << "Lua chon khong hop le! Vui long thu lai." << endl;
                            break;
                        }
                        if (luaChonHienThi != 0)
                        {
                            cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                            cin.get(); // Tạm dừng để người dùng đọc nội dung
                        }
                    } while (luaChonHienThi != 0);
                    break;
                }
                case 4:
                { // Tìm sách theo ID
                    qlgs.timSachTheoID();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get(); 
                    break;
                }
                case 5:
                { // Cập nhật sách theo ID
                    qlgs.capNhatSachTheoID();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 0:
                    cout << "...Quay lai menu chinh..." << endl;
                    clearScreen();
                    break;
                default:
                    cout << "Lua chon khong hop le! Vui long thu lai." << endl;
                    break;
                }
            } while (luaChonSach != 0);
            break;
        }

        case 2:
        { // Quản lý thẻ mượn
            int luaChonTheMuon;
            do
            {
                clearAndShowCardMenu();
                cin >> luaChonTheMuon;
                cin.ignore();

                switch (luaChonTheMuon)
                {
                case 1:
                {
                    qltm.themTheMuonSV();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get(); 
                    break;
                }
                case 2:
                {
                    qltm.xoaTheMuon();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 3:
                {
                    qltm.inDanhSachMuonTheoMaSV();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get(); 
                    break;
                }
                case 4:
                {
                    qltm.inDanhSachTatCaTheMuon();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 5:
                {
                    qltm.danhSachSinhVienTreHan();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 6:
                {
                    qltm.themSachMuon(qlgs.getDSGiaSach(), qltm.getDanhSachTheMuon());
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 7:
                {
                    qltm.traSachMuon(qlgs.getDSGiaSach(), qltm.getDanhSachTheMuon());
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get();
                    break;
                }
                case 8:
                {
                    qltm.inSinhVienMuon5Cuon();
                    cout << "\nNhan phim bat ky de tiep tuc..." << endl;
                    cin.get(); 
                    break; 
                }
                case 0:
                    cout << "...Quay lai menu chinh..." << endl;
                    clearScreen();
                    break;
                default:
                    cout << "Lua chon khong hop le!" << endl;
                    break;
                }
            } while (luaChonTheMuon != 0);
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            qlgs.luuSachVaoFile("sach.txt");
            qltm.luuTheMuonVaoFile("themuon.txt", "chitietmuon.txt", qltm.getDanhSachTheMuon());
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
    } while (luaChon != 0);

    return 0;
}
