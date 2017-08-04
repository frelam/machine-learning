#ifndef ML_PERCEPTRON_HPP
#define ML_PERCEPTRON_HPP
#include <vector>
using namespace std;
#include <iostream>
#include <math.h>
namespace ml{

struct Node{
    Node *left; 
    Node *parent;
    Node *right;
    vector<int> val;
}
typedef bool(*p_func)(vecetor<int>,vecetor<int>);
class Kdtree{
 public:
    Kdtree(){
        p_fun.push_back(Sort_first);
        p_fun.push_back(Sort_second);
        p_fun.push_back(Sort_third);
    }

    void Bulidtree(const vector<int>& data);
    void Searchtree(int& point);
 private:
    vector<p_func> p_fun;
    bool Sort_first(vector<int> i,vector<int> j){return (i[0] < j[0]);}
    bool Sort_second(vector<int> i,vector<int> j){return (i[1] < j[1]);}
    bool Sort_third(vector<int> i,vector<int> j){return (i[2] < j[2]);}
    vector 
    
 }
    bool Kdtree::Sort_option(vector<int>,vector<int>)
    void Kdtree::BuildSubTree(vector<vector<int> > data){
       for()