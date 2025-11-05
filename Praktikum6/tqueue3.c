
#include "tqueue3.h"

/* Program   : tqueue3.c */
/* Deskripsi : realisasi ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 8 Oktober 2025*/
/***********************************/


/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return head3(Q) == 0 && tail3(Q) == 0;
}
 
/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return head3(Q) == (tail3(Q) % 5) + 1;
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return head3(Q) == tail3(Q);
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q) {
    // Kamus Lokal
    int i ;

    // Algoritma
    (*Q).head = 0;
    (*Q).tail = 0;
    for (int i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return Q.wadah[head3(Q)];
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return Q.wadah[tail3(Q)];
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    if (isEmptyQueue3(Q)) {
        return 0;
    }
    else if (head3(Q) > tail3(Q)) {
        return 10 - head3(Q) + tail3(Q) + 1;
    }else {
        return tail3(Q) - head3(Q) + 1;
    }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (int i = 1; i <= 5; i++) {
        if (i == 5) {
            printf(" %c", Q.wadah[i]);
        }else {
            printf(" %c,", Q.wadah[i]);
        }
    }
    printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q) {
    // Kamus Lokal
    int i;

    // Algoritma
    i = head3(Q);
    for (int j = 1; j <= sizeQueue3(Q); j++) {
        if (j == sizeQueue3(Q)) {
            printf(" %c", Q.wadah[i]);
        }else {
            printf(" %c," ,Q.wadah[i]);
        }
        i = (i % 5) + 1;
    }
    printf("\n");
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
    // Kamus Lokal

    // Algoritma
    if (!isFullQueue3(*Q)) {
        if (isEmptyQueue3(*Q)) {
            (*Q).wadah[1] = E;
            (*Q).head = 1;
            (*Q).tail = 1;
        }else if (tail3(*Q) < 5) {
            (*Q).wadah[tail3(*Q) + 1] = E;
            (*Q).tail = tail3(*Q) + 1;
        }else {
            (*Q).wadah[1] = E;
            (*Q).tail = 1;
        }
    }

}
  
/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E) {
    // Kamus Lokal

    // Algoritma
    if (!isEmptyQueue3(*Q)) {
        if (isOneElement3(*Q)) {
            (*E) = infoHead3(*Q);
            (*Q).wadah[head3(*Q)] = '#';
            (*Q).head = 0;
            (*Q).tail = 0;
        }
        else if (head3(*Q) < 5) {
            (*E) = infoHead3(*Q);
            (*Q).wadah[head3(*Q)] = '#';
            (*Q).head = head3(*Q) + 1;
        }else {
            (*E) = infoHead3(*Q);
            (*Q).wadah[head3(*Q)] = '#';
            (*Q).head = 1;
        }
    }else {
        (*E) = ' ';
    }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
    // Kamus Lokal

    // Algoritma
    return tail3(Q) < head3(Q);
}