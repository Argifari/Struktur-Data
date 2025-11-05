/* Program   : mbrowser.c */
/* Deskripsi : UNDO REDO*/
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 24 September 2025*/
/***********************************/
// header file
#include <stdio.h>
#include "tstack.c"
#include "string.h"


/* include tstack+boolean */

// main program
int main() {
    // Kamus 
    int perintah;
    string alamat;
    string c;
    TstackStr Undo;
    TstackStr Redo;
    // Algoritma
    createStackStr(&Undo);
    createStackStr(&Redo);
    printf("===== mbrowser.c berjalan =====");
    printf("Macam-Macam Perintah : \n");
    printf("1. Menambah alamat baru\n");
    printf("2. Melakukan backward\n");
    printf("3. Melakukan forward\n");
    printf("4. Exit\n");

    do {
        printf("\n===== Masukkan Kode Perintah (1,2,3,4) =====\n");
        scanf("%d", &perintah);
        switch (perintah)
        {
        case 1:
            printf("Masukkan Alamat baru: ");
            scanf("%s",&alamat.value);
            pushStr(&Undo,alamat);
            createStackStr(&Redo);
            break;
        case 2:
            if (isEmptyStackStr(Undo)) {
                printf("Tidak ada yang bisa diUndo\n");
            }else {
                popStr(&Undo, &c);
                pushStr(&Redo, c);
                printf("Yg diUndo: %s", c.value);
            }
            break;
        case 3:
            if (isEmptyStackStr(Redo)) {
                printf("Tidak ada yang bisa diRedo\n");
            }else {
                popStr(&Redo, &c);
                pushStr(&Undo, c);
                printf("Yg diRedo: %s", c.value);
            }
            break;
        case 4:
            printf("===== Program Selesai =====\n");
            break;
        default:
            printf("Kode tidak valid\n");
            break;
        }
        printf("\nIsi stack undo: ");
        viewStackStr(Undo);
        printf("\nIsi stack redo: ");
        viewStackStr(Redo);
    } while(perintah != 4);
    return 0;

}