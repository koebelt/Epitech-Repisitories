/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IServer
*/

#ifndef ISERVER_HPP_
#define ISERVER_HPP_

namespace istudio {
    class IServer {
        public:
            IServer();
            ~IServer();

            /**
             * @author Paul Gazeau-Rousseau
             *
             *
             * @brief This Function is used when creating a server
             */
            virtual void create() = 0;

            /**
             * @author Paul Gazeau-Rousseau
             *
             * @brief This Function is used when starting a server
             */
            virtual void start() = 0;
        protected:
        private:
    };
}

#endif /* !ISERVER_HPP_ */
