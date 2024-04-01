// Fitur untuk Pelanggan Warnet:
// 1. Pembelian Billing: Pelanggan dapat membeli billing untuk penggunaan
//    internet di warnet.
// 2. Login: Pelanggan dapat melakukan login ke dalam sistem untuk mengakses layanan
//    internet dan fitur lainnya.
// 3. Pembelian Minuman: Pelanggan dapat membeli minuman yang tersedia di warnet.
// 4. Pembelian Makanan: Pelanggan dapat membeli makanan yang tersedia di warnet.
// 5. Pemilihan Game: Pelanggan dapat memilih game yang ingin dimainkan dari daftar
// game yang tersedia.

// Fitur untuk Operator Warnet:
// 1. Instalasi Game: Operator dapat menginstal game baru ke dalam sistem untuk ditawarkan
//    kepada pelanggan.
// 2. Manajemen PC: Operator dapat mengawasi dan mengelola penggunaan PC di warnet,
//    termasuk mengontrol waktu penggunaan.
// 3. Manajemen Akun: Operator dapat mengelola akun pelanggan, termasuk pendaftaran baru,
//    pembayaran, dan perpanjangan billing.
// 4. Penambahan Menu: Operator dapat menambahkan menu baru untuk minuman dan makanan
//    yang akan dijual di warnet.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i, choice;

void Pelanggan();
//void Billing();
//void LoginPelanggan();

void OP();
//void MenuOP();

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
        OP();
        break;
    case 3:
        printf("Exiting Program.");
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
        //Billing();
        break;
    case 2:
        //LoginPelanggan();
        break;
    default:
        main();
        break;
    }
}

void OP()
{
    char AID[100], pass[100];
    printf("*UI*\n");
    printf("Admin ID :\n");
    gets(AID);
    printf("Password :\n");
    gets(pass);
    if (strcmp(AID, "xxadminxx123") == 0 && strcmp(pass, "opganteng") == 0)
    {
        //MenuOP();
    }
    else
        {
            // gatau something kesempatan or exit program
        }
}