#include "../include/perceptron.hpp"
#include<stdlib.h>

namespace ml{

vector<float> perceptron::forward(const vector<float> input){
    int i,j;
    vector<float> output(weight.size());
    for (i = 0;i<weight.size();i++){output[i] = 0;}
    if (input.size() != weight[0].size()){
        cout<<"dimension wrong";
        exit(0);
    }
    for (i = 0;i<weight.size();i++){
        for (j = 0;j<weight[0].size();j++){

            output[i] += input[j] * weight[i][j]; 
        }
    output[i] = 1/(1 + exp(output[i]));
    }
   return output;
}
void perceptron::backward(const vector<float> output,const vector<float> input,
                        const vector<float> loss,bool isupdate){
    int i,j;
    vector<float> pre_loss(loss.size());
    for (i= 0;i<output.size();i++){
        pre_loss[i] = output[i] * (1 - output[i]) * loss[i];
    }
    if (isupdate){
        for (i= 0;i<output.size();i++){
            for (j = 0;j<input.size();j++){ 
    
                float weight_update = pre_loss[i] * input[j]; 
                perceptron::weight[i][j] -= weight_update * 0.1*0.99; 
            }
        float bias_update = pre_loss[i];
        perceptron::bias[i] -= bias_update * 0.1*0.99; 
     }
    }
}
}

