#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>

class CPolynomial
{
private:
	std::vector<double> c;		// Koeffizienten
	char variable;				// Variable (nur f�r Ausgabezwecke)

	// Sind die f�hrenden Koeffizienten des Polynoms 0, werden diese abgeschnitten und der Grad angepasst
	void trim() {
		while (std::abs(c.back()) <= 0.00000001 && c.size() > 1) c.pop_back();
		
		c.shrink_to_fit();
	}

public:
	CPolynomial(const std::vector<double>& param, const char var = 'x') {
		c = param;
		variable = var;
		trim();
	}

	CPolynomial(const double param[], const int degree, const char var = 'x') {
		for (int i = degree; i >= 0; --i) 
			c.push_back(param[i]);

		variable = var;
		trim();
	}

	unsigned int degree() const {
		return c.size() - 1;
	}

	char changeVariable(const char v) {
		if (v >= 97 && v <= 122) 
			variable = v;
		
		return variable;
	}

	void testOutput() const {
		std::streamsize ss = std::cout.precision();
		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		for (int i = c.size()-1; i >= 0; --i) {
			if (i == c.size() - 1) {
				if (c[i] == -1) std::cout << "-";
				else if (c[i] != 1) std::cout << c[i];
			}
			else {
				if (c[i] < 0) {
					std::cout << " -";
					if(c[i] != -1 || i == 0) std::cout << " " << std::abs(c[i]);
				}
				else if (c[i] > 0) {
					std::cout << " +";
					if(c[i] != 1 || i == 0) std::cout << " " << c[i];
				}
				else {
					if (i == 0) std::cout << "\n";
					continue;
				}
			}

			switch (i) {
			case 0: std::cout << "\n"; break;
			case 1: std::cout << " " << variable; break;
			default: std::cout << " " << variable << "^" << i;
			}
		}
		std::cout << std::defaultfloat;
		std::cout << std::setprecision(ss);
	}

	double operator[](int index){
		if(index < 0 || index >= c.size()) return 0;
		return c[index];
	}

	double evaluateAt(double x){
		double result = 0;
		for(int i = 0;i <= degree(); i++){
			result += c[i] * std::pow(x, i);
		}
		return result;
	}
	std::map<double, double> evaluateAt(std::vector<double> x){
		std::map<double, double> result = {};
		for(double xi : x){
			result[xi] = evaluateAt(xi);
		}
		return result;
	}	

	friend std::ostream& operator<<(std :: ostream & os, CPolynomial& p){
		std::streamsize ss = std::cout.precision();
		os << std::fixed;
		os << std::setprecision(2);
		for (int i = p.c.size()-1; i >= 0; --i) {
			if (i == p.c.size() - 1) {
				if (p.c[i] == -1) os << "-";
				else if (p.c[i] != 1) os << p.c[i];
			}
			else {
				if (p.c[i] < 0) {
					os << " -";
					if(p.c[i] != -1 || i == 0) os << " " << std::abs(p.c[i]);
				}
				else if (p.c[i] > 0) {
					os << " +";
					if(p.c[i] != 1 || i == 0) os << " " << p.c[i];
				}
				else {
					if (i == 0) os << "\n";
					continue;
				}
			}

			switch (i) {
			case 0: os << "\n"; break;
			case 1: os << " " << p.variable; break;
			default: os << " " << p.variable << "^" << i;
			}
		}
		os << std::defaultfloat;
		os << std::setprecision(ss);
		return os;
	}

	CPolynomial operator+(CPolynomial p2){
		std::vector<double> newC = {};
		for(int i = 0; i<=p2.degree();i++){
			newC.push_back((*this)[i] + p2[i]);
		}
		return CPolynomial(newC);
	}

	CPolynomial operator-(CPolynomial p2){
		std::vector<double> newC = {};
		for(int i = 0; i<=p2.degree();i++){
			newC.push_back((*this)[i] - p2[i]);
		}
		return CPolynomial(newC);
	}

	CPolynomial operator*(CPolynomial p2){
		std::vector<double> newC = {};
		for(int i1=0 ; i1 <= degree() ; i1++){
			for(int i2=0 ; i2 <= p2.degree() ; i2++){
				int cX = i1+i2;
				if(newC.size() <= cX) newC.push_back(0);
				newC[cX] += c[i1] * p2.c[i2];
			}
		}
		return CPolynomial(newC);
	}

	CPolynomial operator+=(CPolynomial p2){
		return *this + p2;
	}
	bool operator==(CPolynomial p2){
		if(degree() != p2.degree()) return false;
		for(int i = 0; i<= degree();i++){
			if(c[i] != p2[i]) return false;
		}
		return true;
	}
	bool operator!=(CPolynomial p2){
		return !(*this == p2);
	}
	CPolynomial operator~(){
		std::vector<double> newC = {};
		for(int i = 1; i <= degree();i++){
			newC.push_back(c[i]*i);
		}
		if(newC.size() == 0) newC.push_back(0);	
		return CPolynomial(newC);
	}
};

