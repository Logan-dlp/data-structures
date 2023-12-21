#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Node.h"

namespace data {
    template<class DataType>
    class LinkedList{
        public:
        Node<DataType>* _head;
        Node<DataType>* _tail;
        int _count;

        LinkedList();
        ~LinkedList();

        void append(DataType data);
        void prepend(DataType data);

        void removeHead();
        void removeTail();
    };
}

#endif //_LINKEDLIST_H
