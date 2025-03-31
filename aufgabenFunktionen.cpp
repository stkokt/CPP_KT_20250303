#include <iostream>
#include <string>
#include <vector>

// Aufgabe 1: Schreibe eine Funktion, die in einem String die Vokale zählt.

int cntVokale(std::string str) {
    int count = 0;
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// Alternativaufgabe zu 1: Schreibe eine Funktion, die zwei Wertepaare als 
// Argumente übernimmt (<x1,y1>, <x2,y2>). Diese Wertepaare sind Koordinaten
// von Punkten auf einer Geraden im Koordinatensystem. Errechne den Y- Achsenabschnitt.

float ycross(std::pair<float, float>p1, std::pair<float, float>p2){

    float ycross = 0;
    // Grundformel: f(x) = mx + n, also Anstieg * x-Wert + Y- Achsenabschnitt
    // m wird berechnet durch das Delta (y2 - y1)/ (x2 - x1)
    
    float m = 0;
    m = (p2.second - p1.second)/(p2.first - p1.first);

    // Die Formel wird umgestellt, um n zu berechnen:
    // n = f(x) - mx
    // Man nimmt nun einen der beiden Punkte und setzt
    // ihn bei x und f(x) ein.
    
    float n = p1.second - m * p1.first;

    ycross = n;

    // Kompakte Schreibweise:
    // return p1.second - ((p2.second - p1.second)/(p2.first - p1.first)) * p1.first;

    return ycross;
}

// Aufgabe 2: Implementiere den Bubble- Sort Algorithmus.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Aufgabe 3: Implementiere eine Binärsuche.
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element nicht gefunden
}

// Aufgabe 4: Schreibe eine Funktion mit Rückgabetyp bool, 
//            die als Argument einen Vektor von Floats übernimmt.
//            Von diesen Werten soll das Reziproke gebildet werden (z.B. 8 -> 1/8)
//            Ist der Wert 0, soll er übersprungen werden und die Rückgabe auf 
//            'False' wechseln.

bool reziproke(std::vector<float>& vec){
    bool all_done = true;
    for (auto it = vec.begin(); it != vec.end(); it++){
        if (*it > 0){
            *it = double(1)/(*it);
        }
        else{
            all_done = false;
            continue;
        }
    }

    return all_done;
};


// Aufgabe 5: Implementiere eine Matrixmultiplikation, die als Argumente zwei
//            zweidimensionale Vektoren übernimmt.


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int rows1 = mat1.size();
    int cols1 = mat1[0].size();
    int rows2 = mat2.size();
    int cols2 = mat2[0].size();

    // Überprüfen, ob die Matrizen multipliziert werden können
    if (cols1 != rows2) {
        throw std::invalid_argument("Die Anzahl der Spalten der ersten Matrix muss gleich der Anzahl der Zeilen der zweiten Matrix sein.");
    }

    // Ergebnismatrix initialisieren
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

//    |1 2 3|  *  |9 8 7|  =  |(1*9 + 2*6 + 3*3) (1*8 + 2*5 + 3*2) (1*7 + 2*4 + 3*1)|
//    |4 5 6|     |6 5 4|     |(4*9 + 5*6 + 6*3) (4*8 + 5*5 + 6*2) (4*7 + 5*4 + 6*1)|
//    |7 8 9|     |3 2 1|     |(7*9 + 8*6 + 9*3) (7*8 + 8*5 + 9*2) (7*7 + 8*4 + 9*1)|

//                                              | 30  24 18|
//                                              | 84  69 54|
//                                              |138 114 90|


    // Matrixmultiplikation durchführen
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
                std::cout << mat1[i][k] << " * " << mat2[k][j] << std::endl;
            }
            std::cout << std::endl;
        }
    }

    return result;
}

int main() {

    // Aufgabe 1
    std::cout << "Aufgabe 1" << std::endl;

    std::string str = "Hello World";
    std::cout << "Anzahl der Vokale: " << cntVokale(str) << std::endl;

    std::cout << std::endl;

    // Alternativaufgabe 1
    std::cout << "Alternativaufgabe 1" << std::endl;

    std::cout << ycross(std::make_pair(0.0,1.0), std::make_pair(1.0,2.0)) << std::endl;

    std::cout << std::endl;

    // Aufgabe 2
    std::cout << "Aufgabe 2" << std::endl;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    // Aufgabe 3
    std::cout << "Aufgabe 3" << std::endl;
    int arr1[] = {2, 3, 4, 10, 40};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int target = 10;
    int result = binarySearch(arr1, n1, target);
    if (result != -1) {
        std::cout << "Element gefunden an Index " << result << std::endl;
    } else {
        std::cout << "Element nicht gefunden" << std::endl;
    }

    std::cout << std::endl;

    // Aufgabe 4:
    std::cout << "Aufgabe 4" << std::endl;    
    std::vector<float> rezip = {1,2,5,8,6,0,4,7};
    std::vector<float> rezip1 = {1,2,5,8,6,9,4,7};   
    bool result_reziproke = reziproke(rezip);
    bool result_reziproke1 = reziproke(rezip1);

    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke?"Ja":"Nein") << std::endl;    

    for (auto element : rezip){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "Alle Elemente konnten reziproken Wert bilden: " << (result_reziproke1?"Ja":"Nein") << std::endl;    

    for (auto element : rezip1){
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Aufgabe 5
    std::cout << "Aufgabe 5" << std::endl;
    std::vector<std::vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> mat2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
// Matrizen multiplizieren
std::vector<std::vector<int>> result1 = multiplyMatrices(mat1, mat2);

//    |1 2 3|  *  |9 8 7|  =  |(1*9 + 2*6 + 3*3) (1*8 + 2*5 + 3*2) (1*7 + 2*4 + 3*1)|
//    |4 5 6|     |6 5 4|     |(4*9 + 5*6 + 6*3) (4*8 + 5*5 + 6*2) (4*7 + 5*4 + 6*1)|
//    |7 8 9|     |3 2 1|     |(7*9 + 8*6 + 9*3) (7*8 + 8*5 + 9*2) (7*7 + 8*4 + 9*1)|

//                                              | 30  24 18|
//                                              | 84  69 54|
//                                              |138 114 90|

    // Ergebnis ausgeben
    for (const auto& row : result1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    };

    std::cout << std::endl;

    std::cout << std::endl;

   return 0;
}