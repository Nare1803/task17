#include<iostream>
#include<stdexcept>

class shape{
 public:
	 virtual double area() {
	    throw std::runtime_error("Cant calculate area :");
          }
	 virtual ~shape(){}
};

class Circle : public shape {
private:
    double a;
    double pi = 3.1;

public:
    Circle(double a1) : a(a1) {
        if (a <= 0) {
            throw std::invalid_argument("Radius must be positive :");
        }
    }

    double area() override {
        return pi * a * a;
    }
};

class Rectangle : public shape {
private:
    double a;
    double b;

public:
    Rectangle(double a1, double b1) : a(a1), b(b1) {
        if (a <= 0 || b <= 0) {
            throw std::invalid_argument("Length and width must be positive : ");
        }
    }

    double area()  override {
        return a * b;
    }
};

int main() {

    double r;
    std::cout << "input radius for circle :";
    std::cin >> r;
    
    double a,b;
    std::cout << "input length for rectangle : ";
    std::cin >> a;
    std::cout << "input width for rctangle : ";
    std::cin >> b;

    try {
        Circle circle(r);
        std::cout << "circle's area: " << circle.area() << std::endl;

        Rectangle rectangle(a, b);
        std::cout << "Rectangle's area: " << rectangle.area() << std::endl;

   
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}






