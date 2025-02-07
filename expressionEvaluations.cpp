//#include <iostream>
//#include <vector>
//using namespace std;
//
//class variableToBeEvaluate {
//	int* arr;
//	int size;
//
//public:
//	friend void andOperation(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result);
//	friend void orOperation(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result);
//	friend void Implication(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result);
//	friend void biConditional(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result);
//	friend void notOperation(variableToBeEvaluate& var1, variableToBeEvaluate& result);
//	friend void checkEquivalence(variableToBeEvaluate& result1, variableToBeEvaluate& result2);
//	friend void printSubExpressionResult(string subExpr, variableToBeEvaluate& result);
//	variableToBeEvaluate() : arr(nullptr), size(0) {
//		// default constructor
//	}
//
//	~variableToBeEvaluate() {
//		delete[] arr;
//	}
//
//	void memoryAllocation(int size) {
//		arr = new int[size];
//	}
//
//	void setSize(int size) {
//		this->size = size;
//	}
//
//	void setValues(int index, int value) {
//		arr[index] = value;
//	}
//
//	void print() {
//		for (int x = 0; x < size; x++) {
//			cout << "\033[31m" << arr[x] << " \033[0m"; 
//		}
//		cout << endl;
//	}
//	int getValues(int index) {
//		return arr[index];
//	}
//	int getSize() {
//		return size;
//	}
//};
//
//
//
//struct node {
//	char data;
//	node* next;
//	node(char data) {
//		this->data = data;
//		next = nullptr;
//	}
//	~node() {
//		delete next;
//	}
//	char pop() {
//		return data;
//	}
//};
//
//bool prec(char a, char b) {
//	if (a == '!') {
//		return false;
//	}
//	if (a == '&' && b == '|') {
//		return false;
//	}
//	if (a == '>' && b == '^') {
//		return false;
//	}
//	if (a == '|' && b == '>') {
//		return false;
//	}
//	if (a == '|' && b == '^') {
//		return false;
//	}
//	if (a == '&' && b == '>') {
//		return false;
//	}
//	if (a == '&' && b == '^') {
//		return false;
//	}
//	if (a == '(') {
//		return false;
//	}
//	if (b == '(') {
//		return false;
//	}
//
//	return true;
//}
//class stack {
//	node* top;
//public:
//	stack() {
//		top = nullptr;
//	}
//	void push(char data) {
//		node* n = new node(data);
//		if (top == nullptr) {
//			top = n;
//		}
//		else {
//			n->next = top;
//			top = n;
//		}
//	}
//
//	void insertEquation(string content) {
//		top = nullptr;
//		int start = 0;
//		int end = content.length() - 1;
//		while (end >= start) {
//
//			while (end >= start && content[end] == ' ') {
//				end--;
//			}
//			node* n = new node(content[end]);
//			if (top == nullptr) {
//				top = n;
//			}
//			else {
//				n->next = top;
//				top = n;
//			}
//			end--;
//		}
//	}
//
//	string postFixConversion() {
//
//		node* curr = top;
//		string postFix = "";
//		node* operatorStack = nullptr;
//		while (curr) {
//
//			if (curr->data >= 'a' && curr->data <= 'z' || curr->data >= 'A' && curr->data <= 'Z') {
//				postFix = postFix + curr->data;
//				curr = curr->next;
//				continue;
//			}
//			else {
//				node* n = new node(curr->data);
//				if (operatorStack == nullptr) {
//					operatorStack = n;
//				}
//				else {
//					if (n->data == ')') {
//
//						while (operatorStack->data != '(') {
//							char temp = operatorStack->pop();
//							postFix = postFix + temp;
//							operatorStack = operatorStack->next;
//						}
//						operatorStack = operatorStack->next;
//						curr = curr->next;
//						continue;
//					}
//					while (operatorStack && prec(n->data, operatorStack->data)) {
//						char temp = operatorStack->pop();
//						operatorStack = operatorStack->next;
//						postFix = postFix + temp;
//					}
//					if (operatorStack == nullptr) {
//						operatorStack = n;
//					}
//					else {
//						n->next = operatorStack;
//						operatorStack = n;
//					}
//				}
//			}
//			curr = curr->next;
//
//		}
//		while (operatorStack) {
//			char temp = operatorStack->pop();
//			if (temp == '(') {
//				operatorStack = operatorStack->next;
//				continue;
//			}
//			postFix = postFix + temp;
//			operatorStack = operatorStack->next;
//		}
//		return postFix;
//
//	}
//
//
//
//	void display() {
//		if (top == nullptr) {
//			return;
//		}
//		else {
//			node* curr = top;
//			while (curr) {
//				cout << curr->data << " ";
//				curr = curr->next;
//			}
//			cout << endl;
//		}
//	}
//};
//
//void biConditional(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result) {
//	for (int x = 0; x < var1.getSize(); x++) {
//		result.arr[x] = ((!var1.arr[x]) | var2.arr[x]) & ((!var2.arr[x]) | var1.arr[x]);
//	}
//}
//
//
//void Implication(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result) {
//	for (int x = 0; x < var1.getSize(); x++) {
//		result.arr[x] = (!var1.arr[x]) | var2.arr[x];
//	}
//}
//
//void orOperation(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result) {
//	for (int x = 0; x < var1.getSize(); x++) {
//		result.arr[x] = var1.arr[x] | var2.arr[x];
//	}
//}
//
//
//void andOperation(variableToBeEvaluate& var1, variableToBeEvaluate& var2, variableToBeEvaluate& result) {
//	for (int x = 0; x < var1.getSize(); x++) {
//		result.arr[x] = var1.arr[x] & var2.arr[x];
//	}
//}
//
//void notOperation(variableToBeEvaluate& var1, variableToBeEvaluate& result) {
//	int size = var1.getSize();
//	for (int x = 0; x < size; x++) {
//		result.arr[x] = !(var1.arr[x]);
//	}
//}
//
//void printSubExpressionResult(string subExpr, variableToBeEvaluate& result) {
//	cout << "Sub-expression: " << subExpr << " => ";
//	result.print();  // Print the truth table for the result
//}
//
//
//class evaluateExpression {
//	node* top;
//public:
//	evaluateExpression() {
//		top = nullptr;
//	}
//
//	void Result(string str, variableToBeEvaluate& finalResult, variableToBeEvaluate* arr) {
//		int start = 0;
//		int end = str.length() - 1;
//		vector<variableToBeEvaluate*> tempResults; // Vector to store intermediate results dynamically
//		vector<string> subExpressions;  // Vector to store sub-expressions as they are evaluated
//
//		while (start <= end) {
//			if (str[start] >= 'p' && str[start] <= 'z') {
//				node* n = new node(str[start]);
//				n->next = top;
//				top = n;
//			}
//			else {
//				// Handle NOT operator (unary operator)
//				if (str[start] == '!') {
//					node* n = new node('R');
//					char data = top->pop(); // Pop from the stack
//					top = top->next;
//
//					// Create a new result to store the intermediate NOT result
//					variableToBeEvaluate* newResult = new variableToBeEvaluate();
//					newResult->setSize(finalResult.getSize());
//					newResult->memoryAllocation(finalResult.getSize());
//
//					string subExpr = "!" + string(1, data);  // Construct the sub-expression
//
//					if (data == 'R') {
//						notOperation(*tempResults.back(), *newResult);
//					}
//					else {
//						int index = data - 'p';
//						notOperation(arr[index], *newResult);
//					}
//
//					tempResults.push_back(newResult); // Save this intermediate result
//					n->next = top;
//					top = n;
//
//					// Print the solved sub-expression and its truth table
//					printSubExpressionResult(subExpr, *newResult);
//
//					start++;
//					continue;
//				}
//
//				// Handle binary operators
//				char data2 = top->pop();
//				top = top->next;
//				char data1 = top->pop();
//				top = top->next;
//
//				// Create a new result to store the intermediate binary operation result
//				variableToBeEvaluate* newResult = new variableToBeEvaluate();
//				newResult->setSize(finalResult.getSize());
//				newResult->memoryAllocation(finalResult.getSize());
//
//				int index1 = data1 - 'p';
//				int index2 = data2 - 'p';
//
//				string subExpr = string(1, data1) + " " + string(1, str[start]) + " " + string(1, data2);  // Construct the sub-expression
//
//				if (data1 == 'R' && data2 == 'R') {
//					if (str[start] == '&') {
//						andOperation(*tempResults[tempResults.size() - 2], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '|') {
//						orOperation(*tempResults[tempResults.size() - 2], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '>') {
//						Implication(*tempResults[tempResults.size() - 2], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '^') {
//						biConditional(*tempResults[tempResults.size() - 2], *tempResults.back(), *newResult);
//					}
//					tempResults.pop_back(); // Remove the last two intermediate results
//					tempResults.pop_back();
//				}
//				else if (data1 == 'R') {
//					if (str[start] == '&') {
//						andOperation(*tempResults.back(), arr[index2], *newResult);
//					}
//					else if (str[start] == '|') {
//						orOperation(*tempResults.back(), arr[index2], *newResult);
//					}
//					else if (str[start] == '>') {
//						Implication(*tempResults.back(), arr[index2], *newResult);
//					}
//					else if (str[start] == '^') {
//						biConditional(*tempResults.back(), arr[index2], *newResult);
//					}
//					tempResults.pop_back(); // Remove the last intermediate result
//				}
//				else if (data2 == 'R') {
//					if (str[start] == '&') {
//						andOperation(arr[index1], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '|') {
//						orOperation(arr[index1], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '>') {
//						Implication(arr[index1], *tempResults.back(), *newResult);
//					}
//					else if (str[start] == '^') {
//						biConditional(arr[index1], *tempResults.back(), *newResult);
//					}
//					tempResults.pop_back(); // Remove the last intermediate result
//				}
//				else {
//					// Perform the operation on two variables
//					if (str[start] == '&') {
//						andOperation(arr[index1], arr[index2], *newResult);
//					}
//					else if (str[start] == '|') {
//						orOperation(arr[index1], arr[index2], *newResult);
//					}
//					else if (str[start] == '>') {
//						Implication(arr[index1], arr[index2], *newResult);
//					}
//					else if (str[start] == '^') {
//						biConditional(arr[index1], arr[index2], *newResult);
//					}
//				}
//
//				tempResults.push_back(newResult); // Save the intermediate result
//				node* n = new node('R');
//				n->next = top;
//				top = n;
//
//				// Print the solved sub-expression and its truth table
//				printSubExpressionResult(subExpr, *newResult);
//			}
//			start++;
//		}
//
//		// Copy the final result from the last intermediate result
//		if (!tempResults.empty()) {
//			for (int i = 0; i < finalResult.getSize(); i++) {
//				finalResult.setValues(i, tempResults.back()->getValues(i));
//			}
//		}
//
//		// Free dynamically allocated intermediate results
//		for (auto temp : tempResults) {
//			delete temp;
//		}
//	}
//
//
//
//
//};
//
//
//void checkEquivalence(variableToBeEvaluate& result1, variableToBeEvaluate& result2) {
//	int size = result1.size;
//	for (int x = 0; x < size; x++) {
//		if (result1.arr[x] != result2.arr[x]) {
//			cout << "THE EXPRESSION IS NOT EQUIVALENT...." << endl;
//			return;
//		}
//
//	}
//	cout << "THE EXPRESSION IS EQUIVALENT....." << endl;
//}
//
//
//void menu() {
//	cout << "Instructions : use ! for NOT operator" << endl;
//	cout << "use & for AND operations" << endl;
//	cout << "use | for OR operations" << endl;
//	cout << "use > for implies operations" << endl;
//	cout << "use ^ for Biconditional operations" << endl;
//	cout << "use only () parenthesis  : " << endl;
//}
//
//
//int getLength(string str) {
//
//	int start = 0;
//	int end = str.length();
//	int maxArray = (end / 2) + 1;
//	int* arr = new int[maxArray] {};
//	for (int x = 0; x < end; x++) {
//		char data = str[x];
//		if (data >= 'p' && data <= 'z') {
//			int index = data - 'p';
//			arr[index] = 1;
//		}
//	}
//
//	int count = 0;
//
//	for (int x = 0; x < maxArray; x++) {
//		if (arr[x] == 1) {
//			count++;
//		}
//	}
//	return count;
//}
//
//
//int main() {
//
//	while (true) {
//
//
//		menu();
//		cout << "Enter The Expression 1 : ";
//		string str1;
//		cin >> str1;
//		cout << "Enter The Expression 2 : ";
//		string str2;
//		cin >> str2;
//		int length1 = getLength(str1);
//		int length2 = getLength(str2);
//		if (length1 != length2) {
//			cout << "EXPRESSIONS ARE NOT EQUAL" << endl;
//			exit(1);
//		}
//		int size = pow(2, length1); // Total rows in the truth table
//
//		// Create an array of objects
//		variableToBeEvaluate* variable1 = new variableToBeEvaluate[length1];
//
//
//		for (int x = 0; x < length1; x++) {
//			variable1[x].memoryAllocation(size);
//			variable1[x].setSize(size);
//		}
//
//		// Populate the truth table
//		for (int col = 0; col < length1; col++) {
//			int repeat = pow(2, length1 - col - 1);
//			int value = 0;
//
//			for (int row = 0; row < size; row++) {
//				variable1[col].setValues(row, value);
//				if ((row + 1) % repeat == 0) {
//					value = 1 - value; // Toggle between 0 and 1
//				}
//			}
//		}
//		cout << endl << endl;
//		cout << "REPLACING THE SOLVED EQUATION WITH R" << endl;
//		/// for saving purposes 
//		string str11;
//		string str22;
//
//		stack stack1;
//		stack1.insertEquation(str1);
//		//stack1.display();
//		// str11 has the postFix of equation no 1
//		str11 = stack1.postFixConversion();
//		cout << endl << endl;
//		stack stack2;
//		stack2.insertEquation(str2);
//		//stack2.display();
//		// str22 has the postFix of equation no 2
//		str22 = stack2.postFixConversion();
//
//		////////////////////////////////////////////////////
//		variableToBeEvaluate result1;
//		result1.setSize(size);
//		result1.memoryAllocation(size);
//		evaluateExpression evaluation1;
//		evaluation1.Result(str11, result1, variable1);
//		cout << "THE FIRST EQUATION IS => " << str1 << endl;
//		cout << "THE FINAL TRUTH TABLE IS : ";
//		result1.print();
//		cout << endl;
//		/////////////////////////////////////////////////////
//		variableToBeEvaluate result2;
//		result2.setSize(size);
//		result2.memoryAllocation(size);
//		evaluateExpression evaluation2;
//		evaluation2.Result(str22, result2, variable1);
//		cout << "THE SECOND EQUATION IS => " << str2 << endl;
//		cout << "THE FINAL TRUTH TABLE IS : ";
//		result2.print();
//		cout << endl;
//		/////////////////////////////////////////////////////
//
//
//		// evaluating result
//		checkEquivalence(result1, result2);
//
//
//		cout << endl << endl;
//	}
//
//
//
//	return 0;
//}
