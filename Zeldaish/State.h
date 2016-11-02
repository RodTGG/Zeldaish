#pragma once
class State
{
public:
	State();
	~State();

	virtual void display() = 0;
	virtual int handleEvent() = 0;

	int getID();
private:

protected:
	int id_;
};

