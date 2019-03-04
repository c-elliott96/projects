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
