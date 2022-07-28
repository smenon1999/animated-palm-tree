#ifndef _DSArrayList
#define _DSArrayList

namespace DataStructures {
    template <typename T>
    class ArrayList : public List<T> {
        private:
            std::unique_ptr<T> arr;
            std::size_t capacity;
            std::size_t curr;

        public:

        /**
         * @brief Construct a new Array List< T> object
         * 
         */
        ArrayList<T>() : List<T>() {}

        /**
         * @brief Construct a new Array List< T> object from a copy
         * 
         * @param list 
         */
        ArrayList<T>(const List<T> &list) : List<T> (list) {}

        /**
         * @brief overridden methods from List
         * 
         */

    };
}

#endif