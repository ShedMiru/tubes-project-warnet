#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int x, i, choice, money, kembalian;
char Orderan[100], confirm[100], CurrentAcc[100];
time_t t;
struct tm waktu;

// fungsi & void pelanggan
void Pelanggan();
void LoginPelanggan();
void regispelanggan();
void menupelanggan();
void BeliBilling();
void OrderMakan();
void OrderMinum();
void Games();
void Perjam();
void PM();

// fungsi & void OP
int OP(int);
void MenuOP();

struct
{
    char username[100], pass[100];
} AkunP;

struct
{
    char NamaMakan[100];
    int HargaMakan;
} Makan;

struct
{
    char NamaMinum[100];
    int HargaMinum;
} Minum;

struct
{
    char NamaPesanan[100], NamaAcc[100];
} Pesanan;

struct
{
    char Acc[100];
    int hour, min;
} BillingGame;

FILE *fp;
FILE *fr;

// Menu Utama
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
        printf("Exiting Program...");
        break;
    default:
        main();
        break;
    }
}

// bagian pelanggan
void Pelanggan()
{
    system("cls");
    printf("*UI*\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("Pilih: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        LoginPelanggan();
        break;
    case 2:
        regispelanggan();
        break;
    default:
        printf("Pilihan tidak tersedia");
        system("pause");
        Pelanggan();
    }
}

void regispelanggan()
{
    char username[100];
    fp = fopen("datapelanggan.dat", "ab");
    fr = fopen("datapelanggan.dat", "rb");
lup:
    system("cls");
    fflush(stdin);
    printf("=======REGISTER=======\n");
    printf("Username: ");
    gets(username);
    while (fread(&AkunP, sizeof(AkunP), 1, fr))
    {
        if (strcmp(username, AkunP.username) == 0)
        {
            printf("Username telah dipakai, silahkan pilih username lain\n");
            system("pause");
            goto lup;
        }
    }
    strcpy(AkunP.username, username);
    printf("Password: ");
    gets(AkunP.pass);
    fwrite(&AkunP, sizeof(AkunP), 1, fp);
    fclose(fp);
    fclose(fr);
    printf("Registrasi Berhasil!!\n");
    system("pause");
    Pelanggan();
}

void LoginPelanggan()
{
    char user[100], pass[100];
    int i;
    for (i = 3; i > 0; i--)
    {
        fflush(stdin);
        system("cls");
        printf("=======LOGIN=======\n");
        printf("Username: ");
        gets(user);
        printf("Password: ");
        gets(pass);

        fr = fopen("datapelanggan.dat", "rb");
        while (fread(&AkunP, sizeof(AkunP), 1, fr))
        {
            if (strcmp(user, AkunP.username) == 0 && strcmp(pass, AkunP.pass) == 0)
            {
                strcpy(CurrentAcc, user);
                printf("LOGIN BERHASIL!!\n");
                i = -1;
                system("pause");
                menupelanggan();
            }
        }
        fclose(fr);

        if (i > 1)
        {
            printf("Username atau password salah, kesempatan sisa %d silahkan coba lagi\n", i - 1);
            system("pause");
        }
        else if (i = 0)
        {
            printf("Kesempatan habis!!\n");
            system("pause");
            main();
        }
    }
}

// Fitur untuk Pelanggan Warnet:
// 1. Pembelian Billing: Pelanggan dapat membeli billing untuk penggunaan
//    internet di warnet.
// 2. Login: Pelanggan dapat melakukan login ke dalam sistem untuk mengakses layanan
//    internet dan fitur lainnya.
// 3. Pembelian Minuman: Pelanggan dapat membeli minuman yang tersedia di warnet.
// 4. Pembelian Makanan: Pelanggan dapat membeli makanan yang tersedia di warnet.
// 5. Pemilihan Game: Pelanggan dapat memilih game yang ingin dimainkan dari daftar
// game yang tersedia.

void menupelanggan()
{
    system("cls");
    printf("*UI*\n");
    printf("1. Beli Billing\n");
    printf("2. Pesan Makanan\n");
    printf("3. Pesan Minuman\n");
    printf("4. Games\n");
    printf("5. Logout\n");
    printf("Pilih : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        BeliBilling();
        break;
    case 2:
        OrderMakan();
        break;
    case 3:
        OrderMinum();
        break;
    case 4:
        Games();
        break;
    case 5:
        printf("Logout dan kembali ke menu utama.\n");
        system("pause");
        main();
        break;
    default:
        printf("Pilihan tidak ditemukan.\n");
        menupelanggan();
        break;
    }
}

