#include <stdexcept>

#include "arcpp/archive.hpp"

namespace arcpp {

archive::archive()
	: m_ar(nullptr) {
}

archive::~archive() {
	if (m_ar != nullptr) {
		archive_read_free(m_ar);
		m_ar = nullptr;
	}
}

void archive::open(const std::string& path) {
	if (m_ar != nullptr) {
		archive_read_free(m_ar);
		m_ar = nullptr;
	}

	m_ar = archive_read_new();
	archive_read_support_filter_all(m_ar);
	archive_read_support_format_all(m_ar);
	int res = archive_read_open_filename(m_ar, path.c_str(), 10240);
	if (res != ARCHIVE_OK) {
		if (res != ARCHIVE_OK)
			throw std::runtime_error(archive_error_string(m_ar));
	}
}

iterator archive::files() {
	if (m_ar == nullptr) {
		throw std::runtime_error("No archive is open to iterate through.");
	}
	iterator i(m_ar);
	return i;
}


}