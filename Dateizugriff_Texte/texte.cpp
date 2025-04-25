#include <iostream>
#include <fstream>
#include <string>

int main(){

    // std::ofstream outPutFile("beispiel.txt");

    // if(outPutFile.is_open()){

    //     outPutFile << "Hallo Welt. Das ist ein Beispieltext.\n";
    //     outPutFile << "Das ist eine weitere Zeile\n";
    //     outPutFile.close();
    // }
    // else{
    //     std::cerr << "Fehler beim Öffnen der Datei.\n";
    // }

    std::ofstream outPutFile1("beispiel.txt",std::ios::app);

    if (outPutFile1.is_open()){
        outPutFile1 << "Dieser Text wird am Ende hinzugefügt.\n";
        outPutFile1 << "Eine weitere Zeile wird angehängt.\n";
        outPutFile1.close();
    }
    else{
        std::cerr << "Fehler beim Öffnen der Datei.\n";
    }

    std::ifstream inputFile("beispiel.txt");

    if(inputFile.is_open()){
        std::string line;

        while(std::getline(inputFile, line)){
            std::cout << line << std::endl;
        }

        inputFile.close();
    }
    else{
        std::cerr << "Fehler beim Öffnen der Datei.\n";
    }

    return 0;
}