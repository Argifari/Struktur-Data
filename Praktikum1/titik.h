#ifndef titik_H
#define titik_H
 
/***********************************/
/* Program   : titik.h */
/* Deskripsi : header file modul Titik */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 3 September 2025*/
/***********************************/
//#include <stdio.h>

typedef enum {false, true} boolean;

/* NOTASI ALGORITMIK : */
/* type Titik=<absis:integer, ordinat:integer> */
/* DITERJEMAHKAN KE BAHASA C : */
typedef struct {int absis; int ordinat;} Titik;
/* cara akses T:Titik, T.absis, T.ordinat */

/*KONSTRUKTOR*/
/* procedure makeTitik(output T:Titik, input x:integer, y:integer) */
/* {I.S.: -}*/
/* {F.S.: T terdefinisi}*/
/* {proses: mengisi nilai komponen absis dengan x dan ordinat dengan y} */
void makeTitik(Titik *T, int x, int y);

/* procedure makeTitik0(output T:Titik)*/
/* {I.S.: -}*/
/* {F.S.: T terdefinisi}*/
/* {proses: mengisi nilai komponen absis dan ordinat T dengan 0} */
void makeTitik0(Titik *T);

/**********SELEKTOR**********/
/* function getAbsis(T:Titik)->integer */
/* {mengembalikan nilai komponen absis T} */
int getAbsis(Titik T);

/* function getOrdinat(T:Titik)->integer */
/* {mengembalikan nilai komponen ordinat T} */
int getOrdinat(Titik T);

/*********MUTATOR**********/
/* procedure setAbsis(input/output T, input x) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T.absis=x} */
/* {proses: mengubah nilai komponen absis T dengan x} */
void setAbsis(Titik *T, int x);

/* procedure setOrdinat(input/output T, input y) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T.ordinat=y} */
/* {proses: mengisi nilai komponen ordinat T dengan y} */
void setOrdinat(Titik *T, int y);

/*********PREDIKAT**********/
/* function isOrigin(T:Titik)->boolean */
/* {mengembalikan true jika Titik T adalah titik (0,0)} */
boolean isOrigin(Titik T);

/* function isOnSumbuX(T:Titik)->boolean */
/* {mengembalikan true jika Titik T terletak di sumbu X} */
boolean isOnSumbuX(Titik T);

/* function isOnSumbuY(T:Titik)->boolean */
/* {mengembalikan true jika Titik T terletak di sumbu Y} */
boolean isOnSumbuY(Titik T);

/* function isEqual(T1:Titik, T2:Titik)->boolean */
/* {mengembalikan true jika Titik T1 dan T2 memiliki absis dan ordinat yang sama */
boolean isEqual(Titik T1, Titik T2);

/*********SUBRUTIN LAIN*********/
/* procedure geser(input/output T:Titik, input x, input y) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T bergeser sejauh (x,y)} */
/* {proses: menggeser titik T sejauh (x,y)} */
void geser(Titik *T, int x, int y);

/* procedure refleksiX(input/output T:Titik) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dicerminkan ke sumbu X } */
/* {proses: mencerminkan titik T terhadap sumbu X} */
void refleksiX(Titik *T);

/* procedure refleksiY(input/output T:Titik) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dicerminkan ke sumbu Y } */
/* {proses: mencerminkan titik T terhadap sumbu Y} */
void refleksiY(Titik *T);

/* procedure dilatasi(input/output T:Titik, input k:real) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dilakukan dilatasi dengan faktor skala k } */
/* {proses: melakukan dilatasi titik T terhadap titik pusat (0,0) dengan faktor skala k} */
void dilatasi(Titik *T, float k);

/* procedure dilatasi(input/output T:Titik, input X:Titik, k:real) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dilakukan dilatasi terhadap titik X dengan faktor skala k } */
/* {proses: melakukan dilatasi titik T terhadap titik X dengan faktor skala k} */
void dilatasiX(Titik *T, Titik X, float k);

/* function kuadran(T:Titik)->integer */
/* {mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4} */
/* {asumsi: Titik T bukan titik origin */
int kuadran(Titik T);

#endif