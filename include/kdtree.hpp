#ifndef ML_KDTREE_HPP
#define ML_KDTREE_HPP
#include <vector>
using namespace std;
#include <iostream>
#include <math.h>
namespace ml{

struct TreeNode{
    Node *left; 
    Node *parent;
    Node *right;
    char sort_axis;
    vector<int> val;
};
template<typename DType>
class KdTree{
 public:
    explicit KdTree(vector<DType> &data):data_(data){}
    void BuildTree();    
    TreeNode* FindNearestNeirboor(const DType& point);
 private:
    TreeNode* LocateInTree(const DType& point);
    TreeNode* SearchInTree(TreeNode* location,const DType& point);
    TreeNode* BuildSubTree(TreeNode* root,
                    vector<data> ranged_data,
                    axis_to_sort);
    vector<DType> data_;
    TreeNode* root;
}   