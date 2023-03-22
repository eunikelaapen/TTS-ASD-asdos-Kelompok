#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define mysleep(s) usleep(s*100000)


void center(){
printf("\n\t\t\t\t\t");
}

void center_n(){
printf("\t\t\t\t\t");
}

void loading (){
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tNungguin yaaa ...");
    printf("\n\n\t\t\t\t\t\t\t    ");
    for (int i=0; i<=52; i++){
        printf ("%c", 219);
        mysleep(1);
    }
    printf("\n\n\t\t\t\t\t\t\t\t\t\t Udah guys!");
}
struct
{
    char nama[50], nohp[20], alamat[50], username[20], password[20];
} akun;
struct
{
    char nama[20], nohp[20], alamat[20];
    char tanggal[20];
    int harga, lama,merk;
} riwayat[50];

int d;
d = 0;

header()
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t\t========================\n");
    printf("\t\t\t\t\t\t\t\t\t      RENTAL MOTOR\n");
    printf("\t\t\t\t\t\t\t\t\t========================\n");
}
int login2(){
    system("cls");
    int choice=2;
	system("color F0");
    char password[10], username[10];
    int a, l, p;
    FILE *fp = fopen("akunlogin.txt", "r");
    fscanf(fp, "%s %s %s %s %s", &akun.nama, &akun.nohp, &akun.alamat, &akun.username, &akun.password);
    int attempts = 3;

    while (attempts > 0) {
        printf("Username: ");
        scanf("%s", &username);

        printf("Password: ");
        int i = 0;
        while (i < 20) {
            password[i] = getch();
            if (password[i] == '\r') {
                password[i] = '\0';
                break;
            }
            else if (password[i] == '\b') {
                if (i > 0) {
                    printf("\b \b");
                    i--;
                }
            }
            else {
                printf("*");
                i++;
            }
        }

        if (strcmp(username, akun.username) == 0 && strcmp(password, akun.password) == 0) {
            printf("\nLogin Berhasil!\n");
            break;
        }
        else {
           printf("\nUsername atau Password salah atau mungkin belum memiliki akun!!\n");
            l = 0;
            system("pause");
            system("cls");
            main();
        }
    }
    menu();
}
regis()
{
    int r;
    do
    {
        FILE *fp = fopen("akunlogin.txt", "w");
        r = 1;
        header();
        printf("REGISTER \n");
        printf("Nama         : ");
        scanf("%s", &akun.nama);
        printf("No HP        : ");
        scanf("%d", &akun.nohp);
        printf("ALAMAT       : ");
        scanf("%s", &akun.alamat);
        printf("Username(6 karakter)  : ");
        scanf("%s", &akun.username);
        printf("Password (8 karakter) : ");
        scanf("%s", &akun.password);
        if (strlen(akun.username) < 6)
        {
            printf("username harus minimal 6 karakter \n");
            r = 0;
        }
        if (strlen(akun.password) < 8)
        {
            printf("password harus minimal 8 karakter \n");
            r = 0;
        }
        fprintf(fp, "%s ", akun.nama);
        fprintf(fp, "%s ", akun.nohp);
        fprintf(fp, "%s ", akun.alamat);
        fprintf(fp, "%s ", akun.username);
        fprintf(fp, "%s", akun.password);
        fclose(fp);
        system("pause");
    } while (r == 0);
}
menu()
{
    int menu_2, i, waktu, harga, merk, lama;
    char nama[100], nohp[100], alamat[100];
    do
    {
        harga = 0;
        header();
        printf("MENU \n");
        printf("1. Stok Kendaraan\n");
        printf("2. Data Penyewa\n");
        printf("3. Kalkulasi Harga\n");
        printf("4. Struk Penyewaan\n");
        printf("5. Exit\n");
        printf("MASUKAN PILIHAN (1/2/3/4/5) : ");
        scanf("%d", &menu_2);
        if (menu_2 == 1)
        {
            header();
            printf("\n");
            printf("\t\t\t\t\t\t==================================================================\n");
            printf("\t\t\t\t\t\t                            STOK KENDARAAN                        \n");
            printf("\t\t\t\t\t\t==================================================================\n");
            printf("\t\t\t\t\t\t No.|           Merk Motor           |   Harga Sewa Motor(/Jam)  |\n");
            printf("\t\t\t\t\t\t==================================================================\n");
            printf("\t\t\t\t\t\t 1. |              Mio               |           5k/jam          |\n");
            printf("\t\t\t\t\t\t 2. |             Supra              |           5k/jam          |\n");
            printf("\t\t\t\t\t\t 3. |             Beat               |           5k/jam          |\n");
            printf("\t\t\t\t\t\t 4. |             Vario              |           5k/jam          |\n");
            printf("\t\t\t\t\t\t 5. |             N-Max              |           5k/jam          |\n");
            printf("\t\t\t\t\t\t==================================================================\n");
        }
        else if(menu_2 == 2)
        {
            header();
            printf("\n");
            printf("\t\t\t\t\t\t\t\t\t      Data Penyewa   \n");
            printf("Masukan Nama : ");
            scanf("%s", &riwayat[d].nama);
            printf("Masukan No Hp : ");
            scanf("%s", &riwayat[d].nohp);
            printf("Masukan Alamat : ");
            scanf("%s", &riwayat[d].alamat);
        }
        else if (menu_2 == 3)
        {
            header();
            printf("\n");
            printf("\t\t\t\t\t\t\t\t\t     Kalkulasi Harga\n");
            printf("Masukan Nomer Merk Motor : ");
            scanf("%d", &riwayat[d].merk);
            printf("Tanggal Sewa (d/m/yy) : ");
            scanf("%s", &riwayat[d].tanggal);
            printf("Lama Sewa (dalam jam) : ");
            scanf("%d", &lama);
            harga = lama * 5000;
            riwayat[d].harga = harga;
            d++;
            printf("Selamat anda telah membuat sewa baru \n");
        }
        else if (menu_2 == 4)
        {
            printf("\n");
            char merk[5][100] = {"mio","supra","beat","vario","n-max"};
            printf("| no\t| tanggal\t| nama\t| merk\t| lama\t| harga\n");
            for (i = 0; i < d; i++)
            {
                int m = riwayat[i].merk;
                printf("| %d\t| %s\t| %s\t| %s\t| %d jam\t| %d\n", i + 1, riwayat[i].tanggal, riwayat[i].nama, merk[m-1], lama, riwayat[i].harga);
            }
        }
        else if (menu_2 == 5)
        {
            printf("\n");
            printf("1. Syallom Adinda Sriyanto - 672022002\n");
            printf("2. Beatrix Rannu Girikan - 672022163\n");
            printf("3. Avril Tesya Migoto Minggu - 672022173\n");
            printf("4. Eunike Loise Laapen - 672022190\n");
            printf("5. Putri Azzahra Fitriyana - 672022254\n");
            printf("Thank You!\n");
        }
        else
        {
            printf("INPUT SALAH\n");
        }
       // printf("next.....");
        getch();
    } while (menu_2 != 5);
}
int main()
{
    loading();
    int menu_1;
    do
    {
        system("color F0");
        header();
        printf("1. REGISTER \n");
        printf("2. LOGIN \n");
        //printf("3. Exit \n");
        printf("MASUKAN PILIHAN (1/2) : ");
        scanf("%d", &menu_1);
        if (menu_1 == 1)
        {
            regis();
        }
        else if (menu_1 == 2)
        {
            login2();
        }
        else
        {
            printf("Inputan Tidak Tersedia\n");
            printf("Tekan Enter Untuk Mengulang\n");
        }
        getch();
    } while (menu_1 != 2);
    return 0;
}
