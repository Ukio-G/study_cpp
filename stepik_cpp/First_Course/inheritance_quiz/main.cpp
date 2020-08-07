

struct Base {
 public:
  int a;
  void a_m(){};
  virtual void a_v_m(){};

 protected:
  int b;
  void b_m() { c = 10; };

 private:
  int c;
  virtual void c_v_m(){};
  void c_m(){};
};

struct Delived : private Base {
 private:
  // Производные классы не могут переопределять
  // private-виртуальные методы базового класса, если они унаследованы от
  // базового класса с модификатором private. 
  void c_v_m() {} // Могут быть переопределены
  // void c_v_m(){ с = 10;};  Производные классы не видят private-предков своего базового класса. Это правда
  void a_v_m() {
    a = 10;
  }  // Если в базовом классе виртуальная функция определена как public, то в
     // производном классе её можно переопределить как private. Это правда

  // Производные классы не видят protected-предков своего (непосредственного)
  // базового класса, если они унаследованы от базового класса с модификатором
  // private. Неверно, все видно.
  void protectedBase() {
    b = 20;
    b_m();
  }
};

int main(int argc, char const *argv[])
{
	

	return 0;
}