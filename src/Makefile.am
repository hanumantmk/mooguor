AM_CXXFLAGS= \
	-Wall \
	-Werror \
	-std=c++0x \
	-ggdb3

bin_PROGRAMS =\
	mooguor

lib_LTLIBRARIES=\
	libmooguor.la

libmooguor_la_SOURCES=\
	object.cpp\
	variant.cpp\
	variant_string.cpp\
	variant_list.cpp\
	variant_map.cpp

#libmooguor_la_LDFLAGS=

LDADD=\
	libmooguor.la

mooguor_SOURCES=\
	mooguor.cpp

#test_mooguor_LDFLAGS=\
#	-lgtest_main\
#	-lpthread
#
#test_mooguor_SOURCES=\
#	test_mooguor.cpp
