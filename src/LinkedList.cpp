#include "LinkedList.h"

namespace data {
    template<class DataType>
    inline LinkedList<DataType>::LinkedList(){
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_count = 0;
    }

    template<class DataType>
    inline LinkedList<DataType>::~LinkedList(){
        Node<DataType>* iterator = this->_head;
        Node<DataType>* next;
        while(iterator != nullptr){
            next = iterator->_next;
            delete iterator;
            iterator = next;
        }
    }

    template<class DataType>
    void LinkedList<DataType>::append(DataType data){
        if(this->_head == nullptr){
            this->_head = this->_tail = new Node<DataType>;
            this->_head->_data = data;
        }
        else{
            this->_tail->insertAfter(data);
            this->_tail = this->_tail->_next;
        }
        this->_count++;
    }

    template<class DataType>
    void LinkedList<DataType>::prepend(DataType data){
        Node<DataType>* newNode = new Node<DataType>;
        newNode->_data = data;
        newNode->_next = this->_head;
        this->_head = newNode;

        if(this->_tail == nullptr){
            this->_tail = this->_head;
        }

        this->_count++;
    }

    template<class DataType>
    void LinkedList<DataType>::removeHead(){
        Node<DataType>* node = nullptr;
        if(this->_head != nullptr){
            node = this->_head->_next;
            delete this->_head;
            this->_head = node;

            if(this->_head == nullptr){
                this->_tail = nullptr;
            }

            this->_count--;
        }
    }

    template<class DataType>
    void LinkedList<DataType>::removeTail(){
        Node<DataType>* node = this->_head;
        if(this->_head != nullptr){
            if(this->_head == this->_tail){
                delete this->_head;
                this->_head = this->_tail = nullptr;
            }
            else{
                while(node->_next != this->_tail){
                    node = node->_next;
                }
                this->_tail = node;
                delete node->_next;
                node->_next = nullptr;
            }
            this->_count--;
        }
    }

    template class LinkedList<int>;
}