#ifndef _DOUBLYLINKEDLISTITERATOR_HPP
#define _DOUBLYLINKEDLISTITERATOR_HPP

#include "DoublyNode.hpp"

namespace data{
    template<class> class DoublyLinkedList;

    template<class DataType>
    class DoublyLinkedListIterator {
        public:
        DoublyNode<DataType>* _node;
        DoublyLinkedList<DataType>* _list;

        DoublyLinkedListIterator(DoublyLinkedList<DataType>& list = nullptr);
        DoublyLinkedListIterator(DoublyLinkedList<DataType>* list = nullptr);

        ~DoublyLinkedListIterator() = default;

        void start();
        void back();
        void forth();
        void end();

        DataType& item();
        bool isValid();
        bool hasPrevious();
        bool hasNext();
    };
}

#endif //_DOUBLYLINKEDLISTITERATOR_HPP
