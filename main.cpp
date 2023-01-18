#include <iostream>
template<class T>
class Shape{
public:
	Shape(T width,T heigth): _width(width),_heigth(heigth){
		std::cout << "Constraction Shape\n";
	}
	T calculateArea() {
		return _width * _heigth;
	}
private:
	T _width;
	T _heigth;
};
template<class T>
class Square :public Shape<T> {
public:
	Square(T width,T heigth = width): Shape<T>(width, heigth), _width(width) {
		std::cout << "Constraction Square\n";
	}
	T calculateArea() {
		return _width * _width;
	}
private :
	T _width;
};
//Variadic Template
template<typename ... Args> //шаблон неопределенного количества параметров
class MyClass {
public:
	void print(Args ... args) {
		std::cout << sizeof...(args) << '\n';
		(std::cout << ... << args) << std::endl;
	}
private:
};
template<typename ... Types>
auto func(Types ... args) {
	return (args + ...);
}
template<typename ... Types>
void print(Types ... args) {
	std::cout << sizeof...(args) << '\n';
	(std::cout << ... << args) << std::endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	//наследование шаблонных классов
	Square<int> sq(4,5);
	std::cout << sq.calculateArea() << '\n';//калькулятор класса Square
	std::cout << sq.Shape<int>::calculateArea() << '\n';//калькулятор класса Shape
	std::cout<<func(2, 2.5, 2.7f)<<'\n';
	print(2,' ', 2.5,' ', 2.7f);
	MyClass<int,char,double,char,float> cl;
	cl.print(2, ' ', 2.5, ' ', 2.7f);
	return 0;
}