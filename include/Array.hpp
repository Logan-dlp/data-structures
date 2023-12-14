#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

namespace Data {
    template<class DataType>
    class Array
    {
        public:
        DataType* _array;
        int _size;

        Array (int size);

        virtual ~Array ();

        void resize (int size);

        void insert(DataType item, int index);

        void remove(int index);

        // Getter

        int size ();

        DataType& operator[] (int index);

//        operator int* ();
    };
    
}

#endif // _ARRAY_HPP_
