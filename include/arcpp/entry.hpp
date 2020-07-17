#pragma once

#include <archive.h>
#include <archive_entry.h>

#include <string>

namespace arcpp {

/**
 * @brief A single entry of an archive
 * 
 */
class entry {
public:
	/**
	 * @brief copy constructor
	 * 
	 */
	entry(const entry& other);

	/**
	 * @brief Get the path of the file in the archive
	 * 
	 * @return std::string 
	 */
	std::string path_name() const;

	/**
	 * @brief All possible entry types.
	 * 
	 */
	enum TYPE {
		FILE,
		SYMLINK,
		DIRECTORY,
		SOCKET,
		CHARACTER_DEVICE,
		BLOCK_DEVICE,
		NAMED_PIPE
	};

	/**
	 * @brief Get this entry's filetype.
	 * 
	 * @return entry::TYPE 
	 */
	entry::TYPE type() const;

	/**
	 * @brief Read the contents of the entry
	 * If this entry is not a file, throws std::runtime_error.
	 * 
	 * @return std::string
	 */
	std::string contents() const;

private:
	friend class iterator;

	/**
	 * @brief Constructor is private as it should only be returned from relevant iterators
	 * 
	 * @param e The internal entry representation
	 */
	entry(::archive* ar, archive_entry* e);

	archive_entry* m_entry;
	::archive* m_ar;
};

}