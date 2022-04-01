#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

#define BLACK 0
#define RED 1

namespace ft
{
    template < class T >
    struct Node
    {
        struct Node * parent;
        struct Node * left;
        struct Node * right;
        T value;
        bool color;

        Node(val) : parent(NULL), left(NULL), right(NULL), value(val), color(RED) {}
    };
    
    template < class T >
    class red_black_tree
    {
    private:
        Node * root;
    public:

        red_black_tree(/* args */);
        ~red_black_tree();

        bool isRed(Node * k)
        {
            if (!k) return BLACK;
            return k->color == RED;
        };

        balance_after_insetion(T k)
        {
            Node * u;
            while (isRed(k->parent))
            {
                if (k->parent == k->parent->parent->right)
                {
                    u = k->parent->parent->left;
                    if (isRed(u))
                    {
                        k->parent->color = BLACK;
                        u->color = BLACK;
                        k->parent->parent->color = RED;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->left)
                        {
                            k = k->parent;
                            right_rotate(k);
                        }
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        left_rotate(k->parent->parent);
                    }
                }
                else
                {
                    u = k->parent->parent->right;
                    if (isRed(u))
                    {
                        k->parent->color = BLACK;
                        u->color = BLACK;
                        k->parent->parent->color = RED;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->right)
                        {
                            k = k->parent;
                            left_rotate(k);
                        }
                        k->parent->color = BLACK;
                        k->parent->parent->color = RED;
                        right_rotate(k->parent->parent);
                    }
                }
                if (k == root)
                {
				    break;
			    }
            }
            root.color = BLACK;
        };
        balance_after_deletion(T x)
        {
            Node * s;
            while (x != root && x->color != BLACK)
            {
                if(x == x->parent->left)
                {
                    s = x->parent->right;
                    if (isRed(s))
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        left_rotate(x->parent);
                        s = x->parent->right;
                    }
                    if (!isRed(s->left) && !isRed(s->right))
                    {
                        s->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (!isRed(s->right))
                        {
                            s->color = RED;
                            s->left->color = BLACK;
                            right_rotate(s);
                            s = x->parent->right;
                        }
                        s->color = x->parent->color;
                        x->parent->color = BLACK;
                        s->right->color = BLACK;
                        left_rotate(x->parent);
                        x = root;
                    }
                }
                else
                {
                    s = x->parent->left;
                    if (isRed(s))
                    {
                        s->color = BLACK;
                        x->parent->color = RED;
                        right_rotate(x->parent);
                        s = x->parent->left;
                    }
                    if (!isRed(s->left) && !isRed(s->right))
                    {
                        s->color = RED;
                        x = x->parent;
                    }
                    else
                    {
                        if (!isRed(s->left))
                        {
                            s->color = RED;
                            s->right->color = BLACK;
                            left_rotate(s);
                            s = x->parent->left;
                        }
                        s->color = x->parent->color;
                        x->parent->color = BLACK;
                        s->left->color = BLACK;
                        right_rotate(x->parent);
                        x = root;
                    }
                }
            }
            x->color = BLACK;
        };
    };
    
} // namespace ft


#endif