#ifndef tqueue_H
#define tqueue_H
#include "boolean.h"

/* Program   : tqueue1.h */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 11 Oktober 2025*/
/***********************************/

/* type Proses = <  wadah: array [1..5] of character ,
					head: integer ,
					tail: integer >
                    */
typedef struct {
    char ID;
    int burstTime;    
} Proses;


/* type tQueue = <  wadah: array [1..5] of Proses ,
					head: integer ,
					tail: integer >
{cara akses: Q:tQueue, Q.head=head(Q) ...} */
typedef struct { Proses wadah[6]; //kapasitas 5 elemen, indeks 0 tidak dipakai
                  int head; 
                  int tail; 
                } tqueue1;

/*Procedure MakeProses(input/output P : Proses, input ID : character, input burstTime : integer)
{
I.S : -
F.S : P terdefinisi sebagai proses yang memiliki ID dan burstTime.
}
*/
void MakeProses(Proses *P, char ID, int burstTime);

// Function GetID(P : Proses)  character
// {
// Fungsi yang mengembalikan nilai ID dari Proses P
// }
char GetID(Proses P);

/*Function GetBurstTime(P : Proses)  integer
{mengembalikan nilai burst time dari Proses P}
*/
int GetBurstTime(Proses P);

/*Procedure SetID(input/output P : Proses, input ID : character)
{I.S : P telah terdefinisi
F.S : nilai ID berubah}
*/
void SetID(Proses *P, char ID);

/*Procedure SetBurstTime(input/output P : Proses, input burstTime : integer)
{I.S : P telah terdefinisi
F.S : nilai burst time di P berubah}*/
void SetBurstTime(Proses *P, int burstTime);

/*procedure createQueue ( output Q:tqueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan <'#', -999>, head=tail=0 }*/ 
void CreateQueue(tqueue1 *Q);

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
Proses InfoHead(tqueue1 Q);

/*function infoTail(Q:tQueue)-> Proses 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Proses InfoTail(tqueue1 Q);


/*procedure printQueue(input Q:tqueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue1 Q);

/*procedure viewQueue(input Q:tqueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue1 Q);

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue1 Q);
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue1 Q);

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue1 Q);

/*procedure enqueue( input/output Q:tqueue, input P: Proses )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue1 *Q, Proses e);
  
/*procedure deQueue( input/output Q:tQueue, output P : Proses)
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue1 *Q, Proses *e);


#endif