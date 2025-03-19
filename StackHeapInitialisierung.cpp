#include <iostream>
#include<vector>

using namespace std;

int main()
{
        // Initialisierung eines Vektors auf dem Heap
        vector<int>* vecptr = new vector<int>{1,2,3,4,5};
        for(const int& n : *vecptr){
            cout << n << "\t";
        }

        cout << endl;
        cout << "Adresse des Pointers: " << &vecptr << endl;
        for(int i = 0; i < vecptr -> size(); i++ )
        {cout << "Adresse des Elements " << i << ": " << &vecptr[i] << endl;}

        // Vector Pointer wird zerstört und der
        // Speicherplatz seiner Elemente freigegeben.
        delete vecptr;

        cout << endl;

        // Initialisierung eines Vektors auf dem Stack

        vector<int> vec2{7,8,9};
        cout << "Speicheradresse des Vektor- Objekts: " << &vec2 << endl;
        for(int i = 0; i<3;i++ )
        {cout << "Speicheradresse des Vektor- Elements: " << i << " " << &vec2[i] << endl;}

        // Wie groß ist der Pointer?
        cout << "Größe des Pointers vecptr: " << sizeof(vecptr) << endl;

        int* zahl = new int(5);

        cout << "Größe des Pointers zahl: " << sizeof(zahl) << endl;
        cout << "Größe eines Integers: " << sizeof(int) << endl;

        cout << "Größe eines Char Pointers: " << sizeof(char*) << endl;
        cout << "Größe eines Chars: " << sizeof(char) << endl;

        // Ergo: Ein Pointer hat auf einem System immer dieselbe Größe
        // unabhängig vom Datentyp, auf den er zeigt.


        delete zahl; // Pointer und Wert von Zahl werden zerstört

        return 0;
        // Vektor auf dem Stack und alle seine Elemente
        // werden beim Verlassen dieses Scopes zerstört.
    }

