#pragma once

#include <string>

#include "archive.h"
#include "arcpp/iterator.hpp"

namespace arcpp {

/**
 * @brief Main archive class. Used for reading and writing.
 * 
 */
class archive {
public:
	archive();
	~archive();

	/**
	 * @brief Open the archive at the given path.
	 * 
	 * @param path The path to the archive. 
	 */
	void open(const std::string& path);

	/**
	 * @brief Retrieve an iterator over all files in the opened archive.
	 * 
	 * @return iterator
	 */
	iterator files();

private:
	/// internal liba archive.
	::archive* m_ar;
};

}