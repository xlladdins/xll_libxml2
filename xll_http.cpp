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
	
		int Read(void* buf, int len)
		{
			return xmlNanoHTTPRead(ctx, buf, len);
		}
	};
	
} // namespace nano

auto xxx = []() {
	static nano::http h("https://google.com");
	char buf[10];
	h.Read(buf, 10);
	h.Read(buf, 10);

	return 0;
	}();