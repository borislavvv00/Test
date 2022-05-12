#pragma once

// Customer that takes change from the cashier.
class Customer
{
private:
	double wantedChange; // Change that is wanted from the cashier.
	bool isChangeTaken;  // true if the change is taken, false if still waits for the change.

	// Generates random double variable.
	double GenerateRandomDouble(const rsize_t numberOfCharectersBeforePoint, const rsize_t numberOfCharectersAfterPoint);

	// Calculats the wanted change.
	void CalculetWantedChange();

public:

	Customer()
	{
		wantedChange = 0.0;
		isChangeTaken = false;
	}

	// Gets the wanted change from the customer.
	double GetWantedChange();
};