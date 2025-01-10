#include <Novice.h>
#include"Quaternion.h"

const char kWindowTitle[] = "LE2A_11_クリハラ_ケイタ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Quaternion q1 = { 2.0f,3.0f,4.0f,1.0f };
	Quaternion q2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = Quaternion::Identity();
	Quaternion conj = q1.Conjugate();
	Quaternion inv = q1.Inverse();
	Quaternion normal = q1.Normalize();
	Quaternion mul1 = q1 * q2;
	Quaternion mul2 = q2 * q1;
	float norm = q1.Norm();


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
		Quaternion::QuaternionScreenPrintf(0, 0, identity, ":Identity");
		Quaternion::QuaternionScreenPrintf(0, 20, conj, ":Conjugate");
		Quaternion::QuaternionScreenPrintf(0, 40, inv, ":Inverse");
		Quaternion::QuaternionScreenPrintf(0, 60, normal, ":Normalize");
		Quaternion::QuaternionScreenPrintf(0, 80, mul1, ":Multiply(q1,q2)");
		Quaternion::QuaternionScreenPrintf(0, 100, mul2, ":Multiply(q2,q1)");
		Novice::ScreenPrintf(0, 120, "%3.2f                              :Norm", norm);
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
