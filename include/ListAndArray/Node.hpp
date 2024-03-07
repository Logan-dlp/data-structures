#ifndef _NODE_HPP
#define _NODE_HPP

namespace data{
    template<class Datatype>
    class Node{
        public:
        Datatype _data;
        Node<Datatype>* _next;

        Node();
        Node(Datatype data);
        ~Node();

        void insertAfter(Datatype data);
    };
}

#endif //_NODE_HPP
