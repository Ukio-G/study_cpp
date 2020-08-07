#include <iostream>
#include <sstream>
#include <utility>
//#include <exception>

class bad_from_string : public std::exception
{
public:
    explicit bad_from_string(std::string msg) : error_msg(std::move(msg)) {}
    std::string error_msg;
    const char* what() const noexcept final{
        return error_msg.c_str();
    }
};

template<typename T>
T from_string(const std::string & s)
{
    T result;
    std::istringstream input(s);
    input.exceptions(std::istringstream::badbit);
    if ((input >> std::noskipws >> result).fail() || (input.peek() != EOF)){
            throw bad_from_string("fail");
    }

    return result;
}

int main() {


    try {
//        std::string s1("123");
          from_string<int>("123gsfg");
//          from_string<double>("123.0");
//        std::string c1 = from_string<std::string>(s1); // c1 = "123"
//        from_string<char>(" "); // пробел
//        from_string<std::string>(" "); // исключение
//        from_string<std::string>(""); // исключение
//        from_string<std::string>("a "); // исключение
//        from_string<std::string>(" a"); // исключение
//        from_string<std::string>("a b"); // исключение
//        std::cout << a1 << std::endl;
    }
    catch (bad_from_string & e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "other exception" << std::endl;
    }

    std::cout << "some executing" << std::endl;
    return 0;
}
