#include <iostream>
#define RED 0
#define BLACK 1
using namespace std;
struct Node
{
    bool color;
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(void):color(RED), left(NULL), right(NULL), parent(NULL){}
};
class red_black_tree
{
private:
    Node *root;
    void LLb(Node *node)
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->left->left;
        tmp2->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(tmp1->parent->left == tmp1) tmp2->parent->left = tmp2;
            else tmp2->parent->right = tmp2;
        }
        else root = tmp2;
        tmp1->left = tmp2->right;
        if(tmp2->right) tmp2->right->parent = tmp1;
        tmp2->right = tmp1;
        tmp1->parent = tmp2;
    }
    void RRb(Node *node)
    {
        Node *tmp1, *tmp2, *tmp3, *tmp4;
        tmp1 = node; tmp2 = node->left; tmp3 = node->right; tmp4 = node->right->right;
        tmp3->parent = tmp1->parent;
        if(tmp1->parent)
        {
            if(tmp1->parent->left == tmp1) tmp3->parent->left = tmp3;
            else tmp3->parent->right = tmp3;
        }
        else root = tmp3;
        tmp1->right = tmp3->left;
        if(tmp3->left) tmp3->left->parent = tmp1;
        tmp3->left = tmp1;
        tmp1->parent = tmp3;
    }
    void LRb(Node *node)
    {
        RRb(node->left);
        LLb(node);
    }
    void RLb(Node *node)
    {
        LLb(node->right);
        RRb(node);
    }
    void LL(Node *node)
    {
        LLb(node);
        node->color = RED;
        node->parent->color = BLACK;
    }
    void RR(Node *node)
    {
        RRb(node);
        node->color = RED;
        node->parent->color = BLACK;
    }
    void LR(Node *node)
    {
        LRb(node);
        node->color = RED;
        node->parent->color = BLACK;
    }
    void RL(Node *node)
    {
        RLb(node);
        node->color = RED;
        node->parent->color = BLACK;
    }
    void recolor(Node *node)
    {
        node->color ^= 1;
        node->left->color ^= 1;
        node->right->color ^= 1;
    }
    bool return_color(Node *node)
    {
        if(!node || node->color == BLACK) return BLACK;
        else return RED;
    }
    Node *return_brother(Node *node)
    {
        if(node->parent->left == node) return node->parent->right;
        else return node->parent->left;
    }
