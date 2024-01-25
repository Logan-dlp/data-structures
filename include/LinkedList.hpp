#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Node.hpp"

namespace data {
    template<class> class ListIterator;

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

        ListIterator<DataType> getIterator();
    };
}

#endif //_LINKEDLIST_H
