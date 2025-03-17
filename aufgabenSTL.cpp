#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <string>

int main() {

    /*
    Aufgabe 1: 

    Erstelle einen STL Container, der die Namen von fünf Personen enthält. 
    {"Alice", "Bob", "Charlie", "David", "Eve"}
    Füge dann eine neue Person am Anfang und am Ende hinzu. 
    Entferne schließlich die dritte Person.

    */
   {
    // Hier ist wegen push_back und push_front 
    // z.B. eine Liste ein geeigneter STL Container
    std::list<std::string> personen = {"Alice", "Bob", "Charlie", "David", "Eve"};

    // Neue Person am Anfang hinzufügen
    personen.push_front("Frank");

    // Neue Person am Ende hinzufügen
    personen.push_back("Grace");

    // Dritte Person entfernen
    auto it = personen.begin();
    std::advance(it, 2);    // oder it += 2
    personen.erase(it);

    // Liste ausgeben
    for (const auto& personName : personen) {
        std::cout << personName << " ";
    }
    std::cout << std::endl;
   }

   /*
   Aufgabe 2: 

    Erstelle einen STL Container, der die Namen von fünf Ländern enthält.
    {"Deutschland", "Frankreich", "Italien", "Spanien", "Portugal"} 
    Füge dann drei weitere Länder hinzu und entferne ein Land. 
    Gib schließlich alle Länder in alphabetischer Reihenfolge aus.
   */
   {

    // Hier bietet sich ein (geordnetes) Set an,
    // eben wegen des Sich- Selbst- Sortierens
    std::set<std::string> countries = {"Germany", "France", "Italy", "Spain", "Portugal"};

    // Drei weitere Länder hinzufügen
    countries.insert("Sweden");
    countries.insert("Norway");
    countries.insert("Denmark");

    // Ein Land entfernen
    countries.erase("France"); // einfacher Zugriff über den (Hash-)Wert

    // Länder in alphabetischer Reihenfolge ausgeben
    for (const auto& country : countries) {
        std::cout << country << " ";
    }
    std::cout << std::endl;
   }

   /*
   Aufgabe 3: 

    Erstelle einen STL Container, der die Namen von fünf Personen und ihre Alter enthält. 
    Füge dann zwei weitere Personen hinzu und ändere das Alter einer bestehenden Person. 
    Gib schließlich alle Namen und Alter aus.
   */

   {
    // Hier sollte eine Map zum Einsatz kommen, aber auch ein Vektor
    // von Tupelen wäre möglich.
    std::map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}, {"David", 28}, {"Eve", 22}};
    
    // Exemplarisch ein Tupel 
    // (man könnte eben auch einen Vektor von Tupelen nutzen,
    //  aber der Zugriff ist schwieriger)
    std::tuple<std::string, int> tpl{"Alice",30};
    std::cout << "Name: " << std::get<0>(tpl) << std::endl;
    std::cout << "Alter: " << std::get<1>(tpl) << std::endl;

    // Zwei weitere Personen hinzufügen
    ages["Frank"] = 40;
    ages["Grace"] = 32;

    // Alter einer bestehenden Person ändern
    ages["Bob"] = 26;

    // Alle Namen und Alter ausgeben
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << " Jahre" << std::endl;
    }

   }

   /*
   Aufgabe 4: 

    Erstelle einen STL Container, der die Zahlen von 1 bis 5 enthält. 
    Füge dann die Zahlen 0 am Anfang und 6 am Ende hinzu. 
    Entferne schließlich die Zahl 3.
   */

   {
    // Hier mit einer Deque implemtiert, 
    // aber wäre auch eine Liste möglich.
    std::deque<int> numbers = {1, 2, 3, 4, 5};

    // Zahl 0 am Anfang hinzufügen
    numbers.push_front(0);

    // Zahl 6 am Ende hinzufügen
    numbers.push_back(6);

    // Zahl 3 entfernen
    auto it = std::find(numbers.begin(), numbers.end(), 3);
    if (it != numbers.end()) {
        numbers.erase(it);
    }

    // Deque ausgeben
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

   }

    return 0;
}
