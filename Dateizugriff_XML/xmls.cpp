#include <iostream>
#include <fstream>
#include <string>

int main() {

    // SCHREIBEN
    
    // Erstelle ein ofstream-Objekt und öffne die Datei im Schreibmodus
    std::ofstream outputFile("data.xml");

    // Überprüfe, ob die Datei erfolgreich geöffnet wurde
    if (outputFile.is_open()) {
        // Schreibe XML-Daten in die Datei
        outputFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        outputFile << "<persons>\n";
        outputFile << "    <person>\n";
        outputFile << "        <name>Alice</name>\n";
        outputFile << "        <age>30</age>\n";
        outputFile << "        <city>Berlin</city>\n";
        outputFile << "    </person>\n";
        outputFile << "    <person>\n";
        outputFile << "        <name>Bob</name>\n";
        outputFile << "        <age>25</age>\n";
        outputFile << "        <city>München</city>\n";
        outputFile << "    </person>\n";
        outputFile << "</persons>\n";

        // Schließe die Datei
        outputFile.close();
    } else {
        std::cerr << "Fehler beim Öffnen der Datei zum Schreiben.\n";
    }



    // LESEN

    // Erstelle ein ifstream-Objekt und öffne die Datei im Lesemodus
    std::ifstream inputFile("data.xml");

    // Überprüfe, ob die Datei erfolgreich geöffnet wurde
    if (inputFile.is_open()) {
        std::string line;

        // Lies die Datei zeilenweise
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }

        // Schließe die Datei
        inputFile.close();
    } else {
        std::cerr << "Fehler beim Öffnen der Datei zum Lesen.\n";
    }
    
    
    return 0;
}
