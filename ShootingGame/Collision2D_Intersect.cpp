#include"Collision2D.h"

bool IntersectMediator(const CollisionShape2D& a, const CollisionShape2D& b) {
	switch (a.GetType()) {
	case EAABB:
		switch (b.GetType()) {
		case EAABB:
			return Intersect(static_cast<const AABB2D&>(a), static_cast<const AABB2D&>(b));

		case ECircle:
			return Intersect(static_cast<const Circle2D&>(b), static_cast<const AABB2D&>(a));
		}
		break;

	case ECircle:
		switch (b.GetType()) {
		case EAABB:
			return Intersect(static_cast<const Circle2D&>(a), static_cast<const AABB2D&>(b));

		case ECircle:
			return Intersect(static_cast<const Circle2D&>(a), static_cast<const Circle2D&>(b));

		}
		break;

	case ECapcule:
		switch (b.GetType()) {
		case ECapcule:
			return Intersect(static_cast<const Capsule2D&>(a), static_cast<const Capsule2D&>(b));

		}

		break;
	}


	return false;
}

bool Intersect(const Circle2D& a, const Circle2D& b)
{
	float distSq = (a.mCenter - b.mCenter).LengthSq();
	float sumRadii = a.mRadius + b.mRadius;
	return distSq <= (sumRadii * sumRadii);
}

bool Intersect(const AABB2D& a, const AABB2D& b)
{
	bool no = 
		a.mMax.x < b.mMin.x ||
		a.mMax.y < b.mMin.y ||
		b.mMax.x < a.mMin.x ||
		b.mMax.y < a.mMin.y;
	return !no;
}

// �J�v�Z���Ƃ̏Փ˂̓J�v�Z���̐^�񒆂𑖂钆�S���Ƃ̋���������i�J�v�Z���̊O���͂��̐����Ƃ̋������������̂Łj
bool Intersect(const Capsule2D& a, const Capsule2D& b)
{
	float distSq = LineSegment2D::MinDistSq(a.mSegment,b.mSegment);
	float sumRadii = a.mRadius + b.mRadius;
	return distSq <= (sumRadii * sumRadii);
}

bool Intersect(const Circle2D& s, const AABB2D& box)
{
	return false;
}

bool Intersect(const LineSegment2D& a, const LineSegment2D& b, float* outT1, float* outT2) {
	Vector2 av = a.DirVector(), bv = b.DirVector();
	float crsab = Vector2::Cross(av,bv);
	if (Math::NearZero(crsab)) {
		// ���s���
		return false;
	}
	
	Vector2 v = b.mStart - a.mStart;

	float crsva = Vector2::Cross(v, av);
	float crsvb = Vector2::Cross(v, bv);

	float t1 = crsva / crsab;
	float t2 = crsvb / crsab;

	if (outT1) {
		*outT1 = t1;
	}
	if (outT2) {
		*outT2 = t2;
	}

	if (t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1) {
		return false;
	}

	return true;
}