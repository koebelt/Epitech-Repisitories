/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IManager
*/

#ifndef IMANAGER_HPP_
#define IMANAGER_HPP_

#include <memory>
#include <vector>
#include <list>
#include <functional>

namespace istudio {
    /**
    * @author Paul Gazeau-Rousseau
    *
    * @brief IManager: interface that each manager must implement
    */
    template <typename T>
    class IManager {
        public:
            virtual ~IManager() = default;

            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Operator <<: Need when add a data T into Manager
            ** @param elem (std::unique_ptr<T>): element to add
            **
            ** @return virtual
            **/
            virtual IManager &operator<<(std::shared_ptr<T> elem) = 0;
        protected:
        private:
    };

    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class that handle collectable list
    **
    **/
    template <class U>
    class Collectable {
        public:
            Collectable() = default;
            ~Collectable() = default;

            template <class O, class T>
            class Collector {
                public:
                    Collector(std::list<std::shared_ptr<O>> &list, std::function<bool (T *)> fn = nullptr) {
	        			T *elem = nullptr;

	        			for (auto &e : list) {
	        				if (!(elem = dynamic_cast<T *>(e.get())))
                                continue;
                            if (fn == nullptr || fn(elem))
	        				    _items.push_back(elem);
	        			}
                    };
                    ~Collector() = default;

                    std::vector<T *> hasVector() { return (std::vector<T *>(_items.begin(), _items.end())); };
                    std::list<T *> get() { return _items; };
                    std::list<T *> operator->() { return _items; };
                    std::list<T *> operator*() { return _items; };
                private:
                    std::list<T *> _items{};
            };

			std::list<std::shared_ptr<U>> &operator~() { return _objects; };

            template <typename T>
			Collector<U, T> collect(std::function<bool (T *)> fn = nullptr) { return Collector<U, T>(_objects, fn); };
        protected:

            std::list<std::shared_ptr<U>> _objects{};
    };
}

#endif /* !IMANAGER_HPP_ */
