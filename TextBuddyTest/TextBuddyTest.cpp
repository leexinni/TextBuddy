#include "stdafx.h"
#include "CppUnitTest.h"
#include "TextBuddy.h"
#include "TextBuddy.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddyTest
{		
	TEST_CLASS(TextBuddyTest)
	{
	public:
		
		TEST_METHOD(AddTest)
		{
			// TODO: Your test code here
			TextBuddy test("test.txt");
			Assert::AreEqual(0, test.getNumOfLines());

			test.addToFile("hello");
			string expected = "\n1. hello\n";
			Assert::AreEqual(expected, test.display());
		}
		TEST_METHOD(DisplayTest)
		{
			TextBuddy test("test.txt");
			test.addToFile("apple");
			test.addToFile("cricket");
			test.addToFile("baby");

			string expected = "\n1. apple\n\n2. cricket\n\n3. baby\n";
			Assert::AreEqual(expected, test.display());
			
		}
		TEST_METHOD(SortTest)
		{
			TextBuddy test("test.txt");
			test.addToFile("apple");
			test.addToFile("cricket");
			test.addToFile("baby");
			string expected = "\n1. apple\n\n2. cricket\n\n3. baby\n";
			Assert::AreEqual(expected, test.display());

			test.sort();

			expected = "\n1. apple\n\n2. baby\n\n3. cricket\n";
			Assert::AreEqual(expected, test.display());
		}
		TEST_METHOD(SearchTest)
		{
			TextBuddy test("test.txt");
			test.addToFile("lisa likes to dance");
			test.addToFile("i love to dance");
			test.addToFile("lisa has a hat");

			string expected = "\n1. lisa likes to dance\n\n3. lisa has a hat\n";
			Assert::AreEqual(expected, test.search("lisa"));
		}
	};
}