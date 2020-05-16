#include "gtest/gtest.h"
#include <string>

#include "bst.h"
BST<std::string> makeTree(char* filename);

TEST(lab6,test1_1)
{
    char* filename="war_peace.txt";
    BST<std::string> tree=makeTree(filename);
    int depth=tree.depth();
    EXPECT_EQ(depth,35);
}
TEST(lab6,test1_2)
{
    char* filename="war_peace.txt";
    BST<std::string> tree=makeTree(filename);
    int depth=tree.search("pierre");
    EXPECT_EQ(depth,1963);
}
TEST(lab6,test1_3)
{
    char* filename="war_peace.txt";
    BST<std::string> tree=makeTree(filename);
    int depth=tree.search("natasha");
    EXPECT_EQ(depth,1212);
}
TEST(lab6,test1_4)
{
    char* filename="war_peace.txt";
    BST<std::string> tree=makeTree(filename);
    int depth=tree.search("andrew");
    EXPECT_EQ(depth,1143);
}
