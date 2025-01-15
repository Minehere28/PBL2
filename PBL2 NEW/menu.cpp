#include <iostream>
#include <cstdlib> // Cho system("cls")
#ifdef _WIN32
#include <windows.h> // Windows-specific Sleep
#else
#include <unistd.h> // POSIX-specific sleep
#endif
#include "menu.h"

using namespace std;


// Giao dien ban dau
void start()
{
    printf("\n\n");
    printf("\033[1;34m");
    printf("                    %c%c%c%c%c                                                                       %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("                    %c                                                                               %c\n\n", 186, 186);
    printf("                                              PBL2: DO AN CO SO LAP TRINH                            \n");
    printf("                                       DE TAI: XAY DUNG UNG DUNG QUAN LY THU VIEN                           \n");
    printf("                                                                                                     \n\n");
    printf("                                         Giang Vien Huong Dan:   Dang Hoai Phuong                   \n");
    printf("                                         Sinh Vien Thuc Hien :   Huynh Thao Nhi                     \n");
    printf("                                                                 Nguyen Thi Suong Mai               \n\n");
    printf("                    %c                                                                               %c\n", 186, 186);
    printf("                    %c%c%c%c%c                                                                       %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("");
    printf("                    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          \n\n");
    printf("\033[0m");
    printf("\n\n");
}

void title()
{
    printf("\n\n");
    printf("\033[1;34m");
    printf("                    %c%c%c%c%c                                                                       %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("                    %c                                                                               %c\n\n", 186, 186);
    printf("                                              PBL2: DO AN CO SO LAP TRINH                            \n");
    printf("                                       DE TAI: XAY DUNG UNG DUNG QUAN LY THU VIEN                           \n");
    printf("");
    printf("                    %c                                                                               %c\n", 186, 186);
    printf("                    %c%c%c%c%c                                                                       %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("");
    printf("                    _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          \n\n");
    printf("\033[0m");
    printf("\n\n");
}

// clear screen func
void clearScreen()
{
#ifdef _WIN32
    Sleep(200); // Trong Windows, thời gian tính bằng mili giây (ms)
    system("cls");
#else
    sleep(1.5); // Trong Unix/Linux, thời gian tính bằng giây
    system("clear");
#endif
    title();
    // menu();
}
void menu()
{
    printf("\n\n");
    printf("\033[1;32m");
    printf("         %c%c%c%c%c                                  %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("         %c                                          %c\n", 186, 186);
    printf("                    MENU QUAN LY THU VIEN         \n");
    printf("         %c                                          %c\n", 186, 186);
    printf("         %c%c%c%c%c                                  %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n");

    printf("\033[1;32m"); // Đổi màu menu chính sang xanh lá cây
    printf("       \t1. Quan ly sach\n");
    printf("       \t2. Quan ly the muon\n");
    printf("       \t0. Thoat chuong trinh\n");
    printf("\033[0m");
    printf("\n");
    cout << "==================================" << endl;

    printf("Nhap lua chon cua ban: ");
}


void clearAndShowBookMenu()
{
    clearScreen();
    
    printf("\n\n");
    printf("\033[92m");
    printf("         %c%c%c%c%c                        %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("         %c                                %c\n", 186, 186);
    printf("                    QUAN LY SACH         \n");
    printf("         %c                                %c\n", 186, 186);
    printf("         %c%c%c%c%c                        %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n");
    
    printf("       \t1. Them sach\n");
    printf("       \t2. Xoa sach theo ID\n");
    printf("       \t3. Hien thi danh sach sach\n");
    printf("       \t4. Tim sach theo ID\n");
    printf("       \t5. Cap nhat thong tin sach theo ID\n");
    printf("       \t0. Quay lai menu chinh\n");
    printf("\033[0m");
    printf("\n");
    cout << "==================================" << endl;

    printf("Nhap lua chon cua ban: ");
}

// void clearAndShowCardMenu()
// {
//     clearScreen();
//     cout << "\n========== QUAN LY THE MUON ==========" << endl;
//     cout << "1. Them the muon" << endl;
//     cout << "2. Xoa the muon theo ma sinh vien" << endl;
//     cout << "3. In danh sach muon theo ma sinh vien" << endl;
//     cout << "4. In toan bo danh sach the muon" << endl;
//     cout << "5. Danh sach sinh vien tre han" << endl;
//     cout << "6. Muon sach" << endl;
//     cout << "7. Tra sach" << endl;
//     cout << "8. Sinh vien muon du 5 cuon sach" << endl;
//     cout << "0. Quay lai menu chinh." << endl;
//     cout << "==================================" << endl;
//     cout << "Lua chon cua ban: ";
// }

// void clearAndAddBookMenu()
// {
//     clearScreen();
//     cout << "\n========== THEM SACH ==========" << endl;
//     cout << "1. Them sach vao gia sach hien co" << endl;
//     cout << "2. Tao gia sach moi va them sach" << endl;
//     cout << "0. Quay lai menu quan ly sach" << endl;
//     cout << "==================================" << endl;
// }

// void clearAndDisplayBookMenu()
// {
//     clearScreen();
//     cout << "\n========== HIEN THI SACH ==========" << endl;
//     cout << "1. Hien thi danh sach theo ma gia sach" << endl;
//     cout << "2. Hien thi tat ca sach" << endl;
//     cout << "0. Quay lai menu quan ly sach" << endl;
//     cout << "==================================" << endl;
// }

void clearAndShowCardMenu()
{
    clearScreen();

    printf("\n\n");
    printf("\033[92m");
    printf("         %c%c%c%c%c                        %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("         %c                                %c\n", 186, 186);
    printf("                 QUAN LY THE MUON         \n");
    printf("         %c                                %c\n", 186, 186);
    printf("         %c%c%c%c%c                        %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n");

    printf("       \t1. Them the muon\n");
    printf("       \t2. Xoa the muon theo ma sinh vien\n");
    printf("       \t3. In danh sach muon theo ma sinh vien\n");
    printf("       \t4. In toan bo danh sach the muon\n");
    printf("       \t5. Danh sach sinh vien tre han\n");
    printf("       \t6. Muon sach\n");
    printf("       \t7. Tra sach\n");
    printf("       \t8. Sinh vien muon du 5 cuon sach\n");
    printf("       \t0. Quay lai menu chinh\n");
    printf("\033[0m");
    printf("\n");
    cout << "==================================" << endl;
    printf("Nhap lua chon cua ban: ");
}

void clearAndAddBookMenu()
{
    clearScreen();

    printf("\n\n");
    printf("\033[92m");
    printf("         %c%c%c%c%c                 %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("         %c                         %c\n", 186, 186);
    printf("                  THEM SACH              \n");
    printf("         %c                         %c\n", 186, 186);
    printf("         %c%c%c%c%c                 %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n");

    printf("       \t1. Them sach vao gia sach hien co\n");
    printf("       \t2. Tao gia sach moi va them sach\n");
    printf("       \t0. Quay lai menu quan ly sach\n");
    printf("\033[0m");
    printf("\n");
}

void clearAndDisplayBookMenu()
{
    clearScreen();

    printf("\n\n");
    printf("\033[92m");
    printf("         %c%c%c%c%c                  %c%c%c%c%c                   \n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("         %c                          %c\n", 186, 186);
    printf("                HIEN THI SACH            \n");
    printf("         %c                          %c\n", 186, 186);
    printf("         %c%c%c%c%c                  %c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n");

    printf("       \t1. Hien thi danh sach theo ma gia sach\n");
    printf("       \t2. Hien thi tat ca sach\n");
    printf("       \t0. Quay lai menu quan ly sach\n");
    printf("\033[0m");
    printf("\n");
}


void clearAndShowMainMenu()
{
    clearScreen();
    menu();
}
