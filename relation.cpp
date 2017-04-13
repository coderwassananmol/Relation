#include<iostream>
using namespace std;
class relation
{
	private:
		int arr1[10][2];
		int arr2[10][2];
		int n;
		int temp;
	public:
		void getData();
		void printData();
		int reflexive();
		int symmetric();
		int transitive();
		void makeDefault();
		relation(int num)
		{
			n=num;
			temp=0;
		}
};
void relation::makeDefault()
{
	temp=0;
}
void relation::getData()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(j==0)
			{
				cout << "Enter a: ";
				cin >> arr1[i][j];
			}
			else
			{
				cout << "Enter b: ";
				cin >> arr1[i][j];
			}
		}
	}
}
void relation::printData()
{
	cout << "{";
	for(int i=0; i<n; i++)
	{
		cout << "(";
		for(int j=0; j<2; j++)
		{
			if(j==0)
				cout << arr1[i][j] << ",";
			else
				cout << arr1[i][j];
		}
		cout << ")";
	}
	cout << "}";
}
int relation::reflexive()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(j==0)
			{
				if(arr1[i][j]==arr1[i][++j])
					temp=1;
				else
					temp=0;
			}
			else
			{
				continue;
			}
		}
	}
	return temp;
	makeDefault();
}
int relation::symmetric()
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr1[i][0]==arr1[j][1] && arr1[i][1]==arr1[j][0])
			{
				temp=1;
				return temp; 
			}
			else
			{
				temp=0;
			}
		}
	}
	return temp;
	makeDefault();
}
int relation::transitive()
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr1[i][1]==arr1[j][0])
			{
				for(int k=0; k<n; k++)
				{
					if(arr1[k][0]==arr1[i][0] && arr1[k][1]==arr1[j][1])
					{
						temp=1;
						return temp;
					}
					else
					{
						temp=0;
					}
				}
			}
		}
	}
	return temp;
	makeDefault();
}
int main()
{
	int n,ch,res;
	char choice;
	cout << "Enter number of relations: ";
	cin >> n;
	relation obj(n);
	obj.getData();
	cout << endl;
	cout << "The relation is: " << endl;
	obj.printData();
	cout << endl;
	do
	{
		cout << "What you wish to do?" << endl;
		cout << "1. Check if it is reflexive.\n";
		cout << "2. Check if it is symmetric.\n";
		cout << "3. Check if it is transitive.\n";
		cout << "Enter choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				res=obj.reflexive();
				if(res==1)
				{
					cout << "Yes, the relation is reflexive.\n";
				}
				else
				{
					cout << "No, the relation is not reflexive.\n";
				}
				cout << "Do you want to check any other property? (Y/N)\n";
				cin >> choice;
				break;
			case 2:
				res=obj.symmetric();
				if(res==1)
				{
					cout << "Yes, the relation is symmetric.\n";
				}
				else
				{
					cout << "No, the relation is not symmetric.\n";
				}
				cout << "Do you want to check any other property? (Y/N)\n";
				cin >> choice;
				break;
			case 3:
				res=obj.transitive();
				if(res==1)
				{
					cout << "Yes, the relation is transitive.\n";
				}
				else
				{
					cout << "No, the relation is not transitive.\n";
				}
				cout << "Do you want to check any other property? (Y/N)\n";
				cin >> choice;
				break;
			default:
				cout << "Wrong option, please choose again.\n";
		}
	} while(choice=='Y' || choice=='y');
	return 0;
}
