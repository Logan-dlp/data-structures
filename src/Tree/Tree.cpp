#include "../../include/Tree/Tree.hpp"

namespace data {
    template<class DataType>
    inline Tree<DataType>::Tree() {
        this->_data = DataType(0);
        this->_parent = nullptr;
    }

    template<class DataType>
    inline Tree<DataType>::Tree(DataType data) {
        this->_data = DataType(data);
        this->_parent = nullptr;
    }

    template<class DataType>
    inline Tree<DataType>::~Tree() {
        this->destroy();
    }

    template<class DataType>
    int Tree<DataType>::count() {
        int ctp = 1;
        DoublyLinkedListIterator<Node*> itr = this->_children.getIterator();
        for (itr.start(); itr.isValid(); itr.forth()) {
            ctp += itr.item()->count();
        }
        return ctp;
    }

    template<class DataType>
    void Tree<DataType>::destroy() {
        DoublyLinkedListIterator<Node*> itr(this->_children);
        Node* node = nullptr;
        itr.start();
        while (itr.isValid()) {
            node = itr.item();
            this->_children.removeBefore(itr);
        }
    }
}
