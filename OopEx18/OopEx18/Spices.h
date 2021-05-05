#pragma once
#include "Ingredient.h"

using namespace std;

class Spices :public Ingredient {
	string _spices_form;
public:
	Spices(const size_t id, const string& name, const double fats, const double protein, const double carbohydrates, const int kcal, const string& spices_form) 
		:Ingredient(id,name, fats, protein, carbohydrates, kcal) {
		setSpicesForm(spices_form);
	}

	string getSpicesForm()const {
		return _spices_form;
	}

	void setSpicesForm(const string& spices_form) {
		if (spices_form.empty()) throw NullException("Cheese country is Null", __LINE__, "Ex18.cpp", __TIME__);
		_spices_form = spices_form;
	}

	void showIngredient() override {
		Ingredient::showIngredient();
		cout << "Spices form (powder,herb and so on): " << getSpicesForm() << endl;
	}



};