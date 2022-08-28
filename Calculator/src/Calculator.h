#pragma 
#include <string>
#include <vector>
#include <imgui/imgui.h>

// Calculator data api
class CalculatorData
{
public:
	CalculatorData();
	std::string& GetCalculationString();
	std::string& GetResultString();
	void AppendDigit(int);
	void SetOperation(const char*);
	void PerformOperation();


private:
	double		number,
				result;
	int8_t		op;
	bool		numberIsFloat;
	std::string	sCalculation,
				sNumber;
	std::vector<std::string> operations;
};




// Calculator Display
class Calculator
{
public:
	Calculator();
	void Render();
private:
	void DisplayDigitButton(const char*);
	void DisplayUnaryOperatorButton(const char*);
	void DisplayBinaryOperatorButton(const char*);
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
