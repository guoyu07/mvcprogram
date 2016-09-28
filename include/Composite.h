#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include <iostream>
#include <vector>
using namespace std;

// 2. Create an "interface" (lowest common denominator)
class Component
{
	protected:
		int value;
		vector < Component * > children; // 4. "container" coupled to the interface
	public:
		//	virtual void traverse() = 0;
		virtual void traverse()
		{
			if (isLeaf()) {
				cout <<"" <<value << ' ';
			} else {
				cout<<"["<<value<<"]: ";
				for (int i = 0; i < children.size(); i++)
					// 5. Use polymorphism to delegate to children
					children[i]->traverse();
			}
		}
		virtual int getValue() { return value;}
		virtual bool isLeaf() = 0;
};

class Leaf: public Component
{
	// 1. Scalar class   3. "isa" relationship
	//	int value;
	public:
		Leaf(int val)
		{
			value = val;
		}
		//	void traverse()
		//	{
		//		cout << value << ' ';
		//	}
		/*virtual*/ bool isLeaf(){return true;};
};

class Composite: public Component
{
	// 1. Vector class   3. "isa" relationship
	public:
		// 4. "container" class coupled to the interface
		void add(Component *ele)
		{
			children.push_back(ele);
			value += ele->getValue();
		}
		//	virtual void traverse()
		//	{
		//		for (int i = 0; i < children.size(); i++){
		// 5. Use polymorphism to delegate to children
		//			cout<<":"<<i<<": ";
		//			children[i]->traverse();
		//		}
		//	}
		Composite(){
			value = 0;
		}
		/*virtual*/ bool isLeaf(){return false;};
};

#endif

