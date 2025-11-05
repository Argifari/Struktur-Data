/* Program   : mqueue.h */
/* Deskripsi : Diver main ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 1 Oktober 2025*/
/***********************************/

// Header file 
#include <stdio.h>
#include "tqueue.c"

// Program main 
int main () {
    // Kamus 
    tqueue Q;
    tqueue Q1;
    char e;
    // Algoritma
    printf("\n\n=========================== Program Main Queue Berjalan ===========================\n\n");
    createQueue(&Q);
    createQueue(&Q1);
    printf("Membuat tqueue Q: \n");
    printQueue(Q);
    
    printf("\n\n=========================== MELAKUKAN enqueue ===========================\n\n");
    enqueue(&Q,'a');
    enqueue(&Q,'b');
    enqueue(&Q,'2');
    enqueue(&Q,'j');
    enqueue(&Q,'c');
    printf("tqueue Q sekarang : \n");
    viewQueue(Q);
    
    printf("\n\n=========================== PENGETESAN FUNGSI PREDIKAT ===========================\n\n");
    printf("\nIsEmptyQueue(Q) : %d\n", isEmptyQueue(Q));
    printf("IsFullQueue(Q) : %d\n", isFullQueue(Q));
    
    
    printf("\n\n=========================== PENGETESAN FUNGSI SELEKTOR ===========================\n\n");
    printf("Ukuran Queue Q : %d\n", sizeQueue(Q));
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q : %d\n", tail(Q));
    
    
    
    printf("\n\n=========================== MELAKUKAN dequeue ===========================\n\n");
    dequeue(&Q, &e);
    printf("Hasil setelah didequeue : %c\n", e);
    printf("Queue Q sekarang :\n");
    viewQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q : %d\n", tail(Q));
    
    dequeue(&Q, &e);
    dequeue(&Q, &e);
    dequeue(&Q, &e);
    
    printf("Queue Q sekarang :\n");
    viewQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q : %d\n", tail(Q));
    
    printf("\n\n=========================== PENGETESAN FUNGSI SELEKTOR ===========================\n\n");
    printf("IsOneElement(Q): %d\n", isOneElement(Q));
    dequeue(&Q, &e);
    
    printf("Queue Q sekarang :\n");
    printQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q : %d\n", tail(Q));
    
    printf("\n\n=========================== MELAKUKAN enqueue2 ===========================\n\n");
    enqueue(&Q,'a');
    enqueue(&Q,'n');
    enqueue(&Q,'j');
    
    enqueue(&Q1,'a');
    enqueue(&Q1,'y');
    
    printf("Queue Q1 sekarang :\n");
    viewQueue(Q1);
    
    enqueue2(&Q,&Q1, 'g');
    printf("Queue Q1 sekarang :\n");
    viewQueue(Q1);
    printf("Head Queue Q1 : %d\n", head(Q1));
    printf("Tail Queue Q1: %d\n", tail(Q1));
    printf("Queue Q sekarang :\n");
    viewQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q: %d\n", tail(Q));
    
    enqueue2(&Q,&Q1,'g');
    enqueue2(&Q,&Q1,'i');
    enqueue2(&Q,&Q1,'l');
    
    
    dequeue(&Q, &e);
    printf("Queue Q1 sekarang :\n");
    viewQueue(Q1);
    printf("Head Queue Q1 : %d\n", head(Q1));
    printf("Tail Queue Q1: %d\n", tail(Q1));
    printf("Queue Q sekarang :\n");
    viewQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q: %d\n", tail(Q));
    
    printf("\n\n=========================== MELAKUKAN dequeue2 ===========================\n\n");
    dequeue2(&Q,&Q1,&e);
    
    printf("Queue Q1 sekarang :\n");
    viewQueue(Q1);
    printf("Head Queue Q1 : %d\n", head(Q1));
    printf("Tail Queue Q1: %d\n", tail(Q1));
    printf("Queue Q sekarang :\n");
    viewQueue(Q);
    printf("Head Queue Q : %d\n", head(Q));
    printf("Tail Queue Q: %d\n", tail(Q));
    
    
    printf("\n\n=========================== PROGRAM SELESAI ===========================\n\n");
    
    return 0;
}