AM_CXXFLAGS= \
	-Wall \
	-Werror \
	-std=c++11 \
	-ggdb3

bin_PROGRAMS =\
	mooguor

lib_LTLIBRARIES=\
	libmooguor.la

libmooguor_la_SOURCES=\
	object.cpp\
	parser_json.cpp\
	variant.cpp\
	variant_string.cpp\
	variant_list.cpp\
	variant_map.cpp

libmooguor_la_LDFLAGS=\
	-ljson

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
