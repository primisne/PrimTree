#include <queue>
#include <stack>
#include <vector>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;
template<class T> class vecter;

template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(int el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	T key;
	Node *left, *right ;
};

template<class T>
class Tree {
public:
	vector<T> myvecter;       
	Node<T> *root;
	Node<T> *temp;
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	void visit(Node<T> *p);
	int height(Node<T> *p);
	void balance(vector<T> myvecter, int first, int last);
	void TreeSize(Node<T> *p, int *count);
	bool search(const T &el)   ;
	void deletemmerging(Node<T> *p);
	void findAndDeletebymerging(const T &el);
	

protected:

	void clear(Node<T> *p);
	void inorder(Node<T> *p);

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
	     clear(p->left);
	     clear(p->right);
	     delete p;
	}
}


template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	while(p != 0) {
		prev = p;
		if(p->key < el)
			p=p->right;
		else
			p=p->left;
	}
	if(root == 0)
		root = new Node<T>(el);
	else if(prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp=node;
	if(node->right == 0)
		node = node->left;
	else if(node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while(tmp->right != 0) {
			prev = tmp;
			tmp=tmp->right;
		}
		node->key = tmp->key;
		if(prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	if (p != 0) {
		inorder(p->left);   
		visit(p);
		inorder(p->right);
		  
}

}

template<class T>
void Tree<T>::visit(Node<T> *p){
	cout << p->key << endl;
	myvecter.push_back(p->key);    
}


template<class T>
int Tree<T>::height(Node<T> *p){
	if (p == NULL)
    {
        return 0;
    }

    int Left = height(p->left);
    int Right = height(p->right); 

    if (Left > Right)
        return 1 + Left;
    else
        return 1 + Right;;
}
template<class T>
void  Tree<T>::balance(vector<T> myvecter, int first, int last)
    {    
		if (first <= last) 
		{
			int middle = (first + last)/2;
			insert(myvecter.at(middle));
			balance(myvecter, first, middle-1);
			balance(myvecter, middle+1, last);
		}
}

template<class T>
bool Tree<T>::search(const T &el)       
{
   Node<T> *temp=root;     

   while(temp!=NULL)
   {
      if(temp->key==el)
         break;

      if(el>temp->key)
         temp=temp->right;

      if(el<temp->key)
         temp=temp->left;
   }

   if(temp==NULL)
      return false; 
   else if(temp->key==el)
         return true;   
}  

template<class T>
void Tree<T>::deletemmerging(Node<T> *p) {
	 Node<T> *temp=p;
	 if(p != 0){
	 if(!p->right)
		 p=p->left;

	 else if(p->left==0)
	  p=p->right;
	 else
	   {temp = p->left;
	   while (temp->right==0)
		   temp = temp->right;
	   temp->right = p->right;
	   temp = p;
	   p = p->left;
    }
		 delete temp;
	 }
 }

template<class T>
void Tree<T>::findAndDeletebymerging(const T &el)
{  Node<T> *p = root, *prev = 0;
	while(p!=0){
	   if (p->key == el)
		   break;
	   prev = p;
	   if (p->key < el)
		   p = p->right;
	   else
		   p = p->left;
	}
	if(p != 0&& p->key == el)
		if (p == root)
			deletemmerging(root);
		else if(prev->left == p)
			deletemmerging(prev->left);
		else deletemmerging(prev->right);
	else if (root != 0)
		cout <<"Key"<< el << "is not in a tree."<<endl;
	else cout<< "the tree is empty."<<endl;
}



