#include "BandwagonController.h"

BandwagonController::BandwagonController()
{
	Httpcode = 0;
	cHost = "https://api.64clouds.com/v1/";
	//httpData = (new std::string());
	curl = curl_easy_init();
	if (curl)
	{
		//curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, true);
		//curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);


		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */
	}
}


BandwagonController::BandwagonController(std::string id,std::string key):cVPSID(id),cPrivateKey(key)
{
	Httpcode = 0;
	cHost = "https://api.64clouds.com/v1/";
	//httpData = (new std::string());
	curl = curl_easy_init();
	if (curl)
	{
		//curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, true);
		//curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
		
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		// Hook up data handling function.
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

		
	}
}


BandwagonController::~BandwagonController()
{

	/* cleanup */
	curl_easy_cleanup(curl);
}

int BandwagonController::getVPSInfo(std::string &response,int &httpcode)
{
	std::string temp;
	temp = cHost + "getServiceInfo?veid=" + cVPSID + "&api_key=" + cPrivateKey;


	/* Perform the request, res will get the return code */

	curl_easy_setopt(curl, CURLOPT_URL, temp.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
	res = curl_easy_perform(curl);
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &Httpcode);

	/* Check for errors */
	if (res != CURLE_OK)
		fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	httpcode = Httpcode;
	
	return 1;
}


bool BandwagonController::setVPSID(std::string ID)
{
	cVPSID = ID;
	if (cVPSID != ID)
	{
		return false;
	}
	return true;
}

bool BandwagonController::setVPSKey(std::string Key)
{
	cPrivateKey = Key;
	if (cPrivateKey != Key)
	{
		return false;
	}
	return true;
}