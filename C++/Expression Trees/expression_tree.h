/*
NAME:	Nusra Ahmed
DATE:	11/10/17
FILE:	expression_tree.h
DESCR:	Lab #10: Uses a binary tree to evaluate postfix expressions
*/

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H
#include <iostream> 
#include <stack>
#include <queue>
using namespace std;

struct exp_node
{
	int number;
	char op;
	exp_node* left_field; // Pointer to left child node
	exp_node *right_field; // Pointer to right child node
};

class expression_tree
{
public:
	// Default constructor
	expression_tree();
	//Parameterized constructor
	expression_tree(istream& ins);
	// Destructor and function to destroy individual subtrees
	void destroySubTree(exp_node* node_ptr);
	~expression_tree() { destroySubTree(root_ptr); }

	//member functions
	exp_node* get_root() { return root_ptr; }
	exp_node* buildTree(queue<exp_node*> postfix);
private:
	exp_node *root_ptr; // Pointer to the root node
};

//default constructor
expression_tree::expression_tree()
{
	root_ptr = nullptr;
}

//function used in destructor(declared inline)
void expression_tree::destroySubTree(exp_node * node_ptr)
{
	if (node_ptr)
	{
		if (node_ptr->left_field)
			destroySubTree(node_ptr->left_field);
		if (node_ptr->right_field)
			destroySubTree(node_ptr->right_field);
		delete node_ptr;
	}

}

//parameterized constructor
expression_tree::expression_tree(istream& ins) {
	//create a queue with the postfix expression in it.
	queue<exp_node*> postfix;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()))
		{
			exp_node *val = new exp_node;
			ins >> val->number;
			val->op = NULL;
			val->left_field = val->right_field = nullptr;
			postfix.push(val);
		}
		else if (strchr("+*", ins.peek()) != nullptr)
		{
			exp_node *symbol = new exp_node;
			ins >> symbol->op;
			symbol->number = NULL;
			symbol->left_field = symbol->right_field = nullptr;
			postfix.push(symbol);
		}
		else if (ins.peek() == ' ') {
			ins.ignore();
		}
		else
		{
			cout << "Invalid Expression" << endl;
			exit(-1);
		}
	}

	//pass the stack to a seperate function to build the tree
	root_ptr = buildTree(postfix);
}

//function to build the tree
exp_node* expression_tree::buildTree(queue<exp_node*> postfix) {
	stack<exp_node*> treeStack;
	exp_node *tree_ptr, *t1, *t2;

	//Traverse through the postfix queue
	while (postfix.size() > 0)
	{
		// If the current exp_node* is a number
		if (postfix.front()->op == NULL) //postfix.top() is not an operator, therefore op == NULL;
		{
			tree_ptr = postfix.front();
			postfix.pop(); //pop the front value off of the queue
			treeStack.push(tree_ptr); //push it onto the treeStack
		}
		else //the current exp_node* is '+' or '*'
		{
			tree_ptr = postfix.front(); //set tree_ptr to the operand
			postfix.pop(); //pop the front value off of the queue

			//pop two top nodes off of the treeStack after storing them in temp variables
			t1 = treeStack.top(); 
			treeStack.pop();      
			t2 = treeStack.top();
			treeStack.pop();

			//set the temp variables as children of the tree_ptr since it is an operand
			tree_ptr->right_field = t1;
			tree_ptr->left_field = t2;

			//finally add this tree_ptr to the stack
			treeStack.push(tree_ptr);
		}
	}

	//loop ends, tree_ptr is set to the top/only value of the stack
	tree_ptr = treeStack.top();
	treeStack.pop();

	//returns back to the parameterized constructor
	return tree_ptr;
}

//function to determine if an exp_node* is a leaf
bool is_leaf(const exp_node* node_ptr)
{
	return (node_ptr->left_field == nullptr) && (node_ptr->right_field == nullptr);
}

//function used to process the operands from the evaluate function
int calculate(int A, int B, char op) {
	if (op == '+')
		return A + B;
	else
		return A * B;
}

//recursive non-member functions to evaluate and return an integer
int evaluate(exp_node* node_ptr)
{
	//tree is empty
	if (node_ptr == nullptr)
		return 0;
	//node is an integer, returns if root is a leaf as well
	else if (is_leaf(node_ptr))
		return node_ptr->number;
	else {
		//recursively evaluate the left subtree (postorder)
		int left_value = evaluate(node_ptr->left_field);
		//recursively evalute the right subtree (postorder)
		int right_value = evaluate(node_ptr->right_field);
		//visit the node to perform operations
		if (node_ptr->op == '+')
			return left_value + right_value;
		else if (node_ptr->op == '*')
			return left_value * right_value;
		else
			return -99999; //error in program
	}
}

#endif

/*OUTPUT
Enter the postfix expression: 3 7 + 14 *
				*
					14 [leaf]
					+
						7 [leaf]
						3 [leaf]

		==> evaluates to 140
Enter another postfix expression or <Enter> to end: 1 2 + 4 * 3 +
						+
							3 [leaf]
							*
								4 [leaf]
								+
									2 [leaf]
									1 [leaf]

		==> evaluates to 15
Enter another postfix expression or <Enter> to end:
This concludes the Binary Tree Math Postfix Expression program!

Press any key to continue . . .
*/