/**
 * @file restrict.cpp
 *
 * Implementation of functionality for checking if the game will be able run on the system.
 */

#include "appfat.h"
#include "utils/paths.h"

namespace devilution {

/**
 * @brief Check that we have write access to the game install folder

 */
void ReadOnlyTest()
{
	const std::string path = paths::PrefPath() + "Diablo1ReadOnlyTest.foo";
	FILE *f = fopen(path.c_str(), "wt");
	if (f == nullptr) {
		DirErrorDlg(paths::PrefPath().c_str());
	}

	fclose(f);
	remove(path.c_str());
}

} // namespace devilution
