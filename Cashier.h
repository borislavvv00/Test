#pragma once

// Cashier who returns the change and count the money at the end of the day.
class Cashier
{
private:
	double money;               // Money in the cash register.
	size_t value_10_Stotinki;   // Number of coins with value of 10 stotinki.
	size_t value_20_Stotinki;   // Number of coins with value of 20 stotinki.
	size_t value_50_Stotinki;   // Number of coins with value of 50 stotinki.
	size_t value_1_Leva;        // Number of coins with value of 1 lv.
	size_t value_2_Leva;        // Number of coins with value of 2 lv.
	size_t value_5_Leva;        // Number of banknotes with value of 5 lv.
	size_t value_10_Leva;       // Number of banknotes with value of 10 lv.
	size_t value_20_Leva;       // Number of banknotes with value of 20 lv.
	size_t value_50_Leva;       // Number of banknotes with value of 50 lv.
	size_t value_100_Leva;      // Number of banknotes with value of 100 lv.

	// Calculates banknote or coin to be returned.
	bool CalculateValue(double &change, size_t &currency, double value);

public:

	Cashier()
	{
		money = 0.0;
	}

	// Sets number of 10 Stotinki coins.
	void SetNumberOf_10_StotinkiCoins(const size_t number);

	// Sets number of 20 Stotinki coins.
	void SetNumberOf_20_StotinkiCoins(const size_t number);

	// Sets number of 50 Stotinki coins.
	void SetNumberOf_50_StotinkiCoins(const size_t number);

	// Sets number of 1 Leva coins.
	void SetNumberOf_1_LevaCoins(const size_t number);

	// Sets number of 2 Leva coins.
	void SetNumberOf_2_LevaCoins(const size_t number);

	// Sets number of 5 Leva banknotes.
	void SetNumberOf_5_LevaBanknotes(const size_t number);

	// Sets number of 10 Leva banknotes.
	void SetNumberOf_10_LevaBanknotes(const size_t number);

	// Sets number of 20 Leva banknotes.
	void SetNumberOf_20_LevaBanknotes(const size_t number);

	// Sets number of 50 Leva banknotes.
	void SetNumberOf_50_LevaBanknotes(const size_t number);

	// Sets number of 100 Leva banknotes.
	void SetNumberOf_100_LevaBanknotes(const size_t number);

	// Gets the full amount of money in the cash register.
	double GetMoney();

	// Calculates the needed change to return to the customer.
	bool IsChangeReady(const double neededChange);
};