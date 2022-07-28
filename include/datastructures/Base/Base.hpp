#ifndef _DSBase
#define _DSBase
#include <string>
#include <stdexcept>

namespace DataStructures {
    class Base {
        public:
            /**
             * @brief formats object as a string
             * 
             * @return string format of object
             */
            virtual std::string to_string() = 0;
    };
}

#endif