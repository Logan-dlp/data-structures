#include "../include/DoublyNode.hpp"

namespace data{
    template<class DataType>
    inline DoublyNode<DataType>::DoublyNode(){
        this->_data = DataType(0);
        this->_previous = nullptr;
        this->_next = nullptr;
    }

    template<class DataType>
    inline DoublyNode<DataType>::DoublyNode(DataType data){
        this->_data = data;
        this->_previous = nullptr;
        this->_next = nullptr;
    }

    template<class DataType>
    inline DoublyNode<DataType>::~DoublyNode(){
        this->_previous = nullptr;
        this->_next = nullptr;
    }

    template<class DataType>
    void DoublyNode<DataType>::insertBefore(DataType data){
        DoublyNode<DataType>* newNode = new DoublyNode<DataType>(data);
        newNode->_previous = this->_previous;
        newNode->_next = this;
        this->_previous = newNode;

        if(newNode->_previous != nullptr){
            newNode->_previous->_next = newNode;
        }
    }

    template<class DataType>
    void DoublyNode<DataType>::insertAfter(DataType data){
        DoublyNode<DataType>* newNode = new DoublyNode<DataType>(data);
        newNode->_previous = this;
        newNode->_next = this->_next;
        this->_next = newNode;

        if(newNode->_next != nullptr){
            newNode->_next->_previous = newNode;
        }
    }

    template class DoublyNode<int>;
}