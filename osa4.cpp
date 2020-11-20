#include <iostream>
#include <fstream>
using namespace std;

struct Node //ветка бинарного дерева
{
    int data;    //данные
    Node *left;  //указатель на левую ветку
    Node *right; //указатель на правую ветку

    Node(int data = 0, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BinaryTree //бинарное дерево
{
public:
    BinaryTree();                           //конструктор
    void insert(int data, Node *leaf);      //вставка нового элемента
    void insert(int data);                  //вставка нового элемента
    void print_inorder(Node *leaf);         //вывод бинарного дерева в порядке возрастания
    void print_inorder();                   //вывод бинарного дерева в порядке
    void print_inorder_to_file(Node *leaf); //вывод бинарного дерева в порядке возрастания
    void print_inorder_to_file();           //вывод бинарного дерева в порядке

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

void BinaryTree::print_inorder(Node *leaf)
{
    if (leaf != nullptr)
    {
        print_inorder(leaf->left);
        cout << leaf->data << " ";
        print_inorder(leaf->right);
    }
}

void BinaryTree::print_inorder_to_file(Node *leaf)
{
    if (leaf != nullptr)
    {
        print_inorder_to_file(leaf->left);
        ofstream fout;
        fout.open("BinaryTree.txt", ofstream::app);
        print_inorder_to_file(leaf->right);
        fout.close();
    }
}

void BinaryTree::print_inorder_to_file()
{
    print_inorder_to_file(root);
}

void BinaryTree::print_inorder()
{
    print_inorder(root);
    cout << endl;
}

int main()
{

    BinaryTree bt1;
    int value;

    for (int i = 0; i < 9; i++)
    {
        cout << "Enter a value" << endl;
        cin >> value;
        bt1.insert(value);
    }

    ifstream fin;
    fin.open("BinaryTree.txt");

    bt1.print_inorder_to_file();

    while (!fin.eof())
    {
        fin >> value;
        bt1.insert(value);
    }

    bt1.print_inorder();

    fin.close();
}
