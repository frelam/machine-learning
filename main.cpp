///////
#include <ctime>
#include <cstdlib>
#include "./include/perceptron.hpp"
#include <vector>
using namespace std;
int main(){
    vector<vector<float> > data;
    vector<float> label;
    vector<float> data_temp;
    float label_temp;
    vector<vector<float> > weight;
    vector<float> bias;
    int t ,i,j;
    float temp ;
    int input_dim = 3;
    int output_dim = 1; 
    for (i=0;i<100000;i++){
        
        data_temp.clear();
        for (j = 0;j<input_dim;j++){
            //srand(time(0));
            t = rand() % 1000;
            temp = t/1000.0;
            data_temp.push_back(temp);
        }
        data.push_back(data_temp);
        label_temp = data[i][0] * data[i][1] * data[i][2];
        label.push_back(label_temp); 
    
    }
    data_temp.clear();
    for (j = 0;j<input_dim;j++){
            
            t = rand() % 100;
            temp = t/1000.0;
            data_temp.push_back(temp);
        }
    weight.push_back(data_temp);
    t = rand() % 100;
    temp = t/1000.0;
    bias.push_back(temp);
    ml::perceptron p1(weight,bias);
    float sum_loss = 0;
    for (i=0;i<100000;i++){
        vector<float> input = data[i];
        float label_temp = label[i];
        vector<float> output = p1.forward(input);
        vector<float> loss;
        loss.push_back(label_temp - output[0]);
        p1.backward(output,input,loss);
        cout<<loss[0]<<"interation"<<i<<endl;
        sum_loss +=loss[0];
    }
    cout<<"map"<<(sum_loss/100000.0);
    ml::perceptron *_p1 = &p1;
    delete _p1;
}
