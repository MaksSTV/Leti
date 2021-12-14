#include "pch.h"
#include "CppUnitTest.h"
#include "../Eternal_despair_anti_social/Functions.h"
#include "../Eternal_despair_anti_social/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(General_inspection_1)
		{
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(-e + -5) + (4 + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512
			std::string str2 = "(sqrt(4.5) - cbrt(45)) * (ctg(45) + tg(45)) - (5.5 - 88) - (cos(45) + sin(45)) - (ln(45) + log(45)) + (pi + e)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);
			

			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}
			//+ + -e -5 + 4 5
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '5');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '4'); 
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '+');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '-'); Assert::AreEqual(temp[1], '5');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '-'); Assert::AreEqual(temp[1], 'e');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '+');
			calculation.pop(); 
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '+');
		}
		TEST_METHOD(General_inspection_2)
		{
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(sqrt(4.5) - cbrt(45))"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512
			std::string str2 = "(sqrt(4.5) - cbrt(45)) * (ctg(45) + tg(45)) - (5.5 - 88) - (cos(45) + sin(45)) - (ln(45) + log(45)) + (pi + e)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}
			//- sqrt(4.5) cbrt(45)
			temp = calculation.peek();
			Assert::AreEqual(temp[0], 'c');
			Assert::AreEqual(temp[1], 'b');
			Assert::AreEqual(temp[2], 'r');
			Assert::AreEqual(temp[3], 't');
			Assert::AreEqual(temp[4], '(');
			Assert::AreEqual(temp[5], '4');
			Assert::AreEqual(temp[6], '5');
			Assert::AreEqual(temp[7], ')');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], 's');
			Assert::AreEqual(temp[1], 'q');
			Assert::AreEqual(temp[2], 'r');
			Assert::AreEqual(temp[3], 't');
			Assert::AreEqual(temp[4], '(');
			Assert::AreEqual(temp[5], '4');
			Assert::AreEqual(temp[6], '.');
			Assert::AreEqual(temp[7], '5');
			Assert::AreEqual(temp[8], ')');
			calculation.pop();
			temp = calculation.peek();
			Assert::AreEqual(temp[0], '-');
			
		}

		TEST_METHOD(Test_of_calculation_1)
		{
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "5 + 13 - 10"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512
			std::string str2 = "(sqrt(4.5) - cbrt(45)) * (ctg(45) + tg(45)) - (5.5 - 88) - (cos(45) + sin(45)) - (ln(45) + log(45)) + (pi + e)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation_1;
			Stack<std::string> calculation_2;

			while (!prefix.isEmpty()) {
				calculation_1.push(prefix.peek());
				calculation_2.push(prefix.peek());
				prefix.pop();
			}
			//+ 5 - 13 10  --> 8
			temp = calculation_1.peek();
			Assert::AreEqual(temp[0], '1');
			Assert::AreEqual(temp[1], '0');
			calculation_1.pop();

			temp = calculation_1.peek();
			Assert::AreEqual(temp[0], '1');
			Assert::AreEqual(temp[1], '3');
			calculation_1.pop();

			temp = calculation_1.peek();
			Assert::AreEqual(temp[0], '-');
			calculation_1.pop();

			temp = calculation_1.peek();
			Assert::AreEqual(temp[0], '5');
			calculation_1.pop();

			temp = calculation_1.peek();
			Assert::AreEqual(temp[0], '+');

			double x;

			x = calculation_in_prefix_form(calculation_2);

			Assert::AreEqual(x, 8.0);
		}

		TEST_METHOD(Test_of_calculation_2)
		{
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(sqrt(4.5) + -sqrt(4.5))"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512	

			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			double x;

			x = calculation_in_prefix_form(calculation);

			Assert::AreEqual(x, 0.0);
			
		}

		TEST_METHOD(Test_of_calculation_3)
		{
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(sqrt(4.5) - cbrt(45)) * (ctg(45) + tg(45)) - (5.5 - 88) - (cos(45) + sin(45)) - (ln(45) + log(45)) + (pi + e)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}
			
			double x;

			x = calculation_in_prefix_form(calculation);

			bool approx = 0;
			if (x - 69.7252 <= 0.0001) {
				approx = 1;
			}
			Assert::IsTrue(approx);

		}

		TEST_METHOD(Parenthesis_check_lose) {
			
			std::string str1 = "(10 + 40)) + (10 + 40)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Bad
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsFalse(b);
		}

		TEST_METHOD(ctg_180deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ctg(180) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}
	
			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);
			
		}

		TEST_METHOD(ctg_360deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ctg(180) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(ctg_540deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ctg(180) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(ctg_720deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ctg(180) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(tan_90deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(tg(90) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(tan_270deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(tg(90) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}
		
		TEST_METHOD(tan_450deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(tg(90) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}
		
		TEST_METHOD(tan_630deg_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(tg(90) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::invalid_argument)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(ln_0_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ln(0) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(ln_negative10_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(ln(-10) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(log_0_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(log(0) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}
		
		TEST_METHOD(log_negative10_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(log(-10) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(sqrt_negative_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(sqrt(-10) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}

		TEST_METHOD(cbrt_negative_not_exists) {
			Stack<std::string> stack;
			std::string temp;
			std::string temp_parenthesis;
			Stack<std::string> prefix;
			Stack<std::string> buffer; // (cos(45) + sin(45))
			std::string str1 = "(cbrt(-10) + 5)"; // "123 + (12 - 13.5) / (15 - 12)"; // +123/-1213.5-1512


			bool b = true;
			try
			{
				parenthesis_check(str1); // Good
			}
			catch (std::runtime_error)
			{
				b = false;
			}
			Assert::IsTrue(b);


			convert_string_to_stack(str1, stack);
			convert_infix_to_prefix(stack, prefix, buffer);


			Stack<std::string> calculation;

			while (!prefix.isEmpty()) {
				calculation.push(prefix.peek());
				prefix.pop();
			}

			b = true;
			try
			{
				calculation_in_prefix_form(calculation); // Bad
			}
			catch (std::underflow_error)
			{
				b = false;
			}
			Assert::IsFalse(b);

		}
		
		
	};
}
