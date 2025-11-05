/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal   : 17 September 2025*/
/***********************************/

#include <stdio.h>
#include "matriks.h"
#include <stdlib.h>

/* include matriks.h & boolean.h */

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    // Kamus Lokal

    // Algoritma
    (*M).nbaris = 0;
    (*M).nkolom = 0;
    for (int i = 1; i <= 10;i++) {
        for (int j = 1; j <= 10; j++) {
            (*M).cell[i][j] = -999;
        }
    }
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    // Kamus Lokal

    // Algoritma
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    // Kamus Lokal

    // Algoritma
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    // Kamus Lokal

    // Algoritma
    return getNBaris(M) == 0 && getNKolom(M) == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
    // Kamus Lokal

    // Algoritma
    return (getNBaris(M) == 10) && getNKolom(M) == 10;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col) {
    // Kamus Lokal

    // Algoritma
    if (!isFullMatriks(*M)) {
        (*M).cell[row][col] = X;
    }
    if (row > getNBaris(*M)) {
        (*M).nbaris = getNBaris(*M) + 1;
    }
    if (col > getNKolom(*M)) {
        (*M).nkolom = getNKolom(*M) + 1;
    }
        

}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
    //Kamus Lokal
    boolean colEmpty = true;
    boolean rowEmpty = true;

    // Algoritma

    for (int i = 1; i <= getNBaris(*M); i++) {
        for (int j = 1; j <= getNKolom(*M); j++) {
            if ((*M).cell[i][j] == X) {
                (*M).cell[i][j] = -999;
            }
        }
    }

    for (int i = 1; i <= getNBaris(*M); i++) {
        rowEmpty = true;
        for (int j = 1; j <= getNKolom(*M); j++) {
            if ((*M).cell[i][j] != -999) {
                rowEmpty = false;
            }
            if (rowEmpty == true) {
                (*M).nbaris = getNBaris(*M) - 1;
            }
        }

    }
    for (int j = 1; j <= getNKolom(*M); j++) {
        colEmpty = true;
        for (int i = 1; i <= getNBaris(*M); i++) {
            if ((*M).cell[i][j] != -999) {
                colEmpty = false;
            }
            if (colEmpty == true) {
                (*M).nkolom = getNKolom(*M) - 1;
            }
        }

    }
    
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    // Kamus Lokal

    // Algoritma
    for(int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            (*M).cell[i][j] = rand()%100;
        }
    }
    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    // Kamus Lokal

    // Algoritma
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                (*M).cell[i][j] = 1;
            }else {
                
                (*M).cell[i][j] = 0;
            }
        }
    }
    (*M).nbaris = n;
    (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    // Kamus Lokal

    // Algoritma
    for(int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            scanf("%d", &(*M).cell[i][j]);
        }
    }
    (*M).nbaris = x;
    (*M).nkolom = y;

}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    // Kamus Lokal

    // Algoritma
    for(int i = 1; i <= 10;i++) {
        for(int j = 1; j <= 10; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
 }

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    // Kamus Lokal

    // Algoritma

    for(int i = 1; i <= getNBaris(M);i++) {
        for(int j = 1; j <= getNKolom(M); j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal 
    Matriks hasil;
    initMatriks(&hasil);

    // Algoritma
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for(int i = 1; i <= getNBaris(M1); i++) {
            for( int j = 1; j <= getNKolom(M1); j++) {
                if (M1.cell[i][j] == -999) {
                    hasil.cell[i][j] = M2.cell[i][j];
                }
                else if (M2.cell[i][j] == -999) {
                    hasil.cell[i][j] = M1.cell[i][j];
                }else {
                    hasil.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
                }

            }
        }
        hasil.nbaris = getNBaris(M1);
        hasil.nkolom = getNKolom(M1);
    }
    return hasil;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal 
    Matriks hasil;
    initMatriks(&hasil);

    // Algoritma
    
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for(int i = 1; i <= getNBaris(M1); i++) {
            for( int j = 1; j <= getNKolom(M1); j++) {
                if (M1.cell[i][j] == -999) {
                    hasil.cell[i][j] = M2.cell[i][j];
                }
                else if (M2.cell[i][j] == -999) {
                    hasil.cell[i][j] = M1.cell[i][j];
                }else {
                    hasil.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
                }

            }
        }
        hasil.nbaris = getNBaris(M1);
        hasil.nkolom = getNKolom(M1);
    }
    return hasil;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    // Kamus Lokal 
    Matriks hasil ;

    // Algoritma
    initMatriks(&hasil);
    if (getNKolom(M1) == getNBaris(M2)) {
        hasil.nbaris = getNBaris(M1);
        hasil.nkolom = getNKolom(M2);
        for (int i = 1; i <= getNBaris(M1); i++) {
            for (int j = 1; j <= getNKolom(M2);j++) {
                hasil.cell[i][j] = 0;
                for (int k = 1; k <= getNKolom(M1); k++) {
                    hasil.cell[i][j] += M1.cell[i][k]*M2.cell[k][j];
                }
            }
        }
    }
    return hasil;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    // kamus lokal
    Matriks hasil;

    // Algoritma
    initMatriks(&hasil);
    for (int i = 1; i <= getNBaris(M1); i++) {
        for (int j = 1; j <= getNKolom(M1); j++) {
            hasil.cell[i][j] = x*M1.cell[i][j];
        }
    }
    hasil.nbaris = getNBaris(M1);
    hasil.nkolom = getNKolom(M1);
    return hasil;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    // Kamus Lokal
    Matriks temp;

    // Algoritma
    initMatriks(&temp);
    for (int i = 1; i <= getNBaris(*M); i++) {
        for (int j = 1; j <= getNKolom(*M); j++) {
            temp.cell[i][j] = (*M).cell[i][j];
        }
    }
    temp.nbaris = getNBaris(*M);
    temp.nkolom = getNKolom(*M);
    for (int i = 1; i <= getNBaris(*M); i++) {
        for (int j = 1; j <= getNKolom(*M); j++) {
            (*M).cell[j][i] = temp.cell[i][j]; 
        }
    }
    (*M).nbaris = getNKolom(temp);
    (*M).nkolom = getNBaris(temp);
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    // Kamus Lokal
    Matriks hasil;
    
    // algoritma
    initMatriks(&hasil);

    hasil.nbaris = getNKolom(M);
    hasil.nkolom = getNBaris(M);
    for (int i = 1; i <= getNBaris(hasil); i++) {
        for (int j = 1; j <= getNKolom(hasil); j++) {
            hasil.cell[i][j] = M.cell[j][i];
        }
    }
    return hasil;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n) {
    // Kamus Lokal
    Matriks hasil; 

    // Algoritma
    initMatriks(&hasil);
    for (int i = 1; i <= getNBaris(M) + n*2; i++) {
        for (int j = 1; j <= getNKolom(M) + n*2; j++) {
            hasil.cell[i][j] = 0;
        }
    }

    hasil.nbaris = getNBaris(M) + n*2;
    hasil.nkolom = getNKolom(M) + n*2;
    
    for (int i = 1; i <= getNBaris(M); i++) {
        for (int j = 1; j <= getNKolom(M); j++) {
            hasil.cell[i + n][j + n] = M.cell[i][j];
        }
    }
    return hasil;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size) {
    // Kamus Lokal
    int maks;
    int col;
    int row;
    Matriks hasil;
    
    // Algoritma
    initMatriks(&hasil);
    hasil.nbaris = getNBaris(M) / size;
    hasil.nkolom = getNKolom(M) / size;

    for (int i = 1; i <= getNBaris(hasil); i++) {
        for (int j = 1; j <= getNKolom(hasil); j++) {
            maks = M.cell[(i-1)*size + 1][(j-1)*size + 1];
            
            for (int batasBaris = 1; batasBaris <= size; batasBaris++) {
                for (int batasKolom = 1; batasKolom <= size; batasKolom++) {
            
                    row = (i-1)*size + batasBaris;
                    col = (j-1)*size + batasKolom;

                    if (((row <= getNBaris(M)) && ((col <= getNKolom(M))))) {
                        if (maks < M.cell[row][col]) {
                            maks = M.cell[row][col];
                        }
                    }
                }
            }
            hasil.cell[i][j] = maks;
        }
    }
    return hasil;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size) {
    // Kamus Lokal
    int jumlahElemen;
    int hitung;
    int col;
    int row;
    Matriks hasil;
    
    // Algoritma
    initMatriks(&hasil);
    hasil.nbaris = getNBaris(M) / size;
    hasil.nkolom = getNKolom(M) / size;

    for (int i = 1; i <= getNBaris(hasil); i++) {
        for (int j = 1; j <= getNKolom(hasil); j++) {
            hitung = 0;
            jumlahElemen = 0;
            for (int batasBaris = 1; batasBaris <= size; batasBaris++) {
                for (int batasKolom = 1; batasKolom <= size; batasKolom++) {
            
                    row = (i-1)*size + batasBaris;
                    col = (j-1)*size + batasKolom;
                    
                    if (((row <= getNBaris(M)) && ((col <= getNKolom(M))))) {
                        hitung += M.cell[row][col];
                        jumlahElemen += 1;
                    }
                }
            }
            hasil.cell[i][j] = hitung / jumlahElemen;
        }
    }
    return hasil;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    // Kamus Lokal
    Matriks hasil;
    int jumlah;

    // Algoritma
    initMatriks(&hasil);
    hasil.nbaris = getNBaris(M) - getNBaris(K) + 1;
    hasil.nkolom = getNKolom(M) - getNKolom(K) + 1;
    
    for (int i = 1; i <= getNBaris(hasil); i++) {
        for (int j = 1; j <= getNKolom(hasil); j++) {
            jumlah = 0;

            for (int barisKernel = 1; barisKernel <= getNBaris(K); barisKernel++) {
                for (int kolomKernel = 1; kolomKernel <= getNKolom(K); kolomKernel++) {
                    jumlah += M.cell[i + barisKernel - 1][j + kolomKernel - 1] * K.cell[barisKernel][kolomKernel];
                }
            }

            hasil.cell[i][j] = jumlah;
            
        }
    }
    return hasil;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell}  */
void searchX(Matriks M, int X, int *row, int *col) {
    // Kamus Lokal
    int i, j;

    // Algoritma
    (*row) = -999;
    (*col) = -999;

    for (int i = 1; i <= getNBaris(M); i++) {
        for (int j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] == X) {
                (*row) = i;
                (*col) = j;
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X) {
    // Kamus Lokal
    int hitung = 0;

    // Algoritma
    for (int i = 1; i <= getNBaris(M); i++) {
        for (int j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] == X) {
                hitung++;
            }
        }
    }
    return hitung;
}
