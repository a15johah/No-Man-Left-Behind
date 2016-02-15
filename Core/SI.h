#include "SoundManager.h"
#include "MusicManager.h"

namespace si{
	extern SoundManager* soundManager;
	extern MusicManager* musicManager;

	// Initialize \ Finalize
	bool initalize(SoundManager*& sm, MusicManager*& mm);

	bool finalize();

}