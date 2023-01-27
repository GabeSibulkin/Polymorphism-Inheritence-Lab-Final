/*
Gabe Sibulkin Polymorphism and Inheritance Project submitted 12/5/22
*/

#include "Shapes.h"
#include <iostream>
#include <vector>

using namespace std;

void getsmallestarea(vector<Shape2D*> shapes2D) // passes in whole 2D shape vector, all these  
{												// funcs do the exact same thing but with largest and 3D too 
	int smallestarea = 0;

	Shape2D* smallshape; // init a whole new placeholder to equate object

	smallshape = shapes2D[0]; // init object

	smallestarea = shapes2D[0]->area; // init int value for sorting

	for (int i = 0; i < shapes2D.size(); i++) // loop for whole vector
	{
		if (smallestarea > shapes2D[i]->area) // tests to find smallest 
		{
			smallestarea = shapes2D[i]->area; // sets area for comparison
			smallshape = shapes2D[i]; // sets placeholder object to display name and data
		}
	}

	cout << "Smallest Shape is: " << smallshape->name << ": " << smallshape->area << endl; // display

}

void getsmallestvolume(vector<Shape3D*> shapes3D) // passes in whole 3D shape vector
{
	int smallestvolume = 0;

	Shape3D* smallshape;

	smallshape = shapes3D[0];

	smallestvolume = shapes3D[0]->volume;

	for (int i = 0; i < shapes3D.size(); i++)
	{
		if (smallestvolume > shapes3D[i]->volume)
		{
			smallestvolume = shapes3D[i]->volume;
			smallshape = shapes3D[i];
		}
	}

	cout << "Smallest Shape is: " << smallshape->name << ": " << smallshape->volume << endl;
}


void getlargestarea(vector<Shape2D*> shapes2D)
{
	int largestarea = 0;

	Shape2D* largestshape;

	largestshape = shapes2D[0];

	largestarea = shapes2D[0]->area;

	for (int i = 0; i < shapes2D.size(); i++)
	{
		if (largestarea < shapes2D[i]->area)
		{
			largestarea = shapes2D[i]->area;
			largestshape = shapes2D[i];
		}
	}

	cout << "Largest Shape is: " << largestshape->name << ": " << largestshape->area << endl;
}

void getlargestvolume(vector<Shape3D*> shapes3D)
{
	int largestvolume = 0;

	Shape3D* largestshape;

	largestshape = shapes3D[0];

	largestvolume = shapes3D[0]->volume;

	for (int i = 0; i < shapes3D.size(); i++)
	{
		if (largestvolume < shapes3D[i]->volume)
		{
			largestvolume = shapes3D[i]->volume;
			largestshape = shapes3D[i];
		}
	}

	cout << "Largest Shape is: " << largestshape->name << ": " << largestshape->volume << endl;
}

vector<Shape2D*> insertsort(vector<Shape2D*> shapes2D) // insert Sort func that returns sorted vector of shapes
{
	int i, j;

	Shape2D* key; // placeholer object

	for (i = 1; i < shapes2D.size(); i++) // goes through whole vector
	{
		key = shapes2D[i]; // init key 
		j = i - 1;

		while (j >= 0 && shapes2D[j]->area > key->area) // compares values
		{
			shapes2D[j + 1] = shapes2D[j]; // sets to next
			j = j - 1; 
		}
		shapes2D[j + 1] = key; // sets key object to next vector object
	}

	return shapes2D; // returns final sorted vector
}

void binsearch(vector<Shape2D*> shapes2D, int key) // binary search func
{
	int occurances = 0;

	for (int i = 0; i < shapes2D.size(); i++) // iterates through whole vector
	{
		if (shapes2D[i]->area >= key) // checks if areas are greater than or equal to key value
		{
			occurances++; // incs occurances
		}
	}

	cout << "Found: " << occurances << " occurances of areas greater than or equal to: " << key << endl; // disp
}


