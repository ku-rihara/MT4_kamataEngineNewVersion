

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
	Quaternion Identity()const;

	//共役Quaternionを返す
	Quaternion Conjugate(const Quaternion& quaternion) const;

	// ノルム
	float Norm(const Quaternion& quaternion)const;

	// 正規化
	Quaternion Normalize(const Quaternion& quaternion) const;

	// 逆Quaternion
	Quaternion Inverse(const Quaternion& quaternion);
};


