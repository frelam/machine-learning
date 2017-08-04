#ifndef ML_PERCEPTRON_HPP
#define ML_PERCEPTRON_HPP
#include <vector>
using namespace std;
#include <iostream>
#include <math.h>
namespace ml{

class perceptron{
 public:
    perceptron(vector< vector<float> > weight_,vector<float> bias_):weight(weight_),bias(bias_){}
    vector<float> forward(const vector<float> input);
    void backward(const vector<float> output,const vector<float> input,
                        const vector<float> loss,bool isupdate = true);
 private:
    
    vector<vector<float> > weight;
    vector<float> bias;
};
}
#endif

