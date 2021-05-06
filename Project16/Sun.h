#include "GameObject.h"

class Sun : public GameObject{
public:
	//Sun(const char* shape = "¡Û");
	~Sun();
	bool sun_energy;
	int energy_pos;
	//
	//void Draw(int y, char* canvas);
	void Energy(char* canvas);
};