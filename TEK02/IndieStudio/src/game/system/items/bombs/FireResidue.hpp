/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** FireResidue
*/

#ifndef FIRERESIDUE_HPP_
#define FIRERESIDUE_HPP_

#include "../Bomb.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Fire Residue that appear when classic bomb explode
    **
    **/
    class FireResidue : public Bomb {
        public:
            FireResidue(EntityLiving &entliving);
            ~FireResidue() = default;

            FireResidue(const FireResidue &cpy);
            FireResidue(FireResidue &&ref);
            void spawn(Vector pos);
            void explode(Entity *entity);
            void addComponentToEntity(Entity &entity);
            void waiting_action(Entity *entity);
        protected:
        private:
            EntityLiving &_entliving;
    };
}

#endif /* !FIRERESIDUE_HPP_ */
