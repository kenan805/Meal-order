#pragma once
#include "Ingredient.h"

struct RecipetItem {
	Ingredient* ingredient; //one object
	int amount;

	RecipetItem(Ingredient& ingredient, const int amount)
	{
		setIngredient(ingredient);
		setAmount(amount);
	}

	Ingredient& getIngredient()const {
		return *ingredient;
	}
	int getAmount()const {
		return amount;
	}

	void setIngredient(Ingredient& ingredient) {
		if(&ingredient==NULL) throw NullException("Ingredient is Null", __LINE__, "Ex18.cpp", __TIME__);
		this->ingredient = &ingredient;
	}
	void setAmount(const int amount) {
		if(amount<0)throw InvalidArgumentException("The amount can't be negative", __LINE__, "Ex18.cpp", __TIME__);
		this->amount = amount;
	}
};