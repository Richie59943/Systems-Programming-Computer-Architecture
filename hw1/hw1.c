#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {

  double final_area_disk = M_PI * radius * radius;
  return final_area_disk;
}

double area_of_ring(double outer_radius, double inner_radius) {

  if (outer_radius > inner_radius) {
    double final_area_ring =
        M_PI * ((outer_radius * outer_radius) - (inner_radius * inner_radius));
    return final_area_ring;
  }

  else {
    printf("The outer_radius must be greater than the inner_radius (ENTER "
           "VALID NUMBERS)\n");
  }
  return 0;
}
int bigger_minus_smaller(int a, int b) {

  if (a > b) {

    return (a - b);
  } else {
    return (b - a);
  }
  return 0;
}

bool value_in_range(int lower_bound, int x, int upper_bound) {

  if (x >= lower_bound && x <= upper_bound) {

    return true;
  } else {

    return false;
  }
}

int sum_of_greater_squares(int a, int b, int c) {
  int a_sq = a * a;
  int b_sq = b * b;
  int c_sq = c * c;

  if (a_sq >= b_sq && c_sq >= b_sq)

  {
    return a_sq + c_sq;
  } else if (b_sq >=  a_sq && c_sq >= a_sq) {
    return b_sq + c_sq;
  } else {
    return a_sq + b_sq;
  }
  return false;
}