void BeliBilling()
{
    system("cls");
    printf("*UI*\n");
    printf("\n   Pembelian Billing :");
    printf("\n       Rp.5000/Jam    \n");
    printf("\n    Paket Malam Mulai ");
    printf("\n    Jam 22.00 - 06.00 ");
    printf("\n     Hanya Rp.30000!  \n");
    printf("\n1. Beli Perjam");
    printf("\n2. Paket Malam");
    printf("\n3. Kembali");
    printf("\nPilih : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Perjam();
        break;
    case 2:
        PM();
        break;
    case 3:
        printf("Kembali ke Menu Pelanggan.");
        system("pause");
        menupelanggan();
        break;
    default:
        printf("Pilihan tidak tersedia");
        system("pause");
        BeliBilling();
        break;
    }
}

void Perjam()
{
    t = time(NULL);
    waktu = *localtime(&t);
    int total, jam;
    printf("Billing Perjam\n");
    printf(" Rp.5000/Jam \n");
    printf("Masukan jumlah Jam yang akan dibeli\n");
    scanf("%d", &jam);
    total = jam * 5000;
    printf("\nRincian Billing");
    printf("\nJam         : %d", jam);
    printf("\nTotal harga : Rp.%d", total);
    printf("\nBeli Billing? (Y/N)\n    ");
    getchar();
    gets(confirm);
    fr = fopen("billingperjam.dat", "ab");
    if (strcasecmp(confirm, "Y") == 0)
    {
        printf("Masukan Nominal pembayaran : ");
        scanf("%d", &money);
        if (money > Makan.HargaMakan)
        {
            kembalian = money - Makan.HargaMakan;
            printf("Pembayaran Berhasil!");
            printf("\nTotal Kembalian : %d", kembalian);
            strcpy(BillingGame.Acc, CurrentAcc);
            BillingGame.hour = waktu.tm_hour + jam;
            BillingGame.min = waktu.tm_min;
            fwrite(&BillingGame, sizeof(BillingGame), 1, fr);
            printf("\nBilling berhasil dibeli");
            printf("\n*nunjukin waktu bermain*");
        }
        else if (money == Makan.HargaMakan)
        {
            printf("Pembayaran Berhasil!");
            strcpy(BillingGame.Acc, CurrentAcc);
            BillingGame.hour = waktu.tm_hour + jam;
            BillingGame.min = waktu.tm_min;
            fwrite(&BillingGame, sizeof(BillingGame), 1, fr);
            printf("\nBilling berhasil dibeli");
            printf("\n*nunjukin waktu bermain*");
        }
        else
        {
            printf("Nominal Tidak Mencukupi, pesanan dibatalkan.");
        }
    }
    else
    {
        printf("Pembelian dibatalkan.");
    }
    system("pause");
    fclose(fr);
    menupelanggan();
}

void PM()
{
    printf("\n*belum ges*");
}

