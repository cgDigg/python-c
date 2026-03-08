#ifndef MATH_UTILS_H
#define MATH_UTILS_H
#pragma comment(lib, "maths.lib")
#ifdef __cplusplus
extern "C" {
#endif

	// Windows-specific export/import macros
#ifdef MATH_UTILS_EXPORTS
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif

// Function declarations
	MATH_API double gamma(double value);
	MATH_API double factorial(double value);
	MATH_API double absolute_value(double value);
	MATH_API double power(double base, double exponent);
	MATH_API double square_root(double value);

#ifdef __cplusplus
}
#endif

#endif // MATH_UTILS_H