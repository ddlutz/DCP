/*
This problem was asked by Google.

Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

*/
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sstream>

using namespace std;

 struct TreeNode {

     TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r)
     {
         
     }

    int val;
    TreeNode* left;
    TreeNode* right;

};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string res;
    if (nullptr == root)
    {
        return "";
    }

    deque<TreeNode*> q;
    q.push_back(root);

    while(!q.empty())
    {
        TreeNode* cur = q.front();
        q.pop_front();
        if (cur == nullptr)
        {
            res += "n ";
        }
        else
        {
            res += to_string(cur->val) + " ";
            q.push_back(cur->left);
            q.push_back(cur->right);
        }
    
    }

    return res;

}

vector<string> splitstr(string str)
{
    char delimiter = ' ';
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    
    if (data == "")
    {
        return nullptr;
    }

    TreeNode* root;
    
    vector<string> nodes = splitstr(data);
    root = new TreeNode(stoi(nodes[0]), nullptr, nullptr);
    deque<TreeNode*> q;
    q.push_back(root);

    for(int i = 1; i < nodes.size(); i++)
    {
        TreeNode* node = q.front();
        q.pop_front();

        std::cout << "cur node: " << nodes[i+1] << std::endl;

        if (nodes[i] != string("n"))
        {
            TreeNode* left = new TreeNode(stoi(nodes[i+1]), nullptr, nullptr);
            node->left = left;
            q.push_back(left);
        }

        if(nodes[++i]!= string("n"))
        {
            TreeNode* right = new TreeNode(stoi(nodes[i+2]), nullptr, nullptr);
            node->right = right;
            q.push_back(right);
        }
    }

    return root;
}

int main()
{
    std::cout << "Null test:" << std::endl;
    TreeNode* nullRoot{ nullptr };
    string nullSerialized = serialize(nullRoot);
    std::cout << "Serialized: " << nullSerialized << std::endl;
    std::cout << "Deserialized: " << deserialize(nullSerialized) << std::endl;


    TreeNode root{1, nullptr, nullptr};
    string oneSerialized = serialize(&root);
    std::cout << "Serialized: " << oneSerialized << std::endl;
    std::cout << "Deserialized: " << deserialize(oneSerialized)->val << std::endl;



    return 0;
}