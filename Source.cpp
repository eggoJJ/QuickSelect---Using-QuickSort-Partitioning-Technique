using namespace std;
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

int quickSelect(vector<int>&, int, int, int);

int partion(vector<int>&, int, int);



int main()
{

	srand(time(0));
	int n;
   
	cout << "Enter an array size" << endl;
	cin >> n;
	vector<int>a(n);

	int key;
	char quit;
	while(1)

	{
		for (int j = 0; j < a.size(); j++)
		{
			
			a[j] = 0;
			a[j] = rand() % (201) - 100;
			
		}
		cout << '\n' << '\n';

		key = rand() % (a.size()-1) + 1;
		cout << "The " << key << " least value is " << a[quickSelect(a, key, 0, a.size() - 1)];
		cout << '\n' << '\n' << "------------------------------" << endl;

		sort(a.begin(), a.end());

		for (int j = 0; j < a.size(); j++)
		{
			if (j % 10 == 0 && j != 0) cout << endl;
			if (j == key - 1)
			{
				cout << "***" << a[j] << "***,";
			}
			else
			cout << a[j] << ",";
		}
		cout << '\n' << '\n' << endl;
		quit = getchar();
		if (quit == 'x') break;

	}

	cout << "Enter an array size" << endl;
	cin >> n;
	vector<int>z(n);
	while (1)

	{
		for (int j = 0; j < z.size(); j++)
		{

			z[j] = 0;
			z[j] = rand() % (201) - 100;

		}
		cout << '\n' << '\n';

		key = rand() % (z.size() - 1) + 1;
		cout << "The " << key << " greatest values are ";
		int maxStart = quickSelect(z, z.size() - key, 0, z.size() - 1) +1;
			for (int i = maxStart; i < z.size(); i++)
			{
				cout << z[i] << ", ";
			}
		
		cout << '\n' << '\n' << "------------------------------" << endl;

		sort(z.begin(), z.end());

		for (int j = 0; j < z.size(); j++)
		{
			if (j % 10 == 0 && j != 0) cout << endl;
			if (j == maxStart)
			{
				cout << " *( " << z[j] << ", ";
			}
			else
				cout << z[j] << ",";
		}
		cout << " )* ";
		cout << '\n' << '\n' << endl;
		quit = getchar();
		if (quit == 'x') break;

	}

	
	system("pause");
	return 0;
}

int partion(vector<int> &a, int left, int right)
{
	
	int middleIndex = (right+left) / 2;
	int median = a[middleIndex];
	a[middleIndex] = a[right];
	a[right] = median;

	int temp = right;
	right--;
    while (left <= right) // Traverse 
	{
		
		while (a[left] < median) { left++; } // Left pointer moves if valid
		while (a[right] > median && right!= left) { right--; } // right pointer moves if valid

		if (left >= right) { break; } // If pointers are crossed leave the loop
		swap(a[left], a[right]);  // If we get this far we can swap indexes, also move left pointer 
		left++;

	}
    swap(a[left], a[temp]);
    return left;
	// return the point where our array's are split

	
	
}



int quickSelect(vector<int> &a, int k, int left, int right)
{

	int location = partion(a, left, right); // return the location of the pivot
											// at this point all values to the left are less than and all values to the right are greater than
	
	if ((location - left + 1) == k) return location; 
	
	else if (location - left + 1 < k) quickSelect(a, k - (location - left + 1), location + 1, right);

	else quickSelect(a, k, left, location - 1);


}
