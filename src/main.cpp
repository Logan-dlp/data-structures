#include <iostream>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "../include/ListIterator.hpp"
#include "../include/DoublyNode.hpp"
#include "../include//DoublyLikedList.hpp"

using namespace data;

template<class Datatype>
void displayArray(Array<Datatype>& array);

template<class Datatype>
void displayList(LinkedList<Datatype>& list);

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

    std::cout << list._head->_data << " " << list._count << std::endl;

    list.prepend(3);

    std::cout << list._tail->_data << " " << list._count << std::endl;

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
//    Node<Datatype>* node = list._head;
//    if (node != nullptr){
//        while (node != nullptr){
//            std::cout << node->_data;
//            std::cout << " -> ";
//            node = node->_next;
//        }
//        std::cout << std::endl;
//    }
    ListIterator<Datatype> itr = list.getIterator();
    while(itr.hasNext()){
        std::cout << itr.item() << " -> ";
        itr.forth();
    }
    std::cout << std::endl;
}