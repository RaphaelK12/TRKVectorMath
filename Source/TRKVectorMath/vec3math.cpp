

vec3 vec3::operator&(const vec3& rcVct) const {
	vec3 cVctRes;
	cVctRes.x = x * fabs(rcVct.x);
	cVctRes.y = y * fabs(rcVct.y);
	cVctRes.z = z * fabs(rcVct.z);
	return cVctRes;
}

vec3 vec3::operator%(const vec3& rcVct) const {
	vec3 cVctRes;
	cVctRes.x = (y * rcVct.z) - (z * rcVct.y);
	cVctRes.y = (z * rcVct.x) - (x * rcVct.z);
	cVctRes.z = (x * rcVct.y) - (y * rcVct.x);
	return cVctRes;
}

bool vec3::IsOnLineSegment(const vec3& startVct, const vec3& endVct) const {
	vec3 vectorAB = endVct - startVct;
	vec3 vectorAC = *this - startVct;
	vec3 crossproduct = vectorAB.cross(vectorAC);
	float dotproduct = vectorAB.dot(vectorAC);

	if (crossproduct.length() > traits_type::epsilon())
		return false;

	if (dotproduct < 0)
		return false;

	if (dotproduct > vectorAB.sqr())
		return false;

	return true;
}

bool vec3::operator!=(const vec3& rcVct) const {
	return !((*this) == rcVct);
}

bool vec3::operator==(const vec3& rcVct) const {
	return (fabs(x - rcVct.x) <= traits_type::epsilon()) &&
		(fabs(y - rcVct.y) <= traits_type::epsilon()) &&
		(fabs(z - rcVct.z) <= traits_type::epsilon());
}

bool vec3::IsEqual(const vec3& rclPnt, float tol) const {
	return Distance(*this, rclPnt) <= tol;
}

vec3& vec3::ProjectToPlane(const vec3& rclBase, const vec3& rclNorm) {
	vec3 clTemp(rclNorm);
	*this = *this - (clTemp *= ((*this - rclBase) * clTemp) / clTemp.sqr());
	return *this;
}

void vec3::ProjectToPlane(const vec3& rclBase, const vec3& rclNorm, vec3& rclProj) const {
	vec3 clTemp(rclNorm);
	rclProj = *this - (clTemp *= ((*this - rclBase) * clTemp) / clTemp.sqr());
}

float vec3::DistanceToPlane(const vec3& rclBase, const vec3& rclNorm) const {
	return ((*this - rclBase) * rclNorm) / rclNorm.length();
}

float vec3::DistanceToLine(const vec3& rclBase, const vec3& rclDirect) const {
	return fabs((rclDirect.cross(ec3(*this - rclBase))).length() / rclDirect.length());
}

vec3 vec3::DistanceToLineSegment(const vec3& rclP1, const vec3& rclP2) const {
	float len2 = Base::DistanceP2(rclP1, rclP2);
	if (len2 == 0)
		return rclP1;

	vec3 p2p1 = rclP2 - rclP1;
	vec3 pXp1 = *this - rclP1;
	float dot = pXp1 * p2p1;
	float t = clamp<float>(dot / len2, 0, 1);
	vec3 dist = t * p2p1 - pXp1;
	return dist;
}

vec3& vec3::ProjectToLine(const vec3& rclPoint, const vec3& rclLine) {
	return (*this = ((((rclPoint * rclLine) / rclLine.sqr()) * rclLine) - rclPoint));
}

vec3 vec3::Perpendicular(const vec3& rclBase, const vec3& rclDir) const {
	float t = ((*this - rclBase) * rclDir) / (rclDir * rclDir);
	return rclBase + t * rclDir;
}

float vec3::sqr(void) const {
	return ((x * x) + (y * y) + (z * z));
}

float vec3::GetAngle(const vec3& rcVect) const {
	float divid, fNum;

	divid = length() * ((vec3&)rcVect).length();

	if ((divid < -1e-10f) || (divid > 1e-10f)) {
		fNum = (*this * rcVect) / divid;
		if (fNum < -1)
			return traits_type::pi();
		else if (fNum > 1)
			return 0.0F;
		else
			return acos(fNum);
	}
	else
		return traits_type::maximum(); // division by zero
}

void vec3::TransformToCoordinateSystem(const vec3& rclBase, const vec3& rclDirX, const vec3& rclDirY) {
	vec3 clVectX, clVectY, clVectZ, clVectOld;

	clVectX = rclDirX;
	clVectY = rclDirY;
	clVectZ = rclDirX % rclDirY;
	clVectX.normalize();
	clVectY.normalize();
	clVectZ.normalize();

	clVectOld = *this - rclBase;

	x = clVectX * clVectOld;
	y = clVectY * clVectOld;
	z = clVectZ * clVectOld;
}
