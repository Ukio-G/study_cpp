struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};



//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T>
struct ValueHolder : public ICloneable
{
public:
	ValueHolder(const T & other):data_(other){}
	T data_;
	ValueHolder* clone() const
	{
		return new ValueHolder(data_);
	}
};
