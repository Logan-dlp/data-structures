#ifndef _DOUBLYNODE_HPP
#define _DOUBLYNODE_HPP

namespace data{
    template<class DataType>
    class DoublyNode{
        public:
        DataType _data;
        DoublyNode<DataType>* _previous;
        DoublyNode<DataType>* _next;

        DoublyNode();
        DoublyNode(DataType data);
        ~DoublyNode();

        void insertBefore(DataType data);
        void insertAfter(DataType data);
    };
}

#endif //_DOUBLYNODE_HPP
