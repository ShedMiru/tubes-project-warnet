// Fitur untuk Pelanggan Warnet:
// 1. Pembelian Billing: Pelanggan dapat membeli billing untuk penggunaan
//    internet di warnet.
// 2. Login: Pelanggan dapat melakukan login ke dalam sistem untuk mengakses layanan
//    internet dan fitur lainnya.
// 3. Pembelian Minuman: Pelanggan dapat membeli minuman yang tersedia di warnet.
// 4. Pembelian Makanan: Pelanggan dapat membeli makanan yang tersedia di warnet.
// 5. Pemilihan Game: Pelanggan dapat memilih game yang ingin dimainkan dari daftar
// game yang tersedia.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i, choice;

void Pelanggan();
// void Billing();
// void LoginPelanggan();

int OP(int);
void MenuOP();

void main()
{
    system("cls");
    printf("*UI*\n");
    printf("1. Pelanggan\n");
    printf("2. OP\n");
    printf("3. Exit\n");
    printf("Pilih : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Pelanggan();
        break;
    case 2:
        getchar();
        OP(2);
        break;
    case 3:
        system("cls");
        printf("Exiting Program. . .");
        break;
    default:
        main();
        break;
    }
}

void Pelanggan()
{
    printf("*UI*\n");
    printf("1. Beli Billing\n");
    printf("2. Login\n");
    printf("Pilih : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // Billing();
        break;
    case 2:
        // LoginPelanggan();
        break;
    default:
        printf("Pilihan tidak ditemukan, kembali ke Menu\n");
        system("pause");
        main();
        break;
    }
}

int OP(int n)
{
    char AID[50], pass[50];
    printf("*UI*\n");
    printf("Admin ID : ");
    gets(AID);
    printf("Password : ");
    gets(pass);
    if (strcmp(AID, "admin123") == 0 && strcmp(pass, "opganteng") == 0)
    {
        printf("\nLogin Berhasil!\n");
        system("pause");
        MenuOP();
    }
    else if (n > 0)
    {
        printf("\nID atau Password salah.\n");
        printf("%d kesempatan tersisa.\n\n", n);
        OP(n - 1);
    }
    else
    {
        printf("\nID atau Password salah.\n");
        printf("Kembali ke menu utama.\n");
        system("pause");
        main();
    }
}

// Fitur untuk Operator Warnet:
// 1. Instalasi Game: Operator dapat menginstal game baru ke dalam sistem untuk ditawarkan
//    kepada pelanggan.
// 2. Manajemen PC: Operator dapat mengawasi dan mengelola penggunaan PC di warnet,
//    termasuk mengontrol waktu penggunaan.
// 3. Manajemen Akun: Operator dapat mengelola akun pelanggan, termasuk pendaftaran baru,
//    pembayaran, dan perpanjangan billing.
// 4. Penambahan Menu: Operator dapat menambahkan menu baru untuk minuman dan makanan
//    yang akan dijual di warnet.

void MenuOP()
{
    system("cls");
    printf("*UI*\n");
    printf("1. Install Game\n");
    printf("2. Manage PC\n");
    printf("3. Manage Akun\n");
    printf("4. Add Menu\n");
    printf("5. Kembali ke Menu Utama\n");
    printf("Pilih : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // Install Game
        break;
    case 2:
        // Manage PC
        break;
    case 3:
        // Manage Akun
        break;
    case 4:
        // Add Menu
        break;
    case 5:
        printf("Kembali ke menu utama.\n");
        system("pause");
        main();
        break;
    default:
        printf("Pilihan tidak ditemukan.\n");
        MenuOP();
        break;
    }
}