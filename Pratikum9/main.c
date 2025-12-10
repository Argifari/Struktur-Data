/* File : list3.c */
/* Deskripsi : Main body ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 19 November 2025*/

// header file
#include <stdio.h>
#include "list3.c"

// main program

int main () {
    // Kamus
    address A;
    address B;
    List3 Senarai;
    infotype V;

    // Algoritma

    printf("\n\n== Test Alokasi =============================\n\n");
    A = Alokasi('a');
    B = Alokasi('j');
    printf("Isi address B : %c\n", info(B));
    
    printf("\n\n== Test Dealokasi ===========================\n\n");
    Dealokasi(&B);
    if (B == NIL) {
        printf("Dealokasi berhasil\n");
    }else {
        printf("Dealokasi tidak berhasil\n");
    }
    printf("\n\n== Test CreateList ==========================\n\n");
    CreateList(&Senarai);
    
    if (First(Senarai) == NIL) {
        printf("CreateList berhasil\n");
    }else {
        printf("CreateList tidak berhasil\n");
    }
    
    printf("\n\n== Test IsEmptyList =========================\n\n");
    
    if (IsEmptyList(Senarai)) {
        printf("List kosong\n");
    }else {
        printf("List tidak kosong\n");
    }
    printf("\n\n== Test NbElm ===============================\n\n");
    
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    
    printf("\n\n== Test InsertVFirst ========================\n\n");
    
    printf("Insert Karakter a  : \n");
    InsertVFirst(&Senarai,'a');
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    
    printf("\n\n== Test InsertVLast =========================\n\n");
    printf("Insert Karakter b di akhir : \n");
    InsertVLast(&Senarai,'b');
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    
    printf("\n\n== Test DeleteVFirst ========================\n\n");
    DeleteVFirst(&Senarai,&V);
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    printf("Elemen list yang dihapus : %c\n", V);
    
    printf("\n\n== Test DeleteVLast =========================\n\n");
    InsertVLast(&Senarai,'g');
    InsertVLast(&Senarai,'c');
    printf("Kondisi sebelum DeleteVLast : \n");
    PrintList(Senarai);
    DeleteVLast(&Senarai,&V);
    printf("\nKondisi setelah DeleteVLast : \n");
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    printf("Elemen list yang dihapus : %c\n", V);
    
    printf("\n\n== Test DeleteX =============================\n\n");
    InsertVLast(&Senarai,'h');
    printf("Kondisi sebelum DeleteVLast : \n");
    PrintList(Senarai);
    DeleteX(&Senarai,'g');
    printf("\nKondisi setelah DeleteX X = g : \n");
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    
    printf("\n\n== Test SearchX =============================\n\n");
    A = NIL;
    
    InsertVLast(&Senarai,'h');
    InsertVLast(&Senarai,'f');
    InsertVLast(&Senarai,'z');
    PrintList(Senarai);
    printf("Jumlah elemen list sekarang : %d\n", NbElm(Senarai));
    
    SearchX(Senarai,'z',&A);
    if (A == NIL) {
        printf("z tidak ditemukan di list\n");
    }else {
        printf("z ditemukan di list\n");
    }
    
    printf("\n\n== Test UpdateX =============================\n\n");

    printf("List sebelum diupdate X : \n");
    PrintList(Senarai);
    UpdateX(&Senarai,'z','=');
    printf("List setelah diupdateX pada nilai z : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test Invers ==============================\n\n");

    printf("List sebelum diInvers : \n");
    PrintList(Senarai);
    Invers(&Senarai);
    printf("List setelah diInvers : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test InsertVAfterX ==============================\n\n");

    printf("List sebelum diInsertVAfterX : \n");
    PrintList(Senarai);
    InsertVAfterX(&Senarai,'h','7');
    printf("List setelah diInsertVAfterX setelah h : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test InsertVBeforeX ==============================\n\n");
    DeleteVFirst(&Senarai,&V);
    printf("List sebelum diInsertVBeforeX : \n");
    PrintList(Senarai);
    InsertVBeforeX(&Senarai,'7','5');
    printf("List setelah diInsertVBeforeX sebelum 7 : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test DeleteVAfterX ===============================\n\n");
    printf("List sebelum diDeleteVAfterX : \n");
    PrintList(Senarai);
    DeleteVAfterX(&Senarai,'f',&V);
    printf("List setelah diDeleteVAfterX X = f : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test DeleteVBeforeX ==============================\n\n");
    printf("List sebelum diDeleteVBeforeX : \n");
    PrintList(Senarai);
    DeleteVBeforeX(&Senarai,'b',&V);
    printf("List setelah diDeleteVBeforeX X = b : \n");
    PrintList(Senarai);
    
    printf("\n\n== Test CountX =======================================\n\n");
    InsertVLast(&Senarai,'b');
    InsertVLast(&Senarai,'b');
    InsertVLast(&Senarai,'b');
    printf("List  : \n");
    PrintList(Senarai);
    printf("hasil Count X = b %d\n : ", CountX(Senarai,'b'));
    
    printf("\n\n== Test FrekuensiX =======================================\n\n");

    printf("List  : \n");
    PrintList(Senarai);
    printf("hasil Count X = b %f\n", FrekuensiX(Senarai,'b'));
    
    printf("\n\n== Test Modus =======================================\n\n");

    printf("List  : \n");
    PrintList(Senarai);
    printf("hasil Count X = b %c\n : ", Modus(Senarai));
    
    printf("\n\n== Test CountVocal =======================================\n\n");

    printf("List  : \n");
    PrintList(Senarai);
    printf("hasil Count banyak genap %d\n : ", CountVocal(Senarai));










    printf("\n\n== Program Selesai ==========================\n\n");

    return 0;
}
