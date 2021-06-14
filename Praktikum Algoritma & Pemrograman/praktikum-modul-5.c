#include <stdio.h>
#include <stdlib.h>
//struct untuk menampung data nama movie dan ratingnya
struct data
{
    char movie[100];
    float rate;
}x[100];

int main()
{
    struct data temp;
    FILE *fp; //pointer untuk file movie.txt
    FILE *fasc; //pointer untuk file ascending.txt
    FILE *fdsc; //pointer untuk file descending.txt
    int i = 0, size, j,mode;
    char ch;
    //buka file dengan memanfaatkan pointer fp dan mode r(read)
    fp = fopen("movie.txt", "r");
    if (fp == NULL) // jika setelah di-read dan dialokasikan ke fp, nilai fp = NULL (kosong). printf selanjutnya
    {
        printf("\n File tidak dapat dibuka \n");
        exit(0);
    }
    //untuk membaca file dalam beberapa baris dan menampilkannya dalam program gunakan perulangan
    while (ch != EOF) //fungsi EOF berguna untuk mengindentifikasikan END OF FILE
    {
        fscanf(fp, "%s %f", &x[i].movie, &x[i].rate); //setalah dibaca, tulis file kedalam array of struct
        printf("%s %.1f\n", x[i].movie, x[i].rate);
        ch = fgetc(fp);
        i++;//untuk mengulang terus hinggan EOF dan mengetahui size of fp atau ch
    }
    size = i - 1;
        //bubble sort ascending
        for (i = 1; i < size; ++i)
            for (j = 0; j < size - i; j++)
                if (x[j + 1].rate < x[j].rate)
                {
                    temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
        //hasil ascending
        fasc = fopen("ascending.txt", "w"); //buka dan buat file baru untuk menulis hasil ascending dengan mode w(write)
        puts("\nAscending:");
        for (i = 0; i < size; i++){
            printf("%s %.1f \n", x[i].movie, x[i].rate);
            fprintf(fasc, "%s %.1f \n", x[i].movie, x[i].rate);
        }
        printf("\nFile sukses diurutkan dalam ascending dan disimpan sebagai ascending.txt \n \n");
    //bubble sort descending
        for (i = 1; i < size; ++i)
            for (j = 0; j < size - i; j++)
                if (x[j + 1].rate > x[j].rate)
                {
                    temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
            //hasil descending
        fdsc = fopen("descending.txt", "w");// buka dan buat file baru untuk menulis hasil descending dengan mode w(write)
                puts("\nDescending:");
        for (i = 0; i < size; i++)
        {
            printf("%s %.1f \n", x[i].movie, x[i].rate);
            fprintf(fdsc, "%s %.1f \n", x[i].movie, x[i].rate);
            }
            printf("\nFile sukses diurutkan dalam descending dan disimpan sebagai descending.txt \n \n");
            fclose(fp);   //untuk close file movie
            fclose(fasc); //untuk close file ascending
            fclose(fdsc); //untuk close file descending
            return 0;
}
