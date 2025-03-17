#include <iostream>
#include <vector>

int main(){

    std::vector<int> vec1 = {0,1,2,3,4,5,6,7,8,9};

    // for (auto it = vec1.begin(); it != vec1.end(); it++){
    //     std::cout << *it << "\t";
    // }

    // for (int i = 0; i<10; i++){
    //     vec1.push_back(i+10);
    //     std::cout << vec1.size() << std::endl;
    //     std::cout << vec1.capacity() << std::endl;
    //     std::cout << &vec1 << std::endl;
    // }

    std::vector<int>* vec2 = new std::vector<int>;
    //vec2 -> reserve(50);

    for (int i = 0; i<50; i++){
        vec2 -> push_back(i);
        std::cout << vec2 -> size() << "\t";
        std::cout << vec2 -> capacity() << "\t";
        std::cout << &vec2[0] << std::endl;
    }



    return 0;
}