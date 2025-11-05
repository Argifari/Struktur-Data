
#include "tabel.h"
/* Deskripsi : Modul realisasi Table*/
/* NIM/Nama : 24060124130107 Muhammad Firdaus Argifari*/
/* Tanggal : 10 September 2025*/

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T) {
    (*T).size = 0;
    for (int i = 1; i <= 10; i++) {
        (*T).wadah[i] = ' ';
    }
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T) {
    return T.size;
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T) {
    return getSize(T) == 0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T) {
    return getSize(T) == 10;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos) {
    int i = 1;
    (*pos) = -999;
    while (i <= getSize(T) && (*pos) == -999) {
        if (T.wadah[i] == x) {
            (*pos) = i;
        }
    }
    
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x) {
    // kamus lokal
    int count = 0;
    for (int i = 1; i <= getSize(T); i++) {
        if (x == T.wadah[i]) {
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
    
int countVocal(Tabel T) {
    //kamus lokal
    int count = 0;

    for (int i = 1; i <= getSize(T); i++) {
        if (T.wadah[i] == 'a' || T.wadah[i] == 'A' || T.wadah[i] == 'i' || T.wadah[i] == 'I'
        || T.wadah[i] == 'u' || T.wadah[i] == 'U' || T.wadah[i] == 'e' || T.wadah[i] == 'E'
        || T.wadah[i] == 'o' || T.wadah[i] == 'O') {
            count++;
        }
    }
    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x) {
    if (!isFullTable(*T)) {
        (*T).size = getSize(*T) + 1;
        (*T).wadah[getSize(*T)] = x;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x) {
    if (countX(*T,x) == 0 && !isFullTable(*T)) {
        (*T).size = getSize(*T) + 1;
        (*T).wadah[getSize(*T)] = x;
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x) {
    if (!isEmptyTable(*T)) {
        for (int i = 1; i <= getSize(*T); i++) {
            if ((*T).wadah[i] == x) {
                (*T).wadah[i] = ' ';
            }
        }
        for (int i = 1; i < getSize(*T); i++) {
            if ((*T).wadah[i] == ' ') {
                (*T).wadah[i] = (*T).wadah[i + 1];
                (*T).wadah[i + 1] = ' ';
            }
        }
        (*T).size = getSize(*T) - 1; 
    }
}
    

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx) {
    if (!isEmptyTable(*T)) {
        for (int i = idx; i < getSize(*T); i++) {
            (*T).wadah[i] = (*T).wadah[i + 1];
        }
        (*T).wadah[idx] = ' ';
        (*T).size = getSize(*T) - 1; 
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x) {
    // kamus lokal
    int n;
    n = countX(*T,x);
    if (!isEmptyTable(*T)) {
        for (int i = 1; i <= getSize(*T); i++) {
            if ((*T).wadah[i] == x) {
                (*T).wadah[i] = ' ';
            }
        }
        for (int i = 1; i < getSize(*T); i++) {
            for (int j = 1; j < getSize(*T); j++) {
                if ((*T).wadah[j] == ' ') {
                    (*T).wadah[j] = (*T).wadah[j + 1];
                    (*T).wadah[j + 1] = ' ';
                }
            }
        }
    }

    (*T).size = getSize(*T) - n; 
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T) {
    for (int i = 1; i <= 10; i++) {
        printf("%c, ", T.wadah[i]);
    }
    printf("\n");
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T) {
    for (int i = 1; i <= getSize(T); i++) {
        printf("%c, ", T.wadah[i]);
    }
    printf("\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N) {
    // Kamus Lokal
    char temp = '0';

    for (int i = 1; i <= N; i++) {
        scanf("%c",&temp);
        if (temp != '0') {
            (*T).wadah[getSize((*T)) + i] = temp;
        }else {
            i -= 1;
            N -= 1;
        }
    }

    (*T).size = getSize((*T)) + N;
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> character 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
char Modus(Tabel T) {
    // Kamus Lokal
    int hitung = 0;
    char ans;

    for (int i = 1; i <= getSize(T); i++) {
        if (hitung <= countX(T,T.wadah[i])) {
            hitung = countX(T,T.wadah[i]);
            ans = T.wadah[i];
        }
    }
    return ans;
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2) {
    if (getSize(T1) != getSize(T2)) {
        return false;
    }else {
        for (int i = 1; i <= getSize(T1); i++) {
            if (T1.wadah[i] != T2.wadah[i]) {
                return false;
            }
        }
    }
    return true;
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T) {
    //Kamus Lokal
    Tabel ans;
    createTable(&ans);

    for (int i = getSize(T); i > 0; i--) {
        ans.wadah[i] = T.wadah[i];
    }
    return ans;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T) {
    
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T) {
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T);

