#include "pch.h"
#include "gtest\gtest.h"
#include <string>

std::string EquationSystem(const double& a, const double& b, const double& c, const double& d, const double& e, const double& f)
{
	std::string Solution;
	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		Solution += '5';
	}
	else if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		double y = (a * f - c * e) / (a * d - c * b);
		double x = (d * e - b * f) / (d * a - b * c);
		Solution += "2 " + std::to_string(x) + ' ' + std::to_string(y);
	}
	else if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
	{
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{
			double y;
			if (b == 0)
				y = f / d;
			else if (d == 0)
				y = e / b;
			else if (e == 0 || f == 0)
				y = 0;
			Solution += "4 " + std::to_string(y);
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x;
			if (a == 0)
				x = f / c;
			else if (c == 0)
				x = e / a;
			else if (e == 0 || f == 0)
				x = 0;
			Solution += "3 " + std::to_string(x);
		}
		else
			Solution += "0";
	}
	else if (a == 0 && c == 0)
	{
		double y;
		if (e == 0)
			y = f / d;
		else if (f == 0)
			y = e / b;	
		else
			y = e / b;
		Solution += "4 " + std::to_string(y);
	}
	else if (b == 0 && d == 0)
	{
		double x;
		if (e == 0)
			x = f / c;
		else if (f == 0)
			x = e / a;	
		else
			x = e / a;
		Solution += "3 " + std::to_string(x);
	}
	else if (b == 0 && e == 0)
	{
		double k, n;
		k = -c / d;
		n = f / d;
		Solution += "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (d == 0 && f == 0)
	{
		double k, n;
		k = -a / b;
		n = e / b;
		Solution += "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (a == 0 && e == 0)
	{
		double k, n;
		k = -d / c;
		n = f / c;
		Solution += "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if (c == 0 && f == 0)
	{
		double k, n;
		k = -b / a;
		n = e / a;
		Solution += "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else if ((a / b == c / d))
	{
		double k, n;
		k = -c / d;
		n = f / d;
		Solution += "1 " + std::to_string(k) + " " + std::to_string(n);
	}
	else
	{
		Solution += "Are you kidding me?";
	}
	return Solution;
}
TEST(FirstCondition, InfiniteSolutions) {
	EXPECT_EQ(EquationSystem(0, 0, 0, 0, 0, 0),std::string("5"));
}

TEST(SecondCondition,  OnlyOneSolution) {
	EXPECT_EQ(EquationSystem(10, 0, 10, 1, 2, 3), std::string("2 0.200000 1.000000"));
}

TEST(SecondCondition, OnlyOneSolution1) {
	EXPECT_EQ(EquationSystem(10, 0, 10, 1, 2, 3), std::string("2 0.200000 1.000000"));
}

TEST(ThirdCondition, InfiniteSolutions) {
	EXPECT_EQ(EquationSystem(0, 2, 0, 2, 1, 0), std::to_string(0));
}

TEST(ThirdCondition, InfiniteSolutions1) {
	EXPECT_EQ(EquationSystem(2, 0, 2, 0, 0, 1), std::to_string(0));
}

TEST(ThirdCondition, InfiniteWithYAnswer) {
	EXPECT_EQ(EquationSystem(0, 0, 0, 2, 0, 5), std::string("4 2.500000"));
}

TEST(ThirdCondition, InfiniteWithYAnswer1) {
	EXPECT_EQ(EquationSystem(0, 2, 0, 0, 5, 0), std::string("4 2.500000"));
}

TEST(ThirdCondition, InfinteWithYAnswer2) {
	EXPECT_EQ(EquationSystem(0, 2, 0, 0, 0, 0), std::string("4 0.000000"));
}

TEST(ThirdCondition, InfiniteWithXAnswer) {
	EXPECT_EQ(EquationSystem(0, 0, 2, 0, 0, 5), std::string("3 2.500000"));
}

TEST(ThirdCondition, InfiniteWithXAnswer1) {
	EXPECT_EQ(EquationSystem(2, 0, 0, 0, 5, 0), std::string("3 2.500000"));
}

TEST(ThirdCondition, InfiniteWithXAnswer2) {
	EXPECT_EQ(EquationSystem(2, 0, 0, 0, 0, 0), std::string("3 0.000000"));
}

TEST(FourthCondition, InfinteWithYAnswer3) {
	EXPECT_EQ(EquationSystem(0, 2, 0, 3, 0, 0),std::string("4 0.000000"));
}

TEST(FourthCondition, InfinteWithYAnswer4) {
	EXPECT_EQ(EquationSystem(0, 3, 0, 3, 1, 1), std::string("4 0.333333"));
}

TEST(FifthCondition, InfiniteWithXAnswer3) {
	EXPECT_EQ(EquationSystem(3, 0, 3, 0, 0, 0), std::string("3 0.000000"));
}

TEST(FifthCondition, InfiniteWithXAnswer4) {
	EXPECT_EQ(EquationSystem(3, 0, 3, 0, 1, 1), std::string("3 0.333333"));
}

TEST(SixthCondition, InfiniteKN) {
	EXPECT_EQ(EquationSystem(3, 0, 3, 3, 0, 0), std::string("1 -1.000000 0.000000"));
}

TEST(SeventhCondition, InfiniteKN) {
	EXPECT_EQ(EquationSystem(3, 3, 3, 0, 0, 0), std::string("1 -1.000000 0.000000"));
}

TEST(EighthCondition, InfiniteKN) {
	EXPECT_EQ(EquationSystem(0, 3, 3, 3, 0, 0), std::string("1 -1.000000 0.000000"));
}

TEST(NinthCondition, InfiniteKN) {
	EXPECT_EQ(EquationSystem(3, 3, 0, 3, 0, 0), std::string("1 -1.000000 0.000000"));
}

TEST(LastCondition, Are_you_kidding_me) {
	EXPECT_EQ(EquationSystem(1, -1, 1, 1, 0, 0), std::string("Are you kidding me?"));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	
}