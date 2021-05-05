#pragma once
#include "Ingredient.h"

using namespace std;

class Meat :public Ingredient {
	string _meat_type;
public:
	Meat(const size_t id, const string& name, const double fats, const double protein, const double carbohydrates, const int kcal, const string& meat_type) 
		:Ingredient(id,name, fats, protein, carbohydrates, kcal) {
		setMeatType(meat_type);
	}

	string getMeatType()const {
		return _meat_type;
	}

	void setMeatType(const string& meat_type) {
		if (meat_type.empty()) throw NullException("Meat type is Null", __LINE__, "Ex18.cpp", __TIME__);
		_meat_type = meat_type;
	}

	void showIngredient() override {
		Ingredient::showIngredient();
		cout << "Meat type: " << getMeatType() << endl;
	}

};