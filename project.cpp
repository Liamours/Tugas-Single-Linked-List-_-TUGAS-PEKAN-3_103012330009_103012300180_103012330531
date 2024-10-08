#include "project.h"
#include <iostream>

void Create_List(List& L) {
    L.First = nullptr;
}

adr New_Elemen(infotype data) {
    adr p = new elmList;
    if (p != nullptr) {
        p->info = data;
        p->next = nullptr;
    }
    return p;
}

void Insert_First(List& L, adr p) {
    if (L.First == nullptr) {
        L.First = p;
    } else {
        p->next = L.First;
        L.First = p;
    }
}

void Insert_Last(List& L, adr p) {
    if (L.First == nullptr) {
        L.First = p;
    } else {
        adr q = L.First;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void Insert_After(List& L, adr prec, adr p) {
    if (prec != nullptr && p != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void Delete_First(List& L, adr& p) {
    if (L.First != nullptr) {
        p = L.First;
        L.First = L.First->next;
        p->next = nullptr;
    }
}

void Delete_Last(List& L, adr& p) {
    if (L.First != nullptr) {
        if (L.First->next == nullptr) {
            p = L.First;
            L.First = nullptr;
        } else {
            adr q = L.First;
            while (q->next->next != nullptr) {
                q = q->next;
            }
            p = q->next;
            q->next = nullptr;
        }
    }
}

void Delete_After(List& L, adr prec, adr& p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void Show(const List& L) {
    adr p = L.First;
    cout << endl;
    while (p != nullptr) {
        cout << "Kegiatan: " << p->info.kegiatan << ", "
             << "Hari: " << p->info.hari << ", "
             << "Waktu Mulai: " << p->info.jamMulai << p->info.menitMulai << ", "
             << "Waktu Selesai: " << p->info.jamAkhir << p->info.menitAkhir << endl;
        p = p->next;
    }
    cout << endl;
}

void SortByHaridanWaktu_Insertion(List& L) {
    if (L.First == nullptr) {
        cout << "list kosong" << endl;
        return;
    }

    adr SL = nullptr;
    adr p = L.First;

    while (p != nullptr) {
        adr r = p->next;

        if (SL == nullptr || konversiWaktu(SL->info.hari, SL->info.jamMulai, SL->info.menitMulai) >=
                             konversiWaktu(p->info.hari, p->info.jamMulai, p->info.menitMulai)) {
            p->next = SL;
            SL = p;
        } else {
            adr q = SL;
            while (q->next != nullptr && konversiWaktu(q->next->info.hari, q->next->info.jamMulai, q->next->info.menitMulai) <
                                        konversiWaktu(p->info.hari, p->info.jamMulai, p->info.menitMulai)) {
                q = q->next;
            }
            p->next = q->next;
            q->next = p;
        }
        p = r;
    }

    L.First = SL;
}

void SortByHaridanWaktu_Selection(List& L) {
    if (L.First == nullptr) {
        cout << "list kosong" << endl;
        return;
    }

    adr p = L.First;
    adr prevP = nullptr;

    while (p != nullptr) {
        adr min = p;
        adr prevMin = nullptr;
        adr q = p->next;
        adr prevQ = p;

        while (q != nullptr) {
            if (konversiWaktu(q->info.hari, q->info.jamMulai, q->info.menitMulai) < konversiWaktu(min->info.hari, min->info.jamMulai, min->info.menitMulai)) {
                min = q;
                prevMin = prevQ;
            }
            prevQ = q;
            q = q->next;
        }

        if (min != p) {
            if (prevMin != nullptr) {
                prevMin->next = min->next;
            }
            if (prevP != nullptr) {
                prevP->next = min;
            } else {
                L.First = min;
            }
            min->next = p->next;
            prevP = min;
        } else {
            prevP = p;
        }

        p = min->next;
    }
}

adr SearchByOrder(List& L, int index) {
    adr p;
    int i;

    p = L.First;

    if (index == 1) {
        return p;
    } else {
        for (i=1; i<=index; i++) {
            p = p->next;
        }
    }

    return p;
}

int konversiWaktu(string hari, int jamMulai, int menitMulai) {
	int hari_angka, total_waktu;

    if (hari == "Senin") {
        hari_angka = 1;
    } else if (hari == "Selasa") {
        hari_angka = 2;
    } else if (hari == "Rabu") {
        hari_angka = 3;
    } else if (hari == "Kamis") {
        hari_angka = 4;
    } else if (hari == "Jumat") {
        hari_angka = 5;
    } else if (hari == "Sabtu") {
        hari_angka = 6;
    } else if (hari == "Minggu") {
        hari_angka = 7;
    } else {
        cout << "Hari tidak valid" << endl;
        return -1;
    }

    total_waktu = hari_angka * 24 * 60 + jamMulai * 60 + menitMulai;

    return total_waktu;
}

void Input_New_Data(infotype &data) {
    cout << "Input kegiatan: ";
    cin >> data.kegiatan;
    cout << "Input hari: ";
    cin >> data.hari;
    cout << "Input jam mulai: ";
    cin >> data.jamMulai;
    cout << "Input menit mulai: ";
    cin >> data.menitMulai;
    cout << "Input jam akhir: ";
    cin >> data.jamAkhir;
    cout << "Input menit akhir: ";
    cin >> data.menitAkhir;
}
