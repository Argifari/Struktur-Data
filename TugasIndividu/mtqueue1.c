/*
Nama File : mtqueue1.c
Deskripsi : Main Driver dari ADT Queeue 1 deengan head yang selalu 1;
Pembuat : 24060124130107 / Muhammad Firdaus Argifari
TGL peembbuatan : 11 Oktobbeer 2025
*/

// Headeer file

#include <stdio.h>
#include "tqueue1.c"

// Main Program

int main () {
    // Kamus
    tqueue1 Q;
    Proses P1,P2,P3,P4,P5;
    Proses P;
    int totWaktu;
    int Quantum;

    // Algoritma
    Quantum = 3;
    totWaktu = 0;
    printf("\n\n========================== PROGRAM PENJADWALAN ROUND ROBIN BERJALAN==========================\n\n");
    printf("\n\n========================== PEMBUATAN SETIAP PROSES ==========================\n\n");
    MakeProses(&P1,'1',3);
    MakeProses(&P2,'2',6);
    MakeProses(&P3,'3',1);
    MakeProses(&P4,'4',4);
    MakeProses(&P5,'5',7);
    
    printf("\n\n========================== PEMBUATAN QUEUE ==========================\n\n");
    CreateQueue(&Q);
    printf("Queue Q sekarang : \n");
    printQueue(Q);
    
    printf("\n\n========================== ENQUEUE SETIAP PROSES ==========================\n\n");
    enqueue(&Q,P1);
    enqueue(&Q,P2);
    enqueue(&Q,P3);
    enqueue(&Q,P4);
    enqueue(&Q,P5);
    
    printf("Queue Q sekarang : \n");
    printQueue(Q);
    printf("\n\n========================== PENJADWALAN ROUND ROBIN BERJALAN ==========================\n\n");
    
    while (!isEmptyQueue(Q))
    {   printf("\n==== MULAI ====\n");
        printf("Antrian Proses Sekarang :\n");
        printQueue(Q);
        printf("\nWaktu Mulai Proses %c : %d\n", GetID(InfoHead(Q)), totWaktu);
        if (GetBurstTime(InfoHead(Q)) <= Quantum) {
            totWaktu += GetBurstTime(InfoHead(Q)); 
            printf("\nWaktu Selesai Proses %c : %d\n", GetID(InfoHead(Q)), totWaktu);
            dequeue(&Q,&P);
        }else {
            SetBurstTime(&Q.wadah[Head(Q)], GetBurstTime(InfoHead(Q)) - Quantum);
            dequeue(&Q,&P);
            enqueue(&Q,P);
            totWaktu += Quantum;
        }
    }
    printf("\n\n========================== PENJADWALAN ROUND ROBIN BERHENTI ==========================\n\n");
    
    
    printf("\n\n========================== PROGRAM PENJADWALAN ROUND ROBIN BERAKHIR ==========================\n\n");
    return 0;
}