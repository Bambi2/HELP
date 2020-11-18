#include <iostream>
#include <fstream>
using namespace std;

struct Node //ветка бинарного дерева
{
    int data;    //данные
    Node *left;  //указатель на левую ветку
    Node *right; //указатель на правую ветку

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BinaryTree //бинарное дерево
{
public:
    BinaryTree();                      //конструктор
    ~BinaryTree();                     //деструктор
    void insert(int data, Node *leaf); //вставка нового элемента
    void insert(int data);             //вставка нового элемента
    void print_inorder_to_file(Node *leaf);
    void print_inorder_to_file();

private:
    Node *root; //корень дерева
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

void BinaryTree::insert(int data, Node *leaf)
{
    if (data < leaf->data)
    {
        if (leaf->left != nullptr)
        {
            insert(data, leaf->left);
        }
        else
        {
            leaf->left = new Node(data);
        }
    }
    else
    {
        if (leaf->right != nullptr)
        {
            insert(data, leaf->right);
        }
        else
        {
            leaf->right = new Node(data);
        }
    }
}

void BinaryTree::insert(int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else
    {
        insert(data, root);
    }
}

void BinaryTree::print_inorder_to_file(Node *leaf)
{
    if (leaf != nullptr)
    {
        print_inorder_to_file(leaf->left);
        ofstream file;
        file.open("BinaryTree.txt");
        file << leaf->data << ", ";
        print_inorder_to_file(leaf->right);
        cout << endl;
        file.close();
    }
}

void BinaryTree::print_inorder_to_file()
{
    print_inorder_to_file(root);
}

int main()
{
    BinaryTree bt1;

    bt1.insert(8);
    bt1.insert(11);
    bt1.insert(7);
    bt1.insert(3);
    bt1.insert(4);
    bt1.insert(5);
    bt1.insert(9);
    bt1.insert(13);
    bt1.insert(12);
    bt1.insert(6);
    bt1.insert(10);

    bt1.print_inorder_to_file();
}
