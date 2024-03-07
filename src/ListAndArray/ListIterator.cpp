#include "../../include/ListAndArray/ListIterator.hpp"
#include "../../include/ListAndArray/LinkedList.hpp"

namespace data {
    template <class DataType>
    inline ListIterator<DataType>::ListIterator(LinkedList<DataType>* list){
        this->_list = list;
        this->_node = list->_head;
    }

    template <class DataType>
    inline ListIterator<DataType>::ListIterator(LinkedList<DataType>& list){
        this->_list = &list;
        this->_node = list._head;
    }

    template <class DataType>
    void ListIterator<DataType>::start(){
        if(this->_list != nullptr){
            this->_node = this->_list->_head;
        }
    }

    template <class DataType>
    void ListIterator<DataType>::forth(){
        if(this->_node != nullptr){
            this->_node = this->_node->_next;
        }
    }

    template <class DataType>
    DataType& ListIterator<DataType>::item(){
        return this->_node->_data;
    }

    template <class DataType>
    bool ListIterator<DataType>::isValid(){
        return this->_node != nullptr;
    }

    template <class DataType>
    bool ListIterator<DataType>::hasNext(){
        return this->_node->_next != nullptr;
    }

    template class ListIterator<int>;
}