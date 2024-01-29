#include "../include/DoublyLikedList.hpp"

namespace data{
    template<class DataType>
    inline DoublyLinkedList<DataType>::DoublyLinkedList(){
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_count = 0;
    }

    template<class DataType>
    inline DoublyLinkedList<DataType>::DoublyLinkedList(DataType data){
        this->_head = this->_tail = new DoublyNode<DataType>;
        this->_head->_data = this->_tail->_data = data;
        this->_count = 1;
    }

    template<class DataType>
    inline DoublyLinkedList<DataType>::~DoublyLinkedList(){
        DoublyNode<DataType>* iterator = this->_head;
        DoublyNode<DataType>* next;
        while (iterator != nullptr){
            next = iterator->_next;
            delete iterator;
            iterator = next;
        }
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::append(DataType data){
        if(this->_head == nullptr){
            this->_head = this->_tail = new DoublyNode<DataType>;
            this->_head->_data = data;
        }
        else{
            this->_head->insertAfter(data);
            this->_tail = this->_tail->_next;
        }
        this->_count++;
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::prepend(DataType data){
        if(this->_head == nullptr){
            this->_head = this->_tail = new DoublyNode<DataType>;
            this->_head->_data = data;
        }
        else{
            this->_head->insertBefore(data);
            this->_head = this->_head->_previous;
        }
        this->_count++;
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::removeHead(){
        if(this->_head != nullptr){
            DoublyNode<DataType>* node;
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
    void DoublyLinkedList<DataType>::removeTail(){
        if(this->_tail != nullptr){
            DoublyNode<DataType>* node;
            node = this->_tail->_previous;
            delete this->_tail;
            this->_tail = node;

            if(this->_tail == nullptr){
                this->_tail = nullptr;
            }

            this->_count--;
        }
    }

    template<class DataType>
    DoublyLinkedListIterator<DataType> DoublyLinkedList<DataType>::getIterator(){
        return DoublyLinkedListIterator<DataType>(this);
    }

    template class DoublyLinkedList<int>;
}