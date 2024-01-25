#ifndef _LIST_ITERATOR_HPP
#define _LIST_ITERATOR_HPP

#include "Node.hpp"

namespace data {
    template<class> class LinkedList;

    template<class DataType>
    class ListIterator {
        public:
        Node<DataType>* _node;
        LinkedList<DataType>* _list;

        ListIterator(LinkedList<DataType>& list = nullptr);
        ListIterator(LinkedList<DataType>* list = nullptr);

        ~ListIterator() = default;

        void start();
        void forth();

        DataType& item();
        bool isValid();
        bool hasNext();
    };
}

#endif //_LIST_ITERATOR_HPP
