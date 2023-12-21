#ifndef _NODE_H
#define _NODE_H

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

#endif //_NODE_H
