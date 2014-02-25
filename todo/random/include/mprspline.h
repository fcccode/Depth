/*-----------------------------------------------------------------------------*\
| Matpack - Rational Cubic Spline Interpolation                     mprspline.h |
|                                                                               |
| Last change: Sep 12, 2004                                                     |
|                                                                               |
| Matpack Library Release 1.9.0                                                 |
| Copyright (C) 1991-2004 by Berndt M. Gammel                                   |
|                                                                               |
| Permission to  use, copy, and  distribute  Matpack  in  its entirety  and its |
| documentation  for non-commercial purpose and  without fee is hereby granted, |
| provided that this license information and copyright notice appear unmodified |
| in all copies.  This software is provided 'as is'  without express or implied |
| warranty.  In no event will the author be held liable for any damages arising |
| from the use of this software.						|
| Note that distributing Matpack 'bundled' in with any product is considered to |
| be a 'commercial purpose'.							|
| The software may be modified for your own purposes, but modified versions may |
| not be distributed without prior consent of the author.			|
|                                                                               |
| Read the  COPYRIGHT and  README files in this distribution about registration	|
| and installation of Matpack.							|
|                                                                               |
\*-----------------------------------------------------------------------------*/

#include "mpcurvebase.h"

//-----------------------------------------------------------------------------//

#ifndef _MPRSPLINE_H_
#define _MPRSPLINE_H_

namespace MATPACK {

class MpRationalCubicSpline : public MpCurveBase
{
  protected:
    int boundary;	
    double p,r1,r2;
    Vector dx,dy,a,b,c,d;

    void Differences (const Vector& x, Vector& dx);
    void InverseDifferences (const Vector& x, Vector& dx);
    void SplineA  (double p, const Vector& dx, Vector& z);
    void SplineB1 (double p, const Vector& dx, const Vector& y, 
		   Vector& y1, Vector& f, const Vector& z);
    void SplineC1 (double p, const Vector& x, const Vector& dx, 
		   const Vector& y, const Vector& y1,
		   Vector &a, Vector &b, Vector &c, Vector &d);
    void SplineB2 (double p, const Vector& dx, const Vector& y, 
		   Vector& y2, Vector& f, const Vector& z);
    void SplineC2 (double p, const Vector& x, const Vector& dx, 
		   const Vector& y, const Vector& y2,
		   Vector &a, Vector &b, Vector &c, Vector &d);  

  public:

    MpRationalCubicSpline (void) 
      : boundary(Natural), p(0.0) { }
    virtual ~MpRationalCubicSpline (void)  { }
    virtual int Interpolate (const Vector &x, const Vector &y);
    virtual double GetX (double u) { return u; }
    virtual double GetY (double u);

    void   SetSmoothing (double smoothing);
    double GetSmoothing (void) const { return p; }
    void   SetBoundaryConditions (int bnd, double b1 = 0.0, double b2 = 0.0);
    int    GetBoundaryConditions (void) const { return boundary; }
    int    GetBoundaryConditions (double &b1, double &b2) const 
           { b1 = r1; b2 = r2; return boundary; }
};

} // namespace MATPACK

//-----------------------------------------------------------------------------//

#endif
