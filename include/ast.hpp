#pragma once
#include <vector>

// #include <cmath>
#include <memory>
#include <string>
class ExprAST {
public:
	virtual ~ExprAST() = default;
};

class NumExprAST : public ExprAST {
	double Val;

public:
	explicit NumExprAST(double Val);
};

class VariableExprAST : public ExprAST{
	std::string Name;

public:
	explicit VariableExprAST(const std::string &Name);
};

class BinaryExpAST : public ExprAST {
	char Op;
	std::unique_ptr<ExprAST> LHS, RHS;

public:
	explicit BinaryExpAST(char Op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS);
};

class CallExprAST : public ExprAST {
	std::string Callee;
	std::vector<std::unique_ptr<ExprAST>> Args;

public:
	explicit CallExprAST(const std::string &Callee, std::vector<std::unique_ptr<ExprAST>> Args);
};
