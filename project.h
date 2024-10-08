#ifndef PROJECT_H
#define PROJECT_H
// #define first(L) L.first
// #define next(P) P->Next
// #define info(P) P->Info

#include <iostream>
#include <string>

using namespace std;

struct jadwalKuliah {
    string kegiatan, hari;
    int jamMulai, menitMulai;
    int jamAkhir, menitAkhir;
};

typedef jadwalKuliah infotype;
typedef struct elmList* adr;

struct elmList {
    infotype info;
    adr next;
};

struct List {
    adr First;
};

void Create_List(List& L);

adr New_Elemen(infotype data);

void Insert_First(List& L, adr p);
void Insert_Last(List& L, adr p);
void Insert_After(List& L, adr prec, adr p);

void Delete_First(List& L, adr& p);
void Delete_Last(List& L, adr& p);
void Delete_After(List& L, adr prec, adr& p);

void Show(const List& L);

void SortByHaridanWaktu_Insertion(List& L);
int konversiWaktu(string hari, int jamMulai, int menitMulai);
adr SearchByOrder(List& L, int index);
void SortByHaridanWaktu_Selection(List& L);
void Input_New_Data(infotype &data);

#endif
