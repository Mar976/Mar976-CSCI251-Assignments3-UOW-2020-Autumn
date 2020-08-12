#include <iostream>
#include "collect.h"
#include <vector>
using namespace std;

class Knapsack
{
	private:
		A a;
		B b;
		C c;	
		D d;
		E e;
		F f;
		G g;
		int knapsackSize,seedNum;
		vector<char> knapsackItems;	
		int total;
		bool flag;
		int listA[3],listB[3],listC[3],listD[3],listE[3],listF[3],listG[3];
	public:
		template <typename T>
		bool addIt(int* knapsackSize,vector<char>& knapsack,T obj,int* total,int* arrayOfObjInfo);
		Knapsack(int knapsackSize, int seedNum);
		void process();
		void print();
};
