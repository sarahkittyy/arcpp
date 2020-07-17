#pragma once

#include <archive.h>
#include <archive_entry.h>

#include "arcpp/entry.hpp"

namespace arcpp {

/**
 * @brief To iterate over all entries in the archive.
 * 
 */
class iterator {
public:
	iterator(::archive* ar);

	/**
	 * @brief Check if the iterator still has files to read.
	 * 
	 * @return true If there are no more files left in the archive
	 */
	bool done() const;

	/**
	 * @brief Get the entry at the current iterator point
	 * 
	 * @return entry 
	 */
	entry get() const;

	/**
	 * @brief Move the iterator pointer to the next entry.
	 * 
	 * @return iterator& *this
	 */
	iterator& next();

	/**
	 * @brief Move the iterator to the first entry.
	 * 
	 */
	void reset();

private:
	::archive* m_ar;
	archive_entry* m_entry;

	bool m_ok;
};

}