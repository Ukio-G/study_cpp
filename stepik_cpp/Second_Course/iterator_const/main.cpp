#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <string>
template<class T>
class VectorList
{
private:
    using VectT  = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;


    VectorList() = default;
    VectorList(VectorList const &) = default;
    VectorList(VectorList &&) = default;

    VectorList & operator=(VectorList &&)      = default;
    VectorList & operator=(VectorList const &) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    template<class It>
    void append(It p, It q);

    bool empty() const { return size() == 0; }

    // определите метод size
    size_t size() const
    {
        size_t result = 0;
        for (auto &item : this->data_)
            result += item.size();
        return result;
    }

    // определите const_iterator
   struct const_iterator : std::iterator<std::bidirectional_iterator_tag, const T, ptrdiff_t , const T*, const T&> {
        const_iterator(const const_iterator & other) : current_vector(other.current_vector), current_iterator(other.current_iterator), current_list(other.current_list) {
        }
        const_iterator() = default;
        const_iterator(typename ListT::const_iterator l_it, typename VectT::const_iterator v_it, const ListT * container) : current_vector(l_it), current_iterator(v_it), current_list(container) {
        }

        const_iterator & operator++() {
            std::cout << "++" << std::endl;
            current_iterator++;
            if(current_iterator == (*current_vector).end())
            {
                ++current_vector;
                if(current_list->end() == current_vector)
                {
                    return *this;
                }
                current_iterator = (*current_vector).begin();
            }
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator temp = *this;
            ++*this;
            return temp;
        }

        const_iterator & operator--() {
            std::cout << "--" << std::endl;
            if(current_iterator == (*current_vector).begin()) {
                --current_vector;
                current_iterator = (*current_vector).end();
            }
            --current_iterator;
            return *this;
        }

        const_iterator operator--(int)
        {
            const_iterator temp = *this;
            --*this;
            return temp;
        }

        bool operator!=(const const_iterator other) const
        {
            return (&(*current_iterator) != &(*(other.current_iterator)));
        }

        bool operator==(const const_iterator other) const
        {
            return (&(*current_iterator) == &(*(other.current_iterator)));
        }

        typename const_iterator::reference operator*() const {
            return *current_iterator;
        }

        typename const_iterator::pointer operator->() const {
            return &(*current_iterator);
        }

    public:
        typename VectT::const_iterator current_iterator;
        typename ListT::const_iterator current_vector;
        const ListT * current_list;
    };

    const_iterator begin() const  {
        return const_iterator(data_.cbegin(),data_.front().cbegin(), &data_);
    }
    const_iterator end() const   {
        if (size() == 0)
            return const_iterator(data_.cbegin(),data_.front().cbegin(), &data_);
        return const_iterator(--data_.cend(),data_.back().cend(), &data_);
    }

    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(this->end());
    }
    const_reverse_iterator rend()  const {
        return const_reverse_iterator(this->begin());
    }

private:
    ListT data_;
};

template<class T>
template<class It>
void VectorList<T>::append(It p, It q) // определена снаружи
{
    if (p != q)
        data_.push_back(VectT(p,q));
}

int main()
{

    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {4,5,6};
    std::vector<int> v3 = {7,8,9};

    VectorList<int> vlist;

    vlist.append(v1.begin(), v1.end());
    vlist.append(v2.begin(), v2.end());
    vlist.append(v3.begin(), v3.end());


//    for(auto cit = vlist.begin(); cit != vlist.end(); cit++)
//        std::cout << *cit << std::endl;

//    for(auto cit = --vlist.end(); cit != vlist.begin(); cit--)
//        std::cout << *cit << std::endl;

    for(auto cit = vlist.rbegin(); cit != vlist.rend(); cit++)
        std::cout << *cit << std::endl;

//    std::vector<std::string> s_vec = {"123", "2323"};
//    VectorList<std::string> svlist;
//
//    svlist.append(s_vec.begin(), s_vec.end());
//    std::cout << svlist.rbegin()->c_str() << std::endl;
//
    return  0;
}