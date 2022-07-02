#ifndef XMathUtilH
#define XMathUtilH

//#include <windef.h>
#include <math.h>

#define MAT_ROW  		3
#define MAT_COL		4



// 행렬 계산
extern bool ChangeMat(double d1[], double f1 , double d2[], double f2);

// 가우스 소거법 계산
extern bool CalcGauss(double data[][MAT_COL]);

// 세점으로 원의 방정식 구함
extern bool Get3PointCircle(/*IN*/double *x, /*IN*/double *y
	, /*OUT*/double &cx, /*OUT*/double &cy, /*OUT*/double &r, /*OUT*/double *angle);

// BY struct POINT.
//bool Get3PointCircle( POINT &p1, POINT &p2, POINT &p3,
//                      double &cx, double &cy, double &r, double &angle)

// ARC의 마지막 좌표 계산
extern bool GetArcEndPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey );

extern bool GetArcMidPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey );



extern void CalcRotation(double cx, double cy, double &x, double &y, double angle);
extern double CalcAngle(double x1, double y1, double x2, double y2);


#endif