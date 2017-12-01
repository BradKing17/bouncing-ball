#pragma once
class Vector
{
public:
	Vector();
	~Vector();

private:
	void normalise();
	Vector operator* (float scalar);
	int x = 0;
	int y = 0;
};

