#include <iostream>
#include "sqlite3.h"
#include <string>

void createDatabase(const std::string& dbPath) {
    sqlite3* db;
    char* errMsg = 0;

    // Öffne die Datenbank (wird erstellt, wenn sie nicht existiert)
    int rc = sqlite3_open(dbPath.c_str(), &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Kann Datenbank nicht öffnen: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // SQL-Befehl zum Erstellen einer Tabelle
    const char* createTableSQL = "CREATE TABLE 'Personen' ('ID'	INTEGER,'Name'	TEXT NOT NULL,'Alter'	INTEGER NOT NULL,PRIMARY KEY('ID' AUTOINCREMENT))";

    // Führe den SQL-Befehl aus
    rc = sqlite3_exec(db, createTableSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL-Fehler: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Tabelle erfolgreich erstellt.\n";
    }

    // SQL-Befehl zum Einfügen von Einträgen
    const char* insertSQL = "INSERT INTO 'Personen' ('Name', 'Alter') VALUES ('Alice', 30);" \
        "INSERT INTO 'Personen' ('Name', 'Alter') VALUES ('Bob', 25);" \
        "INSERT INTO 'Personen' ('Name', 'Alter') VALUES ('Charlie', 35);";

    // Führe den SQL-Befehl aus
    rc = sqlite3_exec(db, insertSQL, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL-Fehler: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Einträge erfolgreich hinzugefügt.\n";
    }

    // Schließe die Datenbankverbindung
    sqlite3_close(db);
}

void queryDatabase(const std::string& dbPath) {
    sqlite3* db;
    char* errMsg = 0;

    // Öffne die Datenbank
    int rc = sqlite3_open(dbPath.c_str(), &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Kann Datenbank nicht öffnen: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // SQL-Befehl zum Abfragen der Daten
    const char* querySQL = "SELECT * FROM Personen;";
    sqlite3_stmt* stmt;

    // Kompiliere den SQL-Befehl
    rc = sqlite3_prepare_v2(db, querySQL, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "Fehler beim Kompilieren des SQL-Befehls: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Durchlaufe die Ergebnisse
    std::cout << "Personen in der Datenbank:\n";
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char* name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);

        std::cout << "ID: " << id << ", Name: " << name << ", Alter: " << age << "\n";
    }

    // Finalisiere das Statement
    sqlite3_finalize(stmt);

    // Schließe die Datenbankverbindung
    sqlite3_close(db);
}

int main() {
    std::string dbPath = "example.db";

    // Erstelle die Datenbank und füge Einträge hinzu
     createDatabase(dbPath);

    // Frage die Datenbank ab
    queryDatabase(dbPath);

    return 0;
}
