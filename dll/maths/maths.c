#include <stdio.h>
#include <windows.h>
__declspec(dllexport) double gamma(double value) {
	return tgamma(value);
}
__declspec(dllexport) double factorial(double value) {
	return tgamma(value + 1);
}
__declspec(dllexport) double absolute_value(double value) {
	if (value<0)
	{
		double value_;
		value_ = 0 - value;
		return value_;
	}
	else {
		if (value>0)
		{
			return value;
		}
		else {
			return 0;
		}
	}
}
__declspec(dllexport) double power(double base, double exponent) {
	if (base == 0 && exponent == 0) {
		return 1; // 0^0 is often defined as 1
	}
	return pow(base, exponent);
}
__declspec(dllexport) double square_root(double value) {
	if (value < 0) {
		SetLastError(ERROR_INVALID_PARAMETER);
		return -1; // Indicate an error for negative input
	}
	return sqrt(value);
}