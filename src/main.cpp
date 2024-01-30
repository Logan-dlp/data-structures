#include <iostream>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "../include/ListIterator.hpp"
#include "../include/DoublyLinkedList.hpp"
#include "../include/DoublyLinkedListIterator.hpp"

using namespace data;

template<class Datatype>
void displayArray(Array<Datatype>& array);

template<class Datatype>
void displayList(LinkedList<Datatype>& list);

template<class DataType>
void displayDoublyList(DoublyLinkedList<DataType>& list);

int main()
{
//    std::cout << "# Creation des tableau et initialisation" << std::endl;
//    Array<int> array(10);
//    displayArray(array);
//    array[0] = 12;
//    displayArray(array);
//    std::cout << "# Redimentionement du tableau" << std::endl;
//    array.resize(8);
//    displayArray(array);
//    std::cout << "# Insertion d'une valeur" << std::endl;
//    array.insert(2, 2);
//    displayArray(array);
//    std::cout << "# Supression d'une valeur" << std::endl;
//    array.remove(2);
//    displayArray(array);

//    LinkedList<int> list;
//    list.append(0);
//    list.append(1);
//    list.append(2);
//    list.prepend(3);
//    displayList(list);
//    list.removeHead();
//    displayList(list);
//    list.removeTail();
//    displayList(list);

    DoublyLinkedList<int> list = DoublyLinkedList(1);
    list.append(8);

    displayDoublyList(list);

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

template<class Datatype>
void displayList(LinkedList<Datatype>& list){
    ListIterator<Datatype> itr = list.getIterator();
    while(itr.isValid()){
        std::cout << itr.item() << " -> ";
        itr.forth();
    }
    std::cout << std::endl;
}

template<class DataType>
void displayDoublyList(DoublyLinkedList<DataType>& list){
    DoublyLinkedListIterator<DataType> itr = list.getIterator();
    while(itr.isValid()){
        std::cout << itr.item() << " -> ";
        itr.forth();
    }
    std::cout << std::endl;
}