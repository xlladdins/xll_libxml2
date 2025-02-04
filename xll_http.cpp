// xll_http.cpp - wrappers for nanohttp
#include <libxml/nanohttp.h>
#include "xll24/include/xll.h"

#define CATEGORY "HTTP"

namespace nano { 

	/*
	struct init {
		init()
		{
			xmlNanoHTTPInit();
		}
		~init()
		{
			xmlNanoHTTPCleanup();
		}
	};
	class http {
		void* ctx;
	public:
		http(const char* url)
		{
			xmlNanoHTTPInit();
			ctx = xmlNanoHTTPOpen(url, &ctx);
		}
	};
	*/

} // namespace nano