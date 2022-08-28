#pragma 
#include <string>
#include <vector>
#include <imgui/imgui.h>

// Calculator data and methods
class CalculatorData
{
public:
	CalculatorData();
	std::string& GetCalculationString();
	std::string& GetResultString();
	void UpdateNumber(int);
	void Operation();

private:
	std::string	sCalculation,
				sNumber,
				binaryOperator;

	double		number,
				result;
	bool numberIsFloat;
};




// Calculator Displayer
class Calculator
{
public:
	Calculator();
	void Render();
private:
	void DisplayDigitButton(const char*);
	void DisplayOperatorButton(const char*);
	void DisplayDigitsGroup();
	void DisplayOperatorGroup1();
	void DisplayOperatorGroup2();
	void DisplayCurrentCalculation();
	void DisplayResult();
private:
	CalculatorData	data;
	ImVec2			regionAvail;
	ImVec2			buttonSize;
	int				btnsPerRow;
};
