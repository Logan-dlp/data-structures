#include "../../include/ListAndArray/DoublyLinkedList.hpp"
#include "../../include/ListAndArray/DoublyLinkedListIterator.hpp"

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
        if(this->_tail == nullptr){
            this->_head = this->_tail = new DoublyNode<DataType>(data);
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
            this->_tail = this->_head = new DoublyNode<DataType>(data);
        }
        else{
            this->_tail->insertBefore(data);
            this->_tail = this->_head->_previous;
        }
        this->_count++;
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::insertAfter(DoublyLinkedListIterator<DataType>& itr, DataType data){
        if(itr._list != this) { return; }
        if(itr._node != nullptr){
            itr._node->insertAfter(data);
            if(itr._node == this->_tail){
                this->_tail = itr._node->_next;
            }
            this->_count++;
        } else{
            this->append(data);
        }
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::insertBefore(DoublyLinkedListIterator<DataType>& itr, DataType data){
        if(itr._list != this) { return; }
        if(itr._node != nullptr){
            itr._node->insertBefore(data);
            if(itr._node == this->_head){
                this->_head = itr._node->_previous;
            }
            this->_count++;
        } else{
            this->prepend(data);
        }
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
    void DoublyLinkedList<DataType>::removeBefore(DoublyLinkedListIterator<DataType> itr){
        DoublyNode<DataType>* node = this->_head;
        if(itr._list != this) { return; }
        if(itr._node == nullptr) { return; }
        if(itr._node == this->_head){
            itr.forth();
            this->removeHead();
        } else{
            while(node->_next != itr._node){
                node = node->_next;
            }
            itr.forth();
            if(node->_next == this->_tail){
                this->_tail = node;
            }

            delete node->_next;
            node->_next = itr._node;
        }
    }

    template<class DataType>
    void DoublyLinkedList<DataType>::removeAfter(DoublyLinkedListIterator<DataType> itr){
        DoublyNode<DataType>* node = this->_tail;
        if(itr._list != this) { return; }
        if(itr._node == nullptr) { return; }
        if(itr._node == this->_tail){
            itr.back();
            this->removeTail();
        } else{
            while(node->_previous != itr._node){
                node = node->_previous;
            }
            itr.back();
            if(node->_previous == this->_head){
                this->_head = node;
            }

            delete node->_previous;
            node->_previous = itr._node;
        }
    }

    template<class DataType>
    DoublyLinkedListIterator<DataType> DoublyLinkedList<DataType>::getIterator(){
        return DoublyLinkedListIterator<DataType>(this);
    }

    template class DoublyLinkedList<int>;
}