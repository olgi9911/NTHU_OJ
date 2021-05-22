#include <stdio.h>
///
typedef struct {
	long long numerator; 
	long long denominator; 
} Fraction;

long long GCD(long long a, long long b){
	if(b == 0) return a;
	return GCD(b, a%b);
}

Fraction CreateFrac(long long a, long long b){
	Fraction F;
	F.numerator = a, F.denominator = b;
	return F;
}

void Reduction(Fraction* i){
	long long gcd = GCD(i->numerator, i->denominator);
	i->numerator /= gcd;
	i->denominator /= gcd;
}

Fraction Add(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator += b.numerator;
	Reduction(&a);
	return a;
}

Fraction Sub(Fraction a, Fraction b){
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	a.denominator *= b.denominator;
	a.numerator -= b.numerator;
	Reduction(&a);
	return a;
}

Fraction Mul(Fraction a, Fraction b){
	a.denominator *= b.denominator;
	a.numerator *= b.numerator;
	Reduction(&a);
	return a;
}

Fraction Div(Fraction a, Fraction b){
	a.denominator *= b.numerator;
	a.numerator *= b.denominator;
	Reduction(&a);
	return a;
}

int Compare(Fraction a, Fraction b){
	Reduction(&a); Reduction(&b);
	a.numerator *= b.denominator;
	b.numerator *= a.denominator;
	if(a.numerator > b.numerator) return 1;
	else return 0;
}

///
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int type, p1, q1, p2, q2;
		scanf("%d %d/%d %d/%d", &type, &p1, &q1, &p2, &q2);
		Fraction f1 = CreateFrac(p1, q1), f2 = CreateFrac(p2, q2), ans;
		switch (type) {
			case 0: 
				ans = Add(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 1: 
				ans = Compare(f1, f2) ? Sub(f1, f2) : Sub(f2, f1);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 2: 
				ans = Mul(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 3: 
				ans = Div(f1, f2);
				printf("%lld/%lld\n", ans.numerator, ans.denominator);
				break;
			case 4:
				Reduction(&f1), Reduction(&f2);
				printf("%lld/%lld %lld/%lld\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator);
				break;
		}
	}
}
