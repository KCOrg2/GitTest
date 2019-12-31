/*
 * Copyright (c) 2005 the University of Southern California.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF SOUTHERN CALIFORNIA BE LIABLE TO ANY
 * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE
 * UNIVERSITY OF SOUTHERN CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * THE UNIVERSITY OF SOUTHERN CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF SOUTHERN CALIFORNIA HAS NO
 * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
 * MODIFICATIONS.
 *
 * Authors: Kelvin Chung (tatchung@graphics.usc.edu)	
 * 
 */

#include "Vec2d.h"
#include "math.h"
#include "Vec2f.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



const float Vec2d::EPS = Vec2f::EPS;  // Error tolerance

Vec2d::Vec2d(): x(0), y(0){}

Vec2d::Vec2d(double x, double y)
    :x(x), y(y) {}

void Vec2d::set(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Vec2d::get(double v[2]) const
{
	v[0] = x;
	v[1] = y;
}

void Vec2d::get(float v[2]) const
{
	v[0] = (float) x;
	v[1] = (float) y;
}


double Vec2d::length()
{
	return sqrtf((float) (x*x + y*y));
}

double Vec2d::sqDist(const Vec2d& q)
{
	double dx = x - q.x;
	double dy = y - q.y;
	return dx*dx + dy*dy;
}

Vec2d& Vec2d::operator = (const Vec2d &q)
{
	set(q.x, q.y);
	return *this;
}

bool Vec2d::operator == (const Vec2d& q)
{
	return ((x == q.x) && (y == q.y));
}


bool Vec2d::operator != (const Vec2d& q)
{
	return ((x != q.x) || (y != q.y));
}

Vec2d& Vec2d::operator -= (const Vec2d &q)
{
	x -= q.x;
	y -= q.y;
	return *this;
}

Vec2d& Vec2d::operator += (const Vec2d &q)
{
	x += q.x;
	y += q.y;
	return *this;
}


Vec2d& Vec2d::operator *= (double v)
{
	x *= v;
	y *= v;
	return *this;
}

Vec2d& Vec2d::operator /= (double v)
{
	x /= v;
	y /= v;
	return *this;
}


// I/O functions
ostream& operator << (ostream& os, Vec2d& q)
{
	return (os << q.x << " " << q.y);
}


istream& operator >> (istream& is, Vec2d& q)
{
	return (is >> q.x >> q.y);
}


// Helper functions
Vec2d operator - (const Vec2d& q)
{	
	return Vec2d(-q.x, -q.y);
}

Vec2d operator + (const Vec2d& q)
{		
	return Vec2d(q);
}


Vec2d operator + (const Vec2d &q1, const Vec2d &q2)
{
	return Vec2d(q1.x + q2.x, q1.y + q2.y);
}

Vec2d operator * (const Vec2d &q, const double v)
{
	return Vec2d(q.x*v, q.y*v);
}

Vec2d operator * (const double v, const Vec2d &q)
{
	return Vec2d(q.x*v, q.y*v);
}


Vec2d operator - (const Vec2d &q1, const Vec2d &q2)
{
	return Vec2d(q1.x - q2.x, q1.y - q2.y);
}

Vec2d operator / (const Vec2d& q, const double v)
{
	return Vec2d(q.x/v, q.y/v);
}


bool Vec2d::isZero(double eps)
{
	return ((x > -eps) && (x < eps) && 
		    (y > -eps) && (y < eps));		    
}

bool Vec2d::isApproxEqual(const Vec2d& q) const
{
	const static double eps = 1e-12;

	double dx = x - q.x;
	double dy = y - q.y;

	return ((dx >= -eps) && (dx <= eps) && (dy >= -eps) && (dy <= eps));		    
}
