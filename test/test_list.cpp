#include "../gtest/gtest.h"
#include "../include/LIST.h"
TEST(list,can_create_a_list_copy)
{
    List<int> f;
    f.InsertLast(10);
    ASSERT_NO_THROW(List<int> res(f));
}
TEST(list,can_insertfirst_and_get_an_element)
{
    List<int> f;
    f.InsertFirst(5);
    EXPECT_EQ(5,f.GeNode(5)->val);
}
TEST(list,can_insertlast_and_get_an_element)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(5);
    EXPECT_EQ(5,f.GeNode(5)->val);
}
TEST(list,can_insert_node_in_a_destination_and_get_an_element)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(5);
    f.InsertLast(9);
    NODE<int>* op = new NODE<int>(70,nullptr);
    f.Insert(f.GeNode(5),op);
    EXPECT_EQ(70,f.GeNode(70)->val);
}
TEST(list,copied_list_has_its_own_memory)
{
    List<int> f;
    f.InsertFirst(3);
    List<int> s(f);
    s.InsertLast(12);
    ASSERT_NO_THROW(s.GeNode(12));
}
TEST(list,DELETEALL_actually_deletes)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(3);
    f.InsertLast(2);
    f.DeleteAll();
    EXPECT_EQ(nullptr,f.GitThirst());
}
TEST(list,DeleteNext_actually_deletes_next)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(3);
    f.InsertLast(2);
    f.DeleteTheNext(f.GeNode(3));
    EXPECT_EQ(nullptr,f.GeNode(3));
}
TEST(list,DeleteNext_throws_if_no_next_element_is_presented)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(3);
    f.InsertLast(2);
    ASSERT_ANY_THROW(f.DeleteTheNext(f.GeNode(2)));
}
TEST(list,list_can_be_assigned_to_the_other_list)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> l;
    l.InsertFirst(6);
    l.InsertLast(34);
    l.InsertLast(11);
    l.InsertLast(55);
    l.InsertLast(99);
    l.InsertLast(676);
    l = f;
    EXPECT_EQ(f,l);
}
TEST(list,can_assign_lists_with_different_sizes)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> l;
    l.InsertFirst(1);
    l.InsertLast(34);
    l.InsertLast(11);
    l.InsertLast(55);
    l.InsertLast(33);
    f = l;
    EXPECT_EQ(l,f);
}
TEST(list,list_can_be_assigned_to_itself)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> pipebomb(f);
    f = f;
    EXPECT_EQ(pipebomb,f);
}
TEST(list,when_equal_lists_returns_true)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> b;
    b.InsertFirst(6);
    b.InsertLast(44);
    b.InsertLast(11);
    b.InsertLast(30);
    b.InsertLast(99);
    b.InsertLast(676);
    if (f ==b)
    {
        SUCCEED();
    }
    else
    {
        ADD_FAILURE();
    }
}
TEST(list,when_compared_with_itself_returns_true)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    if (f == f)
    {
        SUCCEED();
    }
    else
    {
        ADD_FAILURE();
    }
}
TEST(list,when_compared_with_different_list_returns_false)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> a;
    a.InsertFirst(6);
    a.InsertLast(44);
    a.InsertLast(11);
    a.InsertLast(30);
    a.InsertLast(22222);
    a.InsertLast(676);
    if (f != a)
    {
        SUCCEED();
    }
    else
    {
        ADD_FAILURE();
    }
}
TEST(list,when_compared_with_list_with_different_length_returns_false)
{
    List<int> f;
    f.InsertFirst(6);
    f.InsertLast(44);
    f.InsertLast(11);
    f.InsertLast(30);
    f.InsertLast(99);
    f.InsertLast(676);
    List<int> a;
    a.InsertFirst(6);
    a.InsertLast(44);
    a.InsertLast(11);
    a.InsertLast(30);
    a.InsertLast(99);
    if (f != a)
    {
        SUCCEED();
    }
    else
    {
        ADD_FAILURE();
    }
}