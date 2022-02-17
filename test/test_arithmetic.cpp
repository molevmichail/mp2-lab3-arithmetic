//тесты для вычисления арифметических выражений

#include <gtest.h>
#include "..\include\arithmetic.h"
#include <gtest.h>

TEST(Tlexeme, can_create_Tlexeme)
{
	ASSERT_NO_THROW(Tlexeme L);
}
TEST(Tlexeme, can_create_Tlexeme_by_string)
{
	string a = "(2+(2-3+1))";
	ASSERT_NO_THROW(Tlexeme L(a));
}
TEST(Tlexeme, correctness_check_unidentified_character)
{
	Tlexeme L("3&+2");
	EXPECT_EQ(0, L.Check_correct());
}
TEST(Tlexeme, correctness_check_brackets_1)
{
	Tlexeme L("(3+2");
	EXPECT_EQ(0, L.Check_correct());

}
TEST(Tlexeme, correctness_check_brackets_2)
{
	Tlexeme L("3+2)");
	EXPECT_EQ(0, L.Check_correct());

}
TEST(Tlexeme, correctness_check_brackets_3)
{
	Tlexeme L("(3+2)7)");
	EXPECT_EQ(0, L.Check_correct());

}
TEST(Tlexeme, correctness_check_brackets_4)
{
	Tlexeme L("(*(3+2)");
	EXPECT_EQ(0, L.Check_correct());
}
TEST(Tlexeme, correctness_check_signs_ofoperations_1)
{
	Tlexeme L("+3+2");
	EXPECT_EQ(0, L.Check_correct());

}
TEST(Tlexeme, correctness_check_signs_ofoperations_2)
{
	Tlexeme L("-3+2");
	EXPECT_EQ(0, L.Check_correct());

}
TEST(Tlexeme, correctness_check_signs_ofoperations_3)
{
	Tlexeme L("3*+2");
	EXPECT_EQ(0, L.Check_correct());
}
TEST(Tlexeme, correctness_check_variable)
{
	Tlexeme L("xy+2");
	EXPECT_EQ(0, L.Check_correct());
}
TEST(Tlexeme, can_convert_in_Polish_entry)
{
	Tlexeme L("(2+3)*6");
	ASSERT_NO_THROW(L.Pol());
}
TEST(Tlexeme, can_convert_empty_string_in_Polish_entry)
{
	Tlexeme L;
	ASSERT_NO_THROW(L.Pol()); // L.Pol()==0
}
TEST(Tlexeme, cant_convert_incorrect_in_Polish_entry)
{
	Tlexeme L("(2+3)*6)");
	ASSERT_ANY_THROW(L.Pol());
}
TEST(Tlexeme, right_convert_in_Polish_entry)
{
	Tlexeme L("(2+3)*6");
	string a = "2 3 + 6 * ";
	EXPECT_EQ(a, L.Pol());
}
TEST(Tlexeme, right_calculation_Tlexeme_1)
{
	Tlexeme L("(2+3)*6");
	EXPECT_EQ(L.Calculation(), 30);
}
