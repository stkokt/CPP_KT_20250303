// Aufgabe 1:
/*
Implementiere den Luhn-Algorithmus zur Überprüfung der 
Gültigkeit einer Kreditkartennummer. 
Der Algorithmus funktioniert wie folgt:

Beginne mit der rechten Ziffer und bewege dich nach links. 
Verdopple die Wertigkeit jeder zweiten Ziffer.
Falls das Verdoppeln einer Ziffer zu einer Zahl größer als 9 führt, 
subtrahiere 9 von dieser Zahl.
Addiere alle Ziffern zusammen.
Wenn die Summe durch 10 teilbar ist, ist die Kreditkartennummer gültig.


Beispiel:
Für die Kreditkartennummer 4532 0151 1283 0366:

Verdopple jede zweite Ziffer von rechts: 
4*2, 5, 3*2, 2, 0*2, 1, 5*2, 1, 1*2, 2, 8*2, 3, 0*2, 3, 6*2, 6

Ergebnis: 
8, 5, 6, 2, 0, 1, 10, 1, 2, 2, 16, 3, 0, 3, 12, 6

Subtrahiere 9 von den Zahlen größer als 9: 
8, 5, 6, 2, 0, 1, 1, 1, 2, 2, 7, 3, 0, 3, 3, 6

Summiere alle Ziffern: 
8+5+6+2+0+1+1+1+2+2+7+3+0+3+3+6 = 50

Da 50 durch 10 teilbar ist, ist die Kreditkartennummer gültig.

*/

// Aufgabe 2:
/*
Eine ID soll erstellt werden. Sie soll die Form haben (exemplarisch)

1000-A12-0001-1

Regeln:

Der erste Zahlenblock soll Werte von 1000 - 9999 enthalten.
Wenn der Höchstwert überschritten ist, soll im nächsten Block 
der nächste Buchstabe im Alphabet gewählt werden und der Wert 
des ersten Blocks wieder auf 1000 gesetzt werden.

Die Zahlen im zweiten Block sollen von 01 - 99 gehen. 

Die Zahlen im dritten Block sollen von 0001 - 9999 gehen.
Wenn die 9999 überschritten wird, soll die letzte Ziffer der ID
um eins erhöht werden und der Block resettet werden.

Die letzte Ziffer der ID soll von 0 bis 9 gehen. Wird die 9
überschritten, beginnt die Zählung von vorn.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool luhnAlgorithm(const std::string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    // Iterate over the digits in reverse order
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }

        sum += n;
        alternate = !alternate;
    }

    // If the total modulo 10 is zero, the number is valid
    return (sum % 10 == 0);
}

string ID(){

    static int firstBlock = 9995;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static short letter = 0;
    static int secondBlock = 95;
    static int thirdBlock = 9995;
    static int fourthBlock = 0;

    if (firstBlock > 9999){
        firstBlock = 1000;
        letter++;
    }

    if(secondBlock > 99){
        secondBlock = 1;
    }

    if(thirdBlock > 9999){
        thirdBlock = 1;
        fourthBlock++;
    }

    string fstB = to_string(firstBlock);
    string sndB = secondBlock<10?'0'+to_string(secondBlock):to_string(secondBlock);
    string trdB = "";
    if (thirdBlock < 10){
        trdB = "000"+ to_string(thirdBlock);
    }
    else if(thirdBlock>9 && thirdBlock<100){
        trdB = "00"+ to_string(thirdBlock);
    } 
    else if(thirdBlock>99 && thirdBlock<1000){
        trdB = "0"+ to_string(thirdBlock);
    }
    else trdB = to_string(thirdBlock);

    string fthB = to_string(fourthBlock);

    firstBlock++;
    secondBlock++;
    thirdBlock++;

    return fstB + "-" + abc[letter] + sndB +"-"+ trdB + "-" + fthB;

}

int main(){

    string cardNr = "4532015112830366";
    if(luhnAlgorithm(cardNr)){cout << "Karte gültig" << endl;}
    else cout << "Karte ungültig" << endl;

    for(int i = 0; i < 10; i++){cout << ID() << endl;}
    
    return 0;
}