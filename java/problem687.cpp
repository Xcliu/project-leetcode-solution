#include <iostream>

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
        int max(int a,int b){
            return a>b?a:b;
        }
        
        int current_max_path{0};
        
        int longest_vertical_Path(TreeNode* root){
            if(!root) return 0;
            int passed_val=0, current_val=0;
            
            if(root->left!=nullptr&&root->right!=nullptr&&root->left->val==root->val&&root->right->val==root->val){
                //std::cout<<"done1"<<std::endl;
                auto temp_1=longest_vertical_Path(root->left)+1;
                auto temp_2=longest_vertical_Path(root->right)+1;
                current_val=temp_1+temp_2;
                passed_val=max(temp_1,temp_2);

            }else if(root->left!=nullptr&&root->left->val==root->val){
                //std::cout<<"done2"<<std::endl;
                passed_val=longest_vertical_Path(root->left)+1;
                longest_vertical_Path(root->right);
                current_val=passed_val;

            }else if(root->right!=nullptr&&root->right->val==root->val){
                //std::cout<<"done3"<<std::endl;
                longest_vertical_Path(root->left);
                passed_val=longest_vertical_Path(root->right)+1;
                current_val=passed_val;
            }else{
                //std::cout<<"done4"<<std::endl;
                longest_vertical_Path(root->left);
                longest_vertical_Path(root->right);
            }
            current_max_path=max(current_val,current_max_path);
            return passed_val;
        }
        
        int longestUnivaluePath(TreeNode* root){
            longest_vertical_Path(root);
            return current_max_path; 
        }
};

int main(){
    auto root= TreeNode(1);
    TreeNode n1,n2,n3,n4,n5;
    n1=TreeNode(4);
    n2=TreeNode(5);
    n3=TreeNode(4);
    n4=TreeNode(4);
    n5=TreeNode(5);
    root.left=&n1;root.right=&n2;
    n1.left=&n3;n1.right=&n4;
    n2.right=&n5;
    auto test=Solution();
    std::cout<< test.longestUnivaluePath(&root)<<std::endl;

    return 0;
}