public:
    red_black_tree(void):root(NULL){}
    Node *find_node(int value, Node *node)
    {
        if(!node) return NULL;
        if(node->data == value) return node;
        else
        {
            if(value > node->data)
                return find_node(value, node->right);
            else
                return find_node(value, node->left);
        }
    }
    Node *find_insert_parent(int value, Node *node)
    {
        if(value > node->data)
        {
            if(node->right) return find_insert_parent(value, node->right);
            else return node;
        }
        else
        {
            if(node->left) return find_insert_parent(value, node->left);
            else return node;
        }
    }
    void insert_node(int value)
    {
        if(!root)
        {
            Node *new_node = new Node;
            new_node->color = BLACK;
            new_node->data = value;
            root = new_node;

            root->color = BLACK;
            mid_order(root);

            return ;
        }
        if(find_node(value, root)) return ;
        else
        {
            Node *p = find_insert_parent(value, root);
            Node *new_node = new Node;
            new_node->data = value;
            new_node->parent = p;
            if(p->color == BLACK)
            {
                if(value > p->data)
                    p->right = new_node;
                else
                    p->left = new_node;

                root->color = BLACK;
                mid_order(root);

                return ;
            }
            else
            {
                if(value > p->data)
                    p->right = new_node;
                else
                    p->left = new_node;
                if(!p->parent->left|| !p->parent->right)// p is red while its brother is black
                {
                    if(!p->parent->left)// p is the right son of its parent
                    {
                        if(value > p->data)
                            RR(p->parent);
                        else
                            RL(p->parent);
                    }
                    else// p is the left son of its parent
                    {
                        if(value > p->data)
                            LR(p->parent);
                        else
                            LL(p->parent);
                    }
                }
                else// p and its brother are all RED
                {
                    recolor(p->parent);
                    Node *gf, *f;
                    f = p->parent;// p's father
                    gf = p->parent->parent;// p's grandfather
                    while(gf && !gf->color)// grandfather exists and its color is red
                    {
                        //as root is always black, the grandfather must have his father
                        if(!return_color(gf->parent->left) && !return_color(gf->parent->right))// grandfather and his brother are all red
                        {
                            recolor(gf->parent);
                            f = gf;
                            gf = gf->parent;
                        }
                        else// grandfather 's brother is black
                        {
                            if(gf->parent->left == gf)
                            {
                                if(gf->left == f) LL(gf->parent);
                                else LR(gf->parent);
                            }
                            else
                            {
                                if(gf->left == f) RL(gf->parent);
                                else RR(gf->parent);
                            }

                            root->color = BLACK;
                            mid_order(root);

                            return ;
                        }
                    }
                }
            }
        }
        root->color = BLACK;
        mid_order(root);
    }
    void delete_node(int value)
    {
        Node *target = find_node(value, root);
        Node *tmp;
        if(!target) return ;
        if(target->left && target->right)
        {
            tmp = target->left;
            while(tmp->right) tmp = tmp->right;
            target->data = tmp->data;
            target = tmp;
        }
        if(!target->left && !target->right)// no sons
        {
            if(target == root) {delete root; root = NULL;}
            else// must have its father
            {
                if(!target->color)// red leaf
                {
                    if(target == target->parent->left) target->parent->left = NULL;
                    else target->parent->right = NULL;
                    delete target;
                }
                else// black leaf
                {
                    if(!return_color(return_brother(target)))// brother is red
                    {
                        if(target->parent->right == target)
                        {
                            target->parent->color = BLACK;
                            return_brother(target)->color = BLACK;
                            return_brother(target)->right->color = RED;
                            LLb(target->parent);
                        }
                        else
                        {
                            target->parent->color = BLACK;
                            return_brother(target)->color = BLACK;
                            return_brother(target)->left->color = RED;
                            RRb(target->parent);
                        }
                        if(target->parent->left == target) target->parent->left = NULL:
                        else target->parent->right = NULL;
                        delete target;
                    }
                    else// brother is black
                    {
                        if(return_color(return_brother(target)->left) + return_color(return_brother(target)->right) == 1)// have one red son
                        {
                            bool r_color = target->parent->color;
                            if(target->parent->left == target)
                            {
                                if(return_brother(target)->left == RED)
                                {
                                    return_brother(target)->left->color = r_color;
                                    target->parent->color = BLACK;
                                    LLb(return_brother(target));
                                    RRb(target->parent);
                                }
                                else
                                {
                                    RRb(target->parent);
                                    target->parent->color = BLACK;
                                    target->parent->parent->color = r_color;
                                    target->parent->parent->right->color = BLACK;
                                }
                            }
                            else
                            {
                                if(return_brother(target)->left == RED)
                                {
                                    LLb(target->parent);
                                    target->parent->color = BLACK;
                                    target->parent->parent->color = r_color;
                                    target->parent->parent->left->color = BLACK;
                                }
                                else
                                {
                                    return_brother(target)->right->color = r_color;
                                    target->parent->color = BLACK;
                                    RRb(return_brother(target));
                                    LLb(target->parent);
                                }
                            }
                            if(target->parent->left == target) target->parent->left = NULL;
                            else target->parent->right = NULL;
                            delete target;
                        }
                        else if(!return_color(return_brother(target)->left) && !return_color(return_brother(target)->right))// have two red son
                        {
                            bool r_color = target->parent->color;
                            if(target->parent->left == target)
                            {
                                target->parent->right->left->color = r_color;
                                target->parent->color = BLACK;
                                RRb(target->parent->right);
                                LLb(target->parent);
                            }
                            else
                            {
                                target->parent->left->right->color = r_color;
                                target->parent->color = BLACK;
                                RRb(target->parent->left);
                                LLb(target->parent);
                            }
                            if(target->parent->left == target) target->parent->left = NULL;
                            else target->parent->right = NULL;
                            delete target;
                        }
                        else// have no red son
                        {
                            if(target->parent->left == target)
                            {
                                if(target->parent->color == RED)
                                {
                                    target->parent->color = BLACK;
                                    target->parent->rght = RED;
                                    target->parent->left = NULL;
                                    delete target;
                                }
                                else
                                {
                                    target = target->parent;
                                    while(return_brother(target)->left->color != RED && return_brother(target)->right->color != RED)
                                    {
                                        ;
                                    }
                                }
                            }
                            else
                            {
                                if(target->parent->color == RED)
                                {
                                    target->parent->color = BLACK;
                                    target->parent->left = RED;
                                    target->parent->right = NULL;
                                    delete target;
                                }
                            }
                        }
                    }
                }
            }
        }
        else// have one son
        {
            if(target->left) {target->data = target->left->data; delete target->left; target->left = NULL; }
            else {target->data = target->right->data; delete target->right; target->right = NULL;}
        }
    }
    void mid_order(Node *node)
    {
        if(node->left) mid_order(node->left);
        cout << node->data << ' ' << node->color << endl;
        if(node->right) mid_order(node->right);
    }
};

int main()
{
    red_black_tree t;
    t.insert_node(14);cout << "*************************\n";
    t.insert_node(6);  cout << "*************************\n";
    t.insert_node(10);cout << "*************************\n";
    t.insert_node(17);cout << "*************************\n";
    t.insert_node(16);cout << "*************************\n";
    t.insert_node(19);cout << "*************************\n";
    t.insert_node(12);cout << "*************************\n";
    t.insert_node(8);  cout << "*************************\n";
    return 0;
}
