#ifndef tstack_H
#define tstack_H 

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack karakter dan string */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 24 September 2025*/
/***********************************/

#include "boolean.h"  //salin dari praktikum lalu
#include "string.h"

/* type Tstack = < wadah : array[1..10] of character,
                   top   : integer > */
typedef	struct { char wadah[11];
                 int  top; 
			   } Tstack;
/*karakter kosong dilambangkan dengan '#'  */

/* type TstackStr = < wadah : array[1..10] of string,
                   top   : integer > */
typedef struct 
{
    string wadah[11];
    int top;
} TstackStr;
/*string kosong dilambangkan dengan "/"  */

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T);

/*procedure createStackStrs( output T: TstackStr)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = "/" }
	{Proses: menginisialisasi T} */
void createStackStr (TstackStr *T);

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
boolean isEmptyStack (Tstack T);

/*function isEmptyStackStr( T: TstackStr) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStackStr (TstackStr T);

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T);

/*function isFullStackStr( T: TstackStr) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStackStr (TstackStr T);

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E);

/*procedure pushStr ( input/output T:TstackStr, input E: string )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void pushStr (TstackStr *T, string E);

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X);

/*procedure popStr ( input/output T:TstackStr, output X: string )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau "/" }
	{Proses: mengambil elemen top, bila belum kosong }*/
void popStr (TstackStr *T, string *X);

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T);

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T);

/*procedure viewStackStr ( input T:TstackStr )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStackStr (TstackStr T);

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]);

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N);

/* kerjakan latihan aplikasi stack di file mbrowser.c */

#endif
