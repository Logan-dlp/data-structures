#include "../../include/ListAndArray/DoublyLinkedList.hpp"
#include "../../include/ListAndArray/DoublyLinkedListIterator.hpp"

namespace data {
    template<class DataType>
    inline DoublyLinkedListIterator<DataType>::DoublyLinkedListIterator(DoublyLinkedList<DataType>* list){
        this->_list = list;
        this->_node = list->_head;
    }

    template<class DataType>
    inline DoublyLinkedListIterator<DataType>::DoublyLinkedListIterator(DoublyLinkedList<DataType>& list){
        this->_list = &list;
        this->_node = list._head;
    }

    template<class DataType>
    void DoublyLinkedListIterator<DataType>::start(){
        if(this->_list != nullptr){
            this->_node = this->_list->_head;
        }
    }

    template<class DataType>
    void DoublyLinkedListIterator<DataType>::back(){
        if(this->_node != nullptr){
            this->_node = this->_node->_previous;
        }
    }

    template<class DataType>
    void DoublyLinkedListIterator<DataType>::forth(){
        if(this->_node != nullptr){
            this->_node = this->_node->_next;
        }
    }

    template<class DataType>
    void DoublyLinkedListIterator<DataType>::end(){
        if(this->_list != nullptr){
            this->_node = this->_list->_tail;
        }
    }

    template<class DataType>
    DataType& DoublyLinkedListIterator<DataType>::item(){
        return this->_node->_data;
    }

    template<class DataType>
    bool DoublyLinkedListIterator<DataType>::isValid(){
        return this->_node != nullptr;
    }

    template<class DataType>
    bool DoublyLinkedListIterator<DataType>::hasPrevious(){
        return this->_node->_previous != nullptr;
    }

    template<class DataType>
    bool DoublyLinkedListIterator<DataType>::hasNext(){
        return this->_node->_next != nullptr;
    }

    template class DoublyLinkedListIterator<int>;
}
