Praktikum Modul 1 : Program Mendata Mahasiswa dan Konversi Tgl Lahir -> Umur
#include <stdio.h>
#include <string.h>

int main()
{
    int nim,y,d,M;
    long umur, umur1, umur2;
    char kelas[2], nama[100], m[15],almt[100], no[50];

    printf("Input Data Anda\n");
    printf("Nama: ");
    fflush(stdin);
    gets(nama);
    printf("NIM: ");
    scanf("%d", &nim);
    printf("Kelas: ");
    scanf("%s", &kelas);
    printf("Alamat: ");
    fflush(stdin);
    gets(almt);
    printf("No Hp: ");
    fflush(stdin);
    gets(no);
    printf("Contoh: 12 Januari 2002\nTanggal Lahir: ");
    scanf("%d %s %d", &d, &m, &y);
    printf("---Data User---");
    printf("\n%s", nama);
    printf("\n%d",nim);
    printf("\n%s", kelas);
    printf("\n%s",almt);
    printf("\n%s", no);
    printf("\n%d %s %d\n", d, m, y);
    //Konversi Bulan Ke Integer
   if (strcmp(strlwr(m), "januari") == 0)
    {
        M = 1;
    }
    else if (strcmp(strlwr(m), "februari") == 0)
    {
        M = 2;
    }
    else if (strcmp(strlwr(m), "maret") == 0)
    {
        M = 3;
    }
    else if (strcmp(strlwr(m), "april") == 0)
    {
        M = 4;
    }
    else if (strcmp(strlwr(m), "mei") == 0)
    {
        M = 5;
    }
    else if (strcmp(strlwr(m), "juni") == 0)
    {
        M = 6;
    }
    else if (strcmp(strlwr(m), "juli") == 0)
    {
        M = 7;
    }
    else if (strcmp(strlwr(m), "agustus") == 0)
    {
        M = 8;
    }
    else if (strcmp(strlwr(m), "september") == 0)
    {
        M = 9;
    }
    else if (strcmp(strlwr(m), "oktober") == 0)
    {
        M = 10;
    }
    else if (strcmp(strlwr(m), "november") == 0)
    {
        M = 11;
    }
    else if (strcmp(strlwr(m), "desember") == 0)
    {
        M = 12;
    }
    else
    {
        printf("Inputan tanggal anda salah silahkan running dan input kembali sesuai contoh dan kaidah bahasa indonesia yang benar ^-^");
    }
    umur1 = d + M*31 + y*365;
    umur2 = 16 + 2*31 + 2021*365;
    umur = (umur2 - umur1)/365;
    printf("\nUmur: %d tahun", umur);

    return 0;
}
