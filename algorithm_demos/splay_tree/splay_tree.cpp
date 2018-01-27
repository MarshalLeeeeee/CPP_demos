// no duplicate element
#include <iostream>
#define LEFT 0
#define RIGHT 1

using namespace std;

class SplayTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node *parent;
        Node(void):left(NULL), right(NULL), parent(NULL){}
        Node (int value):left(NULL), right(NULL), parent(NULL), data(value){}
    };
    Node *root;

    Node *copy_node(Node *&node, Node *parent_node, Node *other_node)
    {
        if(other_node)
        {
            node = new Node;
            node->parent = parent_node;
            node->left = copy_node(node->left, node, other_node->left);
            node->right = copy_node(node->right, node, other_node->right);
            node->data = other_node->data;
            return node;
        }
        else return NULL;
    }

    void delete_node(Node *&node)
    {
        if(node)
        {
            delete_node(node->left);
            delete_node(node->right);
            delete node;
            node = NULL;
        }
    }

    bool return_identity(Node *node)
    {
        if(node == node->parent->left) return LEFT;
        else return RIGHT;
    }

    void Zig(Node *node)// same as LL
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->left->left;
        tmp2->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(return_identity(tmp1) == LEFT) tmp2->parent->left = tmp2;
            else tmp2->parent->right = tmp2;
        }
        else root = tmp2;
        tmp1->left = tmp2->right;
        if(tmp2->right) tmp2->right->parent = tmp1;
        tmp2->right = tmp1;
        tmp1->parent = tmp2;
    }

    void Zag(Node *node)// same as RR
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->right->right;
        tmp3->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(return_identity(tmp1) == LEFT) tmp3->parent->left = tmp3;
            else tmp3->parent->right = tmp3;
        }
        else root = tmp3;
        tmp1->right = tmp3->left;
        if(tmp3->left) tmp3->left->parent = tmp1;
        tmp3->left = tmp1;
        tmp1->parent = tmp3;
    }

    void adjust(Node *node)
    {
        if(node->parent)
        {
            if(node->data < node->parent->data) Zig(node->parent);
            else Zag(node->parent);
            adjust(node);
        }
    }

    Node *find_insert_parent(Node *node, int value)
    {
        if(value > node->data)
        {
            if(node->right) return find_insert_parent(node->right, value);
            else return node;
        }
        else
        {
            if(node->left) return find_insert_parent(node->left, value);
            else return node;
        }
    }

    Node *subtract(Node *node)
    {
        Node *ans;
        if(!node) return NULL;
        if(node->left)
        {
            ans = node->left;
            while(ans->right) ans = ans->right;
            return ans;
        }
        else
        {
            if(!node->parent) return NULL;
            if(return_identity(node) == RIGHT) return node->parent;
            ans = node->parent;
            while(ans != root && return_identity(ans) == LEFT)
            {
                ans = ans->parent;
            }
            if(ans == root) return NULL;
            else return ans->parent;
        }
    }

    Node *add(Node *node)
    {
        Node *ans;
        if(!node) return NULL;
        if(node->right)
        {
            ans = node->right;
            while(ans->left) ans = ans->left;
            return ans;
        }
        else
        {
            if(!node->parent) return NULL;
            if(return_identity(node) == LEFT) return node->parent;
            ans = node->parent;
            while(ans != root && return_identity(ans) == RIGHT)
            {
                ans = ans->parent;
            }
            if(ans == root) return NULL;
            else return ans->parent;
        }
    }

    void pre(Node *node)
    {
        if(node)
        {
            cout << node->data << endl;
            pre(node->left);
            pre(node->right);
        }
    }

public:
    //constructor and destructor
    SplayTree(void):root(NULL){}
    SplayTree(const SplayTree &other){copy_node(root, NULL, other.root);}
    ~SplayTree(void){delete_node(root);}

    Node *find_node(Node *node, int value)
    {
        if(node)
        {
            if(value == node->data) {adjust(node); return node;}
            else if(value < node->data) return find_node(node->left, value);
            else return find_node(node->right, value);
        }
        else return NULL;
    }

    void insert_node(int value)
    {
        if(!root)
        {
            root = new Node(value);
        }
        else
        {
            if(find_node(root, value)) return ;
            Node *father = find_insert_parent(root, value);
            Node *new_node = new Node(value);
            new_node->parent = father;
            if(value > father->data) father->right = new_node;
            else father->left = new_node;
            adjust(new_node);
        }
    }

    void delete_node(int value)
    {
        Node *target = find_node(root, value);
        if(target)
        {
            if(target->left && target->right)
            {
                Node *substitute = subtract(target);
                Node *new_node = new Node(substitute->data);
                new_node->parent = substitute->parent;
                if(substitute->parent)
                {
                    if(return_identity(substitute) == LEFT) substitute->parent->left = new_node;
                    else substitute->right = new_node;
                }
                new_node->left = substitute->left;
                if(substitute->left) substitute->left->parent = new_node;
                new_node->right = substitute->right;
                if(substitute->right) substitute->right->parent = new_node;

                substitute->left = target->left;
                target->left->parent = substitute;
                substitute->right = target->right;
                target->right->parent = substitute;
                substitute->parent = target->parent;
                if(target->parent)
                {
                    if(return_identity(target) == LEFT) target->parent->left = substitute;
                    else target->parent->right = substitute;
                }
                else root = substitute;

                delete target;
                target = new_node;
            }
            if(!target->left && !target->right)
            {
                if(target->parent)
                {
                    if(return_identity(target) == LEFT) target->parent->left = NULL;
                    else target->parent->right = NULL;
                    adjust(target->parent);
                }
                else root = NULL;
                delete target;
            }
            else
            {
                if(target->left)
                {
                    target->left->parent = target->parent;
                    if(target->parent)
                    {
                        if(return_identity(target) == LEFT) target->parent->left = target->left;
                        else target->parent->right = target->left;
                        adjust(target->parent);
                    }
                    else root = target->left;
                    delete target;
                }
                else
                {
                    target->right->parent = target->parent;
                    if(target->parent)
                    {
                        if(return_identity(target) == LEFT) target->parent->left = target->right;
                        else target->parent->right = target->right;
                        adjust(target->parent);
                    }
                    else root = target->right;
                    delete target;
                }
            }
        }
    }

    void pre_order(void) {pre(root);}
};

int main()
{
    SplayTree t;
    t.insert_node(3);t.pre_order();cout << "*******************" << endl;
    t.insert_node(5);t.pre_order();cout << "*******************" << endl;
    t.insert_node(7);t.pre_order();cout << "*******************" << endl;
    t.insert_node(9);t.pre_order();cout << "*******************" << endl;
    t.insert_node(1);t.pre_order();cout << "*******************" << endl;
    t.insert_node(2);t.pre_order();cout << "*******************" << endl;
    t.insert_node(6);t.pre_order();cout << "*******************" << endl;
    t.insert_node(10);t.pre_order();cout << "*******************" << endl;
    t.insert_node(13);t.pre_order();cout << "*******************" << endl;
    t.insert_node(17);t.pre_order();cout << "*******************" << endl;
    t.insert_node(4);t.pre_order();cout << "*******************" << endl;
    t.insert_node(8);t.pre_order();cout << "*******************" << endl;
    t.insert_node(11);t.pre_order();cout << "*******************" << endl;
    t.delete_node(6);t.pre_order();cout << "*******************" << endl;
    t.delete_node(10);t.pre_order();cout << "*******************" << endl;
    t.delete_node(1);t.pre_order();cout << "*******************" << endl;
    return 0;
}
