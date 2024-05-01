#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// fungsi & void pelanggan
void Pelanggan();
void LoginPelanggan();
void regispelanggan();
void menupelanggan();
void OrderMakan();
void OrderMinum();
void orderPayment();
void Games();
void seeStatus();
void playingGames(char[100]);

// fungsi & void OP
int loginOP(int);
void MenuOP();
void game();
void addGame();
void displayAllGames();
void pc();
void installPC();
void findPCById();
void account();
void createAccount();
void findAccountByUsername();
void deleteAccountById(int);
void food();
void addFood();
void displayFoodMenu();
void seeOrder();
void changeStatus(int);

// Struct untuk data akun
struct Account
{
    char username[100];
    char password[100];
    int id;
};

// Struct untuk data makanan
struct Food
{
    char name[100];
    char category[100];
    double price;
};

struct Order
{
    char OrderName[100], AccName[100], orderstatus[100];
};

// Struct untuk data PC
struct pc
{
    char name[100], date[100];
    int id;
};

// Struct untuk data game
struct InstallGame
{
    char name[100], category[100];
};

// file declaration
FILE *installGame;
FILE *installPc;
FILE *accountFile;
FILE *foodFile;
FILE *orderFile;
FILE *tempFile;

// global var
int x, i, choice, id, idtemp[100];
int count;
double money, kembalian;
char Orderan[100], confirm[100], CurrentAcc[100];
char pilih[100], user[100], pass[100];

// Menu Utama
int main()
{
    installGame = fopen("game.dat", "ab");
    installPc = fopen("pc.dat", "ab");
    accountFile = fopen("accounts.dat", "ab");
    foodFile = fopen("menu.dat", "ab");
    orderFile = fopen("order.dat", "ab");

    if (installGame == NULL || installPc == NULL || accountFile == NULL || foodFile == NULL || orderFile == NULL)
    {
        printf("Error opening files!\n");
        return 1;
    }

    fclose(installGame);
    fclose(installPc);
    fclose(accountFile);
    fclose(foodFile);

    system("cls");
    printf("===============================================================|-|%c|x|\n", 254);
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |     Currently Playing...                      ___ ______       | |\n");
    printf("| |     ||\\\\ '' \\\\       // //\\   ||\\\\  ||\\  || ||      ||         | |\n");
    printf("| |     || ||    \\\\ //\\ // //==\\  || // || \\\\|| ||===   ||         | |\n");
    printf("| |     ||//      \\\\/ \\\\/ //    \\ ||\\\\  ||  \\\\| ||___   ||         | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("======================================================================\n");
    printf("1. Pelanggan\n");
    printf("2. Operator\n");
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
        loginOP(2);
        break;
    case 3:
        system("cls");
        printf("Exiting Program...");
        break;
    default:
        main();
        break;
    }
    return 0;
}

// bagian pelanggan
// Fitur untuk Pelanggan Warnet:
// 1. Pembelian Billing: Pelanggan dapat membeli billing untuk penggunaan
//    internet di warnet.
// 2. Login: Pelanggan dapat melakukan login ke dalam sistem untuk mengakses layanan
//    internet dan fitur lainnya.
// 3. Pembelian Minuman: Pelanggan dapat membeli minuman yang tersedia di warnet.
// 4. Pembelian Makanan: Pelanggan dapat membeli makanan yang tersedia di warnet.
// 5. Pemilihan Game: Pelanggan dapat memilih game yang ingin dimainkan dari daftar
// game yang tersedia.
void Pelanggan()
{
    system("cls");
    printf("  Pilih 1 bila sudah memiliki akun, pilih 2 bila belum memiliki akun\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Kembali ke Menu\n");
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
    case 3:
        printf("Logout dan kembali ke menu utama...\n");
        system("pause");
        main();
        break;
    default:
        printf("Pilihan tidak tersedia...\n");
        system("pause");
        Pelanggan();
    }
}

