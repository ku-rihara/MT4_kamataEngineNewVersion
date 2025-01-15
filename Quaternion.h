#include"CVector3.h"
class Quaternion {
public:
	float x;
	float y;
	float z;
	float w;

	// コンストラクタ
	Quaternion() : x(0), y(0), z(0) ,w(0){}
	Quaternion(float numX, float numY, float numZ,float numW) :
		x(numX), y(numY), z(numZ),w(numW) {}

	// 乗算
	Quaternion operator*(const Quaternion& obj) const;

	//単位
	static Quaternion Identity();

	//共役Quaternionを返す
	Quaternion Conjugate() const;

	// ノルム
	float Norm()const;

	// 正規化
	Quaternion Normalize() const;

	// 逆Quaternion
	Quaternion Inverse()const;

	//任意回転を表すQuaternionの生成
	static Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, const float& angle);

	// ベクトルをQuaternionで回転させた結果のベクトルを求める
	 Vector3 RotateVector(const Vector3& vector);

	static void QuaternionScreenPrintf(int x, int y, const Quaternion& q, const char* label);
};


