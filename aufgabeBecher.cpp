#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

struct Becher {
    int volume = 0;
    bool full = false;
};

struct Person {
    string name = "";
    Becher becher;
    bool thirsty = true; // Anfangs sind alle durstig
};

std::random_device rd;  // Zufällige Startwerte für den Generator
std::mt19937 gen(rd()); // Mersenne-Twister-Generator
std::uniform_int_distribution<> dis(0, 4);

void setVolume(Becher& b) {
    int volumina[]{100, 250, 500, 750, 1000};
    int zahl = dis(gen); // Verwenden Sie den Generator, der außerhalb initialisiert wurde
    b.volume = volumina[zahl];
}

int main() {
    int krug = 5000;

    string namen[] = {"Anna", "Tom", "Baldur", "Erna", "Guido", "Elfriede", "Wilma", "Räuber Hotzenplotz", "Pippi Langstrumpf", "Batman"};
    vector<Becher> vecBecher(10);
    vector<Person> vecPersonen(10);

    // Bechergrößen zufällig zuweisen
    for (auto& becher : vecBecher) {
        setVolume(becher);
    }

    // Becher und Namen den Personen zuweisen
    for (int i = 0; i < 10; i++) {
        vecPersonen[i].name = namen[i];
        vecPersonen[i].becher = vecBecher[i];
    }

    // Becher füllen, bis der Krug leer ist
    for (auto& person : vecPersonen) {
        if (krug >= person.becher.volume) {
            krug -= person.becher.volume;
            person.becher.full = true;
            person.thirsty = false; // Nicht mehr durstig, wenn der Becher voll ist
        }
    }

    // Ausgabe der Bechergrößen und Durst-Status
    for (const auto& person : vecPersonen) {
        cout << "Name: " << person.name
             << ", Bechergröße: " << person.becher.volume
             << ", Durstig: " << (person.thirsty ? "Ja" : "Nein") << '\n';
    }

    cout << krug << endl;

    return 0;
}
