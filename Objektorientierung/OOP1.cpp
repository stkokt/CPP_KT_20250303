// Aufgabe
/*
Einfaches Rollenspiel

Erstelle folgende Klassen:

Spieler:
    private Attribute:
    - name (string)
    - health (int)
    - mana (int)

    öffentliche Methode:
    - überladener Konstruktor (private Attribute werden übergeben)
    - anzeigen (void): Ausgabe der privaten Attribute

NPC (als Freundklasse für Spieler):
    öffentliche Methoden:
    - heilung
        - Argumente: Spieler (Objekt), Menge(int) 
        - soll die health- Punkte des Spielers erhöhen
    - schaden
        - Argumente: Spieler (Objekt), Menge(int)
        - soll die health- Punkte des Spielers minimieren
    - zauber
        - Argumente: Spieler (Objekt), Menge(int)
        - soll die mana- Punkte des Spielers erhöhen

    Alle drei Methoden sollen den jeweils
    neuen Punktestand anzeigen.

*/
#include <iostream>
#include <string>
using namespace std;

class Spieler {
private:
    string name;
    int health;
    int mana;

public:
    Spieler(string playerName, int initialHealth, int initialMana)
        : name(playerName), health(initialHealth), mana(initialMana) {}

    void anzeigen() const {
        cout << "Spieler " << name << " - Gesundheit: " << health << ", Mana: " << mana << endl;
    }

    // Vergleichsoperatoren
    bool operator==(const Spieler& other) const {
        return (health == other.health && mana == other.mana);
    }

    bool operator!=(const Spieler& other) const {
        return !(*this == other);
    }

    bool operator<(const Spieler& other) const {
        return (health < other.health) || (health == other.health && mana < other.mana);
    }

    bool operator>(const Spieler& other) const {
        return (health > other.health) || (health == other.health && mana > other.mana);
    }

    bool operator<=(const Spieler& other) const {
        return !(*this > other);
    }

    bool operator>=(const Spieler& other) const {
        return !(*this < other);
    }

    // Arithmetische Operatoren
    Spieler operator+(const Spieler& other) const {
        return Spieler(name, health + other.health, mana + other.mana);
    }

    // Freund-Klasse
    friend class NPC;
};

class NPC {
public:
    void heilung(Spieler& player, int amount) {
        player.health += amount;
        cout << "NPC heilt Spieler. Neue Gesundheit: " << player.health << endl;
    }

    void schaden(Spieler& player, int amount) {
        player.health -= amount;
        cout << "NPC schädigt Spieler. New Gesundheit: " << player.health << endl;
    }

    void zauber(Spieler& player, int amount) {
        player.mana += amount;
        cout << "NPC erhöht Spielerzauber. Neuer Zauber: " << player.mana << endl;
    }
};

int main() {
    Spieler player1("Max", 100, 50);
    Spieler player2("Moritz", 80, 60);
    NPC npc;

    npc.heilung(player2, 20);
    npc.zauber(player1, 10);

    player1.anzeigen();
    player2.anzeigen();

    // Vergleichsoperatoren
    if (player1 == player2) {
        cout << "Spieler sind gleich." << endl;
    } else {
        cout << "Spieler sind nicht gleich." << endl;
    }

    if (player1 > player2) {
        cout << "Spieler 1 ist stärker als Spieler 2." << endl;
    } else {
        cout << "Spieler 1 ist nicht stärker als Spieler 2." << endl;
    }

    // Arithmetische Operatoren
    Spieler Kampftruppe = player1 + player2;
    Kampftruppe.anzeigen();


    return 0;
}
