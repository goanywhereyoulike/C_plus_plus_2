/****
 THis is started code for SceneGraph project. This code is only a shell and no attempt to compile it has not been made.

 A SceneGraph in games is a very important data structure which manages all the objects active in the game level in terms of the their interconnections, life span, updates, creation or deletion of game objects and such. Usually a tree structure is used for  this. In this project a simple scenegraph in form of a binary search tree is going to be implemented. Game objects are represented by the nodes in the tree. They all inherit from a base abstract object. Next week we learn more about abstract base classes and such in detail. For now, all the nodes are considered objects of type node. First educate yourself on binary search trees, if you are not somehow not familiar with it already.
Each node has a value, representing the data it contians, and coordinate x.
***/
#include <iostream>
#include <memory>
#include <string>
using namespace std;

template<typename T>
class BST {
private:
	struct node;
	using nodeP = unique_ptr<node>;
	struct node 
	{
		T value;
		int x;
		nodeP left;
		nodeP right;
		node(T data, int number) :value(data), x(number), left(nullptr), right(nullptr)
		{}
	};
	

	nodeP root;

// implement the functions described by these headers
	void insert(nodeP &tree, nodeP &mnode)
	{
		if (tree == nullptr)
		{

			tree = move(mnode);
		}
		else
		{
			node* temp = tree.get();
			node* prev = tree.get();
			while (temp)
			{
				prev = temp;
				if (temp->x < mnode->x)
					temp = temp->right.get();
				else
					temp = temp->left.get();
			}
			if (prev->x < mnode->x)
				prev->right = move(mnode);
			else
				prev->left = move(mnode);

		}
		
	}// insert node in the tree.
	bool find(nodeP &temp,T val, int x)
	{

		if (temp == nullptr)
		{
			return false;
		}
		if(temp->value == val&& temp->x==x)
		{
			return true;
		}
		if (temp->x < x)
		{
			return find(temp->right,val,x);
		}
		else
		{

			return find(temp->left,val, x);
		}
	
	
	
	
	}// find the node containing val and return it. This also removes the node from the tree. If not found, return nullptr.
// should print out the values in the tree in ascending order of x, This means "traversing" the tree "inOrder". Look up inOrder traversal.
	void terminate_tree(nodeP &tree)
	{
		if (tree == nullptr)
			return;

		terminate_tree(tree->left);
		terminate_tree(tree->right);
		cout << "delete trees:" << tree->value<<endl;
		tree.reset();
	
	}// should reclaim all the memory used in the tree.
	void print_tree(nodeP &tree)
	{
		if (tree != nullptr)
		{
			print_tree(tree->left);
			cout << "name: "<<tree->value << ", age: " << tree->x << endl;
			print_tree(tree->right);

		}

	}
public:
	BST() :root(nullptr) {}
	~BST() {}

	//void insert(nodeP temp)
	//{
	//
	//insert(temp->value,temp->x);
	//
	//}
	nodeP insert(const T &data, int x)
	{
		auto temp=make_unique<node>(data, x);

		insert(root, temp);

		return temp;
	}
	void print_tree()
	{
		print_tree(root);
		cout << endl;

	}

	bool find(T data,  int x)
	{
		return find(root,data, x);
	
	}

	void deletetree()
	{
		terminate_tree(root);
	}
};
int main()
{
	BST<string> tree;
	tree.insert("Tom", 15);
	tree.insert("Tim", 14);
	tree.insert("Adam", 16);
	tree.insert("Oliver", 20);
	tree.insert("Jack", 11);
	tree.insert("Harry", 16);
	tree.insert("James", 21);
	tree.insert("Lily", 30);
	tree.insert("Sophie", 17);
	tree.insert("Emily", 10);
	tree.insert("Smith", 29);
	tree.insert("Roberts", 32);
	tree.insert("Isla", 34);
	tree.insert("Ava", 9);
	tree.insert("Poppy", 36);
	tree.print_tree();

	bool isfind1= tree.find("Harry",16);
	cout <<"Find Harry?: "<< boolalpha <<isfind1<< endl;
	bool isfind2 = tree.find("Tam", 15);
	cout << "Find Tam?: "<<boolalpha << isfind2 << endl;
	cout << endl;
	tree.deletetree();
	// create a tree of T being string. Insert into it 15 pair of {name, age} into it. THis could be 15 favorite persons of you and such with 15 different age. Fo reach person: 1)create  a nodeP, 2) insert it into the tree. 
	// Next call print_tree().
	// Next use find() to look for 2 person in your tree, one should be in your tree, and one should not. Print the result of find for each case.
	// call terminate to clean up the tree. Make sure the tree is fully empty at the end.
	// MAKE SURE you implement all above such that it is genereic and your tree can be used for other type T's with least changes possible. 
	system("pause");
	return 0;
}