void OrderMakan()
{
    x = 0;
    i = 1;
    fr = fopen("ListMakanan.dat", "rb");
    system("cls");
    printf("*UI*\n");
    printf("List Makanan :\n");
    while (fread(&Makan, sizeof(Makan), 1, fr) == 1)
    {
        printf("\n%d. Nama Makanan   : %s", i, Makan.NamaMakan);
        printf("\nHarga          : %d", Makan.HargaMakan);
        i++;
    }
    printf("\n   Silahkan masukan nama makanan yang akan di order");
    printf("\nOrder Makanan : ");
    gets(Orderan);
    rewind(fr);
    while (fread(&Makan, sizeof(Makan), 1, fr) == 1)
    {
        if (strcmp(Orderan, Makan.NamaMakan) == 0)
        {
            fp = fopen("ListPesanan.dat", "ab");
            x = 1;
            printf("\nNama Makanan   : %s", Makan.NamaMakan);
            printf("\nHarga          : %d", Makan.HargaMakan);
            printf("\nPesan Makanan? (Y/N)\n    ");
            gets(confirm);
            if (strcasecmp(confirm, "Y") == 0)
            {
                printf("Masukan Nominal pembayaran : ");
                scanf("%d", &money);
                if (money > Makan.HargaMakan)
                {
                    kembalian = money - Makan.HargaMakan;
                    printf("Pembayaran Berhasil!");
                    printf("\nTotal Kembalian : %d", kembalian);
                    strcpy(Pesanan.NamaAcc, CurrentAcc);
                    strcpy(Pesanan.NamaPesanan, Makan.NamaMakan);
                    fwrite(&Pesanan, sizeof(Pesanan), 1, fp);
                    printf("\nPesanan berhasil dilakukan, silahkan ditunggu.");
                }
                else if (money == Makan.HargaMakan)
                {
                    printf("Pembayaran Berhasil!");
                    strcpy(Pesanan.NamaAcc, CurrentAcc);
                    strcpy(Pesanan.NamaPesanan, Makan.NamaMakan);
                    fwrite(&Pesanan, sizeof(Pesanan), 1, fp);
                    printf("\nPesanan berhasil dilakukan, silahkan ditunggu.");
                }
                else
                {
                    printf("Nominal Tidak Mencukupi, pesanan dibatalkan.");
                }
                fclose(fp);
            }
            else
            {
                printf("Pembelian dibatalkan.");
            }
        }
    }
    if (x != 1)
    {
        printf("\n\tMakanan tidak ditemukan, Order gagal");
        printf("\n\t\tKembali Ke Menu.\n");
    }
    system("pause");
    fclose(fr);
    menupelanggan();
}

void OrderMinum()
{
    x = 0;
    i = 1;
    fr = fopen("ListMinuman.dat", "rb");
    system("cls");
    printf("*UI*\n");
    printf("List Minuman :\n");
    while (fread(&Minum, sizeof(Minum), 1, fr) == 1)
    {
        printf("\n%d. Nama Minuman   : %s", i, Minum.NamaMinum);
        printf("\nHarga          : %d", Minum.HargaMinum);
        i++;
    }
    printf("\n   Silahkan masukan nama Minuman yang akan di order");
    printf("\nOrder Minuman : ");
    gets(Orderan);
    rewind(fr);
    while (fread(&Minum, sizeof(Minum), 1, fr) == 1)
    {
        if (strcmp(Orderan, Minum.NamaMinum) == 0)
        {
            fp = fopen("ListPesanan.dat", "ab");
            x = 1;
            printf("\nNama Minuman   : %s", Minum.NamaMinum);
            printf("\nHarga          : %d", Minum.HargaMinum);
            printf("\nPesan Minuman? (Y/N)\n    ");
            gets(confirm);
            if (strcasecmp(confirm, "Y") == 0)
            {
                printf("Masukan Nominal pembayaran : ");
                scanf("%d", &money);
                if (money > Minum.HargaMinum)
                {
                    kembalian = money - Minum.HargaMinum;
                    printf("Pembayaran Berhasil!");
                    printf("\nTotal Kembalian : %d", kembalian);
                    strcpy(Pesanan.NamaAcc, CurrentAcc);
                    strcpy(Pesanan.NamaPesanan, Minum.NamaMinum);
                    fwrite(&Pesanan, sizeof(Pesanan), 1, fp);
                    printf("\nPesanan berhasil dilakukan, silahkan ditunggu.");
                }
                else if (money == Minum.HargaMinum)
                {
                    printf("Pembayaran Berhasil!");
                    strcpy(Pesanan.NamaAcc, CurrentAcc);
                    strcpy(Pesanan.NamaPesanan, Minum.NamaMinum);
                    fwrite(&Pesanan, sizeof(Pesanan), 1, fp);
                    printf("\nPesanan berhasil dilakukan, silahkan ditunggu.");
                }
                else
                {
                    printf("Nominal Tidak Mencukupi, pesanan dibatalkan.");
                    system("Pause");
                }
                fclose(fp);
            }
            else
            {
                printf("Pembelian dibatalkan.");
                system("pause");
            }
        }
    }
    if (x != 1)
    {
        printf("\n\tMinuman tidak ditemukan, Order gagal");
        printf("\n\t\tKembali Ke Menu.\n");
        system("pause");
    }
    fclose(fr);
    menupelanggan();
}

void Games()
{
    printf("\n*belum ges*");
}

// Bagian OP
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

// yaudah, nanti praktikan cari alternatif sendiri
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
    printf("5. Logout\n");
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