int main()
{
	int scalefactor = 1; // default scale factor so we don't multiply by 0

	vector<Shape2D*> shapes2D;

	vector<Shape3D*> shapes3D;

	int choice = 0;

	while (choice != 11) // big boy loop
	{
		cout << "1: Populate with preset data" << endl;
		cout << "2: Display 2D shapes" << endl;
		cout << "3: Display 3D shapes" << endl;
		cout << "4: Find Smallest 2D shape" << endl;
		cout << "5: Find Smallest 3D shape" << endl;
		cout << "6: Find Largest 2D shape" << endl;
		cout << "7: Find Largest 3D shape" << endl;
		cout << "8: Sort the 2D shapes" << endl;
		cout << "9: Binary Search for key and above" << endl;
		cout << "10: Set Scale Factor" << endl;
		cout << "11: Quit" << endl;

		cout << "Scale Factor is set to: " << scalefactor << endl;

		cout << "Enter in choice: ";
		cin >> choice;

		cout << "\n";

		switch (choice) // switch case
		{
			case 1: // populate
			{
				if (!shapes2D.empty())
				{
					cout << "Already full" << endl;
					break;
				}
				else
				{
					shapes2D.push_back(new Square());
					shapes2D.push_back(new Square("square1", 5));

					shapes2D.push_back(new Rectangle());
					shapes2D.push_back(new Rectangle("rect1", 6, 5));

					shapes2D.push_back(new Triangle());
					shapes2D.push_back(new Triangle("tri1", 3, 4));

					shapes2D.push_back(new Circle());
					shapes2D.push_back(new Circle("circ1", 3));

					shapes2D.push_back(new Ellipse());
					shapes2D.push_back(new Ellipse("ell1", 2, 3));

					shapes2D.push_back(new Trapezoid());
					shapes2D.push_back(new Trapezoid("trap1", 2, 2, 3));

					shapes2D.push_back(new Sector());
					shapes2D.push_back(new Sector("sect1", 2, 30));


					for (int i = 0; i < shapes2D.size(); i++) // recalculates the areas with new scale factor everytime
					{
						shapes2D[i]->setscalefactor(scalefactor);
						shapes2D[i]->areacalc();
					}

					shapes3D.push_back(new TriPyramid());
					shapes3D.push_back(new TriPyramid("tripyr1", 3, 4, 5));

					shapes3D.push_back(new RectPyramid());
					shapes3D.push_back(new RectPyramid("rectpyr1", 3, 4, 5));

					shapes3D.push_back(new Cylinder());
					shapes3D.push_back(new Cylinder("cylinder1", 3, 4));

					shapes3D.push_back(new Sphere());
					shapes3D.push_back(new Sphere("sphere1", 3));


					for (int i = 0; i < shapes3D.size(); i++) // recalculates the vols with new scale factor everytime
					{
						shapes3D[i]->setscalefactor(scalefactor);
						shapes3D[i]->volcalc();
					}

					break;
				}

				
			}
			case 2: // Disp 2D data
			{
				if (shapes2D.empty()) // Do empty check every time to make sure
				{
					cout << "Empty" << endl;
					break;
				}


				for (int i = 0; i < shapes2D.size(); i++)
				{
					shapes2D[i]->display();
				}

				break;
			}
			case 3: // Disp 3D data
			{
				if (shapes3D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				for (int i = 0; i < shapes3D.size(); i++)
				{
					shapes3D[i]->display();
				}

				break;
			}
			case 4: // Smallest 2D
			{
				if (shapes2D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				getsmallestarea(shapes2D);

				break;
			}
			case 5: // Smallest 3D
			{
				if (shapes3D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				getsmallestvolume(shapes3D);

				break;
			}
			case 6: // Largest 2D
			{
				if (shapes2D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				getlargestarea(shapes2D);


				break;
			}
			case 7: // Largest 3D
			{
				if (shapes3D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				getlargestvolume(shapes3D);

				break;
			}
			case 8: // Sort 2D
			{
				vector<Shape2D*> temp;

				if (shapes2D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				temp = insertsort(shapes2D);

				cout << "Here's the list from lowest to highest: " << endl;

				for (int i = 0; i < temp.size(); i++) // display temp vector
				{
					cout << temp[i]->name << ": " << temp[i]->area << endl;
				}

				break;
			}
			case 9: // Bin Search
			{
				if (shapes2D.empty())
				{
					cout << "Empty" << endl;
					break;
				}

				int key = 0;

				cout << "Enter in key to search for and any greater: ";
				cin >> key;

				binsearch(shapes2D, key);

				break;
			}
			case 10: // Set Scale factor
			{
				cout << "Enter in new Scale Factor: " << endl;

				cin >> scalefactor;

				if (shapes2D.empty())
				{
					break;
				}
				else // recalculates all the areas when new scalefactor is set
				{
					for (int i = 0; i < shapes2D.size(); i++)
					{
						shapes2D[i]->setscalefactor(scalefactor);
						shapes2D[i]->areacalc();
					}
				}
			
				if (shapes3D.empty())
				{
					break;
				}
				else // recalculates all the volumes when new scalefactor is set
				{
					for (int i = 0; i < shapes3D.size(); i++)
					{
						shapes3D[i]->setscalefactor(scalefactor);
						shapes3D[i]->volcalc();
					}
				}
			
				break;
			}
		}

	}

	return 0;
}


