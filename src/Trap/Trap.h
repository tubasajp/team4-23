#pragma once

class CTrap {
private:
	float m_xpos = 0.0f, m_ypos = 0.0f;	// 座標
	float m_size = 1.0f;				// 大きさ
	float m_angle = 0.0f;				// 角度
	char m_serif = 0;					// セリフ
	int m_hndl;							// 画像ハンドル

public:

	void Init();						// 初期化
	void Step();						// 通常
	void Draw();						// 描画
	void Fin();							// 終了

	void DrawSerif(float x, float y,	// 会話描画
		int R, int G, int B, char serif);

	void SetPosX(float x);				// 座標設定
	void SetPosY(float y);
	float GetPosX() { return m_xpos; }	// 座標取得
	float GetPosY() { return m_ypos; }

};