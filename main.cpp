#include <Novice.h>
#include"CMatrix4x4.h"
#include"Quaternion.h"


const char kWindowTitle[] = "LE2A_11_クリハラ_ケイタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Quaternion rotate0 = Quaternion::MakeRotateAxisAngleQuaternion({ 0.71f,0.71f,0.0f }, 0.3f);
	Quaternion rotate1 = Quaternion::MakeRotateAxisAngleQuaternion({ 0.71f,0.0f,0.71f }, 3.141592f);

	Quaternion interpolate0 = Quaternion::Slerp(rotate0, rotate1, 0.0f);
	Quaternion interpolate1 = Quaternion::Slerp(rotate0, rotate1, 0.3f);
	Quaternion interpolate2 = Quaternion::Slerp(rotate0, rotate1, 0.5f);
	Quaternion interpolate3 = Quaternion::Slerp(rotate0, rotate1, 0.7f);
	Quaternion interpolate4 = Quaternion::Slerp(rotate0, rotate1, 1.0f);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Quaternion::QuaternionScreenPrintf(0, 0,  interpolate0, "      : interpolate0, Slerp(q0 , q1, 0.0f)");
		Quaternion::QuaternionScreenPrintf(0, 20, interpolate1, "      : interpolate1, Slerp(q0 , q1, 0.3f)");
		Quaternion::QuaternionScreenPrintf(0, 40, interpolate2, "      : interpolate2, Slerp(q0 , q1, 0.5f)");
		Quaternion::QuaternionScreenPrintf(0, 60, interpolate3, "      : interpolate3, Slerp(q0 , q1, 0.7f)");
		Quaternion::QuaternionScreenPrintf(0, 80, interpolate4, "      : interpolate4, Slerp(q0 , q1, 1.0f)");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
