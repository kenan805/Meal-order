#pragma once
#include "Meal.h"

class Kebab :public Meal {
	string _cooking_rate;
public:
	Kebab(const size_t id, const string& name, const string& cooking_rate) :Meal(id, name)
	{
		setCookingRate(cooking_rate);
	}

	string getCookingRate()const {
		return _cooking_rate;
	}

	void setCookingRate(const string& cooking_rate) {
		if (cooking_rate.empty()) throw NullException("Cooking rate is Null", __LINE__, "Ex18.cpp", __TIME__);
		_cooking_rate = cooking_rate;
	}

	void printRecipe()override {
		cout << "\nMeal name:" << getName() << endl;
		cout << "Kebab cooking rate:" << getCookingRate() << endl << endl;
		Meal::printRecipe();
	}
};