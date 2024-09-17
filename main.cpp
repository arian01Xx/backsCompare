#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

class SolutionTen{
private:
	stack<char> check(stack<char> st, string s){
		for(int i=0; i<s.size(); i++){
			if(s[i]!='#') st.push(s[i]);
			else{
				if(!st.empty()) st.pop();
			}
		}
		return st;
	}
public:
	bool backspaceCompare(string s, string t){
		stack<char> st;
		//strings sin '#'
		stack<char> p=check(st,s);
		stack<char> q=check(st,t);
		if(p.size()!=q.size()) return false;
		else{
			while(!p.empty() && !q.empty()){
				if(p.top() != q.top()) return false;
				p.pop();
				q.pop();
			}
		}
		return true;
	}
};