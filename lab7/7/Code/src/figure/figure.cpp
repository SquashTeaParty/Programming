#include "figure.hpp"
#include "iostream"
#include <numbers>

//	Circle 
	Circle::Circle()
		: radius_(new double(1.))
	{
		std::cout << "[Circle init:\t"
				  << "radius -> " << *radius_
				  << "]\n";
	}

	Circle::Circle(double radius)
		: radius_(new double(radius))
	{
		std::cout << "[Circle init:\t"
				  << "radius -> " << *radius_
				  << "]\n";
	}


	Circle::~Circle()
	{
		std::cout << "[Remove:\tCircle]\n";
		delete(radius_);
	}

	constexpr double pi = 3.14159265358979323846;

	double Circle::calcArea() const
	{
		return pi * (*radius_) * (*radius_);
	}


//	Rectangle
	Rectangle::Rectangle()
		: width_(new double(0.1)), length_(new double(0.1))
	{
		std::cout << "[Rectangle init:\t"
				  << "width -> " << *width_ << ", "
				  << "length -> " << *length_
				  << "]\n";
	}

	Rectangle::Rectangle(double width, double length)
		: width_(new double(width)), length_(new double(length))
	{
		std::cout << "[Rectangle init:\t" 
				  << "width -> " << *width_ << ", "
				  << "length -> " << *length_
				  << "]\n";
	}


	Rectangle::~Rectangle()
	{
		std::cout << "[Remove:\tRectangle]\n";
		delete(width_);
		delete(length_);
	}

	double Rectangle::calcArea() const
	{
		return (*width_) * (*length_);
	}



