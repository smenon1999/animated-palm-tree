#ifndef _DSList
#define _DSList

#include <cstddef>
#include "../Base/Base.hpp"

namespace DataStructures {

    template <typename T>
    class List : public Base {

        private:

        protected:
            /**
             * @brief Construct a new List< T> object
             * 
             */
            List<T>() : m_size(0) {}

            /**
             * @brief Construct a new List< T> object
             * 
             * @param copy copy
             */
            List<T>(const List<T> &copy) {
               this->append(copy);
            }

            /**
             * @brief size of the list
             * 
             */
            std::size_t m_size;

        public:
            /**
             * @brief inserts data at front of list
             * @param data teh data to insert
             */
            virtual void push_front(T) = 0;

            /**
             * @brief brief inserts data at position i; if i is greater than size, insert at the back
             * @param data data to insert
             * @param pos position to insert at
             */
            virtual void insert(T, std::size_t) = 0;

            /**
             * @brief inserts at the back of list
             * @param data the data to insert
             */
            virtual void push_back(T) = 0;

            /**
             * @brief removes and returns object at position i
             * @param pos position to remove from
             */
            virtual T remove(std::size_t) = 0;

            /**
             * @brief removes and returns data from the front of the list
             * @returns the data from the front of the list
             */
            virtual T pop_front() = 0;

            /**
             * @brief removes and returns data from the back of the list
             * @returns the data from the back of the list
             */
            virtual T pop_back() = 0;

            /**
             * @brief returns data from position i in the list
             * @param pos the position to retrieve
             * @returns the data at specified psoition
             */
            virtual T at(std::size_t) = 0;

            /**
             * @brief returns data from the front of the list
             * @returns the data from the front of the lsit
             */
            virtual T front() = 0;

            /**
             * @brief returns data from the back of the list
             * @returns the data from the back of teh list
             */
            virtual T back() = 0;

            /**
             * @brief appends List to the end of List
             * @param list the list to append
             */
            void append(const List<T>& list) {
                for (std::size_t i = 0; i < list.size(); i++)
                    this->push_back(list.at(i));
            }

            /**
             * @brief returns the size of the list
             * @returns size of the list
             */
            int size() {
                return this->m_size;
            }
    };
}


#endif