void regispelanggan()
{
    count = 0;
    struct Account regs;
    accountFile = fopen("accounts.dat", "a+b");
    if (accountFile == NULL)
    {
        printf("Error opening account file!\n");
        return;
    }
lup:
    system("cls");
    fflush(stdin);
    printf("======= REGISTER =======\n");
    printf("Username: ");
    gets(user);
    while (fread(&regs, sizeof(struct Account), 1, accountFile))
    {
        if (strcmp(user, regs.username) == 0)
        {
            printf("Username telah dipakai, silahkan pilih username lain\n");
            system("pause");
            rewind(accountFile);
            goto lup;
        }
    }
    rewind(accountFile);
    printf("Password: ");
    gets(pass);
    id = strlen(pass) * strlen(user);
    while (fread(&regs, sizeof(struct Account), 1, accountFile))
    {
        idtemp[count] = regs.id;
        count++;
    }
    x = 0;
    for (i = 0; i < count; i++)
    {
        if (idtemp[i] == id)
        {
            printf("id %d\n", id);
            if (x == 0)
            {
                id = id + strlen(pass);
                x = 1;
            }
            else
            {
                id = id + strlen(user);
                x = 0;
            }
            i = 0;
        }
    }
    strcpy(regs.username, user);
    strcpy(regs.password, pass);
    regs.id = id;
    printf("Account ID : %d\n", id);
    fwrite(&regs, sizeof(struct Account), 1, accountFile);
    fclose(accountFile);
    printf("Registrasi Berhasil!!\n");
    system("pause");
    Pelanggan();
}

