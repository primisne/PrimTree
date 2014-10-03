#include <iostream>
#include <string>
#include <sstream>
#include "tree.h"
#include <fstream>
using namespace std;

void main()
{
	Tree<int> mytree;
	 

	int i ;
	int a;
	int b;
	int c;
	
	cout<< "How many Node Do you want to insert?";
	cin>>a;
	for(i = 1; i <= a; i++)
        {   int  x=rand();
            mytree.insert(x);
		    
        }
			
	mytree.inorder();
	cout<<"Height=>"<<mytree.height(mytree.root);
	mytree.clear();
	mytree.balance(mytree.myvecter,0,mytree.myvecter.size()-1);
	cout<<endl;
	cout<<"Height Balance=>"<<mytree.height(mytree.root);
	cout<<endl;
	cout<< "What node Do you want to Search?";
	cin>>c;
	cout<<"Search=>"<<mytree.search(c);
	cout<<endl;
	cout<< "What node Do you want to Delete?";
	cin>>b;
  mytree.findAndDeletebymerging(b);
	cout<<"Height when deleted=>"<<mytree.height(mytree.root);	    
        

}
