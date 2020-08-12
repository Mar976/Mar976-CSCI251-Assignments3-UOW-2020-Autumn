#include <vector>
#include <iostream>
#include "collect.h"
#include <typeinfo>
#include <cstring>
#include "A3.h"
using namespace std;

int main(int argc,char *argv[])
{
	//Checking the numbers of arguments
	if(argc!=3)
	{
		cout<<"Less Numbers of Argument!"<<endl;
		exit(0);
	}
	int knapsackSize=0,seedNum=0;
	//Checking if the arguments are number and conver it to the numbers
	try
	{
		knapsackSize=stoi(argv[1]);
		seedNum=stoi(argv[2]);
	}
	catch(exception& e)
	{
		cout<<"The arguments should be number!"<<endl;
		exit(0);
	}
	//Check number is positive
	if(knapsackSize<=0 || seedNum<=0)
	{
		cout<<"The numbers need to be positive!"<<endl;
		exit(0);
	}
	//creating an obj of Knapsack and setting the size of bag and seed number to K obj;
	Knapsack k(knapsackSize,seedNum);
	//Processing the Knapsack and adding objects to the beg
	k.process();
	//printing the objects
	k.print();
	return 0;
}

//KNAPSACK CLASS
//Constructor to set the attributes to the default. 
Knapsack::Knapsack(int knapsackSize,int seedNum)
{
	this->knapsackSize=knapsackSize;
	this->seedNum=seedNum;
	total=0;
	listA[2]=listB[2]=listC[2]=listD[2]=listE[2]=listF[2]=listG[2]=0;
	flag=true;
}
//template to get object of any type and take the size and name from it and add it to the beg.
template <typename T>
bool Knapsack::addIt(int* knapsackSize,vector<char>& knapsackItems,T obj,int* total,int* arrayOfObjInfo)
{
	int objSize=sizeof(obj);
	char objName=obj.getName();
        if(*knapsackSize>=objSize)
        {
                *knapsackSize-=objSize;
                *total+=objSize;
                knapsackItems.push_back(objName);
        	arrayOfObjInfo[0]=0;
                arrayOfObjInfo[1]=objSize;
		arrayOfObjInfo[2]+=1; 
	        return true;
        }
        return false;
}
//generating a char and base on char generate, create obj of that type.
void Knapsack::process()
{
	int defaultRunLimit=0;
	char obj;
	int j=0;
	cout<<"Knapsack Size:"<<knapsackSize<<endl;
	while(flag)
	{
		obj=generate(seedNum);
		switch(obj)
		{
		case 'A':
		{
			flag=addIt(&knapsackSize,knapsackItems,a,&total,listA);
		}
		break;
        	case 'B':
		{
                         flag=addIt(&knapsackSize,knapsackItems,b,&total,listB);
                 }
		break;
          	case 'C':
		{
                         flag=addIt(&knapsackSize,knapsackItems,c,&total,listC);
	        }
		        break;
                case 'D':
		{
          	         flag=addIt(&knapsackSize,knapsackItems,d,&total,listD);
                }
		break;
                case 'E':
		{
                         flag=addIt(&knapsackSize,knapsackItems,e,&total,listE);
	        } 
              	break;
                case 'F':
		{
                          flag=addIt(&knapsackSize,knapsackItems,f,&total,listF);
                }
		break;
                case 'G':
		{
                          flag=addIt(&knapsackSize,knapsackItems,g,&total,listG);
               	}
		break;
		default:
			if(defaultRunLimit!=5)//so I do not want the code to run for forever, therefore,
			{			//the program can take only 5 wrong char. 
				cout<<"Charachter does not exist!"<<endl;
				defaultRunLimit++;
			}
			else
			{
				exit(0);
			}
		}
	}
}
void Knapsack::print()
{
	cout<<"Added object size:"<<total<<endl;
	for(int i=0;i<knapsackItems.size();i++)
	{
		cout<<knapsackItems[i];
	}
	cout<<endl;
	if(listA[2]!=0)
	{
		cout<<a.getName()<<":"<<listA[1]<<","<<listA[2]<<endl;
	}
	if(listB[2]!=0)
        {
               cout<<b.getName()<<":"<<listB[1]<<","<<listB[2]<<endl;
        }
	if(listC[2]!=0)
        {
                cout<<c.getName()<<":"<<listC[1]<<","<<listC[2]<<endl;
        }
	if(listD[2]!=0)
        {
                cout<<d.getName()<<":"<<listD[1]<<","<<listD[2]<<endl;
        }
	if(listE[2]!=0)
        {
                cout<<e.getName()<<":"<<listE[1]<<","<<listE[2]<<endl;
        }
	if(listF[2]!=0)
        {
                cout<<f.getName()<<":"<<listF[1]<<","<<listF[2]<<endl;
        }
	if(listG[2]!=0)
        {
                cout<<g.getName()<<":"<<listG[1]<<","<<listG[2]<<endl;
        }
}
