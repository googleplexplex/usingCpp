#pragma once

class IInsertableInUsing
{
public:
	virtual void onStart() = 0;
	virtual void onEnd() = 0;
};

#define using(type, name, constr, code) \
{\
type name constr;\
name.onStart();\
code \
name.onEnd(); \
}