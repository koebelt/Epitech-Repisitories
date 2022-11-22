/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** Serialisation
*/

#ifndef SERIALISATION_HPP_
    #define SERIALISATION_HPP_

    #include "../food/Pizza.hpp"

    extern "C" {
        #include <cinttypes>
    }

// Voir pour l'hexadecimal peut etre ?
namespace plz {
    class Serialization {
        public:
            static uint8_t pack(Pizza);
            static Pizza unpack(uint8_t);
        protected:
        private:
    };

}

#endif /* !SERIALISATION_HPP_ */
