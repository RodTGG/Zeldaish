#pragma once
class State
{
public:
	State();
	~State();

	virtual void Display() = 0;
	virtual int HandleEvent() = 0;

	int getID();
private:

protected:
	int id;
};

