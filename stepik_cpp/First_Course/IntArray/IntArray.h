#ifndef __INTARRAY_H__
#define __INTARRAY_H__
#include <cstddef>
struct IntArray
{
	explicit IntArray(size_t size);
	IntArray(IntArray const & other);
	~IntArray();
	IntArray & operator=(IntArray const & other);
	void swap(IntArray & array);
	size_t size() const;
	int & get(size_t i);
	int get(size_t i) const;
	void resize(size_t new_size);
private:
	size_t size_;
	int * data_;
};

#endif
