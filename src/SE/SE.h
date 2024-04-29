#pragma once

enum {
	SE1,
	SE2,
	SE3,
	SE4,
	SE5,
	SE6,
	SE7,
	SE8,
	SE9,
	SE10,
	SE11,
	SE12,
	SE13,
	SE14,
	SE15,
	SE16,
	SE17,

	MAX_SE
};

class SE {
private:
	int m_SEhndl;

public:
	void Init(int n);
	void Step();
	void Fin();

};