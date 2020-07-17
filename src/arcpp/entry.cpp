#include <filesystem>

#include "arcpp/entry.hpp"

namespace arcpp {

entry::entry(const entry& other)
	: m_entry(other.m_entry),
	  m_ar(other.m_ar) {
}

entry::entry(::archive* ar, archive_entry* e)
	: m_entry(e),
	  m_ar(ar) {
}

std::string entry::path_name() const {
	return std::string(archive_entry_pathname(m_entry));
}

std::string entry::contents() const {
	if (type() != FILE) {
		throw std::runtime_error("Cannot read contents of non-file type.");
	}

	int64_t size = archive_entry_size(m_entry);	  // get the file content size
	char* data	 = new char[size + 1]();		  // create a buffer
	archive_read_data(m_ar, data, size);		  // read into that buffer
	std::string res(data);						  // save in an std::string
	delete[] data;								  // free the original memory
	return res;									  // return
}

entry::TYPE entry::type() const {
	mode_t type = archive_entry_filetype(m_entry);
	switch (type) {
	case AE_IFDIR:
		return DIRECTORY;
	case AE_IFREG:
		return FILE;
	case AE_IFLNK:
		return SYMLINK;
	case AE_IFCHR:
		return CHARACTER_DEVICE;
	case AE_IFBLK:
		return BLOCK_DEVICE;
	case AE_IFIFO:
		return NAMED_PIPE;
	}
	throw std::runtime_error("Unknown entry type.");
}

}