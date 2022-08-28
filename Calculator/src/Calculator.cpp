#include "Calculator.h"
#include <iostream>
#include <algorithm>

CalculatorData::CalculatorData()
{
	sCalculation = "";
	sNumber = "0";
	number = 0;
	result = 0;
	operations =	 {	
						"+/-", 
						".", 
						"%", 
						"C", 
						"CE", 
						"DEL", 
						"1/x", 
						"x^2", 
						"sqrt", 
						"/", 
						"x", 
						"-", 
						"+", 
						"="
					};
}

std::string& CalculatorData::GetCalculationString()
{
	return sCalculation;
}

std::string& CalculatorData::GetResultString()
{
	return sNumber;
}

void CalculatorData::AppendDigit(int digit)
{
	number *= 10;
	number += digit;

	sNumber = std::to_string(number);
}

void CalculatorData::SetOperation(const char* c)
{
	auto pos = std::find(operations.begin(), operations.end(), c);
	if (pos == operations.end()) std::cout << "Fix Operation Vec";
	op = pos - operations.begin();
}

void CalculatorData::PerformOperation()
{
	switch (op) {
		case 0:
			number = -number;
			sNumber = std::to_string(number);
			break;
		case 1:
			break;
		case 2:
			number /= 100;
			sNumber = std::to_string(number) + std::string("%");
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		default:
			break;


	}
}


Calculator::Calculator()
{
	btnsPerRow = 4;
}

void Calculator::Render()
{
	ImGuiStyle& style = ImGui::GetStyle();;

	// Initialize ImGui Window
	ImGui::Begin("Calculator");

	// Style
	regionAvail = ImGui::GetContentRegionAvail();
	buttonSize.x = (regionAvail.x * (0.25f)) - (style.ItemSpacing.x * (btnsPerRow - 1) / btnsPerRow);
	buttonSize.y = regionAvail.y * 0.12f;

	// Display Calculation and Result STRINGS
	DisplayCurrentCalculation();
	DisplayResult();

	// Display Buttons
	DisplayOperatorGroup1();
	DisplayDigitsGroup();
	DisplayOperatorGroup2();

	ImGui::End();
}

void Calculator::DisplayCurrentCalculation()
{
	ImGui::Text(data.GetCalculationString().c_str());
}

void Calculator::DisplayResult()
{
	ImGui::Text(data.GetResultString().c_str());
}

void Calculator::DisplayDigitButton(const char* c)
{
	if (ImGui::Button(c, buttonSize))
	{
		data.AppendDigit((int)c[0]-48);
	}
}

void Calculator::DisplayUnaryOperatorButton(const char* c)
{
	if (ImGui::Button(c, buttonSize))
	{
		data.SetOperation(c);
		data.PerformOperation();
	}
}

void Calculator::DisplayBinaryOperatorButton(const char* c)
{
	if (ImGui::Button(c, buttonSize))
	{
		data.SetOperation(c);
	}
}


void Calculator::DisplayDigitsGroup()
{
	ImGui::BeginGroup();

	// Row 1
	ImGui::BeginGroup();
	DisplayDigitButton("7");
	ImGui::SameLine();
	DisplayDigitButton("8");
	ImGui::SameLine();
	DisplayDigitButton("9");
	ImGui::EndGroup();

	// Row 2
	ImGui::BeginGroup();
	DisplayDigitButton("4");
	ImGui::SameLine();
	DisplayDigitButton("5");
	ImGui::SameLine();
	DisplayDigitButton("6");
	ImGui::EndGroup();

	// Row 3
	ImGui::BeginGroup();
	DisplayDigitButton("1");
	ImGui::SameLine();
	DisplayDigitButton("2");
	ImGui::SameLine();
	DisplayDigitButton("3");
	ImGui::EndGroup();

	// Row 4
	ImGui::BeginGroup();
	DisplayUnaryOperatorButton("+/-");
	ImGui::SameLine();
	DisplayDigitButton("0");
	ImGui::SameLine();
	DisplayUnaryOperatorButton(".");
	ImGui::EndGroup();

	ImGui::EndGroup();
	ImGui::SameLine();

}

void Calculator::DisplayOperatorGroup1()
{
	ImGui::BeginGroup();

	// Row 1
	ImGui::BeginGroup();
	DisplayUnaryOperatorButton("%");
	ImGui::SameLine();
	DisplayUnaryOperatorButton("CE");
	ImGui::SameLine();
	DisplayUnaryOperatorButton("C");
	ImGui::SameLine();
	DisplayUnaryOperatorButton("DEL");
	ImGui::EndGroup();

	// Row 2
	ImGui::BeginGroup();
	DisplayUnaryOperatorButton("1/x");
	ImGui::SameLine();
	DisplayUnaryOperatorButton("x^2");
	ImGui::SameLine();
	DisplayUnaryOperatorButton("sqrt");
	ImGui::SameLine();
	DisplayBinaryOperatorButton("/");
	ImGui::EndGroup();

	ImGui::EndGroup();
}

void Calculator::DisplayOperatorGroup2()
{
	ImGui::BeginGroup();
	DisplayBinaryOperatorButton("x");
	DisplayBinaryOperatorButton("-");
	DisplayBinaryOperatorButton("+");
	DisplayUnaryOperatorButton("=");
	ImGui::EndGroup();
}

