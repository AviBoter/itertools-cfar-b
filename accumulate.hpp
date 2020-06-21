//
// Created by amichai hadad on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_HPP
#define ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_HPP

#include "range.hpp"

#include <iterator>

namespace itertools {
    typedef struct {
        template<typename T>
        T operator()(T a, T b) const {
            return a+b;
        }
    }myFunc;
    template <typename VAC, typename FUNC = myFunc>
    class accumulate {
        VAC data;
        FUNC func;
    public:
        explicit accumulate(VAC x,FUNC f = myFunc()) : data(x), func(f) {}
        class iterator{
            typename VAC::value_type _it_data;
            typename VAC::iterator _iter;
            typename VAC::iterator _it_end;
            FUNC _it_func;
        public:
            explicit iterator(typename VAC::iterator it, typename VAC::iterator end, FUNC func)
                    : _iter(it), _it_end(end), _it_func(func) ,_it_data(*it){};
            iterator(const iterator& other) = default;
            iterator& operator=(const iterator& other) {
                if (&other != this){
                    this->_it_data = other._it_data;
                    this->_iter = other._iter;
                    this->_it_end = other._it_end;
                    this->_it_func = other._it_func;
                }
                return *this;
            }
            iterator& operator++(){
                ++_iter;
                if(_iter != _it_end)
                    _it_data = _it_func(_it_data, *_iter);
                return *this;
            }
            iterator operator++(int){
                iterator temp = *this;
                ++(*this);
                return temp;
            }
            bool operator==(const iterator& other) {
                return (_iter == other._iter);
            }
            bool operator!=(const iterator& other) {
                return (_iter != other._iter);
            }

            auto operator*(){
                return _it_data;
            }
        };

        iterator begin(){
            return iterator(data.begin(), data.end(), func);
        }
        iterator end(){
            return iterator(data.end(), data.end(), func);
        }


    };

};
#endif //ITERTOOLS_CFAR_A_MASTER_ACCUMULATE_HPP
