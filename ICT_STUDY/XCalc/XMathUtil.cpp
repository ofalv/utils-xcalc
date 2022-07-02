

#include <stdio.h>

#include "XMathUtil.h"

#ifndef M_PI
	#define  M_PI  3.1415926535
#endif



// ��� ġȯ ��� �Լ�
// ���� d1 * f1 + d2 * f2 �� ����ؼ� d1��Ŀ� �Է�
bool ChangeMat(double d1[], double f1 , double d2[], double f2)
{
	for(int i=0; i<MAT_COL; i++)
   {
		d1[i] = f1 * d1[i] + f2 * d2[i];
   }

   return true;
}

//--------------------------------------------------------------------
// 3X4 ����� ���콺 �ҰŹ����� ���� ���ϴ� �Լ�
//--------------------------------------------------------------------
#define MIN_DIVIDED_VALUE		0.000001
#define MIN_SLOPE		0.0001
bool CalcGauss(double data[][MAT_COL])
{
	int i, j, k;

	double mat[MAT_ROW][MAT_COL];

   // ������ ��絵 ���� �Ͽ� �� �������� ���� ��� ���� ����
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



	// �밢����İ�(1,1),(2,2),(3,3)�� 0�� �ƴ� ���� �迭�ǵ��� �Ѵ�.
	// Gauss ��� ������ mat ��� �����
	for(k=0; k<MAT_COL-1; k++)
	{
		for(i=0; i<MAT_ROW; i++)
		{
			if(data[i][k] != 0.0)
			{
         	// M(i, k) �࿭�� ���� 0.0�� �ƴ� ���� ������ ����
				// mat�� ������ �Է��� data���� 0.0���� �ʱ�ȭ�Ͽ� �ߺ��� ������
				for(j=0; j<MAT_COL; j++)
				{
					mat[k][j] = data[i][j];
					data[i][j] = 0.0;
				}
				break;
			}
		}

      // ����ó��
      // k���� 0�� �ƴ� ���� ������ ���� ó����
      // k�� 0�϶��� x��ǥ�� ��� 0.0 �̹Ƿ� �����̰�
      // k�� 1�϶��� y��ǥ�� ��� 0.0�� ���̹Ƿ� ������ ������ ��ǥ�� �ƴ�
		if(i == MAT_ROW) // ����
			return false;
	}



   //----------------------------------------------------------------------------
   // 0.0 ���� ������ ���� ���� ó��
   if( fabs(mat[0][0]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }
   // ù��° ����
   // (  1	, ? , ?  )
   // (  0	, ? , ?  )
   // (  0	, ? , ?  )
   // ���� ����
	ChangeMat(mat[0], 1.0 / mat[0][0], mat[0] , 0.0);
	ChangeMat(mat[1], 1.0, mat[0] , -mat[1][0]);
	ChangeMat(mat[2], 1.0, mat[0] , -mat[2][0]);


   //----------------------------------------------------------------------------
   // 0.0 ���� ������ ���� ���� ó��
   if( fabs(mat[1][1]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }

   // �ι�° ����
   // (  1	, 0 , ?  )
   // (  0	, 1 , ?  )
   // (  0	, 0 , ?  )
   // ���� ����
	ChangeMat(mat[1], 1.0 / mat[1][1], mat[1] , 0.0);
	ChangeMat(mat[0], 1.0, mat[1] , -mat[0][1]);
	ChangeMat(mat[2], 1.0, mat[1] , -mat[2][1]);


   //----------------------------------------------------------------------------
   // 0.0 ���� ������ ���� ���� ó��
   if( fabs(mat[2][2]) < MIN_DIVIDED_VALUE )
   {
   	return false;
   }
   // ����° ����
   // (  1	, 0 , 0  )
   // (  0	, 1 , 0  )
   // (  0	, 0 , 1  )
   // ���� ����
	ChangeMat(mat[2], 1.0 / mat[2][2], mat[2] , 0.0);
	ChangeMat(mat[0], 1.0, mat[2] , -mat[0][2]);
	ChangeMat(mat[1], 1.0, mat[2] , -mat[1][2]);


	for(i=0; i<MAT_ROW; i++)
		for(j=0; j<MAT_COL; j++)
			data[i][j] = mat[i][j];

   return true;
}


//--------------------------------------------------------------------
// 3���� �̿��ؼ� ���� �������� ���ϴ� �Լ�
//--------------------------------------------------------------------
// x^2 + y^2 + Ax + By + C = 0 ���� ������ �Ϲ���
// ���⼭ A, B , C�� ����� ���ؼ� ���콺 �ҰŹ� ����
// A�� ��� : x
// B�� ��� : y
// C�� ��� : 1
// D�� ��� : -x^2 - y^2
// A,B,C���� ���� ����� �׹�° ���� �����
//--------------------------------------------------------------------
// A,B,C�� ���� ������ ���ϱ�
//--------------------------------------------------------------------
// ���� �߽� ( cx, cy )
// cx = - A / 2
// cy = - B / 2
// ������ R = Sqrt( -C - (A^2) / 4 - (B^2) / 4 )
// angle �����Ϳ� ����, ����, ������ ���� �Է�
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
// �߽���ǥ(cx, cy) ������ (sx, sy)�� ����(angle)�� �Է� �ϸ�
// ARC�� ������ ��ǥ (ex, ey)�� ����� �ִ� �Լ�
//--------------------------------------------------------------------
bool GetArcEndPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey )
{
	if(cx == sx && cy==sy)
   	return false;

   double dx = sx - cx;
   double dy = sy - cy;


	// ������ ���ϱ�
   double r = sqrt( dx*dx + dy*dy);
   //str.sprintf("������ : %2.4lf", r);
   //Form1->Memo1->Lines->Add(str);

	// �������� ����
   double sangle = atan2(dy, dx) * 180.0 / M_PI;
   //str.sprintf("������ ���� : %2.4lf", sangle);
   //Form1->Memo1->Lines->Add(str);

   // ������ ���� ����, ��ǥ ���
   double eAngle = sangle + angle;
   ex = r * cos( eAngle * M_PI / 180.0 ) + cx;
   ey = r * sin( eAngle * M_PI / 180.0 ) + cy;

   //str.sprintf("���� ��ǥ (%2.4lf, %2.4lf) , ���� ���� : %2.4lf", ex, ey, eAngle);
   //Form1->Memo1->Lines->Add(str);

	char buf[100];
	sprintf(buf, "kkol     r=%2.3lf, sangle=%2.3lf, eangle=%2.3lf, end(%2.3lf , %2.3lf)",
		r, sangle, eAngle, ex, ey);

 	return true;
}


//--------------------------------------------------------------------
// �߽���ǥ(cx, cy) ������ (sx, sy)�� ����(angle)�� �Է� �ϸ�
// ARC�� �䰣 ��ǥ (ex, ey)�� �������ִ� �ִ� �Լ�
//--------------------------------------------------------------------
bool GetArcMidPos(/*IN*/double cx, /*IN*/double cy, /*IN*/double sx, /*IN*/double sy
	, /*IN*/double angle
	, /*OUT*/double &ex, /*OUT*/double &ey )
{
   return GetArcEndPos( cx, cy, sx, sy, angle/2, ex, ey );
}




//----------------------------------------------------------------------------
// cx, cy�� �߽����� angle ��ŭ ȸ�� ��ȯ ó��
void CalcRotation(double cx, double cy, double &x, double &y, double angle)
{
	double ox = x-cx;
	double oy = y-cy;

	// �������� ��ȯ
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
// ������ ����� ������  ���� ����
#define MOTION_TOLERANCE	  (0.01)
double CalcAngle(double x1, double y1, double x2, double y2)
{
	double angle;

	// ������ ���� (x1, y1)�� �� ���� ���� �������� ����
	if(x1 > x2 + MOTION_TOLERANCE)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	else if(fabs(x1 - x2) < MOTION_TOLERANCE) // x1, x2�� ����ϸ�...
	{
		if(y1 > y2 + MOTION_TOLERANCE)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
	}

	double dx = x2 - x1;
	double dy = y2 - y1;

	// ������ ���ٸ�..����
	if(fabs(dx)< MOTION_TOLERANCE && fabs(dy)<MOTION_TOLERANCE )
		return 0.0;

	// ���� ���
	angle = atan2(dy , dx) * 180 / M_PI;

	return angle;
}

//----------------------------------------------------------------------------




