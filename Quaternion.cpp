﻿#include "Quaternion.h" 
#include <cmath>        
#include<Novice.h>

const float kColumnWidth = 60;

// クォータニオンの乗算
Quaternion Quaternion::operator*(const Quaternion& obj) const {
    return Quaternion(
        w * obj.x + x * obj.w + y * obj.z - z * obj.y,
        w * obj.y - x * obj.z + y * obj.w + z * obj.x,
        w * obj.z + x * obj.y - y * obj.x + z * obj.w,
        w * obj.w - x * obj.x - y * obj.y - z * obj.z
    );
}

// 單位Quaternionの生成
Quaternion Quaternion::Identity() {
    return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

// 共装Quaternionを返す
Quaternion Quaternion::Conjugate() const {
    return Quaternion(-x, -y, -z, w);
}

// ノルム(長さの等価)
float Quaternion::Norm() const {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

// 正規化(ノルムを一にする)
Quaternion Quaternion::Normalize() const {
    float norm = Norm();
    if (norm == 0) {
        // ノルムが0の場合は、Identityを返す
        return Identity();
    }
    return Quaternion(x / norm, y / norm, z / norm, w / norm);
}

// 逆Quaternionを返す
Quaternion Quaternion::Inverse()const {
    float norm = Norm();
    if (norm == 0) {
        // 逆が存在しない場合はIdentity
        return Identity();
    }
    Quaternion conjugate = Conjugate();
    float normSquared = norm * norm;
    return Quaternion(conjugate.x / normSquared, conjugate.y / normSquared, conjugate.z / normSquared, conjugate.w / normSquared);

}

void Quaternion::QuaternionScreenPrintf(int x, int y, const Quaternion& q, const char* label) {
    Novice::ScreenPrintf(x, y, "%.02f", q.x);
    Novice::ScreenPrintf(int(x + kColumnWidth), y, "%.02f", q.y);
    Novice::ScreenPrintf(int(x + kColumnWidth * 2), y, "%.02f", q.z);
    Novice::ScreenPrintf(int(x + kColumnWidth * 3), y, "%.02f", q.w);
    Novice::ScreenPrintf(int(x + kColumnWidth * 5), y, "%s", label);
}

// 任意回転を表すQuaternionの生成
Quaternion Quaternion::MakeRotateAxisAngleQuaternion(const Vector3& axis, const float& angle) {
    // 正規化された軸を使用
    Vector3 normalizedAxis = vNormalize(axis);
    float halfAngle = angle / 2.0f;
    float sinHalfAngle = std::sin(halfAngle);

    return Quaternion(
        normalizedAxis.x * sinHalfAngle,
        normalizedAxis.y * sinHalfAngle,
        normalizedAxis.z * sinHalfAngle,
        std::cos(halfAngle)
    );
}

// ベクトルをQuaternionで回転させた結果のベクトルを求める
Vector3 Quaternion::RotateVector(const Vector3& vector) {
    Quaternion vectorQuat(vector.x, vector.y, vector.z, 0.0f);
    Quaternion inverseQuat = this->Inverse();

    // 回転の計算
    Quaternion rotatedQuat = (*this) * vectorQuat * inverseQuat;

    // 回転後のベクトルを返す
    return Vector3(rotatedQuat.x, rotatedQuat.y, rotatedQuat.z);
}