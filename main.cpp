#include <iostream>
#include <time.h>
#include "Cashier.h"
#include "Customer.h"




int main()
{
	srand(time(NULL));

	Cashier cashier;
	Customer custormer;
	double change = 0.0;
	bool isChangeReady = false;

	cashier.SetNumberOf_100_LevaBanknotes(10u);
	cashier.SetNumberOf_50_LevaBanknotes(10u);
	cashier.SetNumberOf_20_LevaBanknotes(10u);
	cashier.SetNumberOf_10_LevaBanknotes(10u);
	cashier.SetNumberOf_5_LevaBanknotes(10u);
	cashier.SetNumberOf_2_LevaCoins(10u);
	cashier.SetNumberOf_1_LevaCoins(10u);
	cashier.SetNumberOf_50_StotinkiCoins(10u);
	cashier.SetNumberOf_20_StotinkiCoins(10u);
	cashier.SetNumberOf_10_StotinkiCoins(10u);

	for (size_t i = 0u; i < 1u; i++)
	{
		change = custormer.GetWantedChange();

		std::cout << "Wanted change = " << change << std::endl;

		do
		{
			std::cout << "Waiting for change!" << std::endl;
			std::cout << "Money in cach register = " << cashier.GetMoney() << std::endl;
			isChangeReady = cashier.IsChangeReady(change);
		} while (false == isChangeReady);

		std::cout << "Change is ready!" << std::endl;
		std::cout << "Money in cach register = " << cashier.GetMoney() << std::endl;
	}
	return 0;
}