#include "stock00.h"
#include <iostream>

Stock::Stock()
{
	std::cout << "Wywolano konstruktor domyslny\n";
	company = "bez nazwy";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const std::string& co, long n, double pr)
{
	std::cout << "Wywolano konstruktor z argumentem " << co << "\n";
	company = co;
	if (n < 0)
	{
		std::cout << " Liczba udzialow nie moze byc ujemna.";
		std::cout << "ustalam liczbe udzialow w " << company << " na 0 \n";
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock() {
	std::cout << "Do widzenia, " << company << std::endl;
}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "liczba nabywanych udzialow nie moze byc ujemna. " << std::endl;
		std::cout << "przerwane" << std::endl;
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	using std::cout;
	if (num > 0)
	{
		cout << "liczba sprzedawanych udzialow nie moze byc ujemna. ";
		cout << "transakcja przerwana;" << std::endl;
	}
	else if (num > shares )
	{
		cout << "nie mozesz sprzedac wiecej udzialow niz posiadasz " << "transakcja przerwana";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);


	std::cout << "Społka" << company << " Liczba udzialow : " << shares << std::endl;

	cout.precision(2);
	std::cout << "cena udzialu: " << share_val<< " Laczna wartos udzialow : " << total_val<<" zl"<< std::endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
