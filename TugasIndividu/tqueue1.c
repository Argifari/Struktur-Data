#include "tqueue1.h"

/* Program   : tqueue1.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 11 Oktober 2025*/
/***********************************/



/*Procedure MakeProses(input/output P : Proses, input ID : character, input burstTime : integer)
{
I.S : -
F.S : P terdefinisi sebagai proses yang memiliki ID dan burstTime.
}
*/
void MakeProses(Proses *P, char ID, int burstTime) {
    // Kamus Lokal
    // Algoritma
    (*P).ID = ID;
    (*P).burstTime = burstTime;
}

// Function GetID(P : Proses) --> character
// {
// Fungsi yang mengembalikan nilai ID dari Proses P
// }
char GetID(Proses P) {
    // Kamus Lokal
    // Algoritma
    return P.ID;
}

/*Function GetBurstTime(P : Proses) --> integer
{mengembalikan nilai burst time dari Proses P}
*/
int GetBurstTime(Proses P) {
    // Kamus Lokal
    // Algoritma
    return P.burstTime;
}

/*Procedure SetID(input/output P : Proses, input ID : character)
{I.S : P telah terdefinisi
F.S : nilai ID berubah}
*/
void SetID(Proses *P, char ID) {
    // Kamus Lokal

    // Algoritma
    (*P).ID = ID;
}

/*Procedure SetBurstTime(input/output P : Proses, input burstTime : integer)
{I.S : P telah terdefinisi
F.S : nilai burst time di P berubah}*/
void SetBurstTime(Proses *P, int burstTime) {
    // Kamus Lokal

    // Algoritma
    (*P).burstTime = burstTime;   
}

/*procedure createQueue ( output Q:tqueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan <'#', -999>, head=tail=0 }*/ 
void CreateQueue(tqueue1 *Q) {
    // Kamus Lokal
    int i;
    Proses P;

    // Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for (int i = 1; i <= 5; i++) {
        MakeProses(&P,'#',-999);
        (*Q).wadah[i] = P;
    }

}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue1 Q);
#define Head(Q) (Q).head //implementasi fisik macro

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue1 Q);
#define Tail(Q) (Q).tail //implementasi fisik macro

/*function infoHead(Q:tqueue)-> Proses 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Proses InfoHead(tqueue1 Q) {
    // Kamus Lokal
    // Algoritma
    return Q.wadah[Head(Q)];
}

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Proses InfoTail(tqueue1 Q) {
    // Kamus Lokal
    // Algoritma
    return Q.wadah[Tail(Q)];
}


/*procedure printQueue(input Q:tqueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue1 Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= 5; i++) {
        if (i == 5) {
            printf(" <%c,%d>", GetID(Q.wadah[i]), GetBurstTime(Q.wadah[i]));
        }else {
            printf(" <%c,%d>,", GetID(Q.wadah[i]), GetBurstTime(Q.wadah[i]));
        }
    }
    printf("\n");    

}

/*procedure viewQueue(input Q:tqueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue1 Q) {
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= Tail(Q); i++) {
        if (i == Tail(Q)) {
            printf(" <%c,%d>", GetID(Q.wadah[i]), GetBurstTime(Q.wadah[i]));
        }else {
            printf(" <%c,%d>,", GetID(Q.wadah[i]), GetBurstTime(Q.wadah[i]));
        }
    }
    printf("\n");   
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue1 Q) {
    // Kamus Lokal
    // Algoritma
    return Head(Q) == 0 && Tail(Q) == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue1 Q) {
    // Kamus Lokal
    // Algoritma
    return Tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue1 Q) {
    // Kamus Lokal
    // Algoritma
    return Head(Q) == 1 && Tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tqueue, input P: Proses )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue1 *Q, Proses P) {
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue(*Q)) {
        (*Q).wadah[Tail(*Q) + 1] = P;
        (*Q).tail = Tail(*Q) + 1;
        (*Q).head = 1;
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output P : Proses)
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue1 *Q, Proses *P) {
    // Kamus Lokal
    int i;
    Proses E;
    // Algoritma
    if (!isEmptyQueue(*Q)) {
        if (isOneElement(*Q)) {
            (*P) = (*Q).wadah[Head(*Q)];
            MakeProses(&E, '#',-999);
            (*Q).wadah[Head(*Q)] = E;
            (*Q).head = 0;
            (*Q).tail = 0;
        }else {
            (*P) = (*Q).wadah[Head(*Q)];
            MakeProses(&E, '#',-999);
            (*Q).wadah[Head(*Q)] = E;
            for (int i = 1; i <= Tail(*Q) - 1; i++) {
                (*Q).wadah[i] = (*Q).wadah[i + 1];
                (*Q).wadah[i + 1] = E;
            }
            (*Q).tail = Tail(*Q) - 1;
        }
    }
}