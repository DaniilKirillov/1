#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
using namespace std;

struct Node
{
public:
    int amount;
    char data;
    Node* left;
    Node* right;

    Node(Node* l, Node* r)
    {
        this->left = l;
        this->right = r;
        this->amount = l->amount + r->amount;
    }

    Node()
    {
    }
};

struct msort
{
    bool operator() (Node* left, Node* right) const
    {
        return left->amount < right->amount;
    }
};

vector<bool> code;
map<char, vector<bool> > table;

void Code(Node* root)
{
    if (root->left != nullptr)
    {
        code.push_back(0);
        Code(root->left);
    }
    if (root->right != nullptr)
    {
        code.push_back(1);
        Code(root->right);
    }
    if (root->left == nullptr && root->right == nullptr) table[root->data] = code;
    if (!code.empty()) code.pop_back();
}

int main()
{
    cout << "Enter text : ";
    char text[100000];

    cin.getline(text, 100000);
    int size = 0;

    while (text[size] != '\0')
    {
        size++;
    }

    vector<char> symbols;

    // Запись уникальных символов в вектор:
    for (int m = 0; m < size; m++)
    {
        int count = 0;
        for (int l = 0; l < m; l++)
        {
            if (text[l] == text[m]) count++;
        }
        if (count == 0)
        {
            symbols.push_back(text[m]);
        }
    }

    int* index = new int[symbols.size()];
    for (int i = 0; i < symbols.size(); i++) 
    {
        index[i] = 0;
    }

    for (int i = 0; i < symbols.size(); i++) 
    {
        for (int j = 0; j < size; j++)
        {
            if (symbols[i] == text[j]) index[i]++;
        }
    }


    map<char, int> m;
    for (int i = 0; i < symbols.size(); i++)
    {
        char ch = symbols[i];
        m[ch] = index[i];
    }
    map<char, int>::iterator ii;

    // Вывод уникальных символов с количеством на экран
    for (ii = m.begin(); ii != m.end(); ii++)
    {
        cout << ii->first << ":" << ii->second << endl;
    }

    list<Node*> l;
    map<char, int>::iterator i;
    for (i = m.begin(); i != m.end(); ++i)
    {
        Node* n = new Node;
        n->data = i->first;
        n->amount = i->second;
        l.push_back(n);
    }

    while (l.size() != 1)
    {
        l.sort(msort());
        Node* left = l.front();
        l.pop_front();
        Node* right = l.front();
        l.pop_front();

        Node* p = new Node(left, right);
        l.push_back(p);
    }

    Node* root = l.front();

    Code(root);
    
    map<char, vector<bool> >::iterator iii;
    for (iii = table.begin(); iii != table.end(); ++iii)
    {
        cout << iii->first << ":";
        for (int i = 0; i < table.size(); i++)
        {
            cout << iii->first << ":";
            for (int i = 0; i < iii->second.size(); i++)
            {
                if (iii->second[i] == true) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
    }
}