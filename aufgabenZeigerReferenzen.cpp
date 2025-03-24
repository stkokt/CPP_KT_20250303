/*

Aufgabe 1:

    Verknüpfe zwei Integer- Variablen so miteinander,
    dass eine Wertänderung an der einen Variablen auch
    bei der anderen wirksam wird.

Aufgabe 2:

   Erstelle ein Array mit 10 Integer-Werten
   und initialisiere es mit den Zahlen von 1 bis 10.
   Verwende einen Zeiger, um die Werte des Arrays auszugeben.

Aufgabe 3:

   Schreibe ein Programm, das zwei Integer-Arrays
   mit jeweils 5 Elementen enthält. Verwende Zeigerarithmetik,
   um die Summe der Elemente beider Arrays zu berechnen und auszugeben.

Aufgabe 4:

   Erstelle ein Programm, das ein Array von 5 Integer-Werten
   enthält. Verwende einen Zeiger auf einen Zeiger, um auf die
   Elemente des Arrays zuzugreifen und diese zu ändern.

Aufgabe 5:

   Schreibe ein Programm, das ein dynamisches Array von
   Integer-Werten erstellt. Der Benutzer soll die Größe
   des Arrays und die Werte eingeben können. Verwende Zeiger,
   um die Werte des Arrays auszugeben.

Aufgabe 6:

   Schreibe ein Programm, das einen dynamischen Vektor von
   Integer-Werten erstellt. Der Benutzer soll die Größe des Vektors
   und die Werte eingeben können. Verwende Zeiger, um die Werte
   des Vektors auszugeben.

Aufgabe 7:

   Erstelle eine Map, die Schlüssel-Wert-Paare von Integern enthält.
   Verwende Zeiger, um auf die Werte der Map zuzugreifen und diese auszugeben.

Aufgabe 8:

   Schreibe ein Programm, das eine Map von Integer-Schlüsseln und String-Werten
   enthält. Verwende Zeiger, um die Werte der Map zu ändern und die geänderten
   Werte auszugeben.

Aufgabe 9:

    Schreibe ein Programm, das eine dynamische Map von Integer-Schlüsseln
    und String-Werten erstellt. Der Benutzer soll die Anzahl der
    Elemente und die Schlüssel-Wert-Paare eingeben können.
    Verwende Zeiger, um die Werte der Map auszugeben.

Aufgabe 10: Zeiger auf Arrays und Zeiger auf Zeiger

    10.1. Erstelle drei dynamische Arrays von Integern,
    jedes mit 5 Elementen.

    10.2. Erstelle ein Array von Zeigern, das auf die ersten Elemente
    der drei dynamischen Arrays zeigt.

    10.3. Erstelle einen Zeiger, der auf das Array von Zeigern zeigt.

    10.4. Verwende eine Schleife, um über das Array von Zeigern zu
    iterieren und die Elemente der dynamischen Arrays auszugeben.
    Verwende dabei den Zeiger auf das Array von Zeigern.

    10.5. Gebe anschließend den Heapspeicher wieder frei.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    /*
     Das Schlüsselwort 'const':

     Absicherung gegen versehentliches Ändern.
     Sollte bei Lesevorgängen immer benutzt werden!

     Bezieht sich auf den Ausdruck, der links davon steht,
     es sei denn, links davon steht nichts mehr.
     Dann bezieht es sich auf den Ausdruck rechts davon.

     */

    int a = 10;
    int b = 11;

    int const * ptr1 = &a;
    //*ptr1 += 10; // Funktioniert nicht, weil Wert(!) konstant
    ptr1 = &b;  // Zeiger umhängen möglich

    int * const ptr2 = &a; // Wertänderung möglich
    *ptr2 += 10; // Wertänderung möglich
    //ptr2 = &b; // Funktioniert nicht, weil Zeiger konstant

    int const * const ptr3 = &a;
    // Nur Ausgabe möglich, Wert und Pointer hierüber unveränderbar

    const int* const ptr4 = &a;
    // Selbe Funktionalität wie ptr3, nur andere Schreibweise


    {   // Aufgabe 1
        cout<< "\nAufgabe 1" << endl;

        int a = 10;
        int& b = a;
        cout << a << ", " << b <<endl;
        b = 11;
        cout << a << ", " << b <<endl;
    }

    {   // Aufgabe 2
        cout<< "\nAufgabe 2" << endl;

        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int* ptr = arr;

        for (int i = 0; i < 10; ++i) {
            std::cout << *(ptr + i) << " ";
        }
    }

    {   // Aufgabe 3
        cout<< "\nAufgabe 3" << endl;

        int arr1[5] = {1, 2, 3, 4, 5};
        int arr2[5] = {6, 7, 8, 9, 10};
        int* ptr1 = arr1;
        int* ptr2 = arr2;
        int sum = 0;

        for (int i = 0; i < 5; ++i) {
            sum += *(ptr1 + i) + *(ptr2 + i);
        }

        std::cout << "Summe: " << sum << std::endl;
    }

    {   // Aufgabe 4
        cout<< "\nAufgabe 4" << endl;

        int arr[5] = {1, 2, 3, 4, 5};
        int* ptr = arr;
        int** ptr_to_ptr = &ptr;

        for (int i = 0; i < 5; ++i) {
            **ptr_to_ptr += 10;
            ptr++;
        }

        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << " ";
        }
    }

    {   // Aufgabe 5
        cout<< "\nAufgabe 5" << endl;

        int size;
        std::cout << "Größe des Arrays eingeben: ";
        std::cin >> size;

        int* arr = new int[size];
        int* ptr = arr;

        std::cout << "Werte eingeben:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> *(ptr + i);
        }

        std::cout << "Eingegebene Werte:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << *(ptr + i) << " ";
        }

        delete[] arr;
    }

    {   // Aufgabe 6
        cout<< "\nAufgabe 6" << endl;

        int size;
        std::cout << "Größe des Vektors eingeben: ";
        std::cin >> size;

        std::vector<int> vec(size);
        int* ptr = vec.data();

        std::cout << "Werte eingeben:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> *(ptr + i);
        }

        std::cout << "Eingegebene Werte:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << *(ptr + i) << " ";
        }
    }

    {   // Aufgabe 7
        cout<< "\nAufgabe 7" << endl;

        std::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

        for (auto& pair : myMap) {
            int* valuePtr = &pair.second;
            std::cout << pair.first << ": " << *valuePtr << std::endl;
        }
    }

    {   // Aufgabe 8
        cout<< "\nAufgabe 8" << endl;

        std::map<int, std::string> myMap = {{1, "Eins"}, {2, "Zwei"}, {3, "Drei"}};

        for (auto& pair : myMap) {
            std::string* valuePtr = &pair.second;
            *valuePtr += " geändert";
        }

        for (const auto& pair : myMap) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    {   // Aufgabe 9
        cout<< "\nAufgabe 9" << endl;

        int size;
        std::cout << "Anzahl der Elemente eingeben: ";
        std::cin >> size;

        std::map<int, std::string> myMap;

        for (int i = 0; i < size; ++i) {
            int key;
            std::string value;
            std::cout << "Schlüssel eingeben: ";
            std::cin >> key;
            std::cout << "Wert eingeben: ";
            std::cin >> value;
            myMap[key] = value;
        }

        for (const auto& pair : myMap) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    {   // Aufgabe 10
        cout<< "\nAufgabe 10" << endl;

        int* arr1 = new int[5]{1,2,3,4,5};
        int* arr2 = new int[5]{6,7,8,9,10};
        int* arr3 = new int[5]{11,12,13,14,15};
        int* arrPtr[3] = {arr1, arr2, arr3};
        int** ptrPtr = arrPtr;

        for (int* ptr : arrPtr){
            for (int i = 0; i < 5; i++){
                cout << *(ptr + i) << " ";
            }
            cout << endl;
        }

        // Über das Array von Zeigern auf die Elemente der Arrays zugreifen
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                //cout << ptrPtr[i][j] << " ";
                cout << *(*(ptrPtr + i) + j) << " ";
            }
            cout << endl;
        }

        // Speicher freigeben
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    return 0;
}
