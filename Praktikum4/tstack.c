/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124130107 / Muhammad Firdaus Argifari*/
/* Tanggal   : 24 September 2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*T).top = 0;
    for (int i = 1; i <= 10; i++) {
        (*T).wadah[i] = '#';
    }
}

/*procedure createStackStr( output T: TstackStr)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = "/" }
	{Proses: menginisialisasi T} */
void createStackStr (TstackStr *T) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*T).top = 0;
    for (int i = 1; i <= 10; i++) {
        strcpy((*T).wadah[i].value, "/");
    }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function topStr( T: TstackStr) -> integer
	{mengembalikan posisi puncak stack } */
//int top (TstackStr T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define topStr(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function infotopStr( T: TstackStr) -> string
	{mengembalikan nilai elemen top stack } */
//char infotop (TstackStr T);
#define infotopStr(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
    // Kamus Lokal

    // Algoritma
    return top(T) == 0;
}

/*function isEmptyStackStr( T: TstackStr) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStackStr (TstackStr T) {
    // Kamus Lokal

    // Algoritma
    return topStr(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
    // Kamus Lokal

    // Algoritma
    return top(T) == 10;
}

/*function isFullStackStr( T: TstackStr) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStackStr (TstackStr T) {
    // Kamus Lokal

    // Algoritma
    return topStr(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
    // Kamus Lokal

    // Algoritma
    if (!isFullStack(*T)) {
        (*T).wadah[top(*T) + 1] = E;  
        (*T).top = top(*T) + 1;
    }
}

/*procedure pushStr ( input/output T:TstackStr, input E: string )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void pushStr (TstackStr *T, string E) {
    // Kamus Lokal

    // Algoritma
    if (!isFullStackStr(*T)) {
        strcpy((*T).wadah[topStr(*T) + 1].value, E.value);  
        (*T).top = topStr(*T) + 1;
    }   
}


/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
    // Kamus Lokal

    // Algoritma
    if (!isEmptyStack(*T)) {
        (*X) = infotop(*T);
        (*T).wadah[top(*T)] = '#';
        (*T).top = top(*T) - 1;
    }
}

/*procedure popStr ( input/output T:TstackStr, output X: string )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau "/" }
	{Proses: mengambil elemen top, bila belum kosong }*/
void popStr (TstackStr *T, string *X) {
    // Kamus Lokal

    // Algoritma
    if (!isEmptyStackStr(*T)) {
        strcpy((*X).value,infotopStr(*T).value);
        strcpy((*T).wadah[topStr(*T)].value,"/");
        (*T).top = topStr(*T) - 1;
    }   
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (int i = 1; i <= 10; i++) {
        if (i == 10) {
            printf("%c\n", T.wadah[i]);
        }else {
            printf("%c, ", T.wadah[i]);
        }
    }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (int i = 1; i <= top(T); i++) {
        if (i == top(T)) {
            printf("%c\n",T.wadah[i]);
        }else {

            printf("%c, ",T.wadah[i]);
        }
    }
}

/*procedure viewStackStr ( input T:TstackStr )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStackStr (TstackStr T) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (int i = 1; i <= topStr(T); i++) {
        if (i == topStr(T)) {
            printf("%s\n",T.wadah[i].value);
        }else {

            printf("%s, ",T.wadah[i].value);
        }
    }
}


/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]) {
    // Kamus Lokal
    int n,i;
    char x;
    Tstack T;

    // Algoritma
    n = strlen(kata);
    createStack(&T);
    for (int i = 0; i < n/2; i++) {
        push(&T, kata[i]);
    }
    if (n % 2 == 0) {
        for (int i = (n/2); i < n; i++) {
            pop(&T, &x);
            if (kata[i] != x ) {
                return false;
            }
        }
        if (!isEmptyStack(T)){
            return false;
        }else {
            return true;
        }
    }else {
        for (int i = (n/2) + 1; i < n; i++) {
            pop(&T, &x);
            if (kata[i] != x ) {
                return false;
            }
        }
        if (!isEmptyStack(T)){
            return false;
        }else {
            return true;
        } 
    }
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N) {
    // Kamus Lokal
    int i;
    char x;

    // Algoritma
    i = 1;
    if (!isFullStack(*T)) {
        for (int i = 1; i <= N; i++) {
            scanf("%c", &x);
            push(&(*T),x);
        }
    }
    
}

/* kerjakan latihan aplikasi stack di file mbrowser.c */