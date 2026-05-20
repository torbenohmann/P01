#include <cstdlib>
#include "CPolynomial.h"

int main() {
	double p[] = { 0, 0, 2.1, -4.5, 0, -3.3 };
	CPolynomial poly = CPolynomial(p, 5);

	poly.testOutput();


	/* -= Test 1: Zugriffsoperator �berladen =- */
	
	for (int i = 0; i < 6; i++) {
		std::cout << "Koeffizient " << i << ": " << poly[i] << "\n";
	}
	
	
	/* -= Test 2: Methoden �berladen =- */
		
	double x = 0;
	std::cout << "evaluateAt(" << x << ") = " << poly.evaluateAt(x) << "\n";

	std::vector<double> vx = { 0, .5, 1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7 };
	std::map<double, double> res = poly.evaluateAt(vx);
	for (const auto& i : res) {
		std::cout << "f(" << std::setw(3) << i.first << ") = " << i.second << "\n";
	}
	

	
	/* -= Test 3: Ausgabeoperator �berladen =- */
	std::cout << poly;
	
	double p1[] = { 1.3, -1, -2, 0.8 };
	CPolynomial poly1 = CPolynomial(p1, 3);
	
	/* -= Test 4.1: +Operator �berladen =- */
	
	std::cout << "Polynomaddition: \n   " << poly << " plus " << poly1 << " = ";
	CPolynomial polyAdd = poly + poly1;
	std::cout << polyAdd;
	

	/* -= Test 4.2: -Operator �berladen =- */
	
	std::cout << "Polynomsubtraktion: \n   " << poly << " minus " << poly1 << " = ";
	CPolynomial polySub = poly - poly1;
	std::cout << polySub;
	

	/* -= Test 4.3: *Operator �berladen =- */
	
	std::cout << "(Optional) Polynommultiplikation: \n   " << poly << " times " << poly1 << " = ";
	CPolynomial polyMult = poly * poly1;
	std::cout << polyMult;
	
	

	/* -= Test 5: +=Operator �berladen =- */
	
	std::cout << "Polynomaddition (mit +=): \n   " << poly << " plus " << poly1 << " = ";
	poly += poly1;
	std::cout << poly;
	

	/* -= Test 6: Polynome vergleichen =- */
	
	if (poly == poly1) std::cout << "Die Polynome sindidentisch.\n";
	if (poly != poly1) std::cout << "Die Polynome sind ungleich.\n";
	

	/* -= Test 7: Ableitung berechnen =- */
	
	std::cout << "Ableitung berechnen: \n";
	double pAbl[] = { 1, 1, 1 };
	CPolynomial polyAbl = CPolynomial(pAbl, 2);
	std::cout << "Funktion:     " << polyAbl;
	std::cout << "Ableitung:    " << ~polyAbl;
	std::cout << "2. Ableitung: " << ~(~polyAbl);
	std::cout << "3. Ableitung: " << ~(~(~polyAbl));
	

	return EXIT_SUCCESS;
}