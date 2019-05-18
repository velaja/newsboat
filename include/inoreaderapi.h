#ifndef NEWSBOAT_INOREADERAPI_H_
#define NEWSBOAT_INOREADERAPI_H_

#include "cache.h"
#include "remoteapi.h"
#include "urlreader.h"

namespace newsboat {

class InoreaderApi : public RemoteApi {
public:
	explicit InoreaderApi(ConfigContainer* c);
	virtual ~InoreaderApi();
	virtual bool authenticate();
	virtual std::vector<TaggedFeedUrl> get_subscribed_urls();
	virtual void add_custom_headers(curl_slist** custom_headers);
	virtual bool mark_all_read(const std::string& feedurl);
	virtual bool mark_article_read(const std::string& guid, bool read);
	virtual bool update_article_flags(const std::string& inoflags,
		const std::string& newflags,
		const std::string& guid);

private:
	std::vector<std::string> get_tags(xmlNode* node);
	std::string get_new_token();
	std::string retrieve_auth();
	std::string post_content(const std::string& url,
		const std::string& postdata);
	bool star_article(const std::string& guid, bool star);
	bool share_article(const std::string& guid, bool share);
	bool mark_article_read_with_token(const std::string& guid,
		bool read,
		const std::string& token);
	std::string auth;
	std::string auth_header;
};

} // namespace newsboat

#endif /* NEWSBOAT_INOREADERAPI_H_ */
