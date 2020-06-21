//
// Created by amichai hadad on 08/06/2020.
//

#ifndef ITERTOOLS_CFAR_A_MASTER_RANGE_HPP
#define ITERTOOLS_CFAR_A_MASTER_RANGE_HPP

#include <iterator>
namespace itertools {

    class range {
    public:
        int _start;
        int _end;

        range(int x, int y) : _start(x), _end(y) {
            if (x == y) {
                _start = 0;
                _end = 0;
            }
        }

        range(range &other) : _start(other._start), _end(other._end) {}
        class iterator// code from https://www.artificialworlds.net/blog/2017/05/11/c-iterator-example-and-an-iterable-range/
        {
        private:
            int value_;

            class intholder {
                int value_;
            public:
                intholder(int value) : value_(value) {}

                int operator*() { return value_; }
            };

        public:
            // Previously provided by std::iterator - see update below
            typedef int value_type;
            typedef std::ptrdiff_t difference_type;
            typedef int *pointer;
            typedef int &reference;
            typedef std::input_iterator_tag iterator_category;

            explicit iterator(int value) : value_(value) {}

            int operator*() const { return value_; }

            bool operator==(const iterator &other) const { return value_ == other.value_; }

            bool operator!=(const iterator &other) const { return !(*this == other); }

            intholder operator++(int) {
                intholder ret(value_);
                ++*this;
                return ret;
            }

            iterator &operator++() {
                ++value_;
                return *this;
            }
        };

        iterator begin() { return iterator(_start); }

        iterator end() { return iterator(_end); }

        typedef int	value_type;

    };

};

#endif //ITERTOOLS_CFAR_A_MASTER_RANGE_HPP
