/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari */
/* Tanggal   : 3 September 2025  */
/***********************************/
#include <stdio.h>
#include "titik.h"

/*KONSTRUKTOR*/
/* procedure makeTitik(output T:Titik, input x:integer, y:integer) */
/* {I.S.: -}*/
/* {F.S.: T terdefinisi}*/
/* {proses: mengisi nilai komponen absis dengan x dan ordinat dengan y} */
void makeTitik(Titik *T, int x, int y) {
    (*T).absis = x;
    (*T).ordinat = y;
}

/* procedure makeTitik0(output T:Titik)*/
/* {I.S.: -}*/
/* {F.S.: T terdefinisi}*/
/* {proses: mengisi nilai komponen absis dan ordinat T dengan 0} */
void makeTitik0(Titik *T) {
    (*T).absis = 0;
    (*T).ordinat = 0;
}

/**********SELEKTOR**********/
/* function getAbsis(T:Titik)->integer */
/* {mengembalikan nilai komponen absis T} */
int getAbsis(Titik T) {
    return T.absis;
}

/* function getOrdinat(T:Titik)->integer */
/* {mengembalikan nilai komponen ordinat T} */
int getOrdinat(Titik T){
    return T.ordinat;
}

/*********MUTATOR**********/
/* procedure setAbsis(input/output T, input x) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T.absis=x} */
/* {proses: mengubah nilai komponen absis T dengan x} */
void setAbsis(Titik *T, int x) {
    (*T).absis = x;
}

/* procedure setOrdinat(input/output T, input y) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T.ordinat=y} */
/* {proses: mengisi nilai komponen ordinat T dengan y} */
void setOrdinat(Titik *T, int y) {
    (*T).ordinat = y;
}

/*********PREDIKAT**********/
/* function isOrigin(T:Titik)->boolean */
/* {mengembalikan true jika Titik T adalah titik (0,0)} */
boolean isOrigin(Titik T) {
    return getAbsis(T) == 0 && getOrdinat(T) == 0;
}

/* function isOnSumbuX(T:Titik)->boolean */
/* {mengembalikan true jika Titik T terletak di sumbu X} */
boolean isOnSumbuX(Titik T) {
    return getOrdinat(T) == 0;
}

/* function isOnSumbuY(T:Titik)->boolean */
/* {mengembalikan true jika Titik T terletak di sumbu Y} */
boolean isOnSumbuY(Titik T) {
    return getAbsis(T) == 0;
}

/* function isEqual(T1:Titik, T2:Titik)->boolean */
/* {mengembalikan true jika Titik T1 dan T2 memiliki absis dan ordinat yang sama */
boolean isEqual(Titik T1, Titik T2) {
    return getOrdinat(T1) == getOrdinat(T2) && getAbsis(T1) == getAbsis(T2);
}

/*********SUBRUTIN LAIN*********/
/* procedure geser(input/output T:Titik, input x, input y) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T bergeser sejauh (x,y)} */
/* {proses: menggeser titik T sejauh (x,y)} */
void geser(Titik *T, int x, int y) {
    setAbsis(T,getAbsis(*T) + x);
    setOrdinat(T, getOrdinat(*T) + y);
}

/* procedure refleksiX(input/output T:Titik) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dicerminkan ke sumbu X } */
/* {proses: mencerminkan titik T terhadap sumbu X} */
void refleksiX(Titik *T) {
    setOrdinat(T , getOrdinat(*T)*(-1));
}

/* procedure refleksiY(input/output T:Titik) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dicerminkan ke sumbu Y } */
/* {proses: mencerminkan titik T terhadap sumbu Y} */
void refleksiY(Titik *T) {
    setAbsis(T, getAbsis(*T)*(-1));
}

/* procedure dilatasi(input/output T:Titik, input k:real) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dilakukan dilatasi dengan faktor skala k } */
/* {proses: melakukan dilatasi titik T terhadap titik pusat (0,0) dengan faktor skala k} */
void dilatasi(Titik *T, float k) {
    setAbsis(T, getAbsis(*T)*k);
    setOrdinat(T,getOrdinat(*T)*k);
}

/* procedure dilatasi(input/output T:Titik, input X:Titik, k:real) */
/* {I.S.: T terdefinisi} */
/* {F.S.: T dilakukan dilatasi terhadap titik X dengan faktor skala k } */
/* {proses: melakukan dilatasi titik T terhadap titik X dengan faktor skala k} */
void dilatasiX(Titik *T, Titik X, float k) {
    setAbsis(T,(getAbsis(*T) - getAbsis(X))*k + getAbsis(X));
    setOrdinat(T,(getOrdinat(*T) - getOrdinat(X))*k + getOrdinat(X));
}

/* function kuadran(T:Titik)->integer */
/* {mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4} */
/* {asumsi: Titik T bukan titik origin */
int kuadran(Titik T) {
    if (getAbsis > 0) {
        if (getOrdinat > 0 ) {
            return 1;
        }else {
            return 4;
        }
    }else {
        if (getOrdinat > 0) {
            return 2;
        }
        else {
            return 3;
        }
    }
    return isOrigin(T);
}