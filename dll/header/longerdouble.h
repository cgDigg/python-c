#include "type.h"
#include <string.h>
#include <stdio.h>
typedef struct longerdouble {long value,short pointer}longerdouble;
anydef float_add(longerdouble number1, longerdouble number2) {
	if (number1.pointer == number2.pointer) {
        return (longerdouble){number1.value + number2.value, number1.pointer};
	}
	if (number1.pointer > number2.pointer) {
        return (longerdouble){number1.value + number2.value / (long)pow(10, number1.pointer - number2.pointer), number1.pointer};
	}else {
        return (longerdouble){number1.value / (long)pow(10, number2.pointer - number1.pointer) + number2.value, number2.pointer};
	}
    return (longerdouble){0,0};
}
anydef float_multiplication(longerdouble number1, longerdouble number2) {
    return (longerdouble){number1.value * number2.value, number1.pointer + number2.pointer};
}
anydef float_division(longerdouble number1, longerdouble number2) {
    return (longerdouble){number1.value / number2.value, number1.pointer - number2.pointer};
}