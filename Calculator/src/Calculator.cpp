#include "Calculator.h"
#include <iostream>

CalculatorData::CalculatorData()
{
	sCalculation = "";
	sNumber = "0";
	number = 0;
	result = 0;
}

std::string& CalculatorData::GetCalculationString()
{
	return sCalculation;
}

std::string& CalculatorData::GetResultString()
{
	return sNumber;
}

void CalculatorData::UpdateNumber(int digit)
{
	number *= 10;
	number += digit;

	sNumber = std::to_string(number);
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
		data.UpdateNumber((int)c[0]-48);
	}
}

void Calculator::DisplayOperatorButton(const char* c)
{
	if (ImGui::Button(c, buttonSize))
	{

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
	DisplayOperatorButton("+/-");
	ImGui::SameLine();
	DisplayDigitButton("0");
	ImGui::SameLine();
	DisplayOperatorButton(".");
	ImGui::EndGroup();

	ImGui::EndGroup();
	ImGui::SameLine();

}

void Calculator::DisplayOperatorGroup1()
{
	ImGui::BeginGroup();

	// Row 1
	ImGui::BeginGroup();
	DisplayOperatorButton("%");
	ImGui::SameLine();
	DisplayOperatorButton("CE");
	ImGui::SameLine();
	DisplayOperatorButton("C");
	ImGui::SameLine();
	DisplayOperatorButton("DEL");
	ImGui::EndGroup();

	// Row 2
	ImGui::BeginGroup();
	DisplayOperatorButton("1/x");
	ImGui::SameLine();
	DisplayOperatorButton("x^2");
	ImGui::SameLine();
	DisplayOperatorButton("sqrt");
	ImGui::SameLine();
	DisplayOperatorButton("%");
	ImGui::EndGroup();

	ImGui::EndGroup();
}

void Calculator::DisplayOperatorGroup2()
{
	ImGui::BeginGroup();
	DisplayOperatorButton("x");
	DisplayOperatorButton("-");
	DisplayOperatorButton("+");
	DisplayOperatorButton("=");
	ImGui::EndGroup();
}

