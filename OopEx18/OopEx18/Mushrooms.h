#pragma once
#include "Ingredient.h"

using namespace std;

class Mushrooms :public Ingredient {
	string _country;
public:
	Mushrooms(const size_t id, const string& name, const double fats, const double protein, const double carbohydrates, const int kcal, const string& country) 
		:Ingredient(id,name, fats, protein, carbohydrates, kcal) {
		setCountry(country);
	}

	string getCountry()const {
		return _country;
	}

	void setCountry(const string& country) {
		if (country.empty()) throw NullException("Country is Null", __LINE__, "Ex18.cpp", __TIME__);
		_country = country;
	}

	void showIngredient() override {
		Ingredient::showIngredient();
		cout << "Mushroom country: " << getCountry() << endl;
	}

};