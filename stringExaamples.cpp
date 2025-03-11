#include <iostream>
#include <string>

using namespace std;

int main(){

    string hello = "Hallo Welt";

    // Finde den Index, an dem das Wort "Welt" beginnt.
    cout << hello.find("Planet") << endl;
    cout << "Größe des Strings: " << hello.size() << endl;
    cout << "Kapazität des Strings: " << hello.capacity() << endl;
    cout << "Speicheradresse: " << &hello << endl;
    
    // Greife lesend auf einen Index des Strings zu.
    cout << hello[9] << endl;
    cout << hello.at(9) << endl;

    // Greife schreibend auf einen Index des Strings zu.
    hello[9] = 'l';
    cout << hello.at(9) << endl;

    // Füge einen Character oder String an den vorhandenen an.
    hello.append("en voraus.");
    cout << hello << endl;

    // Ersetze einen Teil des Strings mit einer neuen Zeichenkette.
    hello.replace(0,5,"Hohe");
    cout << hello << endl;
    cout << "Größe des Strings: " << hello.size() << endl;
    cout << "Kapazität des Strings: " << hello.capacity() << endl;
    cout << "Speicheradresse: " << &hello << endl; 
    hello.shrink_to_fit();
    cout << "Kapazität des Strings: " << hello.capacity() << endl;


    return 0;
}