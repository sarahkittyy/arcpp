#include <stdexcept>

#include "arcpp/iterator.hpp"

namespace arcpp {

iterator::iterator(::archive* ar)
	: m_ar(ar),
	  m_ok(true) {
	next();
}

iterator& iterator::next() {
	if (done()) {
		throw std::out_of_range("No more entries left in archive iterator.");
	}

	if (archive_read_next_header(m_ar, &m_entry) != ARCHIVE_OK) {
		m_ok = false;
	}

	return *this;
}

entry iterator::get() const {
	return entry(m_ar, m_entry);
}

bool iterator::done() const {
	return !m_ok;
}

void iterator::reset() {
	m_ok	= true;
	m_entry = nullptr;
	next();
}

}