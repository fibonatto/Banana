#pragma once

class ExprAST {
public:
	virtual ~ExprAST() = default;
};

class NumExprAST : public ExprAST {
	double Val;

public:
	explicit NumExprAST(double Val);
};

