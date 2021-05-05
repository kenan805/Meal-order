#pragma once
#include "Meal.h"

class Soup :public Meal {
public:
	Soup(const size_t id, const string& name) :Meal(id, name)
	{

	}

	void printRecipe()override {
		cout << "\nMeal name:" << getName() << endl;
		Meal::printRecipe();
	}
};