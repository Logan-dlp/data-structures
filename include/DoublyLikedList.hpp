#ifndef _DOUBLYLIKEDLIST_HPP
#define _DOUBLYLIKEDLIST_HPP

#include "DoublyNode.hpp"

namespace data{
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

        void removeHead();
        void removeTail();
    };
}

#endif //_DOUBLYLIKEDLIST_HPP
