#include <string>
#include <vector>
#include <stack>
#include <deque>

int priority(char let){
	if(let == '*' || let == '/'){
		return 2;
	}
	else if(let == '+' || let == '-'){
		return 1;
	}
}
