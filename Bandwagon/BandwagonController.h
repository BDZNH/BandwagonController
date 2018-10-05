#ifndef BANDWAGON_CONTROLLER_H
#define BANDWAGON_CONTROLLER_H

#include <string>
#include<curl/curl.h>
namespace
{
	std::size_t callback(
		const char* in,
		std::size_t size,
		std::size_t num,
		std::string* out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}

class BandwagonController
{
public:
	BandwagonController();
	BandwagonController(std::string id, std::string key);
	~BandwagonController();
	int getVPSInfo(std::string &response,int &httpcode);
	bool setVPSID(std::string ID);
	bool setVPSKey(std::string Key);
private:
	std::string cVPSID;
	std::string cPrivateKey;
	std::string cHost;
	int Httpcode;
	CURL *curl;
	CURLcode res;
};


#endif // !BANDWAGON_CONTROLLER_H
