#include <iostream>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "../include/ListIterator.hpp"
#include "../include/DoublyLinkedList.hpp"
#include "../include/DoublyLinkedListIterator.hpp"
#include "../include/BinaryTree.hpp"

using namespace data;

template<class Datatype>
void displayArray(Array<Datatype>& array);

template<class Datatype>
void displayList(LinkedList<Datatype>& list);

template<class DataType>
void displayDoublyList(DoublyLinkedList<DataType>& list);

template<class DataType>
void parcoursSufixe(BinaryTree<DataType>* data);

template<class DataType>
void parcoursInfixe(BinaryTree<DataType>* data);

template<class DataType>
void parcoursPrefixe(BinaryTree<DataType>* data);

template<class DataType>
int count(BinaryTree<DataType>* data);

template<class DataType>
int height(BinaryTree<DataType>* data);

template<class DataType>
void routeWidthLevelCurrent(BinaryTree<DataType>* data, int level);

template<class DataType>
void recursiveWidthTraversal(BinaryTree<DataType>* data);

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

//    DoublyLinkedList<int> list = DoublyLinkedList(1);
//    list.append(8);
//
//    displayDoublyList(list);
//
//    list.removeBefore(list.getIterator());
//
//    displayDoublyList(list);

    BinaryTree<int>* bRoot = new BinaryTree<int>();
    BinaryTree<int>* bItr;

    bRoot->setData(0);
    bRoot->setLeft(new BinaryTree<int>(1, bRoot));
    bRoot->setRight(new BinaryTree<int>(2, bRoot));

    bItr = bRoot;
    bItr = bItr->getLeft();
    bItr->setLeft(new BinaryTree<int>(3, bItr));
    bItr->setRight(new BinaryTree<int>(4, bItr));

    bItr = bItr->getParent();
    bItr = bItr->getRight();
    bItr->setLeft(new BinaryTree<int>(5, bItr));
    bItr->setRight(new BinaryTree<int>(6, bItr));


    parcoursPrefixe(bRoot);
    std::cout << count(bRoot) << std::endl;

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

template<class DataType>
void parcoursSufixe(BinaryTree<DataType>* data) {
    if (data){
        parcoursSufixe(data->getLeft());
        parcoursSufixe(data->getRight());
        std::cout << data->getData() << std::endl;
    }
}

template<class DataType>
void parcoursInfixe(BinaryTree<DataType>* data) {
    if (data){
        parcoursInfixe(data->getLeft());
        std::cout << data->getData() << std::endl;
        parcoursInfixe(data->getRight());
    }
}

template<class DataType>
void parcoursPrefixe(BinaryTree<DataType>* data) {
    if (data){
        std::cout << data->getData() << std::endl;
        parcoursPrefixe(data->getLeft());
        parcoursPrefixe(data->getRight());
    }
}

template<class DataType>
int count(BinaryTree<DataType>* data) {
    if (!data) return 0;
    int countLeft = count(data->getLeft());
    int countRight = count(data->getRight());
    return 1 + countLeft + countRight;
}

template<class DataType>
int height(BinaryTree<DataType>* data) {
    if (!data) return 0;
    int heightLeft = height(data->getLeft());
    int heightRight = height(data->getRight());
    return 1 + std::max(heightLeft, heightRight);
}

template<class DataType>
void routeWidthLevelCurrent(BinaryTree<DataType>* data, int level) {
    if (level == 0) {
        std::cout << data->getData() << std::endl;
    }
    else if (level > 0) {
        routeWidthLevelCurrent(data->getLeft(), level - 1);
        routeWidthLevelCurrent(data->getRight(), level - 1);
    }
}

template<class DataType>
void recursiveWidthTraversal(BinaryTree<DataType>* data){
    int height = height(data);
    for (int level = 0; level < height; ++level) {
        routeWidthLevelCurrent(data, level);
    }
}