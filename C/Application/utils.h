#ifndef UTILS_H
#define UTILS_H

#define TOGGLE_BIT(A,B)  ((A) ^= (1U << ((B) & 31UL)))
#define SET_BIT(A,B)  ((A) |= (1U << ((B) & 31UL)))
#define CLEAR_BIT(A,B)  ((A) &=~ (1U << ((B) & 31UL)))
#define CHECK_BIT(A, B) ((A) & (1U << ((B)& 31UL)))

#endif