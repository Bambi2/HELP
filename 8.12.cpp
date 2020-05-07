#include <iostream>
#include <iomanip>
using namespace std;


class Sterling
{
protected:

	int pounds;
	int shillings;
	int pennies;

public:

	Sterling() {
		pounds = 0;
		shillings = 0;
		pennies = 0;
	}

	Sterling(int pounds, int shillings, int pennies) {
		this->pounds = pounds;
		this->shillings = shillings;
		this->pennies = pennies;
	}

	Sterling(double newCurrency);

	int getPounds() {
		return pounds;
	}

	int getShillings() {
		return shillings;
	}

	int getPennies() {
		return pennies;
	}

	void getSterling() {
		char point;
		cout << "Enter Sterling: ";
		cin >> pounds >> point >> shillings >> point >> pennies;
	}

	void printSterling() {
		cout << pounds << "." << shillings << "." << pennies << endl;
	}



	Sterling operator+(const Sterling& other) const;

	Sterling operator-(const Sterling& other) const;

	Sterling operator*(double other) const;

	Sterling operator/(const Sterling& other) const;

	Sterling operator/(double other) const;

	operator double() const;
};

Sterling::Sterling(double newCurrency) {
	newCurrency *= 240.0;

	pounds = int(newCurrency) / 240;
	shillings = int(newCurrency) % 240 / 12;
	pennies = int(newCurrency) % 12;
}

Sterling Sterling::operator+(const Sterling& other) const {
	Sterling first(pounds, shillings, pennies);
	Sterling second(other.pounds, other.shillings, other.pennies);
	return Sterling(double(first) + double(second));
}

Sterling Sterling::operator-(const Sterling& other) const {
	Sterling first(pounds, shillings, pennies);
	Sterling second(other.pounds, other.shillings, other.pennies);
	return Sterling(double(first) - double(second));
}

Sterling Sterling::operator*(double other) const {
	Sterling first(pounds, shillings, pennies);
	return Sterling(double(first) * other);
}

Sterling Sterling::operator/(const Sterling& other) const {
	Sterling first(pounds, shillings, pennies);
	Sterling second(other.pounds, other.shillings, other.pennies);
	return Sterling(double(first) / double(second));
}

Sterling Sterling::operator/(double other) const {
	Sterling first(pounds, shillings, pennies);
	return Sterling(double(first) / other);
}

Sterling::operator double() const {
	double answer = (pounds * 240.0 + shillings * 12.0 + pennies) / 240.0;
	return answer;
}

class Fraction
{
protected:

	int numerator;
	int denominator;

public:

	Fraction() {
		numerator = 0;
		denominator = 1;
	}

	Fraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void setFraction(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void printFraction() {
		cout << numerator << "/" << denominator << " " << endl;
	}

	int getNumerator() {
		return numerator;
	}

	int getDenominator() {
		return denominator;
	}

	Fraction operator+(const Fraction& other) const {
		int numerator = this->numerator * other.denominator + this->denominator * other.numerator;
		int denominator = this->denominator * other.denominator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	Fraction operator-(const Fraction& other) const {
		int numerator = this->numerator * other.denominator - this->denominator * other.numerator;
		int denominator = this->denominator * other.denominator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	Fraction operator-(int number) const {
		int numerator = this->numerator - this->denominator * number;
		int denominator = this->denominator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}



	Fraction operator*(const Fraction& other) const {
		int numerator = this->numerator * other.numerator;
		int denominator = this->denominator * other.denominator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	Fraction operator*(double number) const {
		int numerator = this->numerator * number;
		int denominator = this->denominator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	Fraction operator/(const Fraction& other) const {
		int numerator = this->numerator * other.denominator;
		int denominator = this->denominator * other.numerator;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	Fraction operator/(double number) const {
		int numerator = this->numerator;
		int denominator = this->denominator * number;
		Fraction::lowterms2(numerator, denominator);
		return Fraction(numerator, denominator);
	}

	bool operator >(int number) {
		if ((numerator - denominator) > number) {
			return true;
		}
		return false;
	}

	bool operator >=(int number) {
		if ((numerator - denominator) >= number) {
			return true;
		}
		return false;
	}

	bool operator==(const Fraction& other) const {
		return numerator == other.numerator && denominator == other.denominator;
	}

	bool operator!=(const Fraction& other) const {
		return !(*this == other);
	}

	void lowterms() {
		long tnum, tden, temp, gcd;

		tnum = labs(numerator);
		tden = labs(denominator);

		if (tden == 0) {
			cout << "Invalid value" << endl;
		}
		else if (tnum == 0) {
			return;
		}

		while (tnum != 0) {
			if (tnum < tden) {
				temp = tnum;
				tnum = tden;
				tden = temp;
			}

			tnum = tnum - tden;
		}

		gcd = tden;
		numerator /= gcd;
		denominator /= gcd;
	}

	static void lowterms2(int& numerator, int& denominator) {
		long tnum, tden, temp, gcd;

		tnum = labs(numerator);
		tden = labs(denominator);

		if (tden == 0) {
			cout << "Invalid value" << endl;
		}
		else if (tnum == 0) {
			return;
		}

		while (tnum != 0) {
			if (tnum < tden) {
				temp = tnum;
				tnum = tden;
				tden = temp;
			}

			tnum = tnum - tden;
		}

		gcd = tden;
		numerator /= gcd;
		denominator /= gcd;
	}

};



class SterFrac : public Sterling, Fraction
{

public:

	SterFrac() : Sterling() {
		numerator = 0;
		denominator = 8;
	}

	SterFrac(int pounds, int sterlings, int pennies, int numerator, int denominator) {
		Sterling(pounds, sterlings, pennies);
		this->numerator = numerator;
		this->denominator = denominator;
	}

	SterFrac(Sterling sterling, Fraction fraction) {
		pounds = sterling.getPounds();
		shillings = sterling.getShillings();
		pennies = sterling.getPennies();
		numerator = fraction.getNumerator();
		denominator = fraction.getDenominator();




		while (numerator >= denominator) {
			numerator -= denominator;
			pennies++;
		}

		while (numerator < 0) {
			numerator += denominator;
			pennies--;
		}

		while (pennies > 11) {
			pennies -= 12;
			shillings++;
		}

		while (pennies < 0) {
			pennies += 12;
			shillings--;
		}

		while (shillings > 19) {
			shillings -= 20;
			pounds++;
		}

		while (shillings < 0) {
			shillings += 20;
			pounds--;
		}

		if (pounds < 0) {
			pounds = 0;
			shillings = 0;
			pennies = 0;
			numerator = 0;
		}

		Fraction::lowterms();

	}

	SterFrac(double newSterling) {
		newSterling *= 1920;

		pounds = int(newSterling) / 1920;
		shillings = int(newSterling) % 1920 / 96;
		pennies = int(newSterling) % 96 / 8;
		numerator = int(newSterling) % 8;

	}

	void getSterFrac() {
		char point, dash, slash;
		cout << "Enter SterFrac: ";
		cin >> pounds >> point >> shillings >> point >> pennies >> dash >> numerator >> slash >> denominator;

		if (denominator != 2 && denominator != 4 && denominator != 8) {
			cout << "Wrong value" << endl;
			exit(1);
		}
	}

	void printSterFrac() {
		cout << pounds << "." << shillings << "." << pennies << "-" << numerator << "/" << denominator << endl;
	}

	SterFrac& operator=(const SterFrac& other);
	SterFrac operator+(const SterFrac& other) const;
	SterFrac operator-(const SterFrac& other) const;
	SterFrac operator*(double number) const;
	double operator/(const SterFrac& other) const;
	SterFrac operator/(double number) const;
};

SterFrac& SterFrac::operator=(const SterFrac& other) {
	pounds = other.pounds;
	shillings = other.shillings;
	pennies = other.pennies;
	numerator = other.numerator;
	denominator = other.denominator;

	return *this;
}

SterFrac SterFrac::operator+(const SterFrac& other) const {
	// Sterling penniesAdder(0,0,1);
	Sterling firstSterling(pounds, shillings, pennies);
	Sterling secondSterling(other.pounds, other.shillings, other.pennies);
	Fraction firstFraction(numerator, denominator);
	Fraction secondFraction(other.numerator, other.denominator);

	Sterling sterlingSum = firstSterling + secondSterling;
	Fraction fractionSum = firstFraction + secondFraction;

	// if (fractionSum > 1){
	//     fractionSum = fractionSum - 1;
	//     sterlingSum = sterlingSum + penniesAdder;
	// }

	fractionSum.lowterms();



	return SterFrac(sterlingSum, fractionSum);
}

SterFrac SterFrac::operator-(const SterFrac& other) const {
	// Sterling penniesAdder(0,0,1);
	Sterling firstSterling(pounds, shillings, pennies);
	Sterling secondSterling(other.pounds, other.shillings, other.pennies);
	Fraction firstFraction(numerator, denominator);
	Fraction secondFraction(other.numerator, other.denominator);

	Sterling sterlingSum = firstSterling - secondSterling;
	Fraction fractionSum = firstFraction - secondFraction;

	// if (fractionSum < 0){
	//     fractionSum = fractionSum + 1;
	//     sterlingSum = sterlingSum - penniesAdder;
	// }


	return SterFrac(sterlingSum, fractionSum);
}

SterFrac SterFrac::operator*(double number) const {
	Sterling firstSterling(pounds, shillings, pennies);
	Fraction firstFraction(numerator, denominator);


	Sterling sterlingSum = firstSterling * number;
	Fraction fractionSum = firstFraction * number;


	return SterFrac(sterlingSum, fractionSum);
}

SterFrac SterFrac::operator/(double number) const {
	Sterling firstSterling(pounds, shillings, pennies);
	Fraction firstFraction(numerator, denominator);


	Sterling sterlingSum = firstSterling / number;
	Fraction fractionSum = firstFraction / number;


	return SterFrac(sterlingSum, fractionSum);
}

double SterFrac::operator/(const SterFrac& other) const {
	Sterling firstSterling(pounds, shillings, pennies);
	Sterling secondSterling(other.pounds, other.shillings, other.pennies);
	Fraction firstFraction(numerator, denominator);
	Fraction secondFraction(other.numerator, other.denominator);

	Sterling sterlingSum = firstSterling / secondSterling;
	Fraction fractionSum = firstFraction / secondFraction;


	return SterFrac(sterlingSum, fractionSum);
}



int main()
{
	SterFrac sf1, sf2, sf3;

	sf1.getSterFrac();
	

	sf3 = sf1 / 2.0;

	sf3.printSterFrac();
}
