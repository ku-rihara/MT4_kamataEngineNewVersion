

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
	/*Quaternion Identity()const;*/
	static Quaternion Identity();

	//共役Quaternionを返す
	Quaternion Conjugate() const;

	// ノルム
	float Norm()const;

	// 正規化
	Quaternion Normalize() const;

	// 逆Quaternion
	Quaternion Inverse();


	static void QuaternionScreenPrintf(int x, int y, const Quaternion& q, const char* label);
};


