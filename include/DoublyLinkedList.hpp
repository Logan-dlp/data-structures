#ifndef _DOUBLYLIKEDLIST_HPP
#define _DOUBLYLIKEDLIST_HPP

#include "DoublyNode.hpp"

namespace data{
    template<class> class DoublyLinkedListIterator;

    template<class DataType>
    class DoublyLinkedList{
        public:
        DoublyNode<DataType>* _head;
        DoublyNode<DataType>* _tail;
        int _count;

        DoublyLinkedList();
        DoublyLinkedList(DataType data);
        ~DoublyLinkedList();

        void append(DataType data);
        void prepend(DataType data);
        void insertAfter(DoublyLinkedListIterator<DataType>& itr, DataType data);
        void insertBefore(DoublyLinkedListIterator<DataType>& itr, DataType data);

        void removeHead();
        void removeTail();
        void removeBefore(DoublyLinkedListIterator<DataType> itr);
        void removeAfter(DoublyLinkedListIterator<DataType> itr);

        DoublyLinkedListIterator<DataType> getIterator();
    };
}

#endif //_DOUBLYLIKEDLIST_HPP
