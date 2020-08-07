#ifndef SINGLETON_H
#define SINGLETON_H
class Singleton
{
	public:
		static Singleton & instance(){
			static Singleton s;
			return s;
		}
		int & data();

		~Singleton();
private:
	Singleton();
	Singleton(Singleton const &);
	Singleton & operator=(Singleton const &);
	
	int data_;
};
#endif // SINGLETON_H

