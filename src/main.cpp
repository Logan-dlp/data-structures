#include <iostream>
#include "Array.hpp"

using namespace Data;

template<class Datatype>
void displayArray(Array<Datatype>& array);

int main()
{
    std::cout << "# Creation des tableau et initialisation" << std::endl;
    Array<int> array(10);
    displayArray(array);
    array[0] = 12;
    displayArray(array);
    std::cout << "# Redimentionement du tableau" << std::endl;
    array.resize(8);
    displayArray(array);
    std::cout << "# Insertion d'une valeur" << std::endl;
    array.insert(2, 2);
    displayArray(array);
    std::cout << "# Supression d'une valeur" << std::endl;
    array.remove(2);
    displayArray(array);

    return 0;
}

template<class Datatype>
void displayArray(Array<Datatype>& array){
    std::cout << "{ ";
    for (int i = 0; i < array._size; ++i) {
        std::cout << array._array[i] << " ";
    }
    std::cout << "}" << std::endl;
}