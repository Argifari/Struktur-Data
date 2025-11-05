/* Program   : mqueue3.c */
/* Deskripsi : main driver ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 8 Oktober 2025*/
/***********************************/

// header file
#include <stdio.h>
#include "tqueue3.c"


// Main program

int main () {
    // Kamus
    tqueue3 Q;
    char E;

    // Algoritma
    printf("\n\n ============================ PROGRAM BERJALAN ==========================\n\n");
    printf("\n\n ============================ CREATE QUEUE3 ==========================\n\n");
    createQueue3(&Q);
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("Tail : %d\n",tail3(Q));
    printQueue3(Q);
    
    printf("\n\n ============================ ENQUEUE QUEUE3 ==========================\n\n");
    enqueue3(&Q,'a');
    enqueue3(&Q,'t');
    enqueue3(&Q,'y');
    enqueue3(&Q,'q');
    enqueue3(&Q,'w');
    
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("Tail : %d\n",tail3(Q));
    printf("Ukuran : %d\n", sizeQueue3(Q));
    viewQueue3(Q);
    
    printf("\n\n ============================ DEQUEUE QUEUE3 ==========================\n\n");
    dequeue3(&Q, &E);
    
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("Tail : %d\n",tail3(Q));
    printf("Isi keluar : %c\n", E);
    printQueue3(Q);
    
    printf("\n\n ============================ ENQUEUE SAAT TAIL = 5 ==========================\n\n");
    enqueue3(&Q,'w');
    
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("InfoHead : %c\n",infoHead3(Q));
    printf("Tail : %d\n",tail3(Q));
    printf("InfoTail : %c\n",infoTail3(Q));
    printQueue3(Q);
    
    printf("\n\n ============================ DEQUEUE SAAT HEAD = 5 ==========================\n\n");
    dequeue3(&Q, &E);
    dequeue3(&Q, &E);
    dequeue3(&Q, &E);
    
    printf("\n\n ============================ SEBELUM DEQUEUE SAAT HEAD = 5 ==========================\n\n");
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("Tail : %d\n",tail3(Q));
    printQueue3(Q);
    
    printf("\n\n ============================ SESUDAH DEQUEUE SAAT HEAD = 5 ==========================\n\n");
    dequeue3(&Q,&E);
    printf("Isi Queue Q sekarang : \n");
    printf("Head : %d\n",head3(Q));
    printf("Tail : %d\n",tail3(Q));
    printQueue3(Q);
    
    printf("\n\n ============================ PENGETESAN FUNGSI PREDIKAT ==========================\n\n");
    
    printf("IsEmptyQueue3(Q) : %d\n", isEmptyQueue3(Q));
    printf("IsFullQueue3(Q) : %d\n", isFullQueue3(Q));
    printf("IsOneElement(Q) : %d\n", isOneElement3(Q));
    printf("IsTailOverGead(Q) : %d\n", isTailOverHead(Q));


    printf("\n\n ============================ PROGRAM SELESAI ==========================\n\n");

    return 0;
}
