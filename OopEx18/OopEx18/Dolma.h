#pragma once
#include "Meal.h"

class Dolma :public Meal {
public:
	Dolma(const size_t id, const string& name) :Meal(id, name)
	{

	}

	void printRecipe()override {
		cout << "\nMeal name:" << getName() << endl << endl;
		Meal::printRecipe();
	}
};