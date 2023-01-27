#pragma once
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const float PI = 3.14159f;

class Shape
{
public:

	string name = "";

	int area = 0.0f;
	int volume = 0.0f;

	int scalefactor = 1;


	void display() 
	{
		if (area == 0 && volume == 0) // checks if its a default shape
		{
			cout << name << ": " << to_string(area) << endl;
		}
		else if (volume == 0) // only 2D shapes
		{
			cout << name << ": " << to_string(area) << endl;
		}
		else if (area == 0) // only 3D shapes
		{
			cout << name << ": " << to_string(volume) << endl;
		}
		
	}

	void setscalefactor(int scale)
	{
		scalefactor = scale;
	}

};

class Shape2D : virtual public Shape
{
public:
	float side, width, height, base, radius, minor,
		major, sidea, sideb, angle;

	int shapetype = 0;

	Shape2D() // shape2D constructor
	{
		side = 0.0f;
		width = 0.0f;
		height = 0.0f;
		base = 0.0f;
		radius = 0.0f;
		minor = 0.0f;
		major = 0.0f;
		sidea = 0.0f;
		sideb = 0.0f;
		angle = 0.0f;
	}
		

	float areacalc()
	{
		switch (shapetype) // switch case to determine which shapes be calculated based on shape type
		{
		case 1: // Square
			area = pow((side * scalefactor), 2);
			return area;
			break;

		case 2: // Rectangle
			area = (width * scalefactor) * (height * scalefactor);
			return area;
			break;

		case 3: // Triangle
			area = (.5 * (base * scalefactor) * (height * scalefactor));
				return area;
				break;
		case 4: // Circle
			area = PI * pow(radius * scalefactor, 2);
			return area;
			break;

		case 5: // Ellipse
			area = PI * (minor * scalefactor) * (major * scalefactor);
			return area;
			break;

		case 6: // Trapezoid
			area = .5 * ((sidea * scalefactor) + (sideb * scalefactor)) * (height * scalefactor);
			return area;
			break;

		case 7: // Sector
			area = .5 * pow(radius * scalefactor, 2) * angle;
			return area;
			break;
		}
			
	}

};

class Square : virtual public Shape2D
{
public:

	Square() // def const
	{
		name = "Default Square";
		side = 0;
		shapetype = 1;
	}

	Square(string sqrname, int sidelength) // custom const
	{
		name = sqrname;
		side = sidelength;
		shapetype = 1;
	}
};

class Rectangle : public Shape2D
{
public:

	Rectangle() // def const
	{
		name = "Default Rectangle";
		width = 0;
		height = 0;
		shapetype = 2;
	}

	Rectangle(string rectname, int rwidth, int rheight) // custom const
	{
		name = rectname;
		width = rwidth;
		height = rheight;
		shapetype = 2;
	}
};

class Triangle : public Shape2D
{
public:

	Triangle() // def const
	{
		name = "Default Triangle";
		base = 0;
		height = 0;
		shapetype = 3;
	}

	Triangle(string triname, int tribase, int triheight) // custom const
	{
		name = triname;
		base = tribase;
		height = triheight;
		shapetype = 3;
	}
};

class Circle : public Shape2D
{
public:

	Circle() // def const 
	{
		name = "Default Circle";
		radius = 0;
		shapetype = 4;
	}

	Circle(string circname, int inputradius) // custom const
	{
		name = circname;
		radius = inputradius;
		shapetype = 4;
	}

};

class Ellipse : public Shape2D
{
public:

	Ellipse() // def const
	{
		name = "Defualt Ellipse";
		minor = 0;
		major = 0;
		shapetype = 5;
	}

	Ellipse(string ellname, int inpminor, int inpmajor) // custom const
	{
		name = ellname;
		minor = inpminor;
		major = inpmajor;
		shapetype = 5;

	}
};

class Trapezoid : public Shape2D
{
public:

	Trapezoid() // def const
	{
		name = "Defualt Trapezoid";
		sidea = 0;
		sideb = 0;
		height = 0;
		shapetype = 6;
	}

	Trapezoid(string trapname, int inpsidea, int inpsideb, int inpheight) // custom const
	{
		name = trapname;
		sidea = inpsidea;
		sideb = inpsideb;
		height = inpheight;
		shapetype = 6;
	}
};

class Sector : public Shape2D // get degrees and convert to radians
{
public:

	Sector() // def const
	{
		name = "Default Sector";
		radius = 0;
		angle = 0 * (PI / 180);
		shapetype = 7;
	}

	Sector(string sectname, int inpradius, int inpangleindegrees) // custom const
	{
		name = sectname;
		radius = inpradius;
		angle = inpangleindegrees * (PI / 180);
		shapetype = 7;
	}
};




class Shape3D : virtual public Shape
{
public:
	float base, baselength, length, height, width, radius;

	int shapetype = 0;

	Shape3D() // def const
	{
		base = 0.0f;
		baselength = 0.0f;
		length = 0.0f;
		height = 0.0f;
		width = 0.0f;
		radius = 0.0f;
	}


	float volcalc()
	{
		switch (shapetype)
		{
		case 1: // Pyramid
			area = (.5 * (base * scalefactor) * (baselength * scalefactor));
			volume = (area * (height * scalefactor)) / 3;
			area = 0; // so the display func doesn't boof
			return volume;
			break;

		case 2: // Rectangular Pyramid
			volume = ((length * scalefactor) * (width * scalefactor) * (height * scalefactor)) / 3;
			return volume;
			break;

		case 3: // Cylinder
			volume = PI * pow(radius * scalefactor,2) * (height * scalefactor);
			return volume;
			break;
		case 4: // Sphere
			volume = (4 * PI * pow(radius * scalefactor, 3)) / 3;
			return volume;
			break;
		}

	}
};

class TriPyramid : public Shape3D
{

public:

	TriPyramid() // def const
	{
		name = "Defualt Tripyr";
		base = 0;
		baselength = 0;
		height = 0;
		shapetype = 1;

	}

	TriPyramid(string pyrmidname, int inpbase, int inpbaselenght, int inpheight) // custom const
	{
		name = pyrmidname;
		base = inpbase;
		baselength = inpbaselenght;
		height = inpheight;
		shapetype = 1;
	}
};

class RectPyramid : public Shape3D
{
public:

	RectPyramid() // def const
	{
		name = "Default RectPyr";
		length = 0;
		width = 0;
		height = 0;
		shapetype = 2;
	}

	RectPyramid(string rectpyrname, int inplength, int inpwidth, int inpheight) // custom const
	{
		name = rectpyrname;
		length = inplength;
		width = inpwidth;
		height = inpheight;
		shapetype = 2;
	}
};

class Cylinder : public Shape3D
{
public:

	Cylinder() // def const
	{
		name = "Default Cylinder";
		radius = 0;
		height = 0;
		shapetype = 3;
	}
	 
	Cylinder(string cylindername, int inpradius, int inpheight) // custom const
	{
		name = cylindername;
		radius = inpradius;
		height = inpheight;
		shapetype = 3;
	}
};

class Sphere : public Shape3D
{
public:

	Sphere() // def const
	{
		name = "Default Sphere";
		radius = 0;
		shapetype = 4;
	}

	Sphere(string spherename, int inpradius) // custom const
	{
		name = spherename;
		radius = inpradius;
		shapetype = 4;
	}
};
