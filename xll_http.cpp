// xll_http.cpp - wrappers for nanohttp
#define LIBXML_HTTP_ENABLED
#pragma warning(disable : 4996)
#include <libxml/xmlmemory.h>
#include <libxml/nanohttp.h>
#include "xll24/include/xll.h"

#define CATEGORY "HTTP"

namespace nano { 
	
	struct init {
		init()
		{
			xmlNanoHTTPInit();
		}
		~init()
		{
			xmlNanoHTTPCleanup();
		}
	} _;
	
	class http {
		void* ctx;
		char* contentType;
	public:
		http(const char* url)
			: ctx(nullptr), contentType(nullptr)
		{
			ctx = xmlNanoHTTPOpen(url, &contentType);
			//xmlNanoHTTPFetchContent(ctx);
		}
		http(const http&) = delete;
		http& operator=(const http&) = delete;
		~http()
		{
			if (contentType) {
				xmlFree(contentType);
			}
			if (ctx) {
				xmlNanoHTTPClose(ctx);
			}
		}
		int FetchContent()
		{
			return 0;// xmlNanoHTTPFetchContent(ctx, 0, 0);
		}
	};
	
} // namespace nano