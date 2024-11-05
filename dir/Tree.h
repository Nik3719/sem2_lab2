#pragma once
#include<string>
#include<iostream>
#include <iomanip>
#include"Tools.h"


using namespace std;

struct TreeNode
{
    int data; 
    TreeNode* left;   
    TreeNode* right; 
    TreeNode(const int& value) : data(value), left(nullptr), right(nullptr) {};
};

struct Tree
{
    TreeNode* root;
    Tree();
    ~Tree();
    void Allocation(TreeNode* node);
    TreeNode* downTree(TreeNode* node, int value);
    void TINSERT(int elem);
    bool TSEARCH(int elem);
    TreeNode* RightOrLeft(TreeNode* node, int& value);
    int countNodes(TreeNode* node);
    bool TISCOMPLETE();
    bool isComplete(TreeNode* node, int index, int numberNodes);
    int height(TreeNode* node);
    
    void PRINT(TreeNode* root, int space = 0);

    TreeNode* findNode(TreeNode* node, const int& value);

    DL<DL<int>> getLevels();
    void LoadLevel(TreeNode* node, int level, DL<int>& levelValues);


    int depth(TreeNode* root, TreeNode* node);

};