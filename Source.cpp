#include <string>
#include <iostream>
#include <chrono>

using namespace std;




const char* Base[4] = { "Hundred ","Thousand ", "Million ", "Billion " };
const char* Numbers[20] = { "","One ","Two ", "Three ", "Four ","Five ","Six ", "Seven ", 
"Eight ","Nine ", "Ten ", "Eleven ",
"Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", 
"Eighteen ", "Nineteen " };
const char* Numbers2[10] = { "","Onety ","Twenty ","Thirty ", "Forty ", "Fifty ","Sixty ","Seventy ", "Eighty ", "Ninety "};

void  Do100s(int num, string& ret)
{
	int Digit1 = num / 100;
	ret.append(Numbers[Digit1]);
	ret.append(Base[0]);
	int Digit2 = num - (Digit1 * 100);

	if (Digit2 < 20 && Digit2 > 9)
	{
		ret.append(Numbers[Digit2]);

	}
	else
	{
		Digit2 = Digit2 / 10;
		ret.append(Numbers2[Digit2]);
		int Digit3 = num - (Digit1 * 100) - (Digit2 * 10);
		ret.append(Numbers[Digit3]);
	}
}

void  Do10s(int num, string& ret)
{
	if (num < 20)
	{
		ret.append(Numbers[num]);
		return;
	}

	int Digit1 = num / 10;
	ret.append(Numbers2[Digit1]);
	int Digit2 = num - (Digit1 * 10);
	ret.append(Numbers[Digit2]);
}

string numberToWords(int num) 
{
	string Result;

	int Billions = ((num / 1000000000));
	int Millions = num - (Billions * 1000000000);
	Millions = Millions / 1000000;
	int Thousands = num - (Billions * 1000000000) - (Millions * 1000000);
	Thousands = Thousands / 1000;
	int Hundreds = num - (Billions * 1000000000) - (Millions * 1000000) - (Thousands * 1000);
	Hundreds /= 100;
	int Tens = num - (Billions * 1000000000) - (Millions * 1000000) - (Thousands * 1000) - (Hundreds * 100);
	if (num == 0)
	{
		return "Zero";
	}

	if (Billions > 0)
	{
		Result.append(Numbers[Billions]);
		Result.append(Base[3]);
	}

	if (Millions > 0)
	{
		if (Millions > 99)
		{
			Do100s(Millions, Result);
		}
		else if(Millions < 10)
		{
			Result.append(Numbers[Millions]);
		}
		else// 10 - 99
		{
			Do10s(Millions, Result);
		}
		Result.append(Base[2]);
	}

	if (Thousands > 0)
	{
		if (Thousands > 99)
		{
			Do100s(Thousands, Result);
		}
		else if (Thousands < 10)
		{
			Result.append(Numbers[Thousands]);
		}
		else// 10 - 99
		{
			Do10s(Thousands, Result);
		}

		Result.append(Base[1]);
	}

	if (Hundreds > 0)
	{
		if (Hundreds > 99)
		{
			Do100s(Hundreds, Result);
		}
		else if (Hundreds < 10)
		{
			Result.append(Numbers[Hundreds]);
		}
		else// 10 - 99
		{
			Do10s(Hundreds, Result);
		}

		Result.append(Base[0]);
	}

	if (Tens > 0)
	{
		if (Tens < 10)
		{
			Result.append(Numbers[Tens]);
		}
		else// 10 - 99
		{
			Do10s(Tens, Result);
		}
	}

	Result.pop_back();
	return Result;
}

int main()
{
	int x = 5;
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	string s = numberToWords(2147483646);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << "[ms]" << endl;


	cout << s << endl ;
}