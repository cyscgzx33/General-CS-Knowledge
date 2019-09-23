# include <cppad/utility/index_sort.hpp>
# include <cppad/utility/vector.hpp>
# include <valarray>
# include <vector>
# include <iostream>


namespace{
    // class that uses < to compare a pair of size_t values
    class Key {
    public:
        size_t first_;
        size_t second_;
        //
        Key(void)
        { }
        //
        Key(size_t first, size_t second)
        : first_(first), second_(second)
        { }
        //
        bool operator<(const Key& other) const
        {   if( first_ == other.first_ )
                return second_ < other.second_;
            return first_ < other.first_;
        }
    };

    template <class KeyVector, class SizeVector>
    bool vector_case(void)
    {   bool ok = true;
        size_t i, j;
        size_t first[]  =  { 1, 3, 6, 232, 3, 6, 1,   2 }; // {4, 4, 3, 3, 2, 2, 1, 1}
        size_t second[] =  { 2, 3, 5, 1,   8, 4, 100, 9923 }; // { 0, 1, 0, 1, 0, 1, 0, 1}
        size_t size     = sizeof(first) / sizeof(first[0]);

        KeyVector keys(size);
        for(i = 0; i < size; i++)
            keys[i] = Key(first[i], second[i]);
            // keys[i]

        SizeVector ind(size);
        CppAD::index_sort(keys, ind);

        // check that all the indices are different
        for(i = 0; i < size; i++)
        {   for(j = 0; j < size; j++)
                ok &= (i == j) | (ind[i] != ind[j]);
        }

        // check for increasing order
        for(i = 0; i < size-1; i++)
        {   if( first[ ind[i] ] == first[ ind[i+1] ] )
                ok &= second[ ind[i] ] <= second[ ind[i+1] ];
            else
                ok &= first[ ind[i] ] < first[ ind[i+1] ];
        }

        // verbosely check the output
        for (i = 0; i < size; i++)
        {
            std::cout << "first[ind" << i << "] = " << first[  ind[i] ] << std::endl;
            std::cout << "second[ind" << i << "] = " << second[  ind[i] ] << std::endl;
        }

        return ok;
    }
}

bool index_sort(void)
{   bool ok = true;

    // some example simple vector template classes
    ok &= vector_case<  std::vector<Key>,  std::valarray<size_t> >();
    // ok &= vector_case< std::valarray<Key>, CppAD::vector<size_t> >();
    // ok &= vector_case< CppAD::vector<Key>,   std::vector<size_t> >();

    return ok;
}

int main()
{
    // call the index_sort to start
    index_sort();

    return 0;
}