/* File : main.c */
/* Deskripsi : main driver ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 12 November 2025*/

// header
#include <stdio.h>
#include "list2.c"

// Program main

int main()
{
    // Kamus
    address P, A, B;
    infotype V;
    List2 Senarai;
    List2 Senarai2;
    List2 concatL;
    List2 splitL1;
    List2 splitL2;
    List2 copyL;


    // Algoritma
    printf("\n\n=== Program Dimulai =====================================\n");
    printf("\n\n=== Testing Alokasi =====================================\n");
    A = Alokasi('G');
    printf("info(A)=%c\t", info(A));
    B = Alokasi('N');
    next(B) = A;
    printf("info(B)=%c\n", B->info);

    printf("\n\n=== Testing Dealokasi ===================================\n");
    Dealokasi(&B);
    if (B == NIL)
    {
        printf("Dealokasi address berhasil\n");
    }
    else
    {
        printf("Dealokasi address tidak berhasil\n");
    }

    printf("\n\n=== Testing CreateList ==================================\n");
    CreateList(&Senarai);
    CreateList(&Senarai2);
    printf("Isi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

    printf("\n\n=== Testing InsertVFirst ================================\n");
    InsertVFirst(&Senarai, 'N');
    InsertVFirst(&Senarai, 'a');
    InsertVFirst(&Senarai, 's');
    printf("Isi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

    printf("\n\n=== Testing EmptyList ===================================\n");
    if (IsEmptyList(Senarai))
    {
        printf("Senarai kosong\n");
    }
    else
    {
        printf("Senarai tidak kosong\n");
    }
    printf("\n\n=== Testing IsOneElm ====================================\n");
    if (IsOneElm(Senarai))
    {
        printf("Senarai satu elemen\n");
    }
    else
    {
        printf("Senarai tidak satu elemen\n");
    }

    printf("\n\n=== Testing InsertVLast =================================\n");
    InsertVLast(&Senarai, 's');
    InsertVLast(&Senarai, 'z');
    InsertVLast(&Senarai, 'o');
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

    printf("\n\n=== Test DeleteVFirst ===================================\n");

    DeleteVFirst(&Senarai, &V);

    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));
    printf("\nelemen Senarai yang dihapus : %c\n", V);

    DeleteVLast(&Senarai, &V);

    printf("\n\n=== Test DeleteVLast ====================================\n");
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));
    printf("\nelemen Senarai yang dihapus : %c\n", V);

    printf("\n\n=== Test DeleteX ========================================\n");

    DeleteX(&Senarai, 'z');
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d", NbElm(Senarai));

    printf("\n\n=== Test SearchX ========================================\n");

    SearchX(Senarai, 'N', &B);
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    if (B == NIL)
    {
        printf("N tidak ditemukan\n");
    }
    else
    {
        printf("N ditemukan\n");
    }

    printf("\n\n=== Test UpdateX ========================================\n");

    UpdateX(&Senarai, 'a', 'j');
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));

    printf("\n\n=== Test Invers =========================================\n");
    Invers(&Senarai);
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nElemen pertama Senarai : %c\n", info(First(Senarai)));

    printf("\n\n=== Test CountX =========================================\n");
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nHitung elemen N : %d\n", CountX(Senarai, 'N'));

    printf("\n\n=== Test FrekuensiX =====================================\n");
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nHitung frekuensi elemen N : %f\n", FrekuensiX(Senarai, 'N'));

    printf("\n\n=== Test CountNG ========================================\n");
    printf("\nIsi Senarai :");
    InsertVLast(&Senarai2, 'N');
    InsertVFirst(&Senarai2, 'G');
    PrintList(Senarai2);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai2));
    printf("\nHitung frekuensi elemen N diikuti G: %d\n", CountNG(Senarai2));

    printf("\n\n=== Test InsertVAfterX ===================================\n");
    InsertVAfterX(&Senarai, 'j', ']');
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    
    printf("\n\n=== Test InsertVBeforeX ==================================\n");
    InsertVBeforeX(&Senarai, 'j', '+');
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    
    printf("\n\n=== Test DeleteVAfterX ===================================\n");
    DeleteVAfterX(&Senarai, 'j', &V);
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nElemen Senarai yang dihapus: %c\n", V);
    
    printf("\n\n=== Test DeleteVBeforeX ==================================\n");
    DeleteVBeforeX(&Senarai, 'N', &V);
    printf("\nIsi Senarai :");
    PrintList(Senarai);

    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nElemen Senarai yang dihapus: %c\n", V);
    
    printf("\n\n=== Test DeleteAllX ======================================\n");
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'N');
    printf("\nIsi Senarai sebelum dihapus:");
    PrintList(Senarai);
    DeleteAllX(&Senarai, 'N');
    printf("\nIsi Senarai setelah dihapus:");
    PrintList(Senarai);
    
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    
    
    printf("\n\n=== Test SearchAllX =====================================\n");
    InsertVLast(&Senarai, 'N');
    InsertVFirst(&Senarai, 'N');
    InsertVLast(&Senarai, 'N');
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    SearchAllX(Senarai,'N');
    
    printf("\n\n=== Test MaxMember ======================================\n");
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nHitung elemen paling banyak : %d\n", MaxMember(Senarai));
    
    printf("\n\n=== Test Modus ==========================================\n");
    printf("\nIsi Senarai :");
    PrintList(Senarai);
    printf("\nHitung elemen Senarai : %d\n", NbElm(Senarai));
    printf("\nHitung elemen modus : %c\n", Modus(Senarai));
    
    printf("\n\n=== Test ConcatList =====================================\n");
    CreateList(&concatL);
    ConcatList(Senarai,Senarai2,&concatL);
    printf("\nIsi Senarai 1 : ");
    PrintList(Senarai);
    printf("\nIsi Senarai 2 : ");
    PrintList(Senarai2);
    printf("\nIsi hasil concat : ");
    PrintList(concatL);
    
    printf("\n\n=== Test SplitList =====================================\n");
    CreateList(&splitL1);
    CreateList(&splitL2);
    SplitList(Senarai,&splitL1,&splitL2);
    printf("\nIsi Senarai utama : ");
    PrintList(Senarai);
    printf("\nIsi hasil split L1 : ");
    PrintList(splitL1);
    printf("\nIsi hasil split L2 : ");
    PrintList(splitL2);
    
    printf("\n\n=== Test CopyList ======================================\n");
    printf("\nIsi Senarai utama : ");
    PrintList(Senarai);
    CreateList(&copyL);
    CopyList(Senarai,&copyL);
    printf("\nIsi hasil copy senarai : ");
    PrintList(copyL);


    
    printf("\n\n=== Program Selesai ====================================\n");
    return 0;
}
