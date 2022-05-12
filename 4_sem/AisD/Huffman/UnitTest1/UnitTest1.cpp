#include "pch.h"
#include "CppUnitTest.h"

#include "../Huffman/HuffmanCode.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(HuffmanTest1)
		{
			std::string sourceString = "it is test string";
			HuffCode huffString = HuffCode(sourceString);
			Assert::IsTrue(huffString.getHuffmanTree()->getSizeTree() == 15);
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->symbol == ' ');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_right->symbol == 't');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_left->next_left->symbol == 'e');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_left->next_right->symbol == 'g');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_left->symbol == 'r');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_right->symbol == 'n');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->symbol == 'i');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_right->symbol == 's');

			Assert::IsTrue(huffString.codingSourceString() == "001101100100011100111000101100010010100101000110");
			Assert::IsTrue(huffString.decodingEncodedString() == sourceString);

	
		}

		TEST_METHOD(HuffmanTest2)
		{
			std::string sourceString = "Take care of the person in yourself";
			HuffCode huffString = HuffCode(sourceString);
			
			Assert::IsTrue(huffString.codingSourceString() == "1001111011000001000010010110111101000000101100000011101000101000001111010111101000101011000011011011000011000010001101111010010001111100");
			Assert::IsTrue(huffString.decodingEncodedString() == sourceString);


		}

		TEST_METHOD(HuffmanTest3)
		{
			std::string sourceString = "A person must dream in order to see the meaning of life";
			HuffCode huffString = HuffCode(sourceString);
			Assert::IsTrue(huffString.codingSourceString() == "0001001100010101100111010010001011110010000101010100011001010011011001001001111011010111010000110010101100111110000100111010011011111000000001011111001011001000101101101010000111101000001111000000101100011011");
			Assert::IsTrue(huffString.decodingEncodedString() == sourceString);


		}

		TEST_METHOD(HuffmanTest4)
		{
			std::string sourceString = "it is test string number four";
			HuffCode huffString = HuffCode(sourceString);
			Assert::IsTrue(huffString.getHuffmanTree()->getSizeTree() == 25);
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->next_left->symbol == 'i');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->next_right->symbol == 's');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_right->next_right->next_left->symbol == 'o');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_right->next_right->next_right->symbol == 'e');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_right->next_left->symbol == 'r');

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_left->symbol == 't');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_left->symbol == 'n');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_right->symbol == 'u');

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_right->symbol == ' ');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_left->next_left->symbol == 'g');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_left->next_right->symbol == 'b');

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_right->next_left->symbol == 'f');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_right->next_right->symbol == 'm');

			Assert::IsTrue(huffString.codingSourceString() == "111011000111110000011100011001100011001110111101010011100001010100001000011010001010000010110010100101");
			Assert::IsTrue(huffString.decodingEncodedString() == sourceString);


		}

		TEST_METHOD(HuffmanTest5)
		{
			std::string sourceString = "But a bit of better butter";
			HuffCode huffString = HuffCode(sourceString);
			Assert::IsTrue(huffString.getHuffmanTree()->getSizeTree() == 21);

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->next_left->next_left->symbol == 'i');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->next_left->next_right->symbol == 'f');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_left->next_right->symbol == 'b');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_left->next_right->symbol == 't');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_left->symbol == 'e');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_left->symbol == 'o');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_left->next_right->next_right->symbol == 'u');

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_right->symbol == ' ');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_left->symbol == 'r');

			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_right->next_left->symbol == 'B');
			Assert::IsTrue(huffString.getHuffmanTree()->getRootNode()->next_right->next_right->next_left->next_right->next_right->symbol == 'a');

			Assert::IsTrue(huffString.codingSourceString() == "00101010010000001000001101111100000101111000011001110100110011000110010010100110011");
			Assert::IsTrue(huffString.decodingEncodedString() == sourceString);

		}
	};
}
