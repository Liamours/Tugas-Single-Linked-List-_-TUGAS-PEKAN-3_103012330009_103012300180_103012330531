#include <iostream>
#include "project.h"

int main() {
    List Raa;
    infotype newData;
    adr P, P1, P2, P3, P4, P5, P6;

    Create_List(Raa);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT tanpa input" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    Input_New_Data(newData);
    P1 = New_Elemen(newData);
    Insert_First(Raa, P1);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P1" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    Input_New_Data(newData);
    P2 = New_Elemen(newData);
    Insert_Last(Raa, P2);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P2" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    Input_New_Data(newData);
    P3 = New_Elemen(newData);
    Insert_First(Raa, P3);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P3" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    Input_New_Data(newData);
    P4 = New_Elemen(newData);
    Insert_Last(Raa, P4);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P4" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;

    Input_New_Data(newData);
    P5 = New_Elemen(newData);
    Insert_After(Raa, P4, P5);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P5" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    Input_New_Data(newData);
    P6 = New_Elemen(newData);
    Insert_After(Raa, P5, P6);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah input P6" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    P = SearchByOrder(Raa, 1);
    Delete_After(Raa, P, P2);

    P = SearchByOrder(Raa, 5);
    if (P6->info.hari == "Senin") {
        Delete_After(Raa, P5, P6);
    }

    SortByHaridanWaktu_Selection(Raa);

    cout << endl;
    cout << "=========================" << endl;
    cout << "INI OUTPUT setelah delete dan sort" << endl;
    cout << "=========================" << endl;
    Show(Raa);
    cout << "=========================" << endl;
    cout << endl;

    return 0;
}
