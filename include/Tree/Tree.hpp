#ifndef _TREE_HPP
#define _TREE_HPP

#include "../ListAndArray/DoublyLinkedList.hpp"

namespace data {
    template <class DataType>
    class Tree {
        public:
        typedef Tree<DataType> Node;

        DataType _data;
        Node* _parent;
        DoublyLinkedList<Node*> _children;

        Tree();
        Tree(DataType data);
        ~Tree();

        int count();
        void destroy();
    };
}

#endif //_TREE_HPP
