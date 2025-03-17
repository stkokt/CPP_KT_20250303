/*
1. Initialisiere einen Vektor mit den Elementen {2,5,4,3,1,7,9,6,8,0}. 
   Durchlaufe ihn einmal ganz, einmal ab der Mitte, 
   einmal bis zur Mitte und einmal rückwärts.
   Bestimme die Summe der Elemente und gebe sie aus.
   Suche nach einem Element im Vector. Gebe den Index des Elements aus.
   Sortiere den Vector.

2. Mache dasselbe wie in Aufgabe 1 mit einem C- Array.

3. Schreibe einen Algorithmus für einen Wortzähler. 
   Text zum Testen (36 Worte):
   "Lorem ipsum dolor sit amet, consectetur adipiscing elit.
    Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
    Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris
    nisi ut aliquip ex ea commodo consequat."

4. Schreibe einen Algorithmus, der nach allen Anfangspositionen 
   eines bestimmten Wortes sucht, das in einem Text mehrfach 
   vorkommt.
   Text zum Testen ('dolor': 12, 63):
   "Lorem ipsum dolor sit amet, consectetur adipiscing elit.
    Ipsum dolor sit amet, consectetur adipiscing elit.
    Dolor sit amet, consectetur adipiscing elit."

   Schreibe den Algorithmus nun so, dass das Wort unabhängig von
   Groß- und Kleinschreibweise gefunden wird.
   (dolor/ Dolor : 12, 63, 108)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int main(){
    {
    vector<int> vec{2,5,4,3,1,7,9,6,8,0};

    // Ausgabe des gesamten Vektors:
    // Variante 1: range-based Loop
    for(int zahl:vec){
        cout << zahl << " ";
    }

    cout << endl;
    // Variante 2: Über Iteratoren
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }

    cout << endl;
    // Variante 3: Über Indizes
    for(int i = 0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    
    cout << endl;

    // Ausgabe des Vektors bis Mitte:
    for(auto it = vec.begin(); it != vec.end()-(vec.size()/2); it++){
        cout << *it << " ";
    }

    cout << endl;

    // Alternativ über Indizes:
    for(int i = 0; i<(vec.size()/2); i++){
        cout << vec[i] << " ";
    }    

    cout << endl;

    // Ausgabe des Vektors ab Mitte:
    for(auto it = vec.begin()+(vec.size()/2); it != vec.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    // Alternativ über Indizes:
    for(int i = (vec.size()/2); i<(vec.size()); i++){
        cout << vec[i] << " ";
    }    

    cout << endl;

    // Ausgabe des Vektors rückwärts:
    for(auto it = vec.rbegin(); it != vec.rend(); it++){
        cout << *it << " ";
    }

    // Summe der Elemente:
    cout << endl;

    int sum = 0;
    for(auto it = vec.begin(); it != vec.end(); it++){
        sum += *it;
    }
    cout << sum << endl;

    // Suche nach Element:

    short idx = 0;
    int target = 9;
    for(auto it = vec.begin(); it != vec.end(); it++){
        if(*it != target){
            idx+=1;
        }
        else{
            break;
        }
    }
    cout << "Element gefunden an Index: " << idx << endl;

    // Elemente sortieren:
    std::sort(vec.begin(), vec.end());

    std::cout << "Sortierte Zahlen: ";
    for (int number : vec) {
        std::cout << number << " ";
    }

    }

    {

    cout<<endl;

    int arr[]{2,5,4,3,1,7,9,6,8,0};
    
    // Ausgabe des gesamten Arrays:
    for(int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << " ";
    }

    cout<<endl;

    // Ausgabe des Arrays ab Mitte:
    for(int i = (sizeof(arr)/sizeof(arr[0])/2);i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << " ";
    }

    cout<<endl;

    // Ausgabe des Arrays bis Mitte:
    for(int i = 0;i<(sizeof(arr)/sizeof(arr[0])/2);i++){
        cout << arr[i] << " ";
    }

    cout<<endl;

    // Ausgabe des Arrays rückwärts:
    for(int i = (sizeof(arr)/sizeof(arr[0]))-1; i>=0; i--){
        cout << arr[i] << " ";
    }

    // Summe der Elemente:
    cout << endl;

    int sum = 0;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        sum += arr[i];
    }
    cout << sum << endl;

    // Suche nach Element:

    int target = 9;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        if(arr[i] == target){
            cout << "Element gefunden an Index: " << i << endl;
        }

    }

    // Das Array sortieren
    sort(arr, arr + sizeof(arr)/sizeof(arr[0]));

    // Das sortierte Array ausgeben
    std::cout << "Sortiertes Array: ";
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    }

    {
    string sampleText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ipsum dolor sit amet, consectetur adipiscing elit. Dolor sit amet, consectetur adipiscing elit.";

    string searchWord = "dolor";
    string tmpWord = "";
    vector<string> words = {};
    size_t pos = 0;
    vector<size_t> positions = {};

    for(int i = 0; i < sampleText.length(); i++) {
        if(sampleText[i] != ' ' && sampleText[i] != '.') {
            tmpWord += sampleText[i];
        } 
        else {
            if (!tmpWord.empty()) {
                words.push_back(tmpWord);
                tmpWord = "";
            }
        }
    }

    // Füge das letzte Wort hinzu, falls es nicht leer ist
    if (!tmpWord.empty()) {
        words.push_back(tmpWord);
    }

    // Ausgabe der Wörter
    for(const string& word : words) {
        cout << word << endl;
    }

    cout << words.size() << endl;
    }

    {
        string sampleText = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ipsum dolor sit amet, consectetur adipiscing elit. Dolor sit amet, consectetur adipiscing elit.";
        stringstream ss(sampleText);
        string word;
        int wordCount = 0;
    
        // Durchlaufe den Stringstream und zähle die Wörter
        while (ss >> word) {
            ++wordCount;
        }
    
        cout << "Anzahl der Wörter: " << wordCount << endl;
    }
}