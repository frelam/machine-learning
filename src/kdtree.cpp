#include "kdtree.hpp"
namespace ml{
template<typename Dtype>
//axis_to_sort 
//begin
Kdtree::BuildSubTree(TreeNode* root,
                     vector<Dtype> ranged_data
                     axis_to_sort){
    ranged_data.sort(ranged_data.begin(),
               ranged_data.end(),
               axis_to_sort);
    mid_num = ranged_data[ranged_data.size()/2];
    TreeNode* leaf = new TreeNode();
    leaf->val = mid_num;
    leaf->parent = root;
    leaf->sort_axis = axis_to_sort;
    if (ranged_data.size() != 1){
        axis = (axis_to_sort + 1) % Dtype.size();
        leaf->left = BuildSubTree(leaf,
                    ranged_data[begin:ranged_data.size()/2-1),
                    axis);
        leaf->right = BuildSubTree(leaf,
                    ranged_data[ranged_data.size()/2+1:end],
                    axis);
    }
    else{
        leaf->left = NULL;
        leaf->right = NULL;
    }
    return leaf;                
    }

Kdtree::BuildTree(){
    this->root = new TreeNode();
    this->root.left = BuildSubTree(this->root,data_);
}    

Kdtree::FindNearestNeirboor(const DType& point){
    TreeNode* location = LocateInTree(point);
    TreeNode* nearest_neirboor = SearchInTree(location,point);
    return nearest_neirboor;
}

KdTree::LocateInTree(const DType& point){
    TreeNode* node_temp;
    TreeNode* location;
    node_temp = this->root.left;
    while(node_temp.left||node_temp.right){
        axis =  node_temp->sort_axis;
        if(point[axis] = node_temp->val[axis]){location = node_temp;break;}
        else if(point[axis] < node_temp->val[axis]){node_temp = node_temp->left;continue;}
            else{node_temp = node_temp->left;continue;}
    }
    return location;

}

KdTree::SearchInTree(TreeNode* location,const DType& point){}
}