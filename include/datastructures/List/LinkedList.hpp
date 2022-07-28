#ifndef _DSLinkedList
#define _DSLinkedList

#include <memory>
#include "List.hpp"

namespace DataStructures {

    /**
     * @brief Single Linked List class, using smart pointers
     * 
     * @tparam T list element data type
     */

    template <typename T>
    class LinkedList : public List<T> {
        private:
            /**
             * @brief Node struct definition
             * 
             */
            struct Node {
                Node (T val) : data(val){}
                ~Node() {}

                T data;
                std::shared_ptr<Node> next;
            };

            std::shared_ptr<Node> head;
            std::shared_ptr<Node> curr;
            std::size_t pos;

        public:
            /**
             * @brief Construct a new Linked List< T> object
             * 
             */
            LinkedList<T>() : List<T>() { this->clear();}

            /**
             * @brief Construct a new Linked List< T> object from copy list
             * 
             * @param copy 
             */
            LinkedList<T>(const List<T> &copy) : List<T>(copy) {}

            /**
             * @brief Destroy the Linked List< T> object
             * 
             */
            virtual ~LinkedList<T>() {this->clear();}

            
            /**
             * @brief advances curr
             * 
             */
            void advance() {
                if (this->curr != nullptr && this->curr->next != nullptr) {
                    this->curr = this->curr->next;
                    this->pos++;
                }
            }

            /**
             * @brief resets curr to the head of the list
             * 
             */
            void reset_curr() {
                this->curr = this->head;
                this->pos = 0;
            }

            /**
             * @brief inserts element after curr
             * 
             */
            void insert_after_curr(T data) {

                if (this->m_size == 0) {
                    this->push_front(data);
                    return;
                };

                std::shared_ptr<Node> newNode = std::make_shared<Node>(data);
                newNode->next = curr->next;
                curr->next = newNode;
                this->m_size++;
            }

            /**
             * @brief removes and returns the element after curr
             * 
             */
            T remove_after_curr() {
                if (this->curr == nullptr || this->curr->next == nullptr)
                    throw std::out_of_range("Cursor at end of list.");

                std::shared_ptr<Node> removedNode = this->curr->next;
                this->curr->next = removedNode->next;
                this->m_size--;
                return removedNode->data;
            }

            /**
             * @brief Overriden methods from List
             * 
             */
            void push_front(T data) override {
                std::shared_ptr<Node> oldHead = this->head;
                this->head = std::make_shared<Node>(data);
                this->head->next = oldHead;
                this->m_size++;
            }

            void insert(T data, std::size_t idx) override {
                if (idx == 0) {
                    this->push_front(data);
                    return;
                }

                if (idx >= this->m_size || idx < 0)
                    throw std::out_of_range("Index out of bounds.");

                this->reset_curr();

                for (std::size_t i = pos; i < idx - 1; i++)
                    this->advance();

                this->insert_after_curr(data);
            }

            void push_back(T data) override {
                for (std::size_t i = pos; i <= this->m_size; i++) 
                    this->advance();
                
                this->insert_after_curr(data);
            }

            T remove(std::size_t idx) override {
                if (idx >= this->m_size || idx < 0)
                    throw std::out_of_range("Index out of bounds.");

                if (idx <= pos)
                    this->reset_curr();
                
                for (std::size_t i = pos; i < idx; i++)
                    this->advance();
                return this->remove_after_curr();
            } 

            T pop_front() override {
                if (this->m_size == 0)
                    throw std::out_of_range("Attempting to pop from empty list.");

                T data = this->head->data;
                this->head = this->head->next;
                this->m_size--;
                return data;
            }

            T pop_back() override {
                if (this->m_size == 0)
                    throw std::out_of_range("Attempting to pop from empty list.");

                for (std::size_t i = pos; i < this->m_size - 1; i++)
                    this->advance();
                
                return this->remove_after_curr();
            }

            T at(std::size_t idx) override {
                if (idx >= this->m_size || idx < 0)
                    throw std::out_of_range("Index out of bounds.");

                this->reset_curr();

                for (std::size_t i = pos; i < idx; i++)
                    this->advance();

                return this->curr->data;
            }

            T front() override {
                if (this->m_size == 0)
                    throw std::out_of_range("Attempting to get front of empty list.");

                return this->head->data;
            }

            T back() override {
                if (this->m_size == 0)
                    throw std::out_of_range("Attempting to get back of empty list.");

                return this->at(this->m_size - 1);
            }

            /**
             * @brief overriden methods from Base
             * 
             */
            void clear() override {
                this->head = nullptr;
                this->curr = head;
                this->pos = 0;
                this->m_size = 0;
            }

            std::string to_string() override {
                std::string out = "<";
                this->reset_curr();
                for (std::size_t i = 0; i < this->m_size; i++) {
                    out += this->at(i);
                    if (i != this->m_size - 1)
                        out += ", ";
                }
                out += ">";
                return out;
            }
    };
}

#endif