void LoginPelanggan()
{
    struct Account login;
    char user[100], pass[100];
    int i;
    for (i = 3; i > 0; i--)
    {
        fflush(stdin);
        system("cls");
        printf("======= LOGIN =======\n");
        printf("Username: ");
        gets(user);
        printf("Password: ");
        gets(pass);

        accountFile = fopen("accounts.dat", "rb");
        while (fread(&login, sizeof(struct Account), 1, accountFile))
        {
            if (strcmp(user, login.username) == 0 && strcmp(pass, login.password) == 0)
            {
                strcpy(CurrentAcc, user);
                printf("LOGIN BERHASIL!!\n");
                i = -1;
                system("pause");
                menupelanggan();
            }
        }
        fclose(accountFile);

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

void menupelanggan()
{
    system("cls");
    printf("=============================\n");
    printf("=    Welcome To D'Warnet    = \n");
    printf("=============================\n");
    printf("1. Pesan Makanan\n");
    printf("2. Pesan Minuman\n");
    printf("3. Games\n");
    printf("4. Lihat Status Pesanan\n");
    printf("5. Logout\n");
    printf("Pilih : ");
    scanf("%d", &choice);

    fflush(stdin);
    switch (choice)
    {
    case 1:
        OrderMakan();
        break;
    case 2:
        OrderMinum();
        break;
    case 3:
        Games();
        break;
    case 4:
        seeStatus();
        break;
    case 5:
        printf("Logout dan kembali ke menu utama...\n");
        system("pause");
        main();
        break;
    default:
        printf("Pilihan tidak ditemukan...\n");
        menupelanggan();
        break;
    }
}

void OrderMakan()
{
    foodFile = fopen("menu.dat", "rb");

    if (foodFile == NULL)
    {
        printf("Error opening food menu file!\n");
        return;
    }
    system("cls");
    struct Food goods;

    printf("Foods Menu:\n");
    printf(" Name\t |Price\n");
    printf("======================\n");
    while (fread(&goods, sizeof(struct Food), 1, foodFile))
    {
        if (strcasecmp(goods.category, "food") == 0)
        {
            printf("%s\t |%.2lf\n", goods.name, goods.price);
        }
    }
    orderPayment();
}

void OrderMinum()
{
    foodFile = fopen("menu.dat", "rb");

    if (foodFile == NULL)
    {
        printf("Error opening food menu file!\n");
        return;
    }
    struct Food goods;

    system("cls");
    printf("Drinks Menu:\n");
    printf(" Name\t |Price\n");
    printf("======================\n");
    while (fread(&goods, sizeof(struct Food), 1, foodFile))
    {
        if (strcasecmp(goods.category, "drink") == 0)
        {
            printf("%s\t |%.2lf\n", goods.name, goods.price);
        }
    }
    orderPayment();
}

void orderPayment()
{
    x = 0;
    i = 1;
    foodFile = fopen("menu.dat", "rb");
    orderFile = fopen("order.dat", "ab");

    if (foodFile == NULL || orderFile == NULL)
    {
        printf("Error opening food menu file!\n");
        return;
    }
    struct Food goods;
    struct Order theOrder;

    printf("\n   Silahkan masukan nama makanan yang akan di order");
    printf("\nOrder Makanan : ");
    gets(Orderan);

    while (fread(&goods, sizeof(struct Food), 1, foodFile) == 1)
    {
        if (strcmp(goods.name, Orderan) == 0)
        {
            x = 1;
            printf("\nNama Makanan   : %s", goods.name);
            printf("\nHarga          : %.2lf", goods.price);
            printf("\nPesan Makanan? (Y/N)\n    ");
            gets(confirm);
            if (strcasecmp(confirm, "Y") == 0)
            {
                printf("Masukan Nominal pembayaran : ");
                scanf("%lf", &money);
                if (money < goods.price)
                {
                    printf("Nominal Tidak Mencukupi, pesanan dibatalkan.\n");
                }
                else
                {
                    printf("Pembayaran Berhasil!");
                    if (money > goods.price)
                    {
                        kembalian = money - goods.price;
                        printf("\nTotal Kembalian : %.2lf", kembalian);
                    }
                    strcpy(theOrder.AccName, CurrentAcc);
                    strcpy(theOrder.OrderName, goods.name);
                    strcpy(theOrder.orderstatus, "Waiting for staff");
                    fwrite(&theOrder, sizeof(struct Order), 1, orderFile);
                    printf("\nPesanan berhasil dilakukan, silahkan ditunggu.\n");
                }
            }
            else
            {
                printf("Pesanan dibatalkan.\n");
            }
        }
    }
    if (x != 1)
    {
        printf("\n\tMakanan tidak ditemukan, Order gagal");
        printf("\n\t\tKembali Ke Menu.\n");
    }
    fclose(orderFile);
    fclose(foodFile);
    system("pause");
    menupelanggan();
}

void seeStatus()
{
    count = 0;
    orderFile = fopen("Order.dat", "rb");
    if (orderFile == NULL)
    {
        printf("Error opening order file!\n");
        return;
    }

    struct Order orderlist;

    printf("Orders :\n");
    printf("=================================\n");
    printf("No.| Name\t|Status\n");
    while (fread(&orderlist, sizeof(struct Order), 1, orderFile))
    {
        printf(" %d |%s\t%s\n", ++count, orderlist.OrderName, orderlist.orderstatus);
    }
    fclose(orderFile);
    system("pause");
    menupelanggan();
}

void Games()
{
    x = 0;
    installGame = fopen("game.dat", "rb");
    if (installGame == NULL)
    {
        printf("No games installed yet!\n");
        return;
    }

    struct InstallGame game;
    printf("No.|\tName\t|  Category\n");
    printf("============================\n");
    while (fread(&game, sizeof(struct InstallGame), 1, installGame))
    {
        printf(" %d | %s\t| %s\n", ++count, game.name, game.category);
    }
    printf("\n Pilih Game yang ingin dimainkan : ");
    gets(pilih);
    rewind(installGame);
    while (fread(&game, sizeof(struct InstallGame), 1, installGame))
    {
        if (strcasecmp(game.name, pilih) == 0)
        {
            playingGames(game.name);
            x = 1;
        }
    }
    if (x != 1)
    {
        printf("Game tidak ditemukan!");
    }
    system("pause");
    fclose(installGame);
    menupelanggan();
}

void playingGames(char gameName[100])
{
    printf("|%s|", gameName);
    count = strlen(gameName);
    for (i = 0; i < 61 - count; i++)
    {
        printf("=");
    }
    printf("|-|%c|x|\n", 254);
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                  Verifying file integrity...                   | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |                                                                | |\n");
    printf("| |   TIP : Did you know you can save your games? Only for $9.99!  | |\n");
    printf("======================================================================\n");
    printf("Type EXIT to quit the game\n");
    gets(pilih);
    if (strcasecmp(pilih, "exit") == 0)
    {
        printf("Quitting...\n");
    }
    else
    {
        playingGames(gameName);
    }
}

// Bagian OP
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
int loginOP(int n)
{
    char AID[50], pass[50];
    printf("===== Login Operator =====\n");
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
        loginOP(n - 1);
    }
    else
    {
        printf("\nID atau Password salah.\n");
        printf("Kembali ke menu utama.\n");
        system("pause");
        main();
    }
}

void MenuOP()
{
    system("cls");
    printf("============================\n");
    printf("= Welcome To Operator Mode =\n");
    printf("============================\n");
    printf("1. Game Installation\n");
    printf("2. PC Management\n");
    printf("3. Account Management\n");
    printf("4. Food Management\n");
    printf("5. See Order\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        game();
        break;
    case 2:
        pc();
        break;
    case 3:
        account();
        break;
    case 4:
        food();
        break;
    case 5:
        seeOrder();
        break;
    case 6:
        printf("Kembali ke Menu Utama...\n");
        system("pause");
        main();
        break;
    default:
        printf("Pilihan tidak ditemukan...\n");
        system("pause");
        MenuOP();
        break;
    }
}

void game()
{
    do
    {
        system("cls");
        printf("\n      Game Menu\n");
        printf("1. Add Game\n");
        printf("2. Display All Games\n");
        printf("3. Back to Operator Menu\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addGame();
            break;
        case 2:
            displayAllGames();
            break;
        case 3:
            printf("Kembali ke Menu Utama...\n");
            system("pause");
            MenuOP();
            return;
        default:
            printf("Pilihan tidak ditemukan...\n");
            system("pause");
            fflush(stdin);
        }
    } while (1);
}

void addGame()
{
    getchar();
    installGame = fopen("game.dat", "ab");
    if (installGame == NULL)
    {
        printf("Error opening game file!\n");
        return;
    }
    struct InstallGame newGame;

    printf("Enter game name: ");
    gets(newGame.name);
    printf("Enter game category: ");
    gets(newGame.category);

    fwrite(&newGame, sizeof(struct InstallGame), 1, installGame);

    printf("Game added successfully!\n");

    fclose(installGame);
    system("pause");
}

void displayAllGames()
{
    count = 0;
    installGame = fopen("game.dat", "rb");
    if (installGame == NULL)
    {
        printf("No games installed yet!\n");
        return;
    }

    struct InstallGame game;
    system("cls");
    printf("No.|\tName\t|  Category\n");
    printf("============================\n");
    while (fread(&game, sizeof(struct InstallGame), 1, installGame))
    {
        printf(" %d | %s\t| %s\n", ++count, game.name, game.category);
    }

    fclose(installGame);
    system("pause");
}

void pc()
{
    do
    {
        system("cls");
        printf("\nPC Menu\n");
        printf("1. Install PC\n");
        printf("2. Find PC by ID\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            installPC();
            break;
        case 2:
            findPCById();
            break;
        case 3:
            printf("Kembali ke Menu Utama...\n");
            system("pause");
            MenuOP();
            return;
        default:
            printf("Invalid choice! Please enter again.\n");
            system("pause");
            fflush(stdin);
        }
    } while (1);
}

void installPC()
{
    count = 0;
    getchar();
    installPc = fopen("pc.dat", "a+b");
    if (installPc == NULL)
    {
        printf("Error opening PC file!\n");
        return;
    }
    struct pc newPc;
    while (fread(&newPc, sizeof(struct pc), 1, installPc))
    {
        count++;
    }
    newPc.id = count + 1;
    rewind(installPc);
    printf("Enter PC name: ");
    gets(newPc.name);
    printf("Enter installation date: ");
    gets(newPc.date);
    fwrite(&newPc, sizeof(struct pc), 1, installPc);
    printf("PC installed successfully!\n");
    fclose(installPc);
    system("pause");
}

void findPCById()
{
    count = 0;
    int id;
    installPc = fopen("pc.dat", "rb");
    if (installPc == NULL)
    {
        printf("Error opening PC file!\n");
        return;
    }

    struct pc pc;
    system("cls");
    printf("Currently installed PC ID's :\n");
    printf("===================================\n");
    while (fread(&pc, sizeof(struct pc), 1, installPc))
    {
        printf(" %d\t", count + 1);
        count++;
        if (count == 5)
        {
            printf("\n");
        }
    }
    printf("\n===================================\n");
    rewind(installPc);
    printf("Enter PC ID to search: ");
    scanf("%d", &id);
    while (fread(&pc, sizeof(struct pc), 1, installPc))
    {
        if (pc.id == id)
        {
            printf("PC found:\n");
            printf("ID: %d\n", pc.id);
            printf("Name: %s\n", pc.name);
            printf("Installation Date: %s\n", pc.date);
            fclose(installPc);
            system("pause");
            return;
        }
    }
    fclose(installPc);
    printf("PC with ID %d not found!\n", id);
    system("pause");
}

void account()
{
    do
    {
        system("cls");
        printf("\nAccount Menu\n");
        printf("1. Create Account\n");
        printf("2. Find Account by Username\n");
        printf("3. Delete Account by ID\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            findAccountByUsername();
            break;
        case 3:
            printf("Enter ID of account to delete: ");
            scanf("%d", &id);
            deleteAccountById(id);
            break;
        case 4:
            printf("Kembali ke Menu Utama...\n");
            system("pause");
            MenuOP();
            return;
        default:
            printf("Invalid choice! Please enter again.\n");
            system("pause");
            fflush(stdin);
        }
    } while (1);
}

void createAccount()
{
    count = 0;
    struct Account regs;
    accountFile = fopen("accounts.dat", "a+b");
    if (accountFile == NULL)
    {
        return;
    }
lup:
    fflush(stdin);
    printf("\nUsername: ");
    gets(user);
    while (fread(&regs, sizeof(struct Account), 1, accountFile))
    {
        if (strcmp(user, regs.username) == 0)
        {
            printf("Username telah dipakai, silahkan pilih username lain\n");
            system("pause");
            rewind(accountFile);
            goto lup;
        }
    }
    rewind(accountFile);
    printf("Password: ");
    gets(pass);
    id = strlen(pass) * strlen(user);
    while (fread(&regs, sizeof(struct Account), 1, accountFile))
    {
        idtemp[count] = regs.id;
        count++;
    }
    x = 0;
    for (i = 0; i < count; i++)
    {
        if (idtemp[i] == id)
        {
            printf("id %d\n", id);
            if (x == 0)
            {
                id = id + strlen(pass);
                x = 1;
            }
            else
            {
                id = id + strlen(user);
                x = 0;
            }
            i = 0;
        }
    }
    strcpy(regs.username, user);
    strcpy(regs.password, pass);
    regs.id = id;
    printf("Account ID : %d\n", id);
    fwrite(&regs, sizeof(struct Account), 1, accountFile);
    fclose(accountFile);
    printf("Account created successfully!\n");
    system("pause");
}

void findAccountByUsername()
{
    getchar();
    accountFile = fopen("accounts.dat", "rb");
    if (accountFile == NULL)
    {
        printf("Error opening account file!\n");
        return;
    }
    struct Account currentAccount;
    while (fread(&currentAccount, sizeof(struct Account), 1, accountFile))
    {
        printf("Username: %s\n", currentAccount.username);
    }
    rewind(accountFile);
    printf("Enter username to search: ");
    gets(user);
    while (fread(&currentAccount, sizeof(struct Account), 1, accountFile))
    {
        if (strcmp(currentAccount.username, user) == 0)
        {
            printf("Account found:\n");
            printf("ID: %d\n", currentAccount.id);
            printf("Username: %s\n", currentAccount.username);
            printf("Password: %s\n", currentAccount.password);
            fclose(accountFile);
            system("pause");
            return;
        }
    }
    fclose(accountFile);
    printf("Account with username %s not found!\n", user);
    system("pause");
}

void deleteAccountById(int id)
{
    x = 0;
    accountFile = fopen("accounts.dat", "rb");
    tempFile = fopen("temp.dat", "wb");
    if (accountFile == NULL)
    {
        printf("Error opening account file!\n");
        return;
    }

    struct Account currentAccount;

    while (fread(&currentAccount, sizeof(struct Account), 1, accountFile))
    {
        if (currentAccount.id != id)
        {
            fwrite(&currentAccount, sizeof(struct Account), 1, tempFile);
        }
        else
        {
            x = 1;
        }
    }

    if (x == 0)
    {
        printf("Account with ID %d not found!\n", id);
    }
    else
    {
        printf("Account succesfully deleted!\n", id);
    }
    fclose(accountFile);
    fclose(tempFile);
    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");
    system("pause");
}

void food()
{
    do
    {
        system("cls");
        printf("\nFood Menu\n");
        printf("1. Add Food\n");
        printf("2. Display Food Menu\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addFood();
            break;
        case 2:
            displayFoodMenu();
            break;
        case 3:
            printf("Kembali ke Menu Utama...\n");
            system("pause");
            MenuOP();
            return;
        default:
            printf("Invalid choice! Please enter again.\n");
            system("pause");
            fflush(stdin);
        }
    } while (1);
}

void addFood()
{
    foodFile = fopen("menu.dat", "ab");
    if (foodFile == NULL)
    {
        printf("Error opening food menu file!\n");
        return;
    }

    fflush(stdin);
    struct Food newFood;

    printf("Enter food name: ");
    gets(newFood.name);
    printf("Enter food category (food/drink): ");
    gets(newFood.category);
    printf("Enter food price: ");
    scanf("%lf", &newFood.price);

    fwrite(&newFood, sizeof(struct Food), 1, foodFile);
    fclose(foodFile);
    printf("Food added successfully!\n");
    system("pause");
}

// Fungsi untuk menampilkan semua menu makanan
void displayFoodMenu()
{
    foodFile = fopen("menu.dat", "rb");
    if (foodFile == NULL)
    {
        printf("Error opening food menu file!\n");
        return;
    }

    struct Food currentFood;

    system("cls");
    printf("Food Menu:\n");
    printf("=================================\n");
    printf(" Name  Category    Price\n");
    while (fread(&currentFood, sizeof(struct Food), 1, foodFile))
    {
        printf("%s\t%s\t%.2lf\n", currentFood.name, currentFood.category, currentFood.price);
    }

    fclose(foodFile);
    system("pause");
}

void seeOrder()
{
    count = 0;
    orderFile = fopen("Order.dat", "rb");
    if (orderFile == NULL)
    {
        printf("Error opening order file!\n");
        return;
    }

    struct Order orderlist;

    system("cls");
    printf("Orders :\n");
    printf("=================================\n");
    printf("No.| Name\t|Status\n");
    while (fread(&orderlist, sizeof(struct Order), 1, orderFile))
    {
        printf(" %d |%s\t%s\t%s\n", ++count, orderlist.OrderName, orderlist.AccName, orderlist.orderstatus);
    }
    fclose(orderFile);

    printf("=================================\n");
    printf("Change status to :\n");
    printf("1. Ongoing\n");
    printf("2. Completed\n");
    printf("3. Exit to menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        changeStatus(1);
        break;
    case 2:
        changeStatus(2);
        break;
    case 3:
        printf("Kembali ke Menu Utama...\n");
        system("pause");
        MenuOP();
        break;
    default:
        printf("Invalid choice! Please enter again.\n");
        system("pause");
        fflush(stdin);
    }

    fclose(orderFile);
}

void changeStatus(int n)
{
    count = 0;
    x = 0;
    orderFile = fopen("order.dat", "rb");
    tempFile = fopen("temp.dat", "wb");
    if (orderFile == NULL)
    {
        printf("Error opening account file!\n");
        return;
    }

    struct Order theOrder;

    printf("Enter order number to change status : ");
    scanf("%d", &choice);

    while (fread(&theOrder, sizeof(struct Order), 1, orderFile))
    {
        ++count;
        if (choice == count)
        {
            if (n == 1)
            {
                strcpy(theOrder.orderstatus, "Ongoing");
                x = 1;
            }
            else if (n == 2)
            {
                strcpy(theOrder.orderstatus, "Completed");
                x = 1;
            }
        }
        fwrite(&theOrder, sizeof(struct Order), 1, tempFile);
    }

    if (x == 0)
    {
        printf("Order not found!\n");
    }
    else
    {
        printf("Order status changed!\n");
    }

    fclose(orderFile);
    fclose(tempFile);
    remove("order.dat");
    rename("temp.dat", "order.dat");
    system("pause");
}