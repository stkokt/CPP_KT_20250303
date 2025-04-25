#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main(){

    // std::ofstream outputFile("daten.csv");

    // if (outputFile.is_open()){
    //     outputFile << "Name, Alter, Stadt\n";
    //     outputFile << "Alice, 30, Berlin\n";
    //     outputFile << "Bob, 25, München\n";

    //     outputFile.close();
    // }
    // else{
    //     std::cerr << "Fehler beim Öffnen der Datei.\n";
    // }

    std::ofstream outputFile1("daten.csv", std::ios::app);

    if (outputFile1.is_open()){

        outputFile1 << "Maria, 18, Barfußhausen\n";

        outputFile1.close();
    }
    else{
        std::cerr << "Fehler beim Öffnen der Datei.\n";
    }

    std::ifstream inputFile("daten.csv");
    
    if(inputFile.is_open()){

        std::string line;

        while(std::getline(inputFile, line)){
            std::stringstream ss(line);
            std::string field;
            std::vector<std::string> fields;
            while(std::getline(ss, field, ',')){
                fields.push_back(field);
            }

            for(const auto& f : fields){
                std::cout << f << " ";
            }
            std::cout << std::endl;
        }
        inputFile.close();
    }
    else {
        std::cerr << "Fehler beim Öffnen der Datei zum Lesen.\n";
    }

    return 0;
}