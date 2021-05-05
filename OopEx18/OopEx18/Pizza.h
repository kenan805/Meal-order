#pragma once
#include "Meal.h"

class Pizza :public Meal {
	string _pizza_size;
public:
	Pizza(const size_t id, const string& name, const string& pizza_size) :Meal(id,name)
	{
		setPizzaSize(pizza_size);
	}

	string getPizzaSize()const {
		return _pizza_size;
	}

	void setPizzaSize(const string& pizza_size) {
		if (pizza_size.empty()) throw NullException("Pizza size is Null", __LINE__, "Ex18.cpp", __TIME__);
		_pizza_size = pizza_size;
	}

	void printRecipe()override {
		cout << "\nMeal name:" << getName() << endl;
		cout << "Pizza size: " << getPizzaSize() << endl << endl;
		Meal::printRecipe();
	}
};