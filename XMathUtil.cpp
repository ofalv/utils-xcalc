

#include <stdio.h>

#include "XMathUtil.h"

#ifndef M_PI
	#define  M_PI  3.1415926535
#endif



// 행렬 치환 명령 함수
// 행을 d1 * f1 + d2 * f2 로 계산해서 d1행렬에 입력
bool ChangeMat(double d1[], double f1 , double d2[], double f2)
{
	for(int i=0; i<MAT_COL; i++)
   {
		d1[i] = f1 * d1[i] + f2 * d2[i];
   }

   return true;
}

//--------------------------------------------------------------------
// 3X4 행렬의 가우스 소거법으로 근을 구하는 함수
//--------------------------------------------------------------------
#define MIN_DIVIDED_VALUE		0.000001
#define MIN_SLOPE		0.0001
bool CalcGauss(double data[][MAT_COL])
{
	int i, j, k;

	double mat[MAT_ROW][MAT_COL];

   // 세점의 경사도 측정 하여 한 직선위에 있을 경우 에러 리턴
   // ( y2-y1) / ( x2-x1) == ( y3 - y2 ) / (x3 - x2)
   // -->  ( y2 - y1 ) * ( x3 - x2 ) == ( y3 - y2 ) * ( x2 - x1 )
   double y2_y1 = data[1][1]-data[0][1];
   double x3_x2 = data[2][0]-data[1][0];
   double y3_y2 = data[2][1]-data[1][1];
   double x2_x1 = data[1][0]-data[0][0];
   if( fabs( y2_y1 * x3_x2 - y3_y2 * x2_x1 ) < MIN_SLOPE )
   {
   	return false;
   }
   //----------------------------------------------------------------------------



	// 대각선행렬값(1,1),(2,2),(3,3)에 0이 아닌 값이 배열되도록 한다.
	// Gauss 계산 가능한 mat 행렬 만들기
	for(k=0; k<MAT_COL-1; k++)
	{
		for(i=0; i<MAT_ROW; i++)
		{
			if(data[i][k] != 0.0)
			{
         	// M(i, k) 행열의 값이 0.0이 아닌 열의 데이터 복사
				// mat에 데이터 입력후 data원소 0.0으로 초기화하여 중복를 방지함
				for(j=0; j<MAT_COL; j++)
				{
					mat[k][j] = data[i][j];
					data[i][j] = 0.0;
				}
				break;
			}
		}

      // 에러처리
      // k열에 0이 아닌 값이 없으면 에러 처리함
      // k가 0일때는 x좌표가 모두 0.0 이므로 직선이고
      // k가 1일때는 y좌표가 모두 0.0인 것이므로 세점은 윈위의 좌표가 아님
		if(i == MAT_ROW) // 에러
			return false;
	}



   //----------------------------------------------------------------------------
   // 0.0 으로 나누는 문제 에러 처리
   if( fabs(mat[0][0]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }
   // 첫번째 열을
   // (  1	, ? , ?  )
   // (  0	, ? , ?  )
   // (  0	, ? , ?  )
   // 으로 만듦
	ChangeMat(mat[0], 1.0 / mat[0][0], mat[0] , 0.0);
	ChangeMat(mat[1], 1.0, mat[0] , -mat[1][0]);
	ChangeMat(mat[2], 1.0, mat[0] , -mat[2][0]);


   //----------------------------------------------------------------------------
   // 0.0 으로 나누는 문제 에러 처리
   if( fabs(mat[1][1]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }

   // 두번째 열을
   // (  1	, 0 , ?  )
   // (  0	, 1 , ?  )
   // (  0	, 0 , ?  )
   // 으로 만듦
	ChangeMat(mat[1], 1.0 / mat[1][1], mat[1] , 0.0);
	ChangeMat(mat[0], 1.0, mat[1] , -mat[0][1]);
	ChangeMat(mat[2], 1.0, mat[1] , -mat[2][1]);


   //----------------------------------------------------------------------------
   // 0.0 으로 나누는 문제 에러 처리
   if( fabs(mat[2][2]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }
   // 세번째 열을
   // (  1	, 0 , 0  )
   // (  0	, 1 , 0  )
   // (  0	, 0 , 1  )
   // 으로 만듦
	ChangeMat(mat[2], 1.0 / mat[2][2], mat[2] , 0.0);
	ChangeMat(mat[0], 1.0, mat[2] , -mat[0][2]);
	ChangeMat(mat[1], 1.0, mat[2] , -mat[1][2]);


	for(i=0; i<MAT_ROW; i++)
		for(j=0; j<MAT_COL; j++)
			data[i][j] = mat[i][j];

   return true;
}


//--------------------------------------------------------------------
// 3점을 이용해서 원의 방정식을 구하는 함수
//--------------------------------------------------------------------
// x^2 + y^2 + Ax + By + C = 0 원의 방정식 일반형
// 여기서 A, B , C의 계수를 구해서 가우스 소거법 적용
// A의 계수 : x
// B의 계수 : y
// C의 계수 : 1
// D의 계수 : -x^2 - y^2
// A,B,C값의 근은 행렬의 네번째 열에 저장됨
//--------------------------------------------------------------------
// A,B,C로 원의 방정식 구하기
//--------------------------------------------------------------------
// 원의 중심 ( cx, cy )
// cx = - A / 2
// cy = - B / 2
// 반지름 R = Sqrt( -C - (A^2) / 4 - (B^2) / 4 )
// angle 포인터에 시점, 중점, 종점의 각도 입력
bool Get3PointCircle(/*IN*/double *x, /*IN*/double *y
	, /*OUT*/double &cx, /*OUT*/double &cy, /*OUT*/double &r, double *angle)
{
	double data[MAT_ROW][MAT_COL];

   for (int i=0; i<MAT_ROW; i++)
   {
   	data[i][0] = x[i];
   	data[i][1] = y[i];
      data[i][2] = 1.0;
      data[i][3] = - x[i]*x[i] - y[i]*y[i];
   }

   if( CalcGauss(data) == false)
		return false;

	double A, B, C;
   A = data[0][3];
   B = data[1][3];
   C = data[2][3];


   cx = - A / 2.0;
   cy = - B / 2.0;
   r = sqrt( -C + (A*A /4.0) + (B*B/4.0) ) ;

	if(angle!=NULL)
	{
		double dx, dy;

		for (int i=0; i<MAT_ROW; i++)
		{
			dx = x[i] - cx;
			dy = y[i] - cy;

			angle[i] = atan2(dy, dx) * 180.0 / M_PI;			
		}
	}

   return true;

}


//---------------------------------------------------------------------------
/*
bool Get3PointCircle( POINT &p1, POINT &p2, POINT &p3,
                      double &cx, double &cy, double &r, double &angle)
{
   static const size_t lDimension = 2;
   double data[lDimension][MAT_ROW];
   memset( data, 0, sizeof(data) );

   data[0][0] = p1.x;
   data[1][0] = p1.y;

   data[0][1] = p2.x;
   data[1][1] = p2.y;

   data[0][2] = p3.x;
   data[1][2] = p3.y;

   return Get3PointCircle( data[0], data[2], cx, cy, r, &angle );
}
*/

//--------------------------------------------------------------------
// 중심좌표(cx, cy) 시작점 (sx, sy)와 각도(angle)를 입력 하면
// ARC의 마지막 좌표 (ex, ey)를 계산해 주는 함수
//--------------------------------------------------------------------
bool GetArcEndPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey )
{
	if(cx == sx && cy==sy)
   	return false;

   double dx = sx - cx;
   double dy = sy - cy;


	// 반지름 구하기
   double r = sqrt( dx*dx + dy*dy);
   //str.sprintf("반지름 : %2.4lf", r);
   //Form1->Memo1->Lines->Add(str);

	// 시작점의 각도
   double sangle = atan2(dy, dx) * 180.0 / M_PI;
   //str.sprintf("시작점 각도 : %2.4lf", sangle);
   //Form1->Memo1->Lines->Add(str);

   // 마지막 점의 각도, 좌표 계산
   double eAngle = sangle + angle;
   ex = r * cos( eAngle * M_PI / 180.0 ) + cx;
   ey = r * sin( eAngle * M_PI / 180.0 ) + cy;

   //str.sprintf("종점 좌표 (%2.4lf, %2.4lf) , 종점 각도 : %2.4lf", ex, ey, eAngle);
   //Form1->Memo1->Lines->Add(str);

	char buf[100];
	sprintf(buf, "kkol     r=%2.3lf, sangle=%2.3lf, eangle=%2.3lf, end(%2.3lf , %2.3lf)",
		r, sangle, eAngle, ex, ey);

 	return true;
}


//--------------------------------------------------------------------
// 중심좌표(cx, cy) 시작점 (sx, sy)와 각도(angle)를 입력 하면
// ARC의 쭝간 좌표 (ex, ey)를 추출해주는 주는 함수
//--------------------------------------------------------------------
bool GetArcMidPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey )
{
   return GetArcEndPos( cx, cy, sx, sy, angle/2, ex, ey );
}




//----------------------------------------------------------------------------
// cx, cy를 중심으로 angle 만큼 회전 변환 처리
void CalcRotation(double cx, double cy, double &x, double &y, double angle)
{
	double ox = x-cx;
	double oy = y-cy;

	// 라디안으로 변환
	double r = angle * M_PI / 180.0 ;

	x = cos(r) * ox - sin(r) * oy;
	y = sin(r) * ox + cos(r) * oy;

	x += cx;
	y += cy;
}
//----------------------------------------------------------------------------

void swap(double &a, double &b)
{
	double x;

	x = a;
	a = b;
	b = x;

}
//----------------------------------------------------------------------------
// 두점이 만드는 직선의  각도 리턴
#define MOTION_TOLERANCE	  (0.01)
double CalcAngle(double x1, double y1, double x2, double y2)
{
	double angle;

	// 데이터 정열 (x1, y1)이 더 작은 값을 가지도록 정열
	if(x1 > x2 + MOTION_TOLERANCE)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	else if(fabs(x1 - x2) < MOTION_TOLERANCE) // x1, x2가 비슷하면...
	{
		if(y1 > y2 + MOTION_TOLERANCE)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
	}

	double dx = x2 - x1;
	double dy = y2 - y1;

	// 두점이 같다면..에러
	if(fabs(dx)< MOTION_TOLERANCE && fabs(dy)<MOTION_TOLERANCE )
		return 0.0;

	// 각도 계산
	angle = atan2(dy , dx) * 180 / M_PI;

	return angle;
}

//----------------------------------------------------------------------------




