#ifndef NODE_H_
#define NODE_H_

#include "date.h"
#include <string>

using std::string;

class Node {
	virtual bool Evaluate(const Date&, const string&) const = 0;
};



#endif /* NODE_H_ */
