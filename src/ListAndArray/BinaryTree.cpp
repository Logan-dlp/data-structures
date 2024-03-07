#include <iostream>
#include "../../include/ListAndArray/BinaryTree.hpp"

namespace data {

    template<class DataType>
    inline BinaryTree<DataType>::BinaryTree() {
        this->_data = DataType(0);
        this->_parent = nullptr;
        this->_left = nullptr;
        this->_right = nullptr;
    }

    template<class DataType>
    inline BinaryTree<DataType>::BinaryTree(const DataType &data, BinaryTree<DataType> *parent, BinaryTree<DataType> *left, BinaryTree<DataType> *right) {
        this->_data = data;
        this->_parent = parent;
        this->_left = left;
        this->_right = right;
    }

    template<class DataType>
    inline BinaryTree<DataType>::~BinaryTree() {
        if (this->_left){
            delete this->_left;
        }
        this->_left = nullptr;

        if (this->_right){
            delete this->_right;
        }
        this->_right = nullptr;
    }

    template<class DataType>
    DataType& BinaryTree<DataType>::getData() {
        return this->_data;
    }

    template<class DataType>
    void BinaryTree<DataType>::setData(const DataType &data) {
        this->_data = data;
    }

    template<class DataType>
    BinaryTree<DataType>* BinaryTree<DataType>::getParent() {
        return this->_parent;
    }

    template<class DataType>
    void BinaryTree<DataType>::setParent(BinaryTree<DataType>* parent) {
        this->_parent = parent;
    }

    template<class DataType>
    BinaryTree<DataType>* BinaryTree<DataType>::getLeft() {
        return this->_left;
    }

    template<class DataType>
    void BinaryTree<DataType>::setLeft(BinaryTree<DataType>* left) {
        this->_left = left;
    }

    template<class DataType>
    BinaryTree<DataType>* BinaryTree<DataType>::getRight() {
        return this->_right;
    }

    template<class DataType>
    void BinaryTree<DataType>::setRight(BinaryTree<DataType>* right) {
        this->_right = right;
    }

    template class BinaryTree<int>;
}