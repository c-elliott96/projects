// file: Fraction.h
// name: Christian Elliott

//--------------------------------------------------------------------------
// Print fraction modeled by numerator n and denominator d.
//--------------------------------------------------------------------------
void fraction_print(int, int);

//--------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e.,
// xn/xd, is set to the sum of the fractions modeled by yn/yd and zn/zd,
// i.e., xn/xd = yn/yd + zn/zd
//--------------------------------------------------------------------------
void fraction_add(int & xn, int & xd,
                  int yn, int yd,
                  int zn, int zd);

//-------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e., xn/xd,
// is set to the difference of the fractions modeled by yn/yd and zn/zd, i.e.,
// xn/xd = yn/yd - zn/zd
//-------------------------------------------------------------------------
void fraction_subtract(int & xn, int & xd,
                       int yn, int yd,
                       int zn, int zd);

//-------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e., xn/xd,
// is set to the product of the fractions modeled by yn/yd and zn/zd, i.e.,
// xn/xd = yn/yd * zn/zd
//-------------------------------------------------------------------------
void fraction_multiply(int & xn, int & xd,
                       int yn, int yd,
                       int zn, int zd);

//-------------------------------------------------------------------------
// The fraction modeled by xn and xd as numerator and denominator, i.e., xn/xd,
// is set to the quotient of the fractions modeled by yn/yd and zn/zd, i.e.,
// xn/xd = (yn/yd) / (zn/zd)
//-------------------------------------------------------------------------
void fraction_divide(int & xn, int & xd,
                     int yn, int yd,
                     int zn, int zd);

//-------------------------------------------------------------------------
// This function tests the equality of two fractions represented by yn/yd
// and zn/zd, and returns a boolean truth value. 
//-------------------------------------------------------------------------
bool fraction_eq(int yn, int yd,
                 int zn, int zd);

//-------------------------------------------------------------------------
// This function tests the non-equality of two fractions represented by
// fraction_eq()
// and returns a boolean truth value.
//-------------------------------------------------------------------------
bool fraction_neq(int yn, int yd,
                  int zn, int zd);

//-------------------------------------------------------------------------
// This function tests if yn/yn is less than zn/zd
// in
// fraction_lt()
// and returns a boolean truth value.
//-------------------------------------------------------------------------
bool fraction_lt(int yn, int yd,
                 int zn, int zd);


//-------------------------------------------------------------------------
// this function finds factors of x^3 + (an/ad)x^2 + (bn/bd)x + (cn/cd)
// in the form of (x - dn/dd)(x - en/ed)(x - fn/fd)
//-------------------------------------------------------------------------
void fraction_factorization(int an, int ad,
                            int bn, int bd,
                            int cn, int cd);
//-------------------------------------------------------------------------
//end
