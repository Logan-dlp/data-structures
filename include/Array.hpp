#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

namespace Data {
    class Array
    {
        public:
        int* _array;
        int _size;

        explicit Array (int size);

        virtual ~Array ();

        // void resize (int size);

        // void insert(int item, int index);

        // void remove(int index);

        // Getter

        // int size ();

        int& operator[] (int index);

        operator Datatype* ();
    };
    
}

#endif // _ARRAY_HPP_