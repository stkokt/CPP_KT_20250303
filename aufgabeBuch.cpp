#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Autor {
    std::string name;
    int geburtsjahr;

    Autor(const std::string& name, int geburtsjahr)
        : name(name), geburtsjahr(geburtsjahr) {}
};

struct Buch {
    std::string titel;
    int erscheinungsjahr;
    Autor autor;

    Buch(const std::string& titel, int erscheinungsjahr, const Autor& autor)
        : titel(titel), erscheinungsjahr(erscheinungsjahr), autor(autor) {}
};

void katalogAusgeben(const std::vector<Buch>& katalog) {
    for (const auto& buch : katalog) {
        std::cout << "Titel: " << buch.titel
                  << ", Erscheinungsjahr: " << buch.erscheinungsjahr
                  << ", Autor: " << buch.autor.name
                  << ", Geburtsjahr: " << buch.autor.geburtsjahr << '\n';
    }
}

void buchHinzufuegen(std::vector<Buch>& katalog, const Buch& buch) {
    katalog.push_back(buch);
}

void buecherVonAutorAusgeben(const std::vector<Buch>& katalog, const std::string& autorName) {
    for (const auto& buch : katalog) {
        if (buch.autor.name == autorName) {
            std::cout << "Titel: " << buch.titel
                      << ", Erscheinungsjahr: " << buch.erscheinungsjahr << '\n';
        }
    }
}

void aeltestesBuchFinden(const std::vector<Buch>& katalog) {
    int aeltestesJahr = std::numeric_limits<int>::max();
    Buch aeltestesBuch = katalog[0];

    for (const auto& buch : katalog) {
        if (buch.erscheinungsjahr < aeltestesJahr) {
            aeltestesJahr = buch.erscheinungsjahr;
            aeltestesBuch = buch;
        }
    }

    std::cout << "Ältestes Buch: " << aeltestesBuch.titel
              << ", Erscheinungsjahr: " << aeltestesBuch.erscheinungsjahr
              << ", Autor: " << aeltestesBuch.autor.name << '\n';
}

int main() {
    std::vector<Buch> katalog = {
        Buch("1984", 1949, Autor("George Orwell", 1903)),
        Buch("To Kill a Mockingbird", 1960, Autor("Harper Lee", 1926)),
        Buch("The Great Gatsby", 1925, Autor("F. Scott Fitzgerald", 1896))
    };

    std::cout << "Bibliothekskatalog:\n";
    katalogAusgeben(katalog);

    std::cout << "\nNeues Buch hinzufügen:\n";
    buchHinzufuegen(katalog, Buch("Moby-Dick", 1851, Autor("Herman Melville", 1819)));
    katalogAusgeben(katalog);

    std::cout << "\nBücher von George Orwell:\n";
    buecherVonAutorAusgeben(katalog, "George Orwell");

    std::cout << "\nÄltestes Buch im Katalog:\n";
    aeltestesBuchFinden(katalog);

    return 0;
}
