#pragma once
#include<iostream>
using namespace std;

class Exception {
protected:
	string text;
	int line;
	string source;
	string createdTime;
	Exception(const string& text, const int line, const string& source, const string& createdTime)
	{
		setText(text);
		setLine(line);
		setSource(source);
		setTime(createdTime);
	}
	string getText()const {
		return text;
	}
	int getLine()const {
		return line;
	}
	string getSource()const {
		return source;
	}
	string getTime()const {
		return createdTime;
	}

	void setText(const string& text) {
		if (text.empty()) throw "Text is empty";
		this->text = text;
	}
	void setLine(const int line) {
		if (line < 0) throw "Line cannot be negative";
		this->line = line;
	}
	void setSource(const string& source) {
		if (source.empty()) throw "Source is empty";
		this->source = source;
	}
	void setTime(const string& createdTime) {
		if (createdTime.empty()) throw "Time is NULL";

		time_t currently = time(0);
		char dt[30]{};
		ctime_s(dt, sizeof dt, &currently);
		string time = dt;

		this->createdTime = dt;
	}

public:
	void PrintMsg()const {
		cout << endl;
		cout << "Text:" << getText() << endl;
		cout << "Line:" << getLine() << endl;
		cout << "Source:" << getSource() << endl;
		cout << "Time: " << getTime() << endl;
	}
};

class SystemException :public Exception {
public:
	SystemException() = default;
	SystemException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{

	}
};

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{

	}
};

class NullException :public Exception {
public:
	NullException() = default;
	NullException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{

	}
};