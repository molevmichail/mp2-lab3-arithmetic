//тесты для стека

#include "stack.h"
#include <gtest.h>
#include "stack.h"
#include <gtest.h>


TEST(TStack, can_create_TStack)
{
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(TStack, checking_for_TStack_emptiness)
{
	TStack<int>s;
	EXPECT_EQ(1, s.Empty());
}
TEST(TStack, can_insert_element_into_TStack)
{
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(0, s.Empty());
}
TEST(TStack, cant_view_element_from_empty_TStack)
{
	TStack<int>s;
	ASSERT_ANY_THROW(s.Top());
}
TEST(TStack, view_element_into_TStack)
{
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(7, s.Top());
	EXPECT_EQ(0, s.Empty());  //элемент не был извлечен при просмотре
}
TEST(TStack, can_put_element_larger_size_TStack)
{
	TStack<int>s;
	for (int i = 0;i < STACK_SIZE + 2;i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(s.Top());
	EXPECT_EQ(STACK_SIZE + 1, s.Top());
}
TEST(TStack, cant_take_element_from_empty_TStack)
{
	TStack<int>s;
	ASSERT_ANY_THROW(s.Pop());
}
TEST(TStack, take_element_from_empty_TStack)
{
	TStack<int>s;
	s.Push(7);
	EXPECT_EQ(7, s.Pop());
	EXPECT_EQ(1, s.Empty());  //элемент был извлечен при просмотре
}
TEST(TStack, get_the_number_of_elements_in_TStack)
{
	TStack<int>s;
	EXPECT_EQ(0, s.Count());
	for (int i = 0; i < 10; i++)
	{
		s.Push(i);
	}
	EXPECT_EQ(10, s.Count());
}
TEST(TStack, clean_TStack)
{
	TStack<int>s;
	for (int i = 0; i < 10; i++)
	{
		s.Push(i);
	}
	s.Clear();
	EXPECT_EQ(1, s.Empty());
}
