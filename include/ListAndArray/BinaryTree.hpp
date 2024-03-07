#ifndef _BINARYTREE_HPP
#define _BINARYTREE_HPP

namespace data {
    template<class DataType>
    class BinaryTree {

    public:
        BinaryTree();
        BinaryTree(const DataType& data, BinaryTree<DataType>* parent = nullptr, BinaryTree<DataType>* left = nullptr, BinaryTree<DataType>* right = nullptr);
        ~BinaryTree();

        DataType& getData();
        void setData(const DataType& data);
        BinaryTree<DataType>* getParent();
        void setParent(BinaryTree<DataType>* parent);
        BinaryTree<DataType>* getLeft();
        void setLeft(BinaryTree<DataType>* left);
        BinaryTree<DataType>* getRight();
        void setRight(BinaryTree<DataType>* right);

    protected:
        DataType _data;
        BinaryTree<DataType>* _parent;
        BinaryTree<DataType>* _left;
        BinaryTree<DataType>* _right;
    };
}

#endif //_BINARYTREE_HPP
