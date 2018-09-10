#include <iostream>
using namespace std;
int main()
{

	int numa = 0; int numb = 0;

	cout<<"Inserte la base (a):";
	cin>>numa;
	cout << "Inserte la altiura (b):";
	cin >> numb;

	for (int b = 1; b <= numb; b++)
	{
		for (int a = 1; a <= numa; a++)
		{
			if (b == 1 || b == numb)
			{
				cout<<"* ";
			}
			else if (a == 1 || a == numa) {
				cout << "* ";
			}
			else {

				cout << "__";
			}
		}
		cout << "\n";
	}





	system("pause>nul");
}