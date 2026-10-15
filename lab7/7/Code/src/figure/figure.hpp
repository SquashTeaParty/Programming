#pragma once
#include "string"

class Figure
{

public:
	Figure() = default;
	virtual ~Figure() = default;

	virtual double calcArea() const = 0;
};

class Circle : public Figure
{
	double* radius_;

public:
	Circle();
	Circle(double);
	~Circle() override;

	double calcArea() const override;
};

class Rectangle : public Figure
{
	double* length_;
	double* width_;

public:
	Rectangle();
	Rectangle(double, double);
	~Rectangle() override;

	double calcArea() const override;
};