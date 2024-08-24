#include <iostream>
using namespace std;
#include<queue>
#pragma region BST
struct node
{
    node* left, * right;
    int m_data;
    node(int val)
    {
        m_data = val;
        left = NULL;
        right = NULL;
    }
}*root;

void insert(node **item,int val)
{
    if (*item == NULL)
    {
        *item = new node(val);
    }
    else
    {
        if (val > (*item)->m_data )
            insert( &(*item)->right, val);
        else
            insert(&(*item)->left,val);
    }
}

void DispInOrder(node* item)
{
    if (item == NULL) 
        return;
    DispInOrder(item->left);
    cout << item->m_data << " "; 
    DispInOrder(item->right);
    
}

void DispPreOrder(node* item)
{
    if (item == NULL)
        return;       
    cout << item->m_data << " ";
    DispPreOrder(item->left);
    DispPreOrder(item->right);
    
}

void DispPostOrder(node* item)
{
    if (item == NULL)
        return;
            
    DispPostOrder(item->left);
    DispPostOrder(item->right);
    cout << item->m_data << " ";
    
}
void LevelOrderTraverseSimpleApproach(node *item)
{
    if (item == NULL)
        return;
    queue<node*>q;
    q.push(item);
    while (!q.empty())
    {
        node* el = q.front();
        cout << el->m_data <<" ";
        q.pop();
        if (el->left)
            q.push(el->left);
        if (el->right)
            q.push(el->right);
    }

}

void LevelOrderTraversallikeLeftViewRightViewLogic(node* item)
{
    if (item == NULL)
        return;
    queue<node*>q;
    q.push(item);
    while (!q.empty())
    {
        auto n = q.size();
        for (auto i = 1; i <= n; i++) {
            node* el = q.front();
            cout << el->m_data << " ";
            q.pop();
            if (el->left)
                q.push(el->left);
            if (el->right)
                q.push(el->right);
        }
    }

}

void PrintLeftOuterView(node* item)
{
    if (item == NULL)
        return;
    queue<node*>q;
    q.push(item);
    while (!q.empty())
    {
        int n = q.size();

        for (auto i = 1;i<= n;i++)
        {
            
            node* el = q.front(); 
            q.pop();
            if(i == 1)
                cout << el->m_data << " ";

            if (el->left)
                q.push(el->left);
            if (el->right)
                q.push(el->right);
        }
    }

}


void PrintRightOuterView(node* item)
{
    if (item == NULL)
        return;
    queue<node*>q;
    q.push(item);
    while (!q.empty())
    {
        int n = q.size();

        for (auto i = 1; i <= n; i++)
        {

            node* el = q.front();
            q.pop();
            if (i == 1)
                cout << el->m_data << " ";

            if (el->left)
                q.push(el->left);
            if (el->right)
                q.push(el->right);
        }
    }

}

void PrintFullOuterView(node* item)
{
    if (item == NULL)
        return;
    queue<node*>q;
    q.push(item);
    while (!q.empty())
    {
        int n = q.size();

        for (auto i = 1; i <= n; i++)
        {

            node* el = q.front();
            q.pop();
            if (i == 1 || (i == n))
                cout << el->m_data << " ";

            if (el->left)
                q.push(el->left);
            if (el->right)
                q.push(el->right);
        }
    }

}

int main()
{
    root = NULL;
    int arr[] = {50,30,20,40,70,60,80};
    for (auto x= 0;x<7;x++)
    {
        insert(&root, arr[x]);
    }
    
    cout << endl << "Now IN ORDER" << endl;
    DispInOrder(root);

    cout << endl << "Now PRE ORDER" << endl;
    DispPreOrder(root);
    
    cout << endl << "Now POST ORDER" << endl;    
    DispPostOrder(root);
    std::cout <<endl<< "Level order Traverse simple Approach\n";
    LevelOrderTraverseSimpleApproach(root);
    
    std::cout << endl << "Level order Traverse Same logic like left view Right View\n";
    LevelOrderTraversallikeLeftViewRightViewLogic(root);
    cout << "\n Left Outer View" << endl;
    PrintLeftOuterView(root);
    cout << "\n right Outer View" << endl;
    PrintRightOuterView(root);
    cout << "\n Full Outer View" << endl;
    PrintFullOuterView(root);




}
#pragma endregion