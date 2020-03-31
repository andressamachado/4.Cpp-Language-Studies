//Frame.h
#pragma once

class Frame {
	char* frameName;
	Frame* pNext;
public:
	Frame();
	~Frame();
	char*& GetFrameName() { return frameName; }
	Frame*& GetpNext() { return pNext; }
};
