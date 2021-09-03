#include <iostream>

struct tree {
    int data;
    tree * left, * right;
};


void create_tree(tree** p, int n)
{
    if (n == 0)
    {
        *p = NULL;
    }
    else
    {

        tree* newP = new tree;
        std::cin >> newP -> data;
        int
            nl = n / 2,
            nr = n - nl - 1;
        create_tree(&newP -> left, nl);
        create_tree(&newP -> right, nr);
        *p = newP;
    }
}

int main()
{
    int n;
    tree* root;
    std::cout << "Input size: ";
    std::cin >> n;
    create_tree(&root, n);
    return 0;
}
