/*

		MUST BE CONVERTED INTO BOX2D, IF EVEN

*/







//#ifndef __PHYSICSUTILS__
//#define __PHYSICSUTILS__
//
//#include "vector.h"
//#include "Utils.h"
//#include "SeanPoint.h"
//#include "SeanRect.h"
//
//namespace PhysicsUtils
//{
//	static bool checkLineCollision(vector p0, vector p1, vector p2, vector p3)
//	{
//		//Ax + Bx = C
//		//A = Y0 - Y1
//		//B = X1 - X0
//		//C = A*x0 + B*y0
//
//		double A1 = p1._Y - p0._Y;
//		double	B1 = p0._X - p1._X;
//		double	C1 = A1 * p0._X + B1 * p0._Y;
//
//		double	A2 = p3._Y - p2._Y;
//		double	B2 = p2._X - p3._X;
//		double	C2 = A2 * p2._X + B2 * p2._Y;
//		double denominator = A1 * B2 - A2 * B1;
//
//		if (denominator == 0) {
//			return false;
//		}
//
//		//x = (B2*C1 - B2*C2) / (A1 * B2 - A2 * B1)
//		//y = (A1*C2 - A2*C1) / (A1 * B2 - A2 * B1)
//
//		double intersectX = (B2 * C1 - B1 * C2) / denominator;
//		double intersectY = (A1 * C2 - A2 * C1) / denominator;
//
//		double rx0 = (intersectX - p0._X) / (p1._X - p0._X);
//		double ry0 = (intersectY - p0._Y) / (p1._Y - p0._Y);
//		double rx1 = (intersectX - p2._X) / (p3._X - p2._X);
//		double ry1 = (intersectY - p2._Y) / (p3._Y - p2._Y);
//
//		if (((rx0 >= 0 && rx0 <= 1) || (ry0 >= 0 && ry0 <= 1)) &&
//			((rx1 >= 0 && rx1 <= 1) || (ry1 >= 0 && ry1 <= 1)))
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	/*sets collision points of p3 and p4 for line-to-line collision*/
//	static void findPoints(SeanPoint A, SeanPoint B, vector &p0, vector &p1)
//	{
//		p0 = { A.position._X, A.position._Y };
//		p1 = { B.position._X, B.position._Y };
//	}
//
//	static void stopAll(vector velocity, vector acceleration)
//	{
//		velocity = 0.0f;
//		acceleration = 0.0f;
//	}
//
//	static bool doTypeCollision(std::vector<SeanRect> boxes, vector headingA, vector headingB)
//	{
//		vector collideToA;
//		vector collideToB;
//
//		for (int i = 0; i != boxes.size(); i++)
//		{
//			for (int j = 0; j != 4; j++)
//			{
//				if (j == 0) // 3 -> 0
//				{
//					PhysicsUtils::findPoints(boxes[i].allVertices[j], boxes[i].allVertices[3], collideToA, collideToB); //Collision between the left hand side of the rect
//				}
//				else //everything else
//				{
//					PhysicsUtils::findPoints(boxes[i].allVertices[j], boxes[i].allVertices[j - 1], collideToA, collideToB);
//				}
//
//				if (PhysicsUtils::checkLineCollision(headingA, headingB, collideToA, collideToB))
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	static bool rectToRectcollision(SeanRect boxA, SeanRect boxB)
//	{
//		double Ax = boxA.UL.position._X;
//		double Ay = boxA.UL.position._Y;
//		double Aw = boxA.size_._X;
//		double Ah = boxA.size_._Y;
//
//		double Bx = boxB.UL.position._X;
//		double By = boxB.UL.position._Y;
//		double Bw = boxB.size_._X;
//		double Bh = boxB.size_._Y;
//
//		if (Ax < Bx + Bw && Ax + Aw > Bx && Ay < By + Bh && Ah + Ay > By) 
//		{
//			return true;
//		}
//
//		return false;
//	}
//};
//
//#endif