#include "SI.h"

namespace si{
	SoundManager* soundManager;
	MusicManager* musicManager;

	bool initalize(SoundManager*& sm, MusicManager*& mm){
		soundManager = sm;
		musicManager = mm;
	}

	bool finalize(){
		delete soundManager;
		delete musicManager;

		return true;
	}
}