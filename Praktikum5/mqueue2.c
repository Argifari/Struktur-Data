/* Program   : mqueue.h */
/* Deskripsi : Diver main ADT Queue representasi kontigu dengan array, 
               model II: head bergeser*/
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 1 Oktober 2025*/
/***********************************/

// Header File 
#include <stdio.h>
#include "tqueue2.c"

// Main Program

int main () {
    // Kamus
    tqueue2 Q;
    tqueue2 Q1;
    tqueue2 Q2;
    char E;
    // Algoritma
    printf("\n\n============================= PROGRAM BERJALAN ============================\n\n");
    createQueue2(&Q);

    printf("\n\n============================= MEMBUAT QUEUE 2 ===============================\n\n");
    printf("Isi Queue2 Q dengan printQueue: \n");
    printQueue2(Q);
    enqueue2(&Q,'a');
    enqueue2(&Q,'z');
    enqueue2(&Q,'u');
    enqueue2(&Q,'r');
    printf("\n\n=============================== MELAKUKAN enqueue2 =====================\n\n");
    printf("Isi Queue2 Q dengan printQueue: \n");
    printQueue2(Q);
    printf("Isi Queue2 Q dengan viewQueue: \n");
    viewQueue2(Q);
    
    printf("\n\n=============================== MELAKUKAN dequeue2 =====================\n\n");
    dequeue2(&Q, &E);
    printf("deque Isi Queue2 Q : \n");
    printQueue2(Q);
    printf("Isi Queue2 Q : \n");
    viewQueue2(Q);
    printf("Hasil dequeue : %c\n", E);
    
    printf("\n\n=============================== PENGETESASN RESETHEAD =====================\n\n");
    enqueue2(&Q,'b');
    printf("Isi Queue2 Q : \n");
    printQueue2(Q);
    printf("Isi Queue2 Q : \n");
    viewQueue2(Q);
    
    dequeue2(&Q, &E);
    printf("Isi Queue2 Q : \n");
    printQueue2(Q);
    printf("Isi Queue2 Q : \n");
    viewQueue2(Q);
    
    resetHead(&Q);
    printf("Setelah Reset Head Queue2 Q : \n");
    printQueue2(Q);
    printf("Setelah Reset Head Isi Queue2 Q : \n");
    viewQueue2(Q);    
    
    
    printf("\n\n=============================== PENGETESAN FUNGSI PREDIKAT =====================\n\n");
    printf("isEmptyQueue2(Q): %d\n", isEmptyQueue2(Q));
    printf("isFullQueue2(Q): %d\n", isFullQueue2(Q));
    printf("isOneElement2(Q): %d\n", isOneElement2(Q));
    printf("isTailStop Queue2 Q : %d\n", isTailStop(Q));
    
    printf("\n\n=============================== PENGETESAN FUNGSI SELEKTOR =====================\n\n");
    printf("head Queue2 Q : %d\n", head2(Q));
    printf("tail Queue2 Q : %d\n", tail2(Q));
    printf("infoHead Queue2 Q : %c\n", infoHead2(Q));
    printf("infoTail Queue2 Q : %c\n", infoTail2(Q));
    printf("size Queue2 Q : %d\n", sizeQueue2(Q));
    
    printf("\n\n=============================== PENGETESAN enqueue2N =====================\n\n");
    printf("================================== Proses Input ============================\n");
    createQueue2(&Q);
    enqueue2N(&Q, 5);
    
    printf("\n\n=============================== HASIL enqueue2N =====================\n\n");
    printf("Isi Queue2 Q dengan printQueue: \n");
    printQueue2(Q);
    printf("Isi Queue2 Q dengan viewQueue: \n");
    viewQueue2(Q);  
    
    printf("\n\n=============================== PENGETESAN ISEQUALQUEUE2 =====================\n\n");
    createQueue2(&Q1);
    createQueue2(&Q2);
    
    enqueue2(&Q1,'b');
    enqueue2(&Q1,'a');
    enqueue2(&Q1,'b');
    
    enqueue2(&Q2,'b');
    enqueue2(&Q2,'a');
    enqueue2(&Q2,'b');
    
    printf("Isi Queue Q1: \n");
    printQueue2(Q1);
    
    printf("Isi Queue Q2: \n");
    printQueue2(Q2);
    
    printf("isEqualQueue2(Q1,Q2): %d\n", isEqualQueue2(Q1,Q2));
    
    printf("\n\n=============================== PENGETESAN KASUS HEAD YG BEDA =====================\n\n");
    dequeue2(&Q1,&E);
    dequeue2(&Q1,&E);
    enqueue2(&Q1,'a');
    enqueue2(&Q1,'b');
    
    printf("Isi Queue Q1: \n");
    printQueue2(Q1);
    
    printf("Isi Queue Q2: \n");
    printQueue2(Q2);
    
    printf("isEqualQueue2(Q1,Q2): %d\n", isEqualQueue2(Q1,Q2));
    
    printf("\n\n=============================== PROGRAM SELESAI =====================\n\n");
    return 0;

}
