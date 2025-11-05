/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue karakter */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 1 Oktober 2025*/
/***********************************/
#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/ 
void createQueue(tqueue *Q) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for (int i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '-';
    }
    
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
int infoHead(tqueue Q) {
    // Kamus Lokal
    // Algoritma
    if (!isEmptyQueue(Q)) {
        return Q.wadah[head(Q)];
    }
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
int infoTail(tqueue Q) {
    // Kamus Lokal
    // Algoritma
    if (!isEmptyQueue(Q)) {

        return Q.wadah[tail(Q)];
    }
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q) {
    // Kamus Lokal
    // Algoritma
    return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= 5; i++) {
        if (i == 5) {
            printf(" %c", Q.wadah[i]);
        }else {
            printf(" %c,",Q.wadah[i]);
        }
    }
    printf("\n");
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= sizeQueue(Q); i++) {
        if (i == 5) {
            printf(" %c", Q.wadah[i]);
        }else {
            printf(" %c,",Q.wadah[i]);
        }
    }
    printf("\n");

}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q) {
    // Kamus Lokal
    // Algoritma
    return tail(Q) == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q) {
    // Kamus Lokal
    // Algoritma
    return tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q) {
    // Kamus Lokal

    // Algoritma
    return tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e) {
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue(*Q)) {
        (*Q).wadah[tail(*Q) + 1] = e;
        (*Q).tail = tail(*Q) + 1;
        (*Q).head = 1;
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e) {
    // Kamus Lokal
    int i;

    // Algoritma
    if (isOneElement(*Q)) {
        (*e) = infoHead(*Q);
        (*Q).wadah[head(*Q)] = '-';
        (*Q).head = 0;
        (*Q).tail = 0;

    }
    else if (!isEmptyQueue(*Q)) {
        (*e) = infoHead(*Q);
        for (int i = head(*Q) + 1; i <= tail(*Q); i++ ) {
            (*Q).wadah[i - 1] = (*Q).wadah[i];
            (*Q).wadah[i] = '-';
        }
        (*Q).tail = tail(*Q) - 1;
    }else {
        (*e) = '-';
    }
}

/*tambahan, dikerjakan bila cukup waktu */

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e) {
    // Kamus Lokal

    // Algoritma
    if (sizeQueue(*Q2) >= sizeQueue(*Q1)) {
        if (!isFullQueue(*Q1)) {
            (*Q1).wadah[tail(*Q1) + 1] = e;
            (*Q1).tail = tail(*Q1) + 1;
            (*Q1).head = 1;
        }
    } else {
        if (!isFullQueue(*Q2)) {
            (*Q2).wadah[tail(*Q2) + 1] = e;
            (*Q2).tail = tail(*Q2) + 1;
            (*Q2).head = 1;
        }
    }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e) {
    // Kamus Lokal
    int i;

    // Algoritma
    if (sizeQueue(*Q1) >= sizeQueue(*Q2)) {
        if (isOneElement(*Q1)) {
            (*e) = infoHead(*Q1);
            (*Q1).wadah[head(*Q1)] = '-';
            (*Q1).head = 0;
            (*Q1).tail = 0;

        }
        else if (!isEmptyQueue(*Q1)) {
            (*e) = infoHead(*Q1);
            for (int i = head(*Q1) + 1; i <= tail(*Q1); i++ ) {
                (*Q1).wadah[i - 1] = (*Q1).wadah[i];
                (*Q1).wadah[i] = '-';
            }
            (*Q1).tail = tail(*Q1) - 1;
        }else {
            (*e) = '-';
        }
    } else {
        if (isOneElement(*Q2)) {
            (*e) = infoHead(*Q2);
            (*Q2).wadah[head(*Q2)] = '-';
            (*Q2).head = 0;
            (*Q2).tail = 0;

        }
        else if (!isEmptyQueue(*Q2)) {
            (*e) = infoHead(*Q2);
            for (int i = head(*Q2) + 1; i <= tail(*Q2); i++ ) {
                (*Q2).wadah[i - 1] = (*Q2).wadah[i];
                (*Q2).wadah[i] = '-';
            }
            (*Q2).tail = tail(*Q2) - 1;
        }else {
            (*e) = '-';
        }
    }

}