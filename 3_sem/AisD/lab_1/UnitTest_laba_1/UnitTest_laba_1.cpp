#include "pch.h"
#include "CppUnitTest.h"
#include "..\First_step_of_evolution\Method.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(FunctionTests) {
public:
	TEST_METHOD(list_is_empty) {
		List list;
		Assert::IsTrue(list.isEmpty());
	}
	TEST_METHOD(list_is_not_empty) {
		List list(12);
		Assert::IsFalse(list.isEmpty());
	}
	TEST_METHOD(insert_in_middle) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.insert(99, 2);//12,13,99,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 99);
		Assert::AreEqual(list.at(3), 14);
		Assert::AreEqual(list.at(4), 15);
		Assert::AreEqual(list.at(5), 16);
	}
	TEST_METHOD(insert_in_head) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.insert(99, 0);//99,12,13,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 99);
		Assert::AreEqual(list.at(1), 12);
		Assert::AreEqual(list.at(2), 13);
		Assert::AreEqual(list.at(3), 14);
		Assert::AreEqual(list.at(4), 15);
		Assert::AreEqual(list.at(5), 16);
	}
	TEST_METHOD(insert_in_tail) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.insert(99, 5);//12,13,14,15,16,99
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
		Assert::AreEqual(list.at(5), 99);
		
	}
	TEST_METHOD(insert_by_not_exsist_index) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = false;
		try
		{
			list.insert(99,10000);
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(insert_in_blank_list) {
		List list;
		list.insert(99, 0);
		Assert::AreEqual(list.at(0), 99);
	}
	TEST_METHOD(remove_head) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.remove(0);//13,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 13);
		Assert::AreEqual(list.at(1), 14);
		Assert::AreEqual(list.at(2), 15);
		Assert::AreEqual(list.at(3), 16);
	}
	TEST_METHOD(remove_middle) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.remove(2);//12,13,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 15);
		Assert::AreEqual(list.at(3), 16);
	}
	TEST_METHOD(remove_tail) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.remove(4);//12,13,14,15
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
	}
	TEST_METHOD(remove_by_not_exsist_index) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = false;
		try
		{
			list.remove(10000);//12,13,14,15
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(push_front_and_push_back_blank_list) {
		List list_1;
		list_1.push_front(12);
		list_1.push_back(13);

		List list_2;
		list_2.push_back(13);
		list_2.push_front(12);

		Assert::AreEqual(list_1.at(0), 12);
		Assert::AreEqual(list_1.at(1), 13);
		Assert::AreEqual(list_2.at(0), 12);
		Assert::AreEqual(list_2.at(1), 13);
	}
	TEST_METHOD(push_front_and_push_back_not_blank_list) {
		List list_1(13);
		list_1.push_front(12);
		list_1.push_back(14);

		List list_2(13);
		list_2.push_back(14);
		list_2.push_front(12);

		Assert::AreEqual(list_1.at(0), 12);
		Assert::AreEqual(list_1.at(1), 13);
		Assert::AreEqual(list_1.at(2), 14);
		Assert::AreEqual(list_2.at(0), 12);
		Assert::AreEqual(list_2.at(1), 13);
		Assert::AreEqual(list_2.at(2), 14);
	}
	TEST_METHOD(pop_front){
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.pop_front();//13,14,15,16
		}
		catch (std::runtime_error)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 13);
		Assert::AreEqual(list.at(1), 14);
		Assert::AreEqual(list.at(2), 15);
		Assert::AreEqual(list.at(3), 16);
	}
	TEST_METHOD(pop_front_blank_list){
		List list;
		bool b = false;
		try
		{
			list.pop_front();
		}
		catch (std::runtime_error)
		{
			b = true;
		}
		Assert::IsTrue(b);
	}
	TEST_METHOD(pop_back){
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.pop_back();//12,13,14,15
		}
		catch (std::runtime_error)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
	}
	TEST_METHOD(pop_back_blank_list){
		List list;
		bool b = false;
		try
		{
			list.pop_back();
		}
		catch (std::runtime_error)
		{
			b = true;
		}
		Assert::IsTrue(b);
	}
	TEST_METHOD(at_full_list) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.at(0);
			list.at(1);
			list.at(2);
			list.at(3);
			list.at(4);//12,13,99,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(at_blank_list) {
		List list;
		bool b = false;
		try
		{
			list.at(0);
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);
	}
	TEST_METHOD(at_list_by_not_exsist_index) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = false;
		try
		{
			list.at(9999);
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(size_list) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		int size = list.get_size();
		Assert::AreEqual(size, 5);
	}
	TEST_METHOD(size_blank_list) {
		List list;

		int size = list.get_size();
		Assert::AreEqual(size, 0);
	}
	TEST_METHOD(clear_list) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		list.clear();
		Assert::IsTrue(list.isEmpty());
	}
	TEST_METHOD(set_in_middle) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.set(2, 99);//12,13,99,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);//
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 99);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);

	}
	TEST_METHOD(set_in_head) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.set(0, 99);//99,13,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);//
		Assert::AreEqual(list.at(0), 99);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(set_in_tail) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = true;
		try
		{
			list.set(4, 99);//12,13,14,15,99
		}
		catch (std::invalid_argument)
		{
			b = false;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 99);

	}
	TEST_METHOD(set_by_not_exsist_index) {
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		bool b = false;
		try
		{
			list.set(10000, 99);
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);
		Assert::AreEqual(list.at(0), 12);
		Assert::AreEqual(list.at(1), 13);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 15);
		Assert::AreEqual(list.at(4), 16);
	}
	TEST_METHOD(set_in_blank_list) {
		List list;
		bool b = false;
		try
		{
			list.set(0, 99);//99,13,14,15,16
		}
		catch (std::invalid_argument)
		{
			b = true;
		}
		Assert::IsTrue(b);//
	}

	TEST_METHOD(reverse_normal_list){
		List list(12);
		for (int index = 0; index < 4; index++) {//12,13,14,15,16
			list.push_back(13 + index);
		}
		list.reverse(); //16, 15, 14, 13, 12
		Assert::AreEqual(list.at(0), 16);
		Assert::AreEqual(list.at(1), 15);
		Assert::AreEqual(list.at(2), 14);
		Assert::AreEqual(list.at(3), 13);
		Assert::AreEqual(list.at(4), 12);
	}

	TEST_METHOD(reverse_blank_list) {
		List list;
		list.reverse();
		Assert::IsTrue(list.isEmpty());
	}

	TEST_METHOD(reverse_small_list) {
		List list(12);
		list.reverse();
		Assert::AreEqual(list.at(0), 12);
	}
};
