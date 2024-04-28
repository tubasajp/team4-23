#pragma once

//IsHitRectのプロトタイプ宣言
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);


//IsHitCircleのプロトタイプ宣言
bool IsHitCircle(int Ax, int Ay, int Ar, int Bx, int By, int Br);

// 矩形の当たり判定
// xy座標は左上の座標
